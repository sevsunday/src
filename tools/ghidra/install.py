#!/usr/bin/env python3
"""
install.py - portable Ghidra (latest release) + the Temurin JDK it requires, under tools/_local/ (D7).

Nothing is installed system-wide. Downloads go to tools/_local/downloads/, the
archives are hashed (SHA-256) and extracted to tools/_local/ghidra/ and
tools/_local/jdk/. Exact versions, URLs and hashes are written to
tools/ghidra/VERSIONS.txt (committed) so a later run can be checked against
what task 8 / task 13 actually used.

Sources (DEPENDENCIES.md D7):
  Ghidra : https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest
  JDK    : https://api.adoptium.net/v3/binary/latest/<major>/ga/windows/x64/jdk/hotspot/normal/eclipse
           (<major> = Ghidra/application.properties application.java.min; 12.x needs 25)

Usage: python tools/ghidra/install.py [--ghidra-url URL] [--jdk-url URL] [--force]
stdlib only.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import sys
import urllib.request
import zipfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
LOCAL = ROOT / "tools" / "_local"
DL = LOCAL / "downloads"
GHIDRA_DIR = LOCAL / "ghidra"
JDK_DIR = LOCAL / "jdk"
VERSIONS = ROOT / "tools" / "ghidra" / "VERSIONS.txt"
GH_API = "https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest"
JDK_API = "https://api.adoptium.net/v3/binary/latest/{major}/ga/windows/x64/jdk/hotspot/normal/eclipse"
UA = {"User-Agent": "VSR_DLL_Source-tools/1.0"}


def sha256(p: Path) -> str:
    h = hashlib.sha256()
    with open(p, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def download(url: str, dest: Path) -> tuple[Path, str]:
    dest.parent.mkdir(parents=True, exist_ok=True)
    req = urllib.request.Request(url, headers=UA)
    with urllib.request.urlopen(req) as resp:
        final = resp.geturl()
        name = dest.name
        cd = resp.headers.get("Content-Disposition", "")
        if "filename=" in cd:
            name = cd.split("filename=")[-1].strip('"; ')
        elif final.split("/")[-1].endswith(".zip"):
            name = final.split("/")[-1]
        target = dest.parent / name
        if target.exists():
            print(f"  already downloaded: {target.name}")
            return target, final
        tmp = target.with_suffix(".part")
        total = int(resp.headers.get("Content-Length") or 0)
        done = 0
        with open(tmp, "wb") as fh:
            while True:
                chunk = resp.read(1 << 20)
                if not chunk:
                    break
                fh.write(chunk)
                done += len(chunk)
                if total:
                    print(f"\r  {target.name}: {done * 100 // total:3d}% ({done >> 20} MB)", end="", flush=True)
        print()
        tmp.rename(target)
        return target, final


def ghidra_asset_url() -> tuple[str, str]:
    with urllib.request.urlopen(urllib.request.Request(GH_API, headers=UA)) as r:
        rel = json.loads(r.read().decode("utf-8"))
    tag = rel["tag_name"]
    for a in rel["assets"]:
        if a["name"].startswith("ghidra_") and a["name"].endswith(".zip") and "PUBLIC" in a["name"]:
            return a["browser_download_url"], tag
    raise SystemExit("no Ghidra PUBLIC zip asset in the latest release")


def extract_single_root(zip_path: Path, dest: Path, force: bool) -> Path:
    if dest.exists():
        if not force and any(dest.iterdir()):
            print(f"  already extracted: {dest}")
            return dest
        shutil.rmtree(dest)
    dest.mkdir(parents=True)
    with zipfile.ZipFile(zip_path) as z:
        names = z.namelist()
        roots = {n.split("/")[0] for n in names if "/" in n}
        z.extractall(dest)
    # flatten a single top-level folder (ghidra_11.x_PUBLIC/, jdk-21.x+y/)
    if len(roots) == 1:
        inner = dest / next(iter(roots))
        if inner.is_dir():
            for item in inner.iterdir():
                shutil.move(str(item), str(dest / item.name))
            inner.rmdir()
    return dest


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ghidra-url", help="override the Ghidra zip URL (default: latest GitHub release)")
    ap.add_argument("--jdk-url", help="override the JDK zip URL (default: Temurin GA of the major Ghidra requires)")
    ap.add_argument("--force", action="store_true", help="re-extract even if present")
    ap.add_argument("--suffix", default="", help="install side by side as tools/_local/ghidra<suffix> + jdk<suffix>, VERSIONS<suffix>.txt")
    args = ap.parse_args(argv)
    global GHIDRA_DIR, JDK_DIR, VERSIONS
    if args.suffix:
        GHIDRA_DIR = LOCAL / f"ghidra{args.suffix}"
        JDK_DIR = LOCAL / f"jdk{args.suffix}"
        VERSIONS = ROOT / "tools" / "ghidra" / f"VERSIONS{args.suffix}.txt"
    DL.mkdir(parents=True, exist_ok=True)

    print("[ghidra] resolving release")
    if args.ghidra_url:
        gurl, gtag = args.ghidra_url, "(pinned url)"
    else:
        gurl, gtag = ghidra_asset_url()
    print(f"  {gtag}: {gurl}")
    gzip, gfinal = download(gurl, DL / gurl.split("/")[-1])
    ghash = sha256(gzip)
    print(f"  sha256 {ghash}")
    extract_single_root(gzip, GHIDRA_DIR, args.force)

    # Ghidra states the JDK it needs (application.java.min); fetch that Temurin GA.
    major = "21"
    app_props = GHIDRA_DIR / "Ghidra" / "application.properties"
    if app_props.exists():
        for line in app_props.read_text(encoding="utf-8").splitlines():
            if line.startswith("application.java.min="):
                major = line.split("=", 1)[1].strip() or major
    jdk_url = args.jdk_url or JDK_API.format(major=major)
    print(f"[jdk] resolving Temurin {major} (Ghidra application.java.min)")
    jzip, jfinal = download(jdk_url, DL / f"temurin-jdk{major}.zip")
    jhash = sha256(jzip)
    print(f"  {jfinal}\n  sha256 {jhash}")
    extract_single_root(jzip, JDK_DIR, args.force)

    # sanity
    headless = GHIDRA_DIR / "support" / "analyzeHeadless.bat"
    java = JDK_DIR / "bin" / "java.exe"
    ok = headless.exists() and java.exists()
    app_props = GHIDRA_DIR / "Ghidra" / "application.properties"
    gver = ""
    if app_props.exists():
        for line in app_props.read_text(encoding="utf-8").splitlines():
            if line.startswith("application.version="):
                gver = line.split("=", 1)[1].strip()
    jrel = JDK_DIR / "release"
    jver = ""
    if jrel.exists():
        for line in jrel.read_text(encoding="utf-8").splitlines():
            if line.startswith("JAVA_VERSION="):
                jver = line.split("=", 1)[1].strip().strip('"')
    stamp = datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC")
    VERSIONS.write_text(
        "# tools/ghidra/VERSIONS.txt - written by tools/ghidra/install.py\n"
        f"installed: {stamp}\n\n"
        f"ghidra.release: {gtag}\n"
        f"ghidra.version: {gver}\n"
        f"ghidra.url: {gurl}\n"
        f"ghidra.zip: {gzip.name}\n"
        f"ghidra.sha256: {ghash}\n"
        f"ghidra.dir: tools/_local/{GHIDRA_DIR.name}\n\n"
        f"jdk.version: {jver}\n"
        f"jdk.url: {jdk_url}\n"
        f"jdk.zip: {jzip.name}\n"
        f"jdk.sha256: {jhash}\n"
        f"jdk.dir: tools/_local/{JDK_DIR.name}\n",
        encoding="utf-8", newline="\n")
    print(f"[done] Ghidra {gver} + JDK {jver}; analyzeHeadless={'ok' if headless.exists() else 'MISSING'}, java={'ok' if java.exists() else 'MISSING'}")
    print(f"       versions recorded in {VERSIONS.relative_to(ROOT)}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
