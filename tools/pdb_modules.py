#!/usr/bin/env python3
"""
pdb_modules.py - per-module build record from a PDB (MSF 7.00 / DBI), stdlib only.

For every object file linked into a DLL the PDB records which compiler built it
(S_COMPILE3: front-end + back-end version, language, flags), the exact command
line (S_ENVBLOCK: cwd / cl / cmd / src / pdb), the library it came from and the
source files it contributed. This script walks the MSF container, the DBI
stream's module-info and file-info substreams and each module's symbol stream
and writes the result as TSV + Markdown. It is the Tier B evidence behind
reference/manifest/BUILD_ENVIRONMENT.md and the per-target flags in
build/build.cmd.

Usage:
    python tools/pdb_modules.py [--pdb-dir original/missions] [--out reference/manifest/pdb]

Outputs per PDB (lowercase stem):
    <dll>.modules.tsv   one row per module: index, module, library, compiler, language,
                        machine, cwd, cmd, source-file count, sources (';'-joined)
    <dll>.modules.md    readable summary grouped by (library, compiler, cmd)
"""
from __future__ import annotations

import argparse
import struct
import sys
from collections import OrderedDict, defaultdict
from pathlib import Path

MSF_MAGIC = b"Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0"

S_COMPILE3 = 0x113C
S_ENVBLOCK = 0x113D
S_COMPILE2 = 0x1116
S_OBJNAME = 0x1101
S_BUILDINFO = 0x114C

# IPI (stream 4) leaf kinds used by LF_BUILDINFO chains
LF_BUILDINFO = 0x1603
LF_SUBSTR_LIST = 0x1604
LF_STRING_ID = 0x1605

LANG = {0: "C", 1: "C++", 2: "FORTRAN", 3: "MASM", 4: "Pascal", 5: "Basic", 6: "COBOL", 7: "LINK",
        8: "CVTRES", 9: "CVTPGD", 10: "C#", 11: "VB", 12: "ILASM", 13: "Java", 14: "JScript",
        15: "MSIL", 16: "HLSL", 0x44: "D", 0x53: "Swift", 0x52: "Rust", 0x4F: "ObjC", 0x50: "ObjC++"}
MACHINE = {0x03: "x86", 0xD0: "x64", 0x06: "x86 (Pentium Pro)", 0x07: "x86 (Pentium III)"}


def cstr(buf: bytes, off: int) -> tuple[str, int]:
    end = buf.index(b"\0", off)
    return buf[off:end].decode("utf-8", "replace"), end + 1


class Msf:
    def __init__(self, data: bytes):
        if not data.startswith(MSF_MAGIC):
            raise ValueError("not an MSF 7.00 PDB")
        self.data = data
        (self.block_size, _free, self.num_blocks, self.dir_bytes, _unk, self.dir_map_block) = \
            struct.unpack_from("<IIIIII", data, len(MSF_MAGIC))
        bs = self.block_size
        n_dir_blocks = (self.dir_bytes + bs - 1) // bs
        map_off = self.dir_map_block * bs
        dir_blocks = struct.unpack_from(f"<{n_dir_blocks}I", data, map_off)
        directory = b"".join(self.block(b) for b in dir_blocks)[: self.dir_bytes]
        pos = 0
        (num_streams,) = struct.unpack_from("<I", directory, pos); pos += 4
        sizes = struct.unpack_from(f"<{num_streams}I", directory, pos); pos += 4 * num_streams
        self.streams: list[tuple[int, tuple[int, ...]]] = []
        for sz in sizes:
            if sz == 0xFFFFFFFF or sz == 0:
                self.streams.append((0, ()))
                continue
            nb = (sz + bs - 1) // bs
            blocks = struct.unpack_from(f"<{nb}I", directory, pos); pos += 4 * nb
            self.streams.append((sz, blocks))

    def block(self, i: int) -> bytes:
        return self.data[i * self.block_size:(i + 1) * self.block_size]

    def stream(self, idx: int) -> bytes:
        sz, blocks = self.streams[idx]
        if sz == 0:
            return b""
        return b"".join(self.block(b) for b in blocks)[:sz]


