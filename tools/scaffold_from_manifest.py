#!/usr/bin/env python3
"""
scaffold_from_manifest.py - seed source/ with PDB-true declarations and stub bodies.

For every source file GBD's PDBs record under missions\\ (reference/manifest/pdb/SUMMARY.md)
this writes:

  <file>.h    include guard, includes / forward declarations derived from the types used,
              the enums assigned to this header, every class with its exact base, members
              (PDB order, PDB access), static members, nested types and methods (PDB
              declaration order, PDB access, virtual / static / const), free-function and
              namespace declarations, plus the QA-gate-2 layout check hook.
  <file>.cpp  one definition per method / free function recorded in the PDB (names,
              parameter names, signatures from tools/pdb_types.py): a stub body with a
              safe default return and a `// DECOMPILE:` pointer; where the ancestor
              (FILE_MAP.md) defines the same function, its body follows under
              `#if 0 // SEED: <path>:<lines>` for the porter.

Inputs : reference/manifest/pdb/<dll>.types.json, <dll>.procs.json (tools/pdb_types.py)
         reference/manifest/strategy02-attempt2/functions.tsv (line numbers, Strategy02 set)
         reference/ancestor-1.3/, reference/ancestor-bz1helper-2015/ (seeds)
         %BZCC_DIR%\\ScriptUtils.h (to know which names the SDK already declares)
Output : source/missions/{shared,strategy02,instant,deathmatch01,luamission,vsrcore}/*
         (existing files are overwritten ONLY if their provenance line says `status: stub`;
          a file whose status moved on is left alone and reported)

Usage: python tools/scaffold_from_manifest.py [--force]
stdlib only.
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import sys
from collections import OrderedDict, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "source" / "missions"
PDB = ROOT / "reference" / "manifest" / "pdb"
A13 = "reference/ancestor-1.3/Missions"
A15 = "reference/ancestor-bz1helper-2015/Shared"
D3 = "@353698f"
D4 = "@6fda4f5"

# ----------------------------------------------------------------------------- file plan
# vsr file stem -> (module .obj, [ancestor stems (without extension)], notes)
FILES: "OrderedDict[str, dict]" = OrderedDict([
    ("shared/dllbase",            dict(module="DllBase.obj",          anc=[f"{A13}/Shared/DllBase"], tier="D3")),
    ("shared/dllutils",           dict(module="DLLUtils.obj",         anc=[f"{A13}/Shared/DLLUtils"], tier="D3")),
    ("shared/startingvehicles",   dict(module="StartingVehicles.obj", anc=[f"{A13}/Shared/StartingVehicles"], tier="D3")),
    ("shared/submission",         dict(module=None,                   anc=[f"{A13}/Shared/SubMission"], tier="D3", header_only=True)),
    ("shared/taunts",             dict(module="Taunts.obj",           anc=[f"{A15}/Taunts", f"{A13}/Shared/Taunts"], tier="D4")),
    ("shared/trace",              dict(module="Trace.obj",            anc=[f"{A13}/Shared/Trace"], tier="D3")),
    ("shared/trnallies",          dict(module="TRNAllies.obj",        anc=[f"{A13}/Shared/TRNAllies"], tier="D3")),
    ("shared/pupmgr",             dict(module="PUPMgr.obj",           anc=[f"{A13}/Shared/PUPMgr"], tier="D3")),
    ("strategy02/strategy02",     dict(module="Strategy02.obj",       anc=[f"{A13}/Strategy02/Strategy02"], tier="D3", lua="original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Strategy.lua")),
    ("instant/instantmission",    dict(module="InstantMission.obj",   anc=[f"{A13}/Instant/InstantMission"], tier="D3", lua="original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/InstantMission.lua")),
    ("deathmatch01/deathmatch01", dict(module="deathmatch01.obj",     anc=[f"{A13}/Deathmatch01/deathmatch01"], tier="D3", lua="original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Deathmatch.lua")),
    ("luamission/luamission",     dict(module="LuaMission.obj",       anc=[f"{A13}/LuaMission/LuaMission"], tier="D3")),
    ("luamission/luabindings",    dict(module="LuaBindings.obj",      anc=[f"{A13}/LuaMission/LuaBindings"], tier="D3")),
])
HELPERS_D4 = ["AIWeaponHelper", "AttacherHelper", "BuildingHelper", "BZ1Helper", "BZCScriptUtils", "CarrierHelper",
              "DispatchHelper", "MathUtils", "MorphObjectHelper", "PortalHelper", "PowerHelper",
              "ProductionClassHelper", "ScrapHelper", "UndeployHelper"]
HELPERS_DECOMPILE_ONLY = ["AmbientSoundHelper", "GravityHelper", "ObjectHelper", "PowerupHelper", "UtilityShipHelper", "VehicleHelper"]
for h in HELPERS_D4:
    FILES[f"vsrcore/{h.lower()}"] = dict(module=f"{h}.obj", anc=[f"{A15}/{h}"], tier="D4")
for h in HELPERS_DECOMPILE_ONLY:
    anc = [f"{A15}/{h}"] if (ROOT / A15 / f"{h}.cpp").exists() else []
    FILES[f"vsrcore/{h.lower()}"] = dict(module=f"{h}.obj", anc=anc, tier="decompile-only")

MODULE_TO_FILE = {v["module"]: k for k, v in FILES.items() if v["module"]}

# Which PDB's types/procs a file is read from (the shared classes are identical in all four).
FILE_PDB = defaultdict(lambda: "strategy02")
FILE_PDB.update({"instant/instantmission": "instant", "deathmatch01/deathmatch01": "deathmatch01",
                 "shared/pupmgr": "deathmatch01", "shared/trace": "deathmatch01"})

# Enum / orphan-UDT placement when no module defines it (ancestor header map first, then this).
TYPE_HOME_OVERRIDE = {
    "Armor_Type": "vsrcore/bzcscriptutils", "Shield_Type": "vsrcore/bzcscriptutils", "ServiceTypes": "vsrcore/bzcscriptutils",
    "SearchMatchMask": "vsrcore/bzcscriptutils", "HP_Types": "vsrcore/bzcscriptutils", "Hash_GOClass": "vsrcore/bzcscriptutils",
    "Hash_BZCClass": "vsrcore/bzcscriptutils", "Patch_Names": "vsrcore/bzcscriptutils", "Category_Type": "vsrcore/bzcscriptutils",
    "Difficulty": "vsrcore/bzcscriptutils", "GameTypes": "vsrcore/bzcscriptutils", "PowerTypes": "vsrcore/bzcscriptutils",
    "TeamFilter_Type": "vsrcore/bzcscriptutils", "PortalType": "vsrcore/bzcscriptutils", "PathType": "vsrcore/bzcscriptutils",
    "ODFName": "vsrcore/bzcscriptutils", "Independence_Type": "vsrcore/bzcscriptutils",
    "DroneStates": "vsrcore/carrierhelper", "PortalEffectState": "vsrcore/portalhelper", "PortalMatchType": "vsrcore/portalhelper",
    "PreTeleportReturnCodes": "vsrcore/portalhelper", "PostTeleportReturnCodes": "vsrcore/portalhelper",
    "EventODFIDs": "vsrcore/bz1helper", "DispatchType": "vsrcore/dispatchhelper", "DispatchState": "vsrcore/dispatchhelper",
    "TauntTypes": "shared/taunts", "SubMission": "shared/submission", "TRNAllies": "shared/trnallies",
    "PUPMgr": "shared/pupmgr", "myprup": "shared/pupmgr", "DLLBase": "shared/dllbase",
}
ANCESTOR_HEADER_TO_FILE = {  # ancestor header basename (lower) -> vsr file
    "bzcscriptutils.h": "vsrcore/bzcscriptutils", "bz1helper.h": "vsrcore/bz1helper", "dispatchhelper.h": "vsrcore/dispatchhelper",
    "portalhelper.h": "vsrcore/portalhelper", "carrierhelper.h": "vsrcore/carrierhelper", "taunts.h": "shared/taunts",
    "submission.h": "shared/submission", "trnallies.h": "shared/trnallies", "pupmgr.h": "shared/pupmgr", "dllbase.h": "shared/dllbase",
    "strategy02.h": "strategy02/strategy02", "deathmatch01.h": "deathmatch01/deathmatch01", "instantmission.h": "instant/instantmission",
    "luamission.h": "luamission/luamission", "luabindings.h": "luamission/luabindings", "mathutils.h": "vsrcore/mathutils",
    "dllutils.h": "shared/dllutils", "startingvehicles.h": "shared/startingvehicles",
}

SDK_TYPES = {"Vector", "Matrix", "Quaternion", "SpawnpointInfo", "VehicleControls", "VECTOR_2D", "MisnImport", "MisnExport",
             "MisnExport2", "AiCommand", "DLLAudioCategory", "DeathmatchGameSubtypes", "EjectKillRetCodes", "NETWORK_LIST_TYPE",
             "ObjectInfoType", "PreGetInReturnCodes", "PrePickupPowerupReturnCodes", "PreSnipeReturnCodes", "RandomizeType",
             "TEAMRELATIONSHIP"}
CRT_TYPES = {"luaL_Reg", "lua_State", "FT", "PMD", "TypeDescriptor", "EHExceptionRecord", "stat", "timespec", "HandleInfo",
             "type_info", "localeinfo_struct", "lconv", "tm"}
CRT_FUNCS = {"vsprintf_s", "sprintf_s", "_snprintf_s", "__local_stdio_printf_options", "__local_stdio_scanf_options",
             "_vsnprintf_s_l", "_vsprintf_s_l", "_vsnprintf_l", "_vscprintf_l", "_snprintf", "vsnprintf", "swprintf_s",
             "_vswprintf_s_l", "__vcrt_va_start_verify_argument_type", "_vfprintf_l", "printf", "fprintf", "sscanf_s",
             "_sscanf_s_l", "strcpy_s", "strcat_s", "strncpy_s", "wcscpy_s", "memcpy_s", "_strnicmp", "_stricmp",
             "atexit", "DllMain", "_DllMainCRTStartup", "__scrt_common_main",
             # <cmath> inline overloads emitted out of line (float floor(float) @00001caa in Strategy02.obj)
             "floor", "ceil", "sqrt", "fabs", "pow", "fmod", "sin", "cos", "tan", "atan2", "asin", "acos", "exp", "log"}
INT_TYPES = {"int", "unsigned int", "long", "unsigned long", "short", "unsigned short", "char", "unsigned char",
             "signed char", "__int64", "unsigned __int64", "wchar_t", "size_t", "unsigned", "DWORD", "DPID", "Handle",
             "TeamNum", "ScrapValue"}

# ----------------------------------------------------------------------------- type text helpers
_VEC = re.compile(r"std::vector<(.+?),std::allocator<\1 ?> ?>")
_STR = re.compile(r"std::basic_string<char,std::char_traits<char>,std::allocator<char> ?>")


def simplify(t: str) -> str:
    t = t.replace("char const *", "const char*").replace("char const*", "const char*")
    for _ in range(3):
        t2 = _VEC.sub(r"std::vector<\1>", t)
        t2 = _STR.sub("std::string", t2)
        if t2 == t:
            break
        t = t2
    t = re.sub(r"\s*\*\s*", "*", t)      # 'char *' -> 'char*'
    t = re.sub(r"\s*&\s*", "&", t)
    t = re.sub(r"\(\s*\*", "(*", t)
    t = t.replace("*const", "* const").replace("&const", "& const")
    t = re.sub(r"\*(\w)", r"* \1", t)    # 'char*name' -> 'char* name'
    t = re.sub(r"&(\w)", r"& \1", t)
    t = re.sub(r" +", " ", t).strip()
    return t


_TYPE_WORDS = {"const", "volatile", "unsigned", "signed", "int", "char", "short", "long", "float", "double", "bool",
               "void", "std", "vector", "pair", "map", "allocator", "basic_string", "char_traits", "less", "string",
               "__int64", "wchar_t", "size_t", "__cdecl", "__thiscall", "__stdcall", "__fastcall", "enum", "struct", "class"}


def udts_in(t: str) -> list[str]:
    """Every (possibly qualified) identifier in a type string that could name a UDT."""
    out = []
    for m in re.finditer(r"\b([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\b", t):
        tok = m.group(1)
        if tok.split("::")[0] in _TYPE_WORDS or tok.startswith("std::"):
            continue
        if re.fullmatch(r"\d+", tok):
            continue
        out.append(tok)
    return out


def base_udt(t: str) -> str:
    """First UDT name referenced by a type string ('' when none)."""
    u = udts_in(t)
    return u[0] if u else ""


def is_by_value(t: str) -> bool:
    core = re.sub(r"std::vector<(.+)>", r"\1", t)
    return not re.search(r"[\*&]", core)


# ----------------------------------------------------------------------------- ancestor function extraction
def blank_noncode(text: str) -> str:
    """Return text with comments and string/char literal contents replaced by spaces (newlines kept)."""
    out = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i)); i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            seg = text[i:j]
            out.append("".join("\n" if ch == "\n" else " " for ch in seg)); i = j
        elif c in "\"'":
            q = c; j = i + 1
            while j < n and text[j] != q:
                if text[j] == "\\":
                    j += 1
                if text[j] == "\n":
                    break
                j += 1
            j = min(j + 1, n)
            out.append(q + " " * (j - i - 2) + q if j - i >= 2 else text[i:j]); i = j
        else:
            out.append(c); i += 1
    return "".join(out)


FUNC_HEAD = re.compile(
    r"(?<![\w:.>])(?P<name>(?:~?[A-Za-z_]\w*)(?:\s*::\s*~?[A-Za-z_]\w*)*)\s*\((?P<args>[^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*(?:const\s*)?(?::\s*[^{;]*?)?\{",
    re.S)
KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "catch", "do", "else", "new", "delete", "case", "defined"}


def extract_functions(path: Path) -> dict[str, list[dict]]:
    """qualified name -> [ {start_line, end_line, text} ] for top-level function definitions."""
    try:
        text = path.read_text(encoding="latin-1")
    except FileNotFoundError:
        return {}
    code = blank_noncode(text)
    out: dict[str, list[dict]] = defaultdict(list)
    depth = 0
    i, n = 0, len(code)
    while i < n:
        c = code[i]
        if c == "{":
            depth += 1; i += 1; continue
        if c == "}":
            depth -= 1; i += 1; continue
        if depth == 0 and c.isalpha() or c == "_" or c == "~":
            m = FUNC_HEAD.match(code, i)
            if m:
                name = re.sub(r"\s+", "", m.group("name"))
                simple = name.split("::")[-1]
                if simple in KEYWORDS or name in KEYWORDS:
                    i += 1; continue
                # must not be preceded by '=' or be a control statement; find the start of the declaration
                brace = m.end() - 1
                # find matching brace
                d = 1; j = brace + 1
                while j < n and d:
                    if code[j] == "{": d += 1
                    elif code[j] == "}": d -= 1
                    j += 1
                # declaration start: walk back from match start to previous ';' '}' or start
                k = i
                while k > 0 and code[k - 1] not in ";}{":
                    k -= 1
                head = code[k:m.start()].strip()
                if head.endswith("=") or "#" in head.split("\n")[-1]:
                    i += 1; continue
                # drop leading preprocessor lines (a preceding #endif etc.) and blank lines
                while True:
                    nl = code.find("\n", k)
                    if nl < 0 or nl >= m.start():
                        break
                    line = code[k:nl].strip()
                    if line == "" or line.startswith("#"):
                        k = nl + 1
                    else:
                        break
                start_line = text.count("\n", 0, k) + 1
                end_line = text.count("\n", 0, j) + 1
                body_text = text[k:j].strip("\n")
                if re.search(r"^\s*#\s*(if|ifdef|ifndef|endif|else|elif)\b", body_text, re.M):
                    body_text = "// (seed omitted: contains preprocessor conditionals; read the ancestor file directly)"
                out[name].append({"start": start_line, "end": end_line, "text": body_text})
                depth = 0
                i = j
                continue
        i += 1
    return out


# ----------------------------------------------------------------------------- loading
def load_json(p: Path):
    return json.loads(p.read_text(encoding="utf-8"))


def load_all():
    types = {}
    procs = {}
    for dll in ("strategy02", "luamission", "instant", "deathmatch01"):
        t = PDB / f"{dll}.types.json"
        p = PDB / f"{dll}.procs.json"
        if t.exists():
            types[dll] = load_json(t)
        if p.exists():
            procs[dll] = load_json(p)
    return types, procs


# Decompile set per PDB (task 8 verified attempt2 against the regenerated Strategy02 set; task 13 produced the other three).
DECOMPILE_SET = {"strategy02": "strategy02-attempt2", "luamission": "luamission-ghidra12.2",
                 "instant": "instant-ghidra12.2", "deathmatch01": "deathmatch01-ghidra12.2"}


def load_lines():
    """(file stem, name) -> [(min_line, max_line, rva, file, set)] from every decompile set that exists."""
    out: dict[tuple, list] = defaultdict(list)
    csv.field_size_limit(10**9)
    for dll, dset in DECOMPILE_SET.items():
        f = ROOT / "reference" / "manifest" / dset / "functions.tsv"
        if not f.exists():
            continue
        with open(f, encoding="utf-8", newline="") as fh:
            for r in csv.DictReader(fh, delimiter="\t"):
                stem = re.sub(r"\.(cpp|h)$", "", r["file"].replace("missions/", ""))
                out[(stem, r["name"])].append((int(r["min_line"]), int(r["max_line"]), r["address"], r["file"], dset))
    return out


def _split_args(args: str) -> list[str]:
    out, depth, cur = [], 0, ""
    for ch in args:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [a for a in out if a.strip() and a.strip() != "void"]


def sdk_declared_names() -> dict[str, set[int]]:
    """SDK function name -> set of accepted parameter counts (defaults expand the range)."""
    bz = os.environ.get("BZCC_DIR") or r"C:\Program Files (x86)\Steam\steamapps\common\BZ2R"
    names: dict[str, set[int]] = defaultdict(set)
    for h in ("ScriptUtils.h", "AiCmds.h"):
        p = Path(bz) / h
        if not p.exists():
            continue
        t = blank_noncode(p.read_text(encoding="latin-1"))
        for m in re.finditer(r"(?:\bDLLAPI\s+|\binline\s+[\w:\*&\s<>,]+?\s+)(\w+)\s*\(([^;{]*?)\)\s*(?:;|\{)", t, re.S):
            name, args = m.group(1), m.group(2)
            parts = _split_args(args)
            required = sum(1 for a in parts if "=" not in a)
            for k in range(required, len(parts) + 1):
                names[name].add(k)
    names["GetMisnAPI"].add(1)
    return names


# ----------------------------------------------------------------------------- planning
def skip_proc_name(name: str) -> bool:
    if "`" in name or "<" in name or "operator" in name:
        return True
    if name.startswith(("std::", "lua_", "luaL_", "luai_", "luaopen_", "__", "_")):
        return True
    simple = name.split("::")[-1]
    return simple in CRT_FUNCS or name in CRT_FUNCS


class Plan:
    def __init__(self):
        self.types, self.procs = load_all()
        self.lines = load_lines()
        self.sdk_names = sdk_declared_names()
        # merged UDT table (shared classes are identical across PDBs; DLL-specific come from their PDB)
        self.udts: dict[str, dict] = {}
        for dll in ("strategy02", "luamission", "instant", "deathmatch01"):
            for n, u in self.types.get(dll, {}).items():
                self.udts.setdefault(n, u)
        # procs by module (dedupe by name + param types)
        self.module_procs: dict[str, list[dict]] = defaultdict(list)
        seen = set()
        self.proc_dlls: dict[tuple, set] = defaultdict(set)  # (name, ptypes) -> {(dll, file)}
        for dll in ("strategy02", "instant", "deathmatch01", "luamission"):
            for r in self.procs.get(dll, []):
                if r["module"] not in MODULE_TO_FILE or skip_proc_name(r["name"]):
                    continue
                self.proc_dlls[(r["name"], tuple(simplify(p["type"]) for p in r["params"]))].add((dll, MODULE_TO_FILE[r["module"]]))
                key = (r["module"], r["name"], tuple(p["type"] for p in r["params"]))
                if key in seen:
                    continue
                seen.add(key)
                self.module_procs[r["module"]].append(r)
        # class -> file
        self.class_home: dict[str, str] = {}
        votes: dict[str, defaultdict] = defaultdict(lambda: defaultdict(int))
        for mod, rows in self.module_procs.items():
            for r in rows:
                if "::" in r["name"]:
                    cls = r["name"].rsplit("::", 1)[0]
                    top = cls.split("::")[0]
                    if top in self.udts:
                        votes[top][MODULE_TO_FILE[mod]] += 1
        for top, v in votes.items():
            self.class_home[top] = max(v.items(), key=lambda kv: kv[1])[0]
        # ancestor header map for the rest
        self.anc_decl = self._ancestor_declarations()
        # Reachability closure: a type is GBD's if a project module defines its methods, an
        # ancestor header declares it, FILE_MAP places it, or project code references it.
        self.project_types: set[str] = set(self.class_home) | set(TYPE_HOME_OVERRIDE) | \
            {n for n in self.anc_decl if n in self.udts}
        self.project_types = {t for t in self.project_types if t in self.udts and t not in SDK_TYPES and t not in CRT_TYPES}
        frontier = list(self.project_types)
        while frontier:
            t = frontier.pop()
            u = self.udts.get(t)
            if not u or u["kind"] == "enum":
                continue
            refs = [b["type"] for b in u["bases"]] + [m["type"] for m in u["members"]] + [s["type"] for s in u["statics"]]
            for m in u["methods"]:
                refs += [m["ret"]] + m["param_types"]
            for nn in u.get("nested", []):
                refs.append(f"{t}::{nn['name']}")
            for r in refs:
                top = base_udt(simplify(r)).split("::")[0]
                full = base_udt(simplify(r))
                for cand in (top, full):
                    if cand in self.udts and cand not in self.project_types and cand not in SDK_TYPES and cand not in CRT_TYPES \
                            and not cand.startswith(("std::", "_", "$", "<", "tag", "__")) and "<" not in cand:
                        self.project_types.add(cand)
                        frontier.append(cand)
        for rows in self.module_procs.values():
            for r in rows:
                for t in [r["ret"]] + [p["type"] for p in r["params"]]:
                    cand = base_udt(simplify(t)).split("::")[0]
                    if cand in self.udts and cand not in SDK_TYPES and cand not in CRT_TYPES and not cand.startswith(("std::", "_", "$", "<", "tag", "__")) and "<" not in cand:
                        self.project_types.add(cand)
        for n in list(self.project_types):
            top = n.split("::")[0]
            if top in self.class_home:
                continue
            home = TYPE_HOME_OVERRIDE.get(top) or self._home_from_ancestor(top)
            self.class_home[top] = home or "vsrcore/bzcscriptutils"
        # namespaces: name prefixes that are not UDTs
        self.namespaces: set[str] = set()
        for rows in self.module_procs.values():
            for r in rows:
                if "::" in r["name"]:
                    ns = r["name"].rsplit("::", 1)[0]
                    if ns.split("::")[0] not in self.udts:
                        self.namespaces.add(ns)
        # header-inline free functions: defined in a .h per the line table, or emitted by >1 module.
        # key -> owning file stem; rendered once, inline, in that header.
        occ: dict[tuple, set] = defaultdict(set)
        for mod, rows in self.module_procs.items():
            for r in rows:
                if "::" in r["name"] and r["name"].split("::")[0] in self.udts:
                    continue
                counts = self.sdk_names.get(r["name"])
                if counts and len(r["params"]) in counts:
                    continue  # SDK inline wrapper, never ours
                occ[(r["name"], tuple(simplify(p["type"]) for p in r["params"]))].add(MODULE_TO_FILE[mod])
        self.header_inline: dict[tuple, str] = {}
        # name -> header stems the line table attributes it to (an inline lives in a .h)
        header_of_name: dict[str, set] = defaultdict(set)
        for (stem_, nm), entries in self.lines.items():
            for c in entries:
                if c[3].endswith(".h"):
                    header_of_name[nm].add(re.sub(r"\.h$", "", c[3].replace("missions/", "")))
        for key, files in occ.items():
            name = key[0]
            owner = None
            hs = header_of_name.get(name)   # exact name only: LuaBindings::X is not the inline X it wraps
            if hs:
                owner = sorted(hs)[0]
            # "defined in several modules" only counts within ONE DLL (an inline from a shared
            # header); the same name defined once per DLL (BuildMission) is a normal function.
            per_dll: dict[str, set] = defaultdict(set)
            for dll, stem in self.proc_dlls.get(key, ()):
                per_dll[dll].add(stem)
            multi_in_one_dll = any(len(s) > 1 for s in per_dll.values())
            if owner is None and multi_in_one_dll:
                owner = sorted(files)[0]
            if owner:
                self.header_inline[key] = owner

    def _ancestor_declarations(self) -> dict[str, str]:
        out = {}
        for root in (ROOT / A15, ROOT / A13 / "Shared", ROOT / A13 / "LuaMission", ROOT / A13 / "Strategy02",
                     ROOT / A13 / "Deathmatch01", ROOT / A13 / "Instant"):
            if not root.exists():
                continue
            for f in root.iterdir():
                if f.suffix.lower() == ".h":
                    t = f.read_text(encoding="latin-1")
                    for m in re.finditer(r"^\s*(?:struct|class|enum|namespace)\s+(\w+)\b[^;{]*\{", t, re.M):
                        out.setdefault(m.group(1), f.name.lower())
        return out

    def _home_from_ancestor(self, name: str):
        h = self.anc_decl.get(name)
        return ANCESTOR_HEADER_TO_FILE.get(h) if h else None

    def is_project_type(self, name: str) -> bool:
        if name.startswith(("std::", "_", "$", "<", "tag", "__")) or "<" in name or "::__l" in name:
            return False
        top = name.split("::")[0]
        if top in SDK_TYPES or top in CRT_TYPES:
            return False
        if name not in self.udts:
            return False
        return top in self.project_types


# ----------------------------------------------------------------------------- rendering
def default_return(ret: str, cls: str | None, udts: dict, statics: list) -> str:
    r = simplify(ret)
    if r.startswith("const ") and not r.endswith(("*", "&")):
        r = r[6:]  # top-level const on a by-value return: irrelevant for the stub expression
    if r in ("", "void"):
        return ""
    if r.endswith("&"):
        core = r[:-1].strip()
        if cls and core == cls:
            own = [s for s in statics if simplify(s["type"]) == f"{cls}*"]
            if len(own) == 1:
                return f"return *{own[0]['name']};"
        core = core.replace("const ", "")
        return f"static {core} s_stub = {core}(); return s_stub;"
    if r.endswith("*"):
        return 'return "";' if r.startswith("const char") else "return NULL;"
    if r == "bool":
        return "return false;"
    if r in ("float", "double"):
        return "return 0.0f;"
    if r in INT_TYPES:
        return "return 0;"
    u = udts.get(r)
    if u and u["kind"] == "enum":
        return f"return ({r})0;"
    return f"return {r}();"


def enum_body(name: str, u: dict, indent: str = "") -> list[str]:
    vals = u["values"]
    lines = []
    simple = name.split("::")[-1]
    if simple.startswith("<unnamed-enum"):
        lines.append(f"{indent}enum {{")
    else:
        lines.append(f"{indent}enum {simple} {{")
    for v in vals:
        val = v["value"]
        if val < 0 and abs(val) > 0xFFFF:
            txt = f"(int)0x{val & 0xFFFFFFFF:08X}"
        elif val > 0xFFFF:
            txt = f"0x{val:08X}"
        else:
            txt = str(val)
        lines.append(f"{indent}    {v['name']} = {txt},")
    lines.append(f"{indent}}};")
    return lines


def method_decl(m: dict, cls_simple: str, params: list[str] | None) -> str:
    name = m["name"]
    ret = simplify(m["ret"])
    ptypes = [simplify(t) for t in m["param_types"]]
    if params and len(params) == len(ptypes):
        args = ", ".join(params)
    else:
        args = ", ".join(ptypes)
    prefix = ""
    if m["prop"] == "static":
        prefix = "static "
    elif m["prop"] in ("virtual", "intro-virtual", "pure-virtual", "pure-intro-virtual"):
        prefix = "virtual "
    suffix = " const" if m["const"] else ""
    if m["prop"] in ("pure-virtual", "pure-intro-virtual"):
        suffix += " = 0"
    if name == cls_simple or name == f"~{cls_simple}":
        return f"{prefix}{name}({args});"
    return f"{prefix}{ret} {name}({args}){suffix};"


def params_decl(proc: dict | None, ptypes: list[str], tpls: list[str] | None = None, comment_names: bool = False) -> list[str]:
    """Render parameters: the METHOD's own types (templates with a name slot) + names borrowed
    from the matching proc when the counts agree, else param_N. comment_names=True renders
    `type /*name*/` for stub definitions (keeps -W4 quiet without touching the signature)."""
    tpls = tpls or [f"{t} @@" if t != "..." else "..." for t in ptypes]
    names = [p["name"] for p in proc["params"]] if proc and len(proc["params"]) == len(tpls) else [f"param_{i + 1}" for i in range(len(tpls))]
    out = []
    for tpl, nm in zip(tpls, names):
        if tpl == "...":
            out.append("...")
            continue
        slot = f"/*{nm}*/" if comment_names else nm
        rendered = simplify(tpl.replace("@@", "VSRNAMESLOT")).replace("VSRNAMESLOT", slot)
        out.append(rendered)
    return out


class Generator:
    def __init__(self, plan: Plan, force: bool):
        self.p = plan
        self.force = force
        self.report: list[str] = []
        self.anc_cache: dict[str, dict] = {}

    # ---------------------------------------------------------------- ancestor seeds
    def ancestor_funcs(self, stem: str) -> dict[str, list[dict]]:
        key = stem
        if key in self.anc_cache:
            return self.anc_cache[key]
        merged: dict[str, list[dict]] = defaultdict(list)
        for anc in FILES[stem]["anc"]:
            for ext in (".cpp", ".h"):
                p = ROOT / (anc + ext)
                if not p.exists():
                    # try case-insensitive
                    d = (ROOT / anc).parent
                    cands = [x for x in d.iterdir() if x.name.lower() == (Path(anc).name + ext).lower()] if d.exists() else []
                    if not cands:
                        continue
                    p = cands[0]
                for name, defs in extract_functions(p).items():
                    for dfn in defs:
                        dfn["path"] = str(p.relative_to(ROOT)).replace("\\", "/")
                    merged[name].extend(defs)
        self.anc_cache[key] = merged
        return merged

    def seed_for(self, stem: str, qualname: str, used: set) -> str:
        funcs = self.ancestor_funcs(stem)
        cands = funcs.get(qualname) or funcs.get(qualname.split("::")[-1]) or []
        for d in cands:
            k = (d["path"], d["start"])
            if k in used:
                continue
            used.add(k)
            return "\n".join([f"#if 0 // SEED: {d['path']}:{d['start']}-{d['end']}", d["text"], "#endif"])
        return ""

    # ---------------------------------------------------------------- per-file
    def classes_for(self, stem: str) -> list[str]:
        out = []
        for n, u in self.p.udts.items():
            if u["kind"] == "enum" or not self.p.is_project_type(n) or "::" in n:
                continue
            if self.p.class_home.get(n) == stem:
                out.append(n)
        # dependency order: a class that uses another same-file class BY VALUE (base, member,
        # static) comes after it. Stable topological sort over a deterministic base order.
        out.sort()
        here = set(out)

        def deps(n: str) -> set[str]:
            u = self.p.udts[n]
            d = set()
            for b in u["bases"]:
                d.add(b["type"].split("::")[0])
            for m in u["members"] + u["statics"]:
                t = simplify(m["type"])
                if is_by_value(t):
                    for name in udts_in(t):
                        d.add(name.split("::")[0])
            for nested in self.nested_of(n):
                d |= deps(nested)
            return {x for x in d if x in here and x != n}

        ordered: list[str] = []
        pending = list(out)
        while pending:
            progressed = False
            for n in list(pending):
                if deps(n) <= set(ordered):
                    ordered.append(n); pending.remove(n); progressed = True
            if not progressed:  # cycle: emit the rest in base order
                ordered += pending
                break
        return ordered

    def enums_for(self, stem: str) -> list[str]:
        out = []
        for n, u in self.p.udts.items():
            if u["kind"] != "enum" or "::" in n or not self.p.is_project_type(n):
                continue
            if self.p.class_home.get(n) == stem:
                out.append(n)
        return sorted(out)

    def nested_of(self, cls: str) -> list[str]:
        # declaration order from the TPI nested list; types only
        order = [x["name"] for x in self.p.udts[cls].get("nested", [])]
        found = []
        for nm in order:
            full = f"{cls}::{nm}"
            if full in self.p.udts and "::__l" not in full and self.p.udts[full]["kind"] != "enum":
                found.append(full)
        return found

    @staticmethod
    def _collect(t: str, acc: set, by_value: set):
        t = simplify(t)
        names = udts_in(t)
        for bu in names:
            acc.add(bu)
            # by value: no pointer/reference anywhere in the type (templates by value too)
            if is_by_value(t) or ("::" in bu):
                by_value.add(bu)

    def refs_of_class(self, cls: str, acc: set, by_value: set):
        u = self.p.udts[cls]
        for b in u["bases"]:
            acc.add(b["type"]); by_value.add(b["type"])
        for m in u["members"]:
            self._collect(m["type"], acc, by_value)
        for s in u["statics"]:
            self._collect(s["type"], acc, by_value)
        for m in u["methods"]:
            for t in [m["ret"]] + m["param_types"]:
                self._collect(t, acc, by_value)
        for nested in self.nested_of(cls):
            self.refs_of_class(nested, acc, by_value)

    def header_includes(self, stem: str, classes: list[str], free_procs: list[dict]) -> tuple[list[str], list[str]]:
        acc, by_value = set(), set()
        for c in classes:
            self.refs_of_class(c, acc, by_value)
        for r in free_procs:
            for t in [r["ret"]] + [p["type"] for p in r["params"]]:
                self._collect(t, acc, by_value)
        incs = ['#include "ScriptUtils.h"']
        fwd = []
        if "lua_State" in acc:
            incs.append('#include "lua.hpp"')
        own_tops = {c.split("::")[0] for c in classes}
        for name in sorted(acc):
            top = name.split("::")[0]
            if top in own_tops or top in SDK_TYPES or top in CRT_TYPES or top not in self.p.udts:
                continue
            if not self.p.is_project_type(top):
                continue
            home = self.p.class_home.get(top)
            if not home or home == stem:
                continue
            u = self.p.udts[top]
            if u["kind"] == "enum" or name in by_value or "::" in name or top in by_value:
                inc = f'#include "{Path(home).name}.h"'
                if inc not in incs:
                    incs.append(inc)
            else:
                kw = "class" if u["kind"] == "class" else "struct"
                fwd.append(f"{kw} {top};")
        # strip forward decls that are also included
        inc_names = {re.search(r'"(.+)\.h"', i).group(1) for i in incs if '.h"' in i and "ScriptUtils" not in i and "lua.hpp" not in i}
        fwd = sorted({f for f in fwd if self.p.class_home.get(f.split()[1].rstrip(";"), "").split("/")[-1] not in inc_names})
        return incs, fwd

    def render_class(self, cls: str, stem: str, indent: str = "") -> list[str]:
        u = self.p.udts[cls]
        simple = cls.split("::")[-1]
        kw = "class" if u["kind"] == "class" else "struct"
        bases = ", ".join(f"{b['access']} {simplify(b['type'])}" for b in u["bases"])
        head = f"{indent}{kw} {simple}" + (f" : {bases}" if bases else "") + " {"
        lines = [head]
        default_access = "private" if kw == "class" else "public"
        cur = default_access
        lines.append(f"{indent}    friend struct VsrLayoutCheck_{re.sub(r'[^A-Za-z0-9_]', '_', cls)}; // scaffold: QA gate 2 hook (layout asserts); not GBD's")

        def set_access(a):
            nonlocal cur
            if a != cur:
                lines.append(f"{indent}{a}:")
                cur = a

        # nested types first (public: the scaffold cannot know GBD's access; the port tightens it)
        nested = self.nested_of(cls)
        nested_enums = [n for n, e in self.p.udts.items() if e["kind"] == "enum" and n.startswith(cls + "::") and n.count("::") == cls.count("::") + 1]
        if nested or nested_enums:
            set_access("public")
            for ne in nested_enums:
                lines += enum_body(ne, self.p.udts[ne], indent + "    ")
            for n in nested:
                lines += self.render_class(n, stem, indent + "    ")
                lines.append("")
        # static members
        for s in u["statics"]:
            set_access(s["access"])
            lines.append(f"{indent}    static {simplify(s['decl'])};")
        # data members in offset order
        for m in sorted(u["members"], key=lambda x: x["offset"]):
            set_access(m["access"])
            decl = simplify(m["decl"])
            # inside the class, nested names may be unqualified; keep qualified (always valid)
            lines.append(f"{indent}    {decl};")
        # methods in declaration order
        procs = self.p.module_procs.get(FILES[stem]["module"], []) if FILES[stem]["module"] else []
        for m in u["methods"]:
            nm = m["name"]
            if nm in ("__vecDelDtor", "__local_vftable_ctor_closure"):
                continue
            if nm == simple and len(m["param_types"]) == 1 and simplify(m["param_types"][0]) == f"const {cls}&":
                continue  # implicit copy ctor
            if nm == "operator=":
                continue
            set_access(m["access"])
            proc = self.find_proc(procs, f"{cls}::{nm}", m["param_types"])
            params = params_decl(proc, m["param_types"], m.get("param_tpls")) if m["param_types"] else None
            lines.append(f"{indent}    {method_decl(m, simple, params)}")
        lines.append(f"{indent}}};")
        return lines

    def find_proc(self, procs: list[dict], qual: str, ptypes: list[str]):
        want = [simplify(t) for t in ptypes]
        for r in procs:
            if r["name"] == qual and [simplify(p["type"]) for p in r["params"]] == want:
                return r
        for r in procs:
            if r["name"] == qual and len(r["params"]) == len(want):
                return r
        return None

    def decompile_pointer(self, stem: str, qual: str, proc: dict | None, used: set) -> str:
        # The file's own DLL's set first (shared files appear in every set with the same line numbers).
        home = DECOMPILE_SET[FILE_PDB[stem]]
        cands = sorted(self.p.lines.get((stem, qual)) or [], key=lambda c: 0 if c[4] == home else 1)
        for c in cands:
            if c in used:
                continue
            used.add(c)
            return f"// DECOMPILE: {Path(c[3]).name}:{c[0]}-{c[1]}  @{c[2]}  (reference/decompiled/{c[4]}/src/{c[3]}.decomp.c)"
        if proc:
            return f"// DECOMPILE: symbol @{proc['rva']:08x} (VA 0x{0x4FC00000 + proc['rva']:08x}) in {proc['module']}; no line record in the {home} set (COMDAT-folded or lineless) - read it at that address"
        return "// DECOMPILE: not emitted as a symbol in the binary (inlined or unused) - port from the ancestor / decompile call sites"

    def render_cpp(self, stem: str, classes: list[str], free_procs: list[dict]) -> list[str]:
        info = FILES[stem]
        own = Path(stem).name
        lines = [f'#include "{own}.h"', ""]
        if any(r["scope"] == "local" and not r.get("header_inline") for r in free_procs):
            lines.insert(1, "// scaffold: file-static functions are unreferenced until their caller is ported (C4505). Remove with the port.")
            lines.insert(2, "#pragma warning(disable: 4505)")
        used_seed: set = set()
        used_line: set = set()
        procs = self.p.module_procs.get(info["module"], []) if info["module"] else []
        # static member definitions
        for cls in classes:
            for c in [cls] + self.nested_of(cls):
                u = self.p.udts[c]
                for s in u["statics"]:
                    d = simplify(s["decl"])
                    # insert the class qualifier before the name
                    nm = s["name"]
                    d2 = re.sub(rf"\b{re.escape(nm)}\b", f"{c}::{nm}", d, count=1)
                    lines.append(f"{d2};")
        if any(self.p.udts[c]["statics"] for c in classes):
            lines.append("")
        # methods
        for cls in classes:
            for c in [cls] + self.nested_of(cls):
                u = self.p.udts[c]
                simple = c.split("::")[-1]
                for m in u["methods"]:
                    nm = m["name"]
                    if nm in ("__vecDelDtor", "__local_vftable_ctor_closure", "operator="):
                        continue
                    if nm == simple and len(m["param_types"]) == 1 and simplify(m["param_types"][0]) == f"const {c}&":
                        continue
                    qual = f"{c}::{nm}"
                    proc = self.find_proc(procs, qual, m["param_types"])
                    params = params_decl(proc, m["param_types"], m.get("param_tpls"), comment_names=True)
                    ret = simplify(m["ret"])
                    is_ctor = nm == simple or nm == f"~{simple}"
                    sig = f"{c}::{nm}({', '.join(params)})" if is_ctor else f"{ret} {c}::{nm}({', '.join(params)})"
                    if m["const"]:
                        sig += " const"
                    body = default_return(m["ret"], c, self.p.udts, u["statics"]) if not is_ctor else ""
                    lines.append(self.decompile_pointer(stem, qual, proc, used_line))
                    lines.append(sig)
                    lines.append("{")
                    lines.append("    // TODO(port): stub - see the DECOMPILE pointer above" + (f"\n    {body}" if body else ""))
                    lines.append("}")
                    seed = self.seed_for(stem, qual, used_seed)
                    if seed:
                        lines.append(seed)
                    lines.append("")
        # free + namespace functions
        mission_class = next((c for c in classes if any(b["type"] in ("LuaMission", "BZ1Helper", "DLLBase") for b in self.p.udts[c]["bases"])), None)
        for r in free_procs:
            if r.get("header_inline"):
                continue
            qual = r["name"]
            params = params_decl(r, [p["type"] for p in r["params"]], [p["tpl"] for p in r["params"]], comment_names=True)
            ret = simplify(r["ret"]) or "void"
            static = "static " if r["scope"] == "local" else ""
            sig = f"{static}{ret} {qual}({', '.join(params)})"
            body = default_return(r["ret"], None, self.p.udts, [])
            if qual == "BuildMission" and mission_class:
                # the one free function whose body is fully known: new <mission class>()
                guard = stem == "luamission/luamission"
                lines.append(self.decompile_pointer(stem, qual, r, used_line))
                if guard:
                    lines.append("#ifndef LUA_LIB  // LuaMissionLib.lib (built -DLUA_LIB) must not define it: each DLL has its own")
                lines.append("DLLBase *BuildMission(void)")
                lines.append("{")
                lines.append(f"\treturn new {mission_class}();")
                lines.append("}")
                if guard:
                    lines.append("#endif")
                lines.append("")
                continue
            lines.append(self.decompile_pointer(stem, qual, r, used_line))
            lines.append(sig)
            lines.append("{")
            lines.append("    // TODO(port): stub - see the DECOMPILE pointer above" + (f"\n    {body}" if body else ""))
            lines.append("}")
            seed = self.seed_for(stem, qual, used_seed)
            if seed:
                lines.append(seed)
            lines.append("")
        return lines

    def provenance(self, stem: str, kind: str) -> str:
        info = FILES[stem]
        anc = " + ".join(f"{a}.{kind} {D4 if A15 in a else D3}" for a in info["anc"]) if info["anc"] else "none (decompile-only)"
        extra = f" | gbd-lua-port {info['lua']}" if info.get("lua") else ""
        return (f"// PROVENANCE: ancestor {anc} | declarations original/missions/{FILE_PDB[stem].capitalize() if FILE_PDB[stem] != 'deathmatch01' else 'deathmatch01'}.pdb via tools/pdb_types.py"
                f"{extra} | status: stub")

    def write(self, rel: str, text: str):
        p = SRC / rel
        if p.exists() and not self.force:
            first = p.read_text(encoding="utf-8", errors="replace").splitlines()[:1]
            if first and "status: stub" not in first[0]:
                self.report.append(f"SKIP (status advanced): {rel}")
                return
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text, encoding="utf-8", newline="\n")
        self.report.append(f"wrote {rel} ({text.count(chr(10))} lines)")

    def generate_file(self, stem: str):
        info = FILES[stem]
        own = Path(stem).name
        classes = self.classes_for(stem)
        enums = self.enums_for(stem)
        procs = self.p.module_procs.get(info["module"], []) if info["module"] else []
        udt_tops = set(self.p.udts)
        free_procs = []
        for r in procs:
            if "::" in r["name"]:
                top = r["name"].split("::")[0]
                if top in udt_tops:
                    continue  # a method (rendered with its class)
            counts = self.p.sdk_names.get(r["name"])
            if counts and len(r["params"]) in counts:
                if r["name"] == "GetMisnAPI":
                    r = dict(r, sdk_declared=True)   # declared (not defined) by the SDK: definition only
                else:
                    continue                          # SDK inline wrapper instantiated into this module - not GBD's
            key = (r["name"], tuple(simplify(p["type"]) for p in r["params"]))
            owner = self.p.header_inline.get(key)
            if owner is not None:
                if owner == stem:
                    r = dict(r, header_inline=True)   # defined inline in THIS header
                else:
                    continue                          # defined inline in another header
            free_procs.append(r)
        free_procs.sort(key=lambda r: r["rva"])
        # header-inline functions owned by this file but recorded only under other modules
        for key, owner in self.p.header_inline.items():
            if owner != stem or any((r["name"], tuple(simplify(p["type"]) for p in r["params"])) == key for r in free_procs):
                continue
            for rows in self.p.module_procs.values():
                hit = next((r for r in rows if (r["name"], tuple(simplify(p["type"]) for p in r["params"])) == key), None)
                if hit:
                    free_procs.append(dict(hit, header_inline=True))
                    break

        # ------------------------------------------------------------------ header
        guard = f"_{own}_"
        h = [self.provenance(stem, "h"), f"#ifndef {guard}", f"#define {guard}", ""]
        incs, fwd = self.header_includes(stem, classes, [r for r in free_procs if not r.get("sdk_declared")])
        h += incs
        if fwd:
            h.append("")
            h += fwd
        h.append("")
        for e in enums:
            h += enum_body(e, self.p.udts[e])
            h.append("")
        for c in classes:
            h += self.render_class(c, stem)
            h.append("")
        # namespaces / free functions
        ns_groups: "OrderedDict[str, list]" = OrderedDict()
        for r in free_procs:
            if r.get("sdk_declared") or r["scope"] == "local":
                continue
            ns = r["name"].rsplit("::", 1)[0] if "::" in r["name"] else ""
            ns_groups.setdefault(ns, []).append(r)
        used_line_h: set = set()
        for ns, rows in ns_groups.items():
            ind = ""
            if ns:
                h.append(f"namespace {ns} {{")
                ind = "    "
            for r in rows:
                nm = r["name"].split("::")[-1]
                ret = simplify(r["ret"]) or "void"
                if r.get("header_inline"):
                    params = params_decl(r, [p["type"] for p in r["params"]], [p["tpl"] for p in r["params"]], comment_names=True)
                    body = default_return(r["ret"], None, self.p.udts, [])
                    h.append(f"{ind}{self.decompile_pointer(stem, r['name'], r, used_line_h)}")
                    h.append(f"{ind}inline {ret} {nm}({', '.join(params)})")
                    h.append(f"{ind}{{")
                    h.append(f"{ind}    // TODO(port): header-inline stub" + (f"\n{ind}    {body}" if body else ""))
                    h.append(f"{ind}}}")
                else:
                    params = params_decl(r, [p["type"] for p in r["params"]], [p["tpl"] for p in r["params"]])
                    h.append(f"{ind}{ret} {nm}({', '.join(params)});")
            if ns:
                h.append("}")
            h.append("")
        if classes:
            for c in classes:
                tag = re.sub(r"[^A-Za-z0-9_]", "_", c)
                h.append(f"#define VSR_LAYOUT_CHECK_{tag}")
            h.append('#include "vsr_layout_asserts.h"')
            for c in classes:
                tag = re.sub(r"[^A-Za-z0-9_]", "_", c)
                h.append(f"#undef VSR_LAYOUT_CHECK_{tag}")
            h.append("")
        h.append(f"#endif // {guard}")
        # standard headers the rendered text needs (free-function signatures included)
        body = "\n".join(h)
        std_incs = []
        for needle, inc in (("std::vector", "<vector>"), ("std::pair", "<utility>"), ("std::map", "<map>"),
                            ("std::string", "<string>"), ("std::unordered_map", "<unordered_map>"), ("std::list", "<list>")):
            if needle in body and f"#include {inc}" not in body:
                std_incs.append(f"#include {inc}")
        if std_incs:
            at = h.index('#include "ScriptUtils.h"') + 1
            h[at:at] = std_incs
        self.write(f"{stem}.h", "\n".join(h) + "\n")

        # ------------------------------------------------------------------ cpp
        if info.get("header_only"):
            return
        c = [self.provenance(stem, "cpp")]
        c += self.render_cpp(stem, classes, free_procs)
        if len(c) <= 3:
            c.append("// (no functions recorded for this module in the PDB - everything inlined or in the header)")
        self.write(f"{stem}.cpp", "\n".join(c) + "\n")

    def run(self):
        for stem in FILES:
            self.generate_file(stem)
        return self.report


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--force", action="store_true", help="overwrite files whose status is no longer 'stub'")
    args = ap.parse_args(argv)
    plan = Plan()
    gen = Generator(plan, args.force)
    for line in gen.run():
        print(line)
    # orphan report
    homes = defaultdict(list)
    for n in plan.udts:
        if plan.is_project_type(n) and "::" not in n:
            homes[plan.class_home.get(n, "?")].append(n)
    print("\nclass/enum placement:")
    for stem in FILES:
        if homes.get(stem):
            print(f"  {stem}: {', '.join(sorted(homes[stem]))}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
