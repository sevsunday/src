#!/usr/bin/env python3
"""
diff_decompile.py - compare two decompile export sets (reference/decompiled/<old> vs <new>).

Reports, in <new>/DIFF_vs_<old>.md:
  1. function roster: added / removed (by name+address), size changes, line-range changes
  2. per-file: function counts and max line
  3. strings: TerminatedCString values added / removed (globals.tsv)
  4. decompiled text: per function, identical / changed (whitespace-normalized), per file totals

Usage: python tools/diff_decompile.py <old_dir> <new_dir>
stdlib only.
"""
from __future__ import annotations

import csv
import re
import sys
from collections import defaultdict
from pathlib import Path

csv.field_size_limit(10**9)
HDR = re.compile(r"^// (?P<name>.+?)  @ (?P<addr>[0-9a-f]+)  lines (?P<a>\d+)-(?P<b>\d+)\s*$")


def read_tsv(p: Path) -> list[dict]:
    if not p.exists():
        return []
    with open(p, encoding="utf-8", newline="") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def functions_in(src_dir: Path) -> dict[tuple, str]:
    """(file, name, addr) -> normalized body text."""
    out = {}
    for p in sorted(src_dir.rglob("*.decomp.c")):
        rel = p.relative_to(src_dir).as_posix()
        cur, body = None, []

        def flush():
            if cur:
                text = "\n".join(body).strip()
                text = re.sub(r"[ \t]+", " ", text)
                text = re.sub(r"\n\s*\n+", "\n", text)
                out[(rel, cur["name"], cur["addr"])] = text

        for line in p.read_text(encoding="utf-8", errors="replace").splitlines():
            m = HDR.match(line)
            if m:
                flush()
                cur, body = m.groupdict(), []
            elif cur is not None and not line.startswith("// ----"):
                body.append(line)
        flush()
    return out


def main(argv=None) -> int:
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    old, new = Path(sys.argv[1]), Path(sys.argv[2])
    md = [f"# DIFF: {new.name} vs {old.name} (tools/diff_decompile.py)", ""]

    # 1. roster
    def roster(d):
        rows = read_tsv(d / "all_functions.tsv")
        return {(r["name"], r["address"]): r for r in rows}
    ro, rn = roster(old), roster(new)
    added = sorted(k for k in rn if k not in ro)
    removed = sorted(k for k in ro if k not in rn)
    resized = [(k, ro[k]["size"], rn[k]["size"]) for k in ro if k in rn and ro[k]["size"] != rn[k]["size"]]
    relined = [(k, ro[k]["minLine"], ro[k]["maxLine"], rn[k]["minLine"], rn[k]["maxLine"]) for k in ro if k in rn
               and (ro[k]["minLine"], ro[k]["maxLine"]) != (rn[k]["minLine"], rn[k]["maxLine"])]
    md += ["## 1. Function roster", "",
           f"old {len(ro)} · new {len(rn)} · added {len(added)} · removed {len(removed)} · resized {len(resized)} · line-range changed {len(relined)}", ""]
    for title, rows in (("Added", added), ("Removed", removed)):
        md.append(f"### {title} ({len(rows)})")
        md += [f"- `{n}` @ {a}" for n, a in rows[:200]]
        if len(rows) > 200:
            md.append(f"- … {len(rows) - 200} more")
        md.append("")
    md.append(f"### Resized ({len(resized)})")
    md += [f"- `{k[0]}` @ {k[1]}: {a} → {b}" for k, a, b in resized[:200]]
    md.append("")
    md.append(f"### Line range changed ({len(relined)})")
    md += [f"- `{k[0]}` @ {k[1]}: {a}-{b} → {c}-{d}" for k, a, b, c, d in relined[:200]]
    md.append("")

    # 2. per-file
    def per_file(rows):
        st = defaultdict(lambda: [0, 0])
        for r in rows.values():
            if r.get("user") != "Y":
                continue
            s = st[r["file"]]
            s[0] += 1
            try:
                s[1] = max(s[1], int(r["maxLine"] or 0))
            except ValueError:
                pass
        return st
    fo, fn = per_file(ro), per_file(rn)
    md += ["## 2. Per-file (user functions, max line)", "", "| file | old fns | new fns | old max | new max |", "|---|---:|---:|---:|---:|"]
    for f in sorted(set(fo) | set(fn)):
        a, b = fo.get(f, [0, 0]), fn.get(f, [0, 0])
        flag = "" if a == b else " **≠**"
        md.append(f"| `{f}` | {a[0]} | {b[0]} | {a[1]} | {b[1]} |{flag}")
    md.append("")

    # 3. strings
    def strings(d):
        return {r["value"] for r in read_tsv(d / "globals.tsv") if r.get("type") == "TerminatedCString"}
    so, sn = strings(old), strings(new)
    md += ["## 3. Strings (TerminatedCString)", "", f"old {len(so)} · new {len(sn)} · added {len(sn - so)} · removed {len(so - sn)}", ""]
    md += [f"- + `{s!r}`" for s in sorted(sn - so)[:200]]
    md += [f"- − `{s!r}`" for s in sorted(so - sn)[:200]]
    md.append("")

    # 4. text
    to, tn = functions_in(old / "src"), functions_in(new / "src")
    same = sum(1 for k in to if k in tn and to[k] == tn[k])
    changed = [k for k in to if k in tn and to[k] != tn[k]]
    only_old = [k for k in to if k not in tn]
    only_new = [k for k in tn if k not in to]
    md += ["## 4. Decompiled text (whitespace-normalized)", "",
           f"identical {same} · changed {len(changed)} · only in old {len(only_old)} · only in new {len(only_new)}", ""]
    by_file = defaultdict(lambda: [0, 0])
    for k in to:
        if k in tn:
            by_file[k[0]][0 if to[k] == tn[k] else 1] += 1
    md += ["| file | identical | changed |", "|---|---:|---:|"]
    for f in sorted(by_file):
        md.append(f"| `{f}` | {by_file[f][0]} | {by_file[f][1]} |")
    md.append("")
    md.append("### Changed functions")
    md += [f"- `{k[1]}` @ {k[2]} ({k[0]})" for k in sorted(changed)[:400]]
    md.append("")
    out = new / f"DIFF_vs_{old.name}.md"
    out.write_text("\n".join(md) + "\n", encoding="utf-8", newline="\n")
    print(f"roster: added {len(added)} removed {len(removed)} resized {len(resized)} relined {len(relined)}; "
          f"strings +{len(sn - so)} -{len(so - sn)}; text identical {same} changed {len(changed)} -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