def parse_dbi(msf: Msf):
    dbi = msf.stream(3)
    hdr = struct.unpack_from("<iIIHHHHHHiiiiiIiiHHI", dbi, 0)
    (_sig, _ver, _age, _gsi, _build, _psi, _pdbdllver, _symrec, _rbld,
     mod_info_size, sec_contr_size, sec_map_size, src_info_size, _ts_size,
     _mfc, _dbg_size, _ec_size, _flags, machine, _pad) = hdr
    pos = 64
    mod_end = pos + mod_info_size
    modules = []
    while pos < mod_end:
        # ModInfo header is 64 bytes before the two strings
        (_unused, ) = struct.unpack_from("<I", dbi, pos)
        sym_stream, = struct.unpack_from("<H", dbi, pos + 34)
        src_count, = struct.unpack_from("<H", dbi, pos + 48)
        name, p = cstr(dbi, pos + 64)
        obj, p = cstr(dbi, p)
        pos = (p + 3) & ~3
        modules.append({"name": name, "obj": obj, "sym_stream": sym_stream, "src_count": src_count})
    # skip section contributions + section map
    pos = mod_end + sec_contr_size + sec_map_size
    # file info substream
    fi = dbi[pos:pos + src_info_size]
    nmod, _nsrc_trunc = struct.unpack_from("<HH", fi, 0)
    q = 4
    _mod_indices = struct.unpack_from(f"<{nmod}H", fi, q); q += 2 * nmod
    mod_counts = struct.unpack_from(f"<{nmod}H", fi, q); q += 2 * nmod
    total = sum(mod_counts)
    offsets = struct.unpack_from(f"<{total}I", fi, q); q += 4 * total
    names_buf = fi[q:]
    k = 0
    for i in range(nmod):
        files = []
        for _ in range(mod_counts[i]):
            s, _ = cstr(names_buf, offsets[k]); k += 1
            files.append(s)
        if i < len(modules):
            modules[i]["sources"] = files
    for m in modules:
        m.setdefault("sources", [])
    return modules, machine


class Ipi:
    """ID stream (stream 4): LF_STRING_ID / LF_SUBSTR_LIST / LF_BUILDINFO records,
    where the compiler's build info lives for /GL (LTCG) compilands."""

    def __init__(self, msf: Msf):
        self.records: dict[int, tuple[int, bytes]] = {}
        if len(msf.streams) <= 4:
            return
        s = msf.stream(4)
        if len(s) < 56:
            return
        _ver, hdr_size, ti_begin, ti_end, _rec_bytes = struct.unpack_from("<IIIII", s, 0)
        pos = hdr_size
        ti = ti_begin
        while pos + 4 <= len(s) and ti < ti_end:
            reclen, kind = struct.unpack_from("<HH", s, pos)
            self.records[ti] = (kind, s[pos + 4: pos + 2 + reclen])
            pos += 2 + reclen
            ti += 1

    def string(self, item: int) -> str:
        rec = self.records.get(item)
        if not rec:
            return ""
        kind, body = rec
        if kind == LF_STRING_ID:
            (sub,) = struct.unpack_from("<I", body, 0)
            text, _ = cstr(body, 4)
            if sub:
                return self.string(sub) + text
            return text
        if kind == LF_SUBSTR_LIST:
            (count,) = struct.unpack_from("<I", body, 0)
            ids = struct.unpack_from(f"<{count}I", body, 4)
            return "".join(self.string(i) for i in ids)
        return ""

    def buildinfo(self, item: int) -> dict:
        rec = self.records.get(item)
        if not rec or rec[0] != LF_BUILDINFO:
            return {}
        (count,) = struct.unpack_from("<H", rec[1], 0)
        ids = struct.unpack_from(f"<{count}I", rec[1], 2)
        names = ["cwd", "tool", "src", "pdb", "args"]
        return {names[i]: self.string(ids[i]) for i in range(min(count, 5))}


def parse_module_syms(msf: Msf, stream_idx: int, ipi: "Ipi | None" = None) -> dict:
    out = {"compiler": "", "language": "", "machine": "", "fe": "", "be": "", "cmd": "", "cwd": "", "cl": "", "src": "", "pdb": "", "objname": "", "tool": ""}
    if stream_idx == 0xFFFF or stream_idx >= len(msf.streams):
        return out
    s = msf.stream(stream_idx)
    if len(s) < 4:
        return out
    pos = 4  # CV signature
    while pos + 4 <= len(s):
        reclen, kind = struct.unpack_from("<HH", s, pos)
        if reclen < 2:
            break
        body = s[pos + 4: pos + 2 + reclen]
        if kind == S_COMPILE3 and len(body) >= 22:
            flags, machine = struct.unpack_from("<IH", body, 0)
            fe = struct.unpack_from("<HHHH", body, 6)
            be = struct.unpack_from("<HHHH", body, 14)
            ver, _ = cstr(body, 22)
            out["compiler"] = ver
            out["language"] = LANG.get(flags & 0xFF, hex(flags & 0xFF))
            out["machine"] = MACHINE.get(machine, hex(machine))
            out["fe"] = ".".join(map(str, fe))
            out["be"] = ".".join(map(str, be))
        elif kind == S_COMPILE2 and len(body) >= 20:
            flags, machine = struct.unpack_from("<IH", body, 0)
            fe = struct.unpack_from("<HHH", body, 6)
            be = struct.unpack_from("<HHH", body, 12)
            ver, _ = cstr(body, 18)
            out["compiler"] = ver
            out["language"] = LANG.get(flags & 0xFF, hex(flags & 0xFF))
            out["machine"] = MACHINE.get(machine, hex(machine))
            out["fe"] = ".".join(map(str, fe))
            out["be"] = ".".join(map(str, be))
        elif kind == S_ENVBLOCK and len(body) >= 1:
            p = 1
            while p < len(body) and body[p] != 0:
                key, p = cstr(body, p)
                if p >= len(body):
                    break
                val, p = cstr(body, p)
                if key in out:
                    out[key] = val
        elif kind == S_OBJNAME and len(body) >= 5:
            out["objname"], _ = cstr(body, 4)
        elif kind == S_BUILDINFO and len(body) >= 4 and ipi is not None:
            (item,) = struct.unpack_from("<I", body, 0)
            bi = ipi.buildinfo(item)
            if bi:
                # LF_BUILDINFO wins over an (absent) S_ENVBLOCK for LTCG compilands
                out["cwd"] = out["cwd"] or bi.get("cwd", "")
                out["tool"] = bi.get("tool", "")
                out["src"] = out["src"] or bi.get("src", "")
                out["pdb"] = out["pdb"] or bi.get("pdb", "")
                out["cmd"] = out["cmd"] or bi.get("args", "")
        pos += 2 + reclen
        pos = (pos + 3) & ~3
    return out


