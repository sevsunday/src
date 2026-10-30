#!/usr/bin/env python3
"""
pdb_types.py - class layouts, enums and function signatures from a PDB's TPI stream.

Reads the type records (stream 2) and the global/module procedure symbols of a
PDB and writes, per PDB:

    <dll>.types.json   every UDT: size, kind, bases (offset), vtable (yes/no + shape
                       size), members (offset, type, name), static members, methods
                       (name, signature, virtual / intro-virtual + vtable slot, static,
                       access), nested types; every enum with its values
    <dll>.types.md     readable layout tables for the project UDTs
    <dll>.procs.tsv    every S_GPROC32/S_LPROC32: rva, name, signature, module
    <dll>.data.tsv     every S_GDATA32/S_LDATA32 (globals and file statics): rva, size,
    <dll>.data.json    section, module, declaration, and the initial value decoded from
                       the DLL image beside the PDB (strings, string tables, numbers,
                       enum arrays; class objects as hex) - the oracle for the
                       string tables and tunables a port has to reproduce

Type indices below 0x1000 are CodeView primitives; above, records in the TPI.
This is Tier B evidence straight from GBD's PDBs (Tier A) - it supersedes
Ghidra's vsr_types.h dump for layout questions and is regenerable.

Usage: python tools/pdb_types.py [--pdb-dir original/missions] [--out reference/manifest/pdb]
stdlib only.
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pdb_modules import Msf, parse_dbi, cstr  # noqa: E402

# ---------------------------------------------------------------- leaf kinds
LF_MODIFIER = 0x1001
LF_POINTER = 0x1002
LF_PROCEDURE = 0x1008
LF_MFUNCTION = 0x1009
LF_ARGLIST = 0x1201
LF_FIELDLIST = 0x1203
LF_BITFIELD = 0x1205
LF_METHODLIST = 0x1206
LF_BCLASS = 0x1400
LF_VBCLASS = 0x1401
LF_IVBCLASS = 0x1402
LF_INDEX = 0x1404
LF_VFUNCTAB = 0x1409
LF_ENUMERATE = 0x1502
LF_ARRAY = 0x1503
LF_CLASS = 0x1504
LF_STRUCTURE = 0x1505
LF_UNION = 0x1506
LF_ENUM = 0x1507
LF_MEMBER = 0x150D
LF_STMEMBER = 0x150E
LF_METHOD = 0x150F
LF_NESTTYPE = 0x1510
LF_ONEMETHOD = 0x1511
LF_VTSHAPE = 0x000A
LF_VFTABLE = 0x151D
LF_INTERFACE = 0x1519

# symbols
S_END = 0x0006
S_BPREL32 = 0x110B
S_LPROC32 = 0x110F
S_GPROC32 = 0x1110
S_REGREL32 = 0x1111
S_LOCAL = 0x113E
S_LPROC32_ID = 0x1146
S_GPROC32_ID = 0x1147
S_PROC_ID_END = 0x114F

PRIM = {
    0x00: "<notype>", 0x03: "void", 0x08: "HRESULT",
    0x10: "signed char", 0x20: "unsigned char", 0x70: "char", 0x71: "wchar_t",
    0x7A: "char16_t", 0x7B: "char32_t", 0x7C: "char8_t",
    0x11: "short", 0x21: "unsigned short", 0x72: "short", 0x73: "unsigned short",
    0x12: "long", 0x22: "unsigned long", 0x74: "int", 0x75: "unsigned int",
    0x13: "__int64", 0x23: "unsigned __int64", 0x76: "__int64", 0x77: "unsigned __int64",
    0x14: "__int128", 0x24: "unsigned __int128", 0x78: "__int128", 0x79: "unsigned __int128",
    0x40: "float", 0x41: "double", 0x42: "long double", 0x43: "float", 0x44: "float", 0x45: "float",
    0x46: "float", 0x47: "float", 0x48: "double",
    0x30: "bool", 0x31: "bool", 0x32: "bool", 0x33: "bool",
}
PRIM_SIZE = {
    "void": 0, "char": 1, "signed char": 1, "unsigned char": 1, "bool": 1, "wchar_t": 2,
    "char16_t": 2, "char32_t": 4, "char8_t": 1, "short": 2, "unsigned short": 2,
    "int": 4, "unsigned int": 4, "long": 4, "unsigned long": 4, "__int64": 8,
    "unsigned __int64": 8, "__int128": 16, "unsigned __int128": 16, "float": 4, "double": 8,
    "long double": 8, "HRESULT": 4, "<notype>": 0,
}
CALLCONV = {0: "__cdecl", 1: "__cdecl", 2: "__pascal", 4: "__fastcall", 7: "__stdcall", 0xB: "__thiscall", 0x18: "__vectorcall"}


def numeric(buf: bytes, pos: int):
    (v,) = struct.unpack_from("<H", buf, pos)
    pos += 2
    if v < 0x8000:
        return v, pos
    if v == 0x8000:  # LF_CHAR
        return struct.unpack_from("<b", buf, pos)[0], pos + 1
    if v == 0x8001:  # LF_SHORT
        return struct.unpack_from("<h", buf, pos)[0], pos + 2
    if v == 0x8002:  # LF_USHORT
        return struct.unpack_from("<H", buf, pos)[0], pos + 2
    if v == 0x8003:  # LF_LONG
        return struct.unpack_from("<i", buf, pos)[0], pos + 4
    if v == 0x8004:  # LF_ULONG
        return struct.unpack_from("<I", buf, pos)[0], pos + 4
    if v == 0x8009:  # LF_QUADWORD
        return struct.unpack_from("<q", buf, pos)[0], pos + 8
    if v == 0x800A:  # LF_UQUADWORD
        return struct.unpack_from("<Q", buf, pos)[0], pos + 8
    raise ValueError(f"numeric leaf 0x{v:x} unsupported")


def skip_pad(buf: bytes, pos: int) -> int:
    while pos < len(buf) and buf[pos] >= 0xF0:
        pos += 1
    return pos


class Tpi:
    def __init__(self, msf: Msf, stream_idx: int = 2):
        s = msf.stream(stream_idx)
        _ver, hdr_size, self.ti_begin, self.ti_end, _bytes = struct.unpack_from("<IIIII", s, 0)
        self.rec: dict[int, tuple[int, bytes]] = {}
        pos = hdr_size
        ti = self.ti_begin
        while pos + 4 <= len(s) and ti < self.ti_end:
            reclen, kind = struct.unpack_from("<HH", s, pos)
            self.rec[ti] = (kind, s[pos + 4: pos + 2 + reclen])
            pos += 2 + reclen
            ti += 1
        self._name_cache: dict[int, str] = {}
        self._size_cache: dict[int, int] = {}
        # name -> ti of the LIVE non-forward definition.
        # GBD linked with /LTCG:incremental, whose database carries stale
        # generations of a class across rebuilds (Strategy02 appears five times,
        # 0xE648 .. 0xECA4). Type indices grow monotonically, so the highest TI
        # is the newest definition - the one operator new() sizes agree with.
        self.udt_by_name: dict[str, int] = {}
        self.generations: dict[str, list[tuple[int, int, int]]] = {}
        for ti, (kind, body) in self.rec.items():
            if kind in (LF_CLASS, LF_STRUCTURE, LF_UNION, LF_ENUM, LF_INTERFACE):
                info = self.udt_header(ti)
                if info and not info["fwdref"]:
                    prev = self.udt_by_name.get(info["name"])
                    if prev is None or ti > prev:
                        self.udt_by_name[info["name"]] = ti
                    self.generations.setdefault(info["name"], []).append((ti, info["size"], info["count"]))

    # ------------------------------------------------------------ headers
    def udt_header(self, ti: int):
        kind, b = self.rec[ti]
        if kind in (LF_CLASS, LF_STRUCTURE, LF_INTERFACE):
            count, prop, field, derived, vshape = struct.unpack_from("<HHIII", b, 0)
            size, p = numeric(b, 16)
            name, p = cstr(b, p)
            return {"kind": "class" if kind == LF_CLASS else "struct", "count": count, "prop": prop,
                    "fwdref": bool(prop & 0x80), "field": field, "derived": derived, "vshape": vshape,
                    "size": size, "name": name}
        if kind == LF_UNION:
            count, prop, field = struct.unpack_from("<HHI", b, 0)
            size, p = numeric(b, 8)
            name, p = cstr(b, p)
            return {"kind": "union", "count": count, "prop": prop, "fwdref": bool(prop & 0x80),
                    "field": field, "derived": 0, "vshape": 0, "size": size, "name": name}
        if kind == LF_ENUM:
            count, prop, utype, field = struct.unpack_from("<HHII", b, 0)
            name, p = cstr(b, 12)
            return {"kind": "enum", "count": count, "prop": prop, "fwdref": bool(prop & 0x80),
                    "field": field, "utype": utype, "size": self.size_of(utype) if utype else 4, "name": name}
        return None

    def resolve_fwd(self, ti: int) -> int:
        if ti < 0x1000 or ti not in self.rec:
            return ti
        kind = self.rec[ti][0]
        if kind in (LF_CLASS, LF_STRUCTURE, LF_UNION, LF_ENUM, LF_INTERFACE):
            h = self.udt_header(ti)
            if h and h["fwdref"]:
                return self.udt_by_name.get(h["name"], ti)
        return ti

    # ------------------------------------------------------------ names
    def name(self, ti: int, decl: str = "") -> str:
        """C++ spelling of type `ti`, wrapped around declarator `decl`."""
        base = self._name(ti, decl)
        return base

    def _name(self, ti: int, decl: str) -> str:
        if ti < 0x1000:
            mode = (ti >> 8) & 0xF
            basic = ti & 0xFF
            pname = PRIM.get(basic, f"<prim 0x{basic:x}>")
            if mode:  # pointer to primitive
                return f"{pname}*{(' ' + decl) if decl else ''}"
            return f"{pname}{(' ' + decl) if decl else ''}"
        if ti not in self.rec:
            return f"<ti 0x{ti:x}>{(' ' + decl) if decl else ''}"
        kind, b = self.rec[ti]
        if kind in (LF_CLASS, LF_STRUCTURE, LF_UNION, LF_ENUM, LF_INTERFACE):
            h = self.udt_header(ti)
            return f"{h['name']}{(' ' + decl) if decl else ''}"
        if kind == LF_MODIFIER:
            (utype, attr) = struct.unpack_from("<IH", b, 0)
            mods = ("const " if attr & 1 else "") + ("volatile " if attr & 2 else "")
            return mods + self._name(utype, decl)
        if kind == LF_POINTER:
            (utype, attr) = struct.unpack_from("<II", b, 0)
            ptrmode = (attr >> 5) & 0x7
            isconst = bool(attr & (1 << 10))
            isvol = bool(attr & (1 << 9))
            sym = "&" if ptrmode == 1 else ("&&" if ptrmode == 4 else "*")
            quals = (" const" if isconst else "") + (" volatile" if isvol else "")
            if ptrmode in (2, 3):  # pointer to member
                return f"<ptr-to-member of {self._name(utype, '')}> {decl}".strip()
            inner_kind = self.rec.get(utype, (0, b""))[0] if utype >= 0x1000 else 0
            if inner_kind in (LF_PROCEDURE, LF_MFUNCTION):
                return self._name(utype, f"({sym}{quals} {decl})".replace("( ", "(").strip())
            if inner_kind == LF_ARRAY:
                return self._name(utype, f"({sym}{quals} {decl})".replace("( ", "(").strip())
            return f"{self._name(utype, '')}{sym}{quals}{(' ' + decl) if decl else ''}"
        if kind == LF_ARRAY:
            (elem, idx) = struct.unpack_from("<II", b, 0)
            size, p = numeric(b, 8)
            esz = self.size_of(elem)
            n = size // esz if esz else 0
            return self._name(elem, f"{decl}[{n}]")
        if kind == LF_PROCEDURE:
            (ret, cc, _attr, nparams, arglist) = struct.unpack_from("<IBBHI", b, 0)
            args = self.arglist(arglist)
            return f"{self._name(ret, '')} {CALLCONV.get(cc, f'cc{cc}')} {decl}({', '.join(args)})".strip()
        if kind == LF_MFUNCTION:
            (ret, cls, this, cc, _attr, nparams, arglist, _thisadj) = struct.unpack_from("<IIIBBHIi", b, 0)
            args = self.arglist(arglist)
            return f"{self._name(ret, '')} {CALLCONV.get(cc, f'cc{cc}')} {decl}({', '.join(args)})".strip()
        if kind == LF_BITFIELD:
            (utype, length, position) = struct.unpack_from("<IBB", b, 0)
            return f"{self._name(utype, decl)} : {length}"
        if kind == LF_VTSHAPE:
            return "<vtshape>"
        return f"<leaf 0x{kind:x}>{(' ' + decl) if decl else ''}"

    def arglist(self, ti: int) -> list[str]:
        if ti not in self.rec:
            return []
        kind, b = self.rec[ti]
        if kind != LF_ARGLIST:
            return []
        (n,) = struct.unpack_from("<I", b, 0)
        tis = struct.unpack_from(f"<{n}I", b, 4)
        out = []
        for a in tis:
            if a == 0:
                out.append("...")
            else:
                out.append(self._name(a, ""))
        return out

    # ------------------------------------------------------------ sizes
    def size_of(self, ti: int) -> int:
        if ti in self._size_cache:
            return self._size_cache[ti]
        sz = self._size_of(ti)
        self._size_cache[ti] = sz
        return sz

    def _size_of(self, ti: int) -> int:
        if ti < 0x1000:
            if (ti >> 8) & 0xF:
                return 4  # 32-bit pointer
            return PRIM_SIZE.get(PRIM.get(ti & 0xFF, ""), 0)
        if ti not in self.rec:
            return 0
        kind, b = self.rec[ti]
        if kind in (LF_CLASS, LF_STRUCTURE, LF_UNION, LF_INTERFACE):
            h = self.udt_header(ti)
            if h["fwdref"]:
                d = self.udt_by_name.get(h["name"])
                return self.udt_header(d)["size"] if d else 0
            return h["size"]
        if kind == LF_ENUM:
            h = self.udt_header(ti)
            return self.size_of(h["utype"]) if h["utype"] else 4
        if kind == LF_MODIFIER:
            return self.size_of(struct.unpack_from("<I", b, 0)[0])
        if kind == LF_POINTER:
            attr = struct.unpack_from("<II", b, 0)[1]
            return (attr >> 13) & 0x3F or 4
        if kind == LF_ARRAY:
            size, _ = numeric(b, 8)
            return size
        if kind == LF_BITFIELD:
            return self.size_of(struct.unpack_from("<I", b, 0)[0])
        return 0

    # ------------------------------------------------------------ field lists
    def fieldlist(self, ti: int) -> list[dict]:
        out = []
        while ti and ti in self.rec:
            kind, b = self.rec[ti]
            if kind != LF_FIELDLIST:
                break
            pos = 0
            cont = 0
            while pos + 2 <= len(b):
                (lk,) = struct.unpack_from("<H", b, pos)
                pos += 2
                if lk == LF_MEMBER:
                    attr, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    off, pos = numeric(b, pos)
                    name, pos = cstr(b, pos)
                    out.append({"k": "member", "attr": attr, "type": typ, "offset": off, "name": name})
                elif lk == LF_STMEMBER:
                    attr, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    name, pos = cstr(b, pos)
                    out.append({"k": "static", "attr": attr, "type": typ, "name": name})
                elif lk == LF_BCLASS:
                    attr, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    off, pos = numeric(b, pos)
                    out.append({"k": "base", "attr": attr, "type": typ, "offset": off})
                elif lk in (LF_VBCLASS, LF_IVBCLASS):
                    attr, typ, vbp = struct.unpack_from("<HII", b, pos); pos += 10
                    vbpo, pos = numeric(b, pos)
                    vbo, pos = numeric(b, pos)
                    out.append({"k": "vbase", "attr": attr, "type": typ, "vbptr_off": vbpo, "vb_off": vbo})
                elif lk == LF_VFUNCTAB:
                    _pad, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    out.append({"k": "vfptr", "type": typ})
                elif lk == LF_ONEMETHOD:
                    attr, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    mprop = (attr >> 2) & 0x7
                    vt = None
                    if mprop in (4, 6):  # intro / pure intro
                        (vt,) = struct.unpack_from("<I", b, pos); pos += 4
                    name, pos = cstr(b, pos)
                    out.append({"k": "method", "attr": attr, "type": typ, "name": name, "vtoff": vt})
                elif lk == LF_METHOD:
                    count, mlist = struct.unpack_from("<HI", b, pos); pos += 6
                    name, pos = cstr(b, pos)
                    for m in self.methodlist(mlist):
                        m["name"] = name
                        out.append(m)
                elif lk == LF_NESTTYPE:
                    _pad, typ = struct.unpack_from("<HI", b, pos); pos += 6
                    name, pos = cstr(b, pos)
                    out.append({"k": "nested", "type": typ, "name": name})
                elif lk == LF_ENUMERATE:
                    (attr,) = struct.unpack_from("<H", b, pos); pos += 2
                    val, pos = numeric(b, pos)
                    name, pos = cstr(b, pos)
                    out.append({"k": "enumerate", "attr": attr, "value": val, "name": name})
                elif lk == LF_INDEX:
                    _pad, cont = struct.unpack_from("<HI", b, pos); pos += 6
                else:
                    break
                pos = skip_pad(b, pos)
            ti = cont
        return out

    def methodlist(self, ti: int) -> list[dict]:
        out = []
        if ti not in self.rec:
            return out
        kind, b = self.rec[ti]
        if kind != LF_METHODLIST:
            return out
        pos = 0
        while pos + 8 <= len(b):
            attr, _pad, typ = struct.unpack_from("<HHI", b, pos); pos += 8
            mprop = (attr >> 2) & 0x7
            vt = None
            if mprop in (4, 6):
                (vt,) = struct.unpack_from("<I", b, pos); pos += 4
            out.append({"k": "method", "attr": attr, "type": typ, "vtoff": vt})
        return out


def access_of(attr: int) -> str:
    return {1: "private", 2: "protected", 3: "public"}.get(attr & 3, "public")


def mprop_of(attr: int) -> str:
    return {0: "", 1: "virtual", 2: "static", 3: "friend", 4: "intro-virtual", 5: "pure-virtual", 6: "pure-intro-virtual"}.get((attr >> 2) & 7, "")


def method_sig(tpi: Tpi, typ: int, name: str) -> str:
    """Render 'ret cc name(args)' for an LF_MFUNCTION / LF_PROCEDURE index."""
    if typ not in tpi.rec:
        return name + "(?)"
    kind, b = tpi.rec[typ]
    if kind == LF_MFUNCTION:
        (ret, cls, this, cc, _attr, nparams, arglist, _adj) = struct.unpack_from("<IIIBBHIi", b, 0)
        args = tpi.arglist(arglist)
        const_this = ""
        if this and this in tpi.rec and tpi.rec[this][0] == LF_POINTER:
            (ut, _a) = struct.unpack_from("<II", tpi.rec[this][1], 0)
            if ut in tpi.rec and tpi.rec[ut][0] == LF_MODIFIER and (struct.unpack_from("<IH", tpi.rec[ut][1], 0)[1] & 1):
                const_this = " const"
        r = tpi.name(ret) if ret else ""
        return f"{r} {CALLCONV.get(cc, '')} {name}({', '.join(args)}){const_this}".replace("  ", " ").strip()
    if kind == LF_PROCEDURE:
        (ret, cc, _attr, nparams, arglist) = struct.unpack_from("<IBBHI", b, 0)
        args = tpi.arglist(arglist)
        return f"{tpi.name(ret)} {CALLCONV.get(cc, '')} {name}({', '.join(args)})".replace("  ", " ").strip()
    return name + "(?)"


def fn_detail(tpi: Tpi, typind: int) -> dict:
    """ret / cc / const-this / param type strings for an LF_MFUNCTION or LF_PROCEDURE."""
    d = {"ret": "", "cc": "", "const": False, "param_types": []}
    if typind not in tpi.rec:
        return d
    kind, b = tpi.rec[typind]
    if kind == LF_MFUNCTION:
        (ret, cls, this, cc, _attr, nparams, arglist, _adj) = struct.unpack_from("<IIIBBHIi", b, 0)
        if this and this in tpi.rec and tpi.rec[this][0] == LF_POINTER:
            (ut, _a) = struct.unpack_from("<II", tpi.rec[this][1], 0)
            if ut in tpi.rec and tpi.rec[ut][0] == LF_MODIFIER and (struct.unpack_from("<IH", tpi.rec[ut][1], 0)[1] & 1):
                d["const"] = True
    elif kind == LF_PROCEDURE:
        (ret, cc, _attr, nparams, arglist) = struct.unpack_from("<IBBHI", b, 0)
    else:
        return d
    d["ret"] = tpi.name(ret) if ret else ""
    d["cc"] = CALLCONV.get(cc, "")
    d["param_types"] = tpi.arglist(arglist)
    # declarator templates with a name slot ("@@"), so arrays / function pointers render correctly
    tis = []
    if arglist in tpi.rec and tpi.rec[arglist][0] == LF_ARGLIST:
        ab = tpi.rec[arglist][1]
        (n,) = struct.unpack_from("<I", ab, 0)
        tis = list(struct.unpack_from(f"<{n}I", ab, 4))
    d["param_tpls"] = ["..." if a == 0 else tpi.name(a, "@@") for a in tis]
    return d


def dump_udts(tpi: Tpi) -> dict:
    out = {}
    for name, ti in sorted(tpi.udt_by_name.items()):
        h = tpi.udt_header(ti)
        entry = {"kind": h["kind"], "size": h["size"], "ti": ti}
        gens = sorted(tpi.generations.get(name, []))
        if len(gens) > 1:
            entry["stale_generations"] = [{"ti": g[0], "size": g[1], "count": g[2]} for g in gens[:-1]]
        if h["kind"] == "enum":
            entry["underlying"] = tpi.name(h["utype"]) if h["utype"] else "int"
            entry["values"] = [{"name": f["name"], "value": f["value"]} for f in tpi.fieldlist(h["field"]) if f["k"] == "enumerate"]
            out[name] = entry
            continue
        fl = tpi.fieldlist(h["field"])
        entry["bases"] = [{"type": tpi.name(f["type"]), "offset": f["offset"], "access": access_of(f["attr"])} for f in fl if f["k"] == "base"]
        entry["vbases"] = [{"type": tpi.name(f["type"])} for f in fl if f["k"] == "vbase"]
        entry["has_vfptr"] = any(f["k"] == "vfptr" for f in fl) or bool(h.get("vshape"))
        entry["members"] = [{"offset": f["offset"], "size": tpi.size_of(f["type"]), "type": tpi.name(f["type"]), "decl": tpi.name(f["type"], f["name"]), "name": f["name"], "access": access_of(f["attr"])} for f in fl if f["k"] == "member"]
        entry["statics"] = [{"type": tpi.name(f["type"]), "name": f["name"], "decl": tpi.name(f["type"], f["name"]), "access": access_of(f["attr"])} for f in fl if f["k"] == "static"]
        methods = []
        for f in fl:
            if f["k"] != "method":
                continue
            m = {"name": f["name"], "sig": method_sig(tpi, f["type"], f["name"]), "prop": mprop_of(f["attr"]),
                 "vtslot": (f["vtoff"] // 4) if f.get("vtoff") is not None else None, "access": access_of(f["attr"])}
            m.update(fn_detail(tpi, f["type"]))
            methods.append(m)
        entry["methods"] = methods
        entry["nested"] = [{"name": f["name"], "type": tpi.name(f["type"])} for f in fl if f["k"] == "nested"]
        out[name] = entry
    return out


def dump_procs(msf: Msf, tpi: Tpi, modules) -> list[dict]:
    # section table for RVA: DBI optional debug header -> section header stream
    dbi = msf.stream(3)
    hdr = struct.unpack_from("<iIIHHHHHHiiiiiIiiHHI", dbi, 0)
    mod_info_size, sec_contr_size, sec_map_size, src_info_size, ts_size, _mfc, dbg_size, ec_size = hdr[9], hdr[10], hdr[11], hdr[12], hdr[13], hdr[14], hdr[15], hdr[16]
    pos = 64 + mod_info_size + sec_contr_size + sec_map_size + src_info_size + ts_size + ec_size
    dbghdr = struct.unpack_from("<11h", dbi, pos)
    sec_hdr_stream = dbghdr[5]
    sections = []
    if sec_hdr_stream >= 0:
        s = msf.stream(sec_hdr_stream)
        for i in range(len(s) // 40):
            name = s[i * 40:i * 40 + 8].rstrip(b"\0").decode("ascii", "replace")
            vsize, vaddr = struct.unpack_from("<II", s, i * 40 + 8)
            sections.append((name, vaddr, vsize))

    def rva(seg: int, off: int) -> int:
        if 1 <= seg <= len(sections):
            return sections[seg - 1][1] + off
        return off

    def proc_detail(typind: int, name: str, param_names: list[str]) -> dict:
        """Structured signature: return type, calling convention, params with names."""
        d = {"ret": "", "cc": "", "const": False, "params": [], "this_class": ""}
        if typind not in tpi.rec:
            return d
        kind, b = tpi.rec[typind]
        if kind == LF_MFUNCTION:
            (ret, cls, this, cc, _attr, nparams, arglist, _adj) = struct.unpack_from("<IIIBBHIi", b, 0)
            d["this_class"] = tpi.name(cls) if cls else ""
            if this and this in tpi.rec and tpi.rec[this][0] == LF_POINTER:
                (ut, _a) = struct.unpack_from("<II", tpi.rec[this][1], 0)
                if ut in tpi.rec and tpi.rec[ut][0] == LF_MODIFIER and (struct.unpack_from("<IH", tpi.rec[ut][1], 0)[1] & 1):
                    d["const"] = True
        elif kind == LF_PROCEDURE:
            (ret, cc, _attr, nparams, arglist) = struct.unpack_from("<IBBHI", b, 0)
        else:
            return d
        d["ret"] = tpi.name(ret) if ret else ""
        d["cc"] = CALLCONV.get(cc, "")
        tis = []
        if arglist in tpi.rec and tpi.rec[arglist][0] == LF_ARGLIST:
            ab = tpi.rec[arglist][1]
            (n,) = struct.unpack_from("<I", ab, 0)
            tis = list(struct.unpack_from(f"<{n}I", ab, 4))
        names = [x for x in param_names if x != "this"]
        for i, a in enumerate(tis):
            pname = names[i] if i < len(names) else f"param_{i + 1}"
            if a == 0:
                d["params"].append({"type": "...", "name": "", "decl": "...", "tpl": "..."})
            else:
                d["params"].append({"type": tpi.name(a), "name": pname, "decl": tpi.name(a, pname), "tpl": tpi.name(a, "@@")})
        return d

    procs = []
    for m in modules:
        si = m["sym_stream"]
        if si == 0xFFFF or si >= len(msf.streams):
            continue
        s = msf.stream(si)
        p = 4
        cur = None
        cur_params: list[str] = []
        cur_bprel: list[tuple[int, str]] = []
        while p + 4 <= len(s):
            reclen, kind = struct.unpack_from("<HH", s, p)
            if reclen < 2:
                break
            body = s[p + 4:p + 2 + reclen]
            if kind in (S_GPROC32, S_LPROC32, S_GPROC32_ID, S_LPROC32_ID) and len(body) >= 35:
                (_parent, _end, _next, length, _dbgs, _dbge, typind, off, seg) = struct.unpack_from("<IIIIIIIIH", body, 0)
                name, _ = cstr(body, 35)
                cur = {"rva": rva(seg, off), "size": length, "name": name, "typind": typind,
                       "scope": "global" if kind in (S_GPROC32, S_GPROC32_ID) else "local",
                       "module": Path(m["name"]).name, "is_id": kind in (S_GPROC32_ID, S_LPROC32_ID)}
                cur_params, cur_bprel = [], []
            elif cur is not None and kind == S_LOCAL and len(body) >= 7:
                (_typ, flags) = struct.unpack_from("<IH", body, 0)
                lname, _ = cstr(body, 6)
                if flags & 1:  # fIsParam
                    cur_params.append(lname)
            elif cur is not None and kind == S_BPREL32 and len(body) >= 9:
                (boff, _typ) = struct.unpack_from("<iI", body, 0)
                lname, _ = cstr(body, 8)
                cur_bprel.append((boff, lname))
            elif cur is not None and kind == S_REGREL32 and len(body) >= 11:
                (roff, _typ, _reg) = struct.unpack_from("<IIH", body, 0)
                lname, _ = cstr(body, 10)
                cur_bprel.append((roff, lname))
            elif cur is not None and kind in (S_END, S_PROC_ID_END):
                names = cur_params or [n for off, n in sorted(cur_bprel) if off >= 8]
                if cur["is_id"]:
                    det = {"ret": "", "cc": "", "const": False, "params": [], "this_class": ""}
                    sig = cur["name"]
                else:
                    det = proc_detail(cur["typind"], cur["name"], names)
                    sig = method_sig(tpi, cur["typind"], cur["name"])
                cur.update(det)
                cur["sig"] = sig
                del cur["typind"], cur["is_id"]
                procs.append(cur)
                cur = None
            p += 2 + reclen
            p = (p + 3) & ~3
    procs.sort(key=lambda r: r["rva"])
    return procs


S_LDATA32 = 0x110C
S_GDATA32 = 0x110D


class PeImage:
    """Just enough of a PE32 reader to turn an RVA into initialized bytes."""

    def __init__(self, data: bytes):
        self.data = data
        pe = struct.unpack_from("<I", data, 0x3C)[0]
        nsec = struct.unpack_from("<H", data, pe + 6)[0]
        opt = pe + 24
        self.image_base = struct.unpack_from("<I", data, opt + 28)[0]
        opt_size = struct.unpack_from("<H", data, pe + 20)[0]
        self.sections = []
        for i in range(nsec):
            s = opt + opt_size + i * 40
            name = data[s:s + 8].rstrip(b"\0").decode("ascii", "replace")
            vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, s + 8)
            self.sections.append((name, vaddr, vsize, rawptr, rawsize))

    def section_of(self, rva: int):
        for sec in self.sections:
            if sec[1] <= rva < sec[1] + max(sec[2], sec[4]):
                return sec
        return None

    def read(self, rva: int, n: int) -> bytes:
        """Initialized bytes at `rva` (zero-filled past the raw data, e.g. .bss)."""
        sec = self.section_of(rva)
        if not sec:
            return b""
        off = rva - sec[1]
        raw = sec[4]
        chunk = self.data[sec[3] + off: sec[3] + min(off + n, raw)] if off < raw else b""
        return chunk + b"\0" * (n - len(chunk))

    def cstr(self, rva: int, limit: int = 4096) -> str | None:
        sec = self.section_of(rva)
        if not sec:
            return None
        off = rva - sec[1]
        if off >= sec[4]:
            return None
        start = sec[3] + off
        end = self.data.find(b"\0", start, start + limit)
        if end < 0:
            return None
        return self.data[start:end].decode("latin-1")

    def va_to_rva(self, va: int) -> int | None:
        rva = va - self.image_base
        return rva if self.section_of(rva) else None


def dump_data(msf: Msf, tpi: Tpi, modules, pe: PeImage | None) -> list[dict]:
    """Every S_GDATA32 / S_LDATA32 in the module symbol streams and the global symbol stream,
    with the type's spelling, size, and (when the PE is available) the initial value decoded:
    strings, pointer-to-string arrays, integer / float / bool scalars and arrays, enum arrays."""
    dbi = msf.stream(3)
    hdr = struct.unpack_from("<iIIHHHHHHiiiiiIiiHHI", dbi, 0)
    # DBI header: sig, ver, age, GlobalStreamIndex, BuildNumber, PublicStreamIndex, PdbDllVersion, SymRecordStream, ...
    sym_record_stream = hdr[7]
    mod_info_size, sec_contr_size, sec_map_size, src_info_size, ts_size, _mfc, dbg_size, ec_size = hdr[9], hdr[10], hdr[11], hdr[12], hdr[13], hdr[14], hdr[15], hdr[16]
    pos = 64 + mod_info_size + sec_contr_size + sec_map_size + src_info_size + ts_size + ec_size
    dbghdr = struct.unpack_from("<11h", dbi, pos)
    sections = []
    if dbghdr[5] >= 0:
        s = msf.stream(dbghdr[5])
        for i in range(len(s) // 40):
            vsize, vaddr = struct.unpack_from("<II", s, i * 40 + 8)
            sections.append((vaddr, vsize))

    def rva(seg: int, off: int) -> int:
        return sections[seg - 1][0] + off if 1 <= seg <= len(sections) else off

    def strip(ti: int) -> int:
        while ti >= 0x1000 and ti in tpi.rec and tpi.rec[ti][0] == LF_MODIFIER:
            ti = struct.unpack_from("<I", tpi.rec[ti][1], 0)[0]
        return tpi.resolve_fwd(ti)

    def decode(ti: int, raw: bytes):
        """Best-effort initial value for a type from its raw bytes."""
        t = strip(ti)
        if t < 0x1000:
            basic = t & 0xFF
            if (t >> 8) & 0xF:  # pointer to primitive
                va = struct.unpack_from("<I", raw, 0)[0] if len(raw) >= 4 else 0
                if va == 0:
                    return None
                r = pe.va_to_rva(va) if pe else None
                if r is not None and basic in (0x10, 0x20, 0x70):  # char / uchar / rchar
                    return pe.cstr(r)
                return f"0x{va:08x}"
            pname = PRIM.get(basic, "")
            if pname in ("char", "signed char", "unsigned char", "bool"):
                v = raw[0] if raw else 0
                return bool(v) if pname == "bool" else v
            if pname == "float" and len(raw) >= 4:
                return struct.unpack_from("<f", raw, 0)[0]
            if pname == "double" and len(raw) >= 8:
                return struct.unpack_from("<d", raw, 0)[0]
            if pname in ("short", "unsigned short", "wchar_t") and len(raw) >= 2:
                return struct.unpack_from("<h" if pname == "short" else "<H", raw, 0)[0]
            if len(raw) >= 4:
                return struct.unpack_from("<i" if "unsigned" not in pname else "<I", raw, 0)[0]
            return None
        kind, b = tpi.rec[t]
        if kind == LF_POINTER:
            (utype, attr) = struct.unpack_from("<II", b, 0)
            va = struct.unpack_from("<I", raw, 0)[0] if len(raw) >= 4 else 0
            if va == 0:
                return None
            u = strip(utype)
            r = pe.va_to_rva(va) if pe else None
            if r is not None and u < 0x1000 and (u & 0xFF) in (0x10, 0x20, 0x70):
                return pe.cstr(r)
            return f"0x{va:08x}"
        if kind == LF_ARRAY:
            (elem, _idx) = struct.unpack_from("<II", b, 0)
            esz = tpi.size_of(elem)
            e = strip(elem)
            if esz == 1 and e < 0x1000 and (e & 0xFF) in (0x10, 0x20, 0x70):
                end = raw.find(b"\0")
                return raw[:end if end >= 0 else len(raw)].decode("latin-1")
            if esz == 0:
                return None
            n = len(raw) // esz
            if n > 512:
                return f"<{n} elements>"
            return [decode(elem, raw[i * esz:(i + 1) * esz]) for i in range(n)]
        if kind == LF_ENUM:
            h = tpi.udt_header(t)
            v = struct.unpack_from("<i", raw, 0)[0] if len(raw) >= 4 else None
            names = {f["value"]: f["name"] for f in tpi.fieldlist(h["field"]) if f["k"] == "enumerate"}
            return names.get(v, v)
        if kind in (LF_CLASS, LF_STRUCTURE, LF_UNION):
            return raw.hex() if len(raw) <= 64 else f"<{len(raw)} bytes, sha-free hex omitted>"
        return None

    out = []
    seen = set()

    def walk(s: bytes, module: str):
        p = 4 if module != "<globals>" else 0
        while p + 4 <= len(s):
            reclen, kind = struct.unpack_from("<HH", s, p)
            if reclen < 2:
                break
            body = s[p + 4:p + 2 + reclen]
            if kind in (S_GDATA32, S_LDATA32) and len(body) >= 11:
                (typind, off, seg) = struct.unpack_from("<IIH", body, 0)
                name, _ = cstr(body, 10)
                r = rva(seg, off)
                key = (r, name)
                if key not in seen and not name.startswith(("std::", "`", "__", "_")) and "$" not in name:
                    seen.add(key)
                    size = tpi.size_of(typind)
                    raw = pe.read(r, size) if (pe and size) else b""
                    try:
                        value = decode(typind, raw) if raw else None
                    except Exception:  # noqa: BLE001 - decoding is best effort
                        value = None
                    sec = pe.section_of(r) if pe else None
                    out.append({"rva": r, "scope": "global" if kind == S_GDATA32 else "local", "module": module,
                                "name": name, "type": tpi.name(typind), "decl": tpi.name(typind, name), "size": size,
                                "section": sec[0] if sec else "", "value": value})
            p += 2 + reclen
            p = (p + 3) & ~3

    for m in modules:
        si = m["sym_stream"]
        if si == 0xFFFF or si >= len(msf.streams):
            continue
        walk(msf.stream(si), Path(m["name"]).name)
    if 0 <= sym_record_stream < len(msf.streams):
        walk(msf.stream(sym_record_stream), "<globals>")
    out.sort(key=lambda r: r["rva"])
    return out


PROJECT_HINTS = ("Helper", "Strategy02", "LuaMission", "DLLBase", "TeamInfo", "MapInfo", "Matrix", "Vector",
                 "Class", "Info", "InstantMission", "Deathmatch01", "PUPMgr", "StartingVehicle", "Quaternion")


def is_project_udt(name: str) -> bool:
    if name.startswith(("std::", "_", "__", "lua_", "Lua", "luaL_", "$_", "<")):
        return name.startswith("Lua") and "::" not in name  # LuaMission / LuaBindings
    return not name.startswith(("std", "type_info", "_s_", "HINSTANCE", "tagLUID", "_GUID", "_RTL", "_LIST", "_TP", "_ACTIVATION", "_EXCEPTION", "_CONTEXT", "_FLOATING", "_M128", "_XSAVE", "_XMM", "_YMM", "_TEB", "_NT_TIB", "_RTTI", "_PMD", "_TypeDescriptor", "_CRT", "_LDOUBLE", "_FILE", "_iobuf", "_Lockit", "_Mtx", "_Cnd", "_Thrd", "_Timespec", "_Xtime", "localeinfo", "lconv", "tm", "_div_t", "_ldiv_t", "_lldiv_t", "_stat", "_SECURITY", "_SYSTEM", "_PROCESS", "_IMAGE", "_RTL_", "_UNICODE", "_STRING", "_CLIENT", "_PEB", "_OSVERSION", "_MEMORY", "_LARGE", "_ULARGE", "_FILETIME", "_SYSTEMTIME", "_WIN32", "_OVERLAPPED", "_STARTUPINFO", "HWND", "HKEY", "HDC", "HICON", "HBITMAP", "HMENU", "HFONT", "HBRUSH", "HPEN", "HRGN", "HPALETTE", "HMETAFILE", "HGLRC", "HMODULE", "HRSRC", "HACCEL", "HCURSOR", "HGDIOBJ", "HCOLORSPACE", "HDESK", "HWINSTA", "HKL", "HMONITOR", "HUMPD", "HRAWINPUT", "HSPRITE", "HLSURF", "HSTR", "HTASK", "HWINEVENTHOOK", "HWND", "ATOM", "Hash", "tagRECT", "tagPOINT", "tagSIZE", "tagMSG", "_tagpropertykey", "tagPROPVARIANT", "tagVARIANT", "tagSAFEARRAY", "tagDEC", "tagCY", "tagBSTRBLOB", "tagBLOB", "tagCLIPDATA", "tagVersionedStream", "tagCAC", "tagCAUB", "tagCAI", "tagCAUI", "tagCAL", "tagCAUL", "tagCAFLT", "tagCADBL", "tagCACY", "tagCADATE", "tagCABSTR", "tagCABSTRBLOB", "tagCABOOL", "tagCASCODE", "tagCAPROPVARIANT", "tagCAH", "tagCAUH", "tagCALPSTR", "tagCALPWSTR", "tagCAFILETIME", "tagCACLIPDATA", "tagCACLSID", "IUnknown", "IStream", "ISequentialStream", "IStorage", "tagSTATSTG", "IRecordInfo", "ITypeInfo", "ITypeLib", "ITypeComp", "IDispatch", "tagTYPEATTR", "tagFUNCDESC", "tagVARDESC", "tagELEMDESC", "tagIDLDESC", "tagPARAMDESC", "tagPARAMDESCEX", "tagTYPEDESC", "tagARRAYDESC", "tagTLIBATTR", "tagDISPPARAMS", "tagEXCEPINFO", "tagBINDPTR", "tagFUNCKIND", "tagINVOKEKIND", "tagCALLCONV", "tagTYPEKIND", "tagVARKIND", "tagSYSKIND", "tagDESCKIND", "tagVARFLAGS", "tagFUNCFLAGS", "tagTYPEFLAGS", "tagPARAMFLAGS", "tagIDLFLAGS", "tagIMPLTYPEFLAGS", "tagLIBFLAGS", "tagCHANGEKIND"))


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
        tpi = Tpi(msf)
        udts = dump_udts(tpi)
        modules, _ = parse_dbi(msf)
        procs = dump_procs(msf, tpi, modules)

        dll = pdb.with_suffix(".dll")
        pe = PeImage(dll.read_bytes()) if dll.exists() else None
        data = dump_data(msf, tpi, modules, pe)
        (out_dir / f"{stem}.data.json").write_text(json.dumps(data, indent=1), encoding="utf-8", newline="\n")
        with open(out_dir / f"{stem}.data.tsv", "w", encoding="utf-8", newline="\n") as fh:
            fh.write("rva\tsize\tsection\tscope\tmodule\tdecl\tvalue\n")
            for r in data:
                v = r["value"]
                vs = json.dumps(v, ensure_ascii=False) if v is not None else ""
                fh.write(f"{r['rva']:08x}\t{r['size']}\t{r['section']}\t{r['scope']}\t{r['module']}\t{r['decl']}\t{vs}\n")

        (out_dir / f"{stem}.types.json").write_text(json.dumps(udts, indent=1), encoding="utf-8", newline="\n")
        (out_dir / f"{stem}.procs.json").write_text(json.dumps(procs, indent=1), encoding="utf-8", newline="\n")
        with open(out_dir / f"{stem}.procs.tsv", "w", encoding="utf-8", newline="\n") as fh:
            fh.write("rva\tsize\tscope\tmodule\tname\tsignature\tparams\n")
            for r in procs:
                fh.write(f"{r['rva']:08x}\t{r['size']}\t{r['scope']}\t{r['module']}\t{r['name']}\t{r['sig']}\t{', '.join(p['decl'] for p in r['params'])}\n")

        proj = {n: u for n, u in udts.items() if is_project_udt(n)}
        md = [f"# {pdb.name} — type layouts (generated by tools/pdb_types.py)", "",
              f"{len(udts)} UDTs in the TPI, {len(proj)} project-looking ones shown. Offsets and sizes in bytes (hex).", ""]
        for name, u in proj.items():
            if u["kind"] == "enum":
                md.append(f"## enum {name} : {u['underlying']} ({len(u['values'])} values)")
                md.append("")
                md.append(", ".join(f"`{v['name']}={v['value']}`" for v in u["values"]))
                md.append("")
                continue
            md.append(f"## {u['kind']} {name} — sizeof 0x{u['size']:X} ({u['size']})")
            md.append("")
            if u.get("stale_generations"):
                md.append("- stale generations in the LTCG database (older → newer): " + ", ".join(f"0x{g['size']:X}/{g['count']}f" for g in u["stale_generations"]) + f" → **0x{u['size']:X}** (live)")
            if u["bases"]:
                md.append("- bases: " + ", ".join(f"`{b['type']}` @ 0x{b['offset']:X}" for b in u["bases"]))
            if u["has_vfptr"]:
                md.append("- has vtable pointer")
            if u["nested"]:
                md.append("- nested: " + ", ".join(f"`{n['name']}`" for n in u["nested"]))
            if u["members"]:
                md.append("")
                md.append("| offset | size | member |")
                md.append("|---:|---:|---|")
                for m in u["members"]:
                    md.append(f"| 0x{m['offset']:X} | 0x{m['size']:X} | `{m['decl']}` |")
            if u["statics"]:
                md.append("")
                md.append("- statics: " + ", ".join(f"`{s['type']} {s['name']}`" for s in u["statics"]))
            if u["methods"]:
                md.append("")
                md.append("| vt | kind | method |")
                md.append("|---:|---|---|")
                for m in u["methods"]:
                    md.append(f"| {m['vtslot'] if m['vtslot'] is not None else ''} | {m['prop']} | `{m['sig']}` |")
            md.append("")
        (out_dir / f"{stem}.types.md").write_text("\n".join(md) + "\n", encoding="utf-8", newline="\n")
        print(f"{pdb.name}: {len(udts)} UDTs ({len(proj)} project), {len(procs)} procs")
    return 0


if __name__ == "__main__":
    sys.exit(main())