def lib_of(module_name: str, obj_name: str) -> str:
    # For objects inside a static library the ModInfo ObjFileName is the .lib and ModuleName the .obj.
    if obj_name and obj_name.lower().endswith(".lib"):
        return obj_name
    return ""


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--pdb-dir", default="original/missions")
    ap.add_argument("--out", default="reference/manifest/pdb")
    args = ap.parse_args(argv)
    root = Path(__file__).resolve().parents[1]
    pdb_dir = (root / args.pdb_dir).resolve()
    out_dir = (root / args.out).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    for pdb in sorted(pdb_dir.glob("*.pdb"), key=lambda p: p.name.lower()):
        stem = pdb.stem.lower()
        msf = Msf(pdb.read_bytes())
        modules, machine = parse_dbi(msf)
        ipi = Ipi(msf)
        rows = []
        for i, m in enumerate(modules):
            info = parse_module_syms(msf, m["sym_stream"], ipi)
            rows.append({
                "index": i,
                "module": m["name"],
                "library": lib_of(m["name"], m["obj"]),
                "compiler": info["compiler"],
                "fe": info["fe"], "be": info["be"],
                "language": info["language"],
                "machine": info["machine"],
                "cwd": info["cwd"],
                "tool": info["tool"],
                "cmd": info["cmd"],
                "src": info["src"],
                "src_count": len(m["sources"]),
                "sources": m["sources"],
            })
        # TSV
        cols = ["index", "module", "library", "compiler", "fe", "be", "language", "machine", "cwd", "tool", "cmd", "src", "src_count", "sources"]
        lines = ["\t".join(cols)]
        for r in rows:
            vals = [str(r[c]) if c != "sources" else ";".join(r["sources"]) for c in cols]
            lines.append("\t".join(v.replace("\t", " ") for v in vals))
        (out_dir / f"{stem}.modules.tsv").write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")

        # Markdown grouped by (library, compiler, cmd)
        groups: "OrderedDict[tuple, list]" = OrderedDict()
        for r in rows:
            key = (r["library"], r["compiler"], r["language"], r["cmd"])
            groups.setdefault(key, []).append(r)
        md = [f"# {pdb.name} — linked modules (generated by tools/pdb_modules.py)", "",
              f"{len(rows)} modules; DBI machine 0x{machine:X}.", "",
              "Each group = one (library, compiler, language, command line). `cmd` is the compiler command",
              "line recorded by `S_ENVBLOCK`; modules without one are linker-synthesized or import stubs.", ""]
        for (lib, comp, lang, cmd), grp in groups.items():
            md.append("## " + (lib or "(direct object / linker)") + f" — {len(grp)} module(s)")
            md.append("")
            md.append(f"- compiler: `{comp or '-'}`  language: {lang or '-'}  fe/be: {grp[0]['fe'] or '-'} / {grp[0]['be'] or '-'}")
            if grp[0]["cwd"]:
                md.append(f"- cwd: `{grp[0]['cwd']}`")
            if grp[0]["tool"]:
                md.append(f"- tool: `{grp[0]['tool']}`")
            if cmd:
                md.append(f"- cmd: `{cmd}`")
            md.append("- modules: " + ", ".join(f"`{Path(r['module']).name}`" for r in grp))
            srcs = sorted({s for r in grp for s in r["sources"] if "vsr_dll_source" in s.lower() or "bzcc" in s.lower()})
            if srcs:
                md.append("- project sources: " + ", ".join(f"`{s}`" for s in srcs))
            md.append("")
        (out_dir / f"{stem}.modules.md").write_text("\n".join(md) + "\n", encoding="utf-8", newline="\n")
        print(f"{pdb.name}: {len(rows)} modules, {len(groups)} build groups")
    return 0


if __name__ == "__main__":
    sys.exit(main())
