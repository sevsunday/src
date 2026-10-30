#!/usr/bin/env python3
"""
compare_pe.py - are two builds of the same DLL the same code?

Two links of identical object files are rarely byte-identical: the PE timestamp,
the PDB GUID / path in the RSDS debug record, the export-directory timestamp and
the size of the debug directory all change with the linker flags, and when the
debug directory grows the linker-generated data behind it (CRT RTTI, the SafeSEH
table, volatile metadata, export and import directories, import names) moves.
Every absolute address that points into the moved block then differs too - in
.rdata and in a handful of .text operands - and the base-relocation table moves
with them. None of that is code.

This tool compares two images modulo exactly those effects and nothing else:

  * .text, .data, .rsrc and the part of .rdata in front of the debug directory
    are compared byte for byte, except that a relocated dword (an absolute
    address listed in .reloc) is compared by what it points at, following
    pointers to a bounded depth;
  * the IAT is compared by the import names its thunks resolve to;
  * the block between the debug directory and the first debug blob (CRT data
    that may shift as a whole) is compared with the shift applied;
  * the tail (debug blobs, export + import directories, name strings) is
    compared structurally: same export names and RVAs, same import names in
    the same order, same relocation count; the RSDS path is reported.

Exit status 0 = EQUIVALENT (same code; only linker metadata differs),
1 = DIFFERS (and the first mismatches are printed), 2 = usage.

Usage:  python tools/compare_pe.py A.dll B.dll
Stdlib only. 32-bit PE (PE32) images, which is what the mission DLLs are.
"""
import struct
import sys

MAX_DEPTH = 6
WINDOW = 32


def load(path):
    d = open(path, 'rb').read()
    pe = struct.unpack_from('<I', d, 0x3C)[0]
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optsize = struct.unpack_from('<H', d, pe + 20)[0]
    magic = struct.unpack_from('<H', d, pe + 24)[0]
    if magic != 0x10B:
        sys.exit('%s: not a PE32 image' % path)
    base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
    ddoff = pe + 24 + 96
    dirs = [struct.unpack_from('<II', d, ddoff + i * 8) for i in range(16)]
    secs = []
    off = pe + 24 + optsize
    for i in range(nsec):
        s = off + i * 40
        name = d[s:s + 8].rstrip(b'\0').decode('ascii', 'replace')
        vsize, vaddr, rawsize, rawptr = struct.unpack_from('<IIII', d, s + 8)
        secs.append((name, vaddr, vsize, rawptr, rawsize))
    img = dict(path=path, d=d, base=base, dirs=dirs, secs=secs)
    img['relocs'] = relocs(img)
    return img


def rva2off(img, rva):
    for name, va, vs, rp, rs in img['secs']:
        if va <= rva < va + max(vs, rs):
            return rp + rva - va
    return None


def relocs(img):
    rva, size = img['dirs'][5]
    if not rva:
        return set()
    off = rva2off(img, rva)
    end = off + size
    out = set()
    d = img['d']
    while off < end:
        page, bsize = struct.unpack_from('<II', d, off)
        if bsize == 0:
            break
        for k in range(8, bsize, 2):
            e = struct.unpack_from('<H', d, off + k)[0]
            if e >> 12 == 3:          # IMAGE_REL_BASED_HIGHLOW
                out.add(page + (e & 0xFFF))
        off += bsize
    return out


def section(img, name):
    for s in img['secs']:
        if s[0] == name:
            return s
    return None


def debug_blobs(img):
    rva, size = img['dirs'][6]
    if not rva:
        return []
    off = rva2off(img, rva)
    out = []
    for i in range(size // 28):
        typ, dsz, daddr, dptr = struct.unpack_from('<IIII', img['d'], off + i * 28 + 12)
        out.append((daddr, daddr + dsz, typ))
    return out


def blob(img, typ):
    for s, e, t in debug_blobs(img):
        if t == typ:
            return img['d'][rva2off(img, s):rva2off(img, e)]
    return None


def iat_names(img):
    rva, size = img['dirs'][12]
    if not rva:
        return []
    off = rva2off(img, rva)
    out = []
    for k in range(0, size, 4):
        e = struct.unpack_from('<I', img['d'], off + k)[0]
        if e == 0:
            out.append(None)
        elif e & 0x80000000:
            out.append('ord%d' % (e & 0xFFFF))
        else:
            out.append(img['d'][rva2off(img, e) + 2:].split(b'\0')[0])
    return out


def imports(img):
    rva, size = img['dirs'][1]
    if not rva:
        return []
    off = rva2off(img, rva)
    names = []
    d = img['d']
    while True:
        oft, ts, fc, nrva, ft = struct.unpack_from('<IIIII', d, off)
        if not (oft or nrva or ft):
            break
        dll = d[rva2off(img, nrva):].split(b'\0')[0]
        t = rva2off(img, oft or ft)
        while True:
            e = struct.unpack_from('<I', d, t)[0]
            if not e:
                break
            if e & 0x80000000:
                names.append((dll, 'ord%d' % (e & 0xFFFF)))
            else:
                names.append((dll, d[rva2off(img, e) + 2:].split(b'\0')[0]))
            t += 4
        off += 20
    return names


def exports(img):
    rva, size = img['dirs'][0]
    if not rva:
        return ([], [])
    off = rva2off(img, rva)
    d = img['d']
    nf, nn, af, an, ao = struct.unpack_from('<IIIII', d, off + 20)
    names = [d[rva2off(img, struct.unpack_from('<I', d, rva2off(img, an) + 4 * k)[0]):].split(b'\0')[0]
             for k in range(nn)]
    funcs = [struct.unpack_from('<I', d, rva2off(img, af) + 4 * k)[0] for k in range(nf)]
    return (names, funcs)


def main(argv):
    if len(argv) != 3:
        print(__doc__)
        return 2
    A = load(argv[1])
    B = load(argv[2])
    dbgA = A['dirs'][6]
    dbgB = B['dirs'][6]
    blobsA = debug_blobs(A)
    blobsB = debug_blobs(B)
    tailA = min(b[0] for b in blobsA) if blobsA else section(A, '.rdata')[1] + section(A, '.rdata')[4]
    tailB = min(b[0] for b in blobsB) if blobsB else section(B, '.rdata')[1] + section(B, '.rdata')[4]
    iat = A['dirs'][12]
    problems = []
    if dbgA[0] != dbgB[0]:
        problems.append(('debug directory at a different RVA', dbgA[0], dbgB[0]))
    if iat != B['dirs'][12]:
        problems.append(('IAT at a different RVA or size', iat, B['dirs'][12]))

    # the block between the debug directory and the first debug blob may move as a whole
    midA0 = (dbgA[0] + dbgA[1] + 15) & ~15
    midB0 = (dbgB[0] + dbgB[1] + 15) & ~15
    ra_mid = sorted(r for r in A['relocs'] if midA0 <= r < tailA)
    rb_mid = sorted(r for r in B['relocs'] if midB0 <= r < tailB)
    shift = (rb_mid[0] - ra_mid[0]) if ra_mid and rb_mid else 0
    dbg_end_A = dbgA[0] + max(dbgA[1], dbgB[1])      # the larger directory, so a new entry is not "data"

    def map_rva(r):
        """A-image RVA -> the B-image RVA holding the same datum, or None if inside the
        debug directory or the tail (compared separately)."""
        if r < dbgA[0]:
            return r
        if r < dbg_end_A:
            return None
        if r < tailA:
            return r + shift
        return None

    memo = {}

    def equiv(ra, rb, n, depth):
        key = (ra, rb, n)
        if key in memo:
            return memo[key]
        memo[key] = True                      # provisional, for cycles
        oa = rva2off(A, ra)
        ob = rva2off(B, rb)
        if oa is None or ob is None:
            memo[key] = (oa is None and ob is None)
            return memo[key]
        i = 0
        while i < n:
            ia = (ra + i) in A['relocs']
            ib = (rb + i) in B['relocs']
            if ia or ib:
                if not (ia and ib):
                    memo[key] = False
                    return False
                pa = struct.unpack_from('<I', A['d'], oa + i)[0] - A['base']
                pb = struct.unpack_from('<I', B['d'], ob + i)[0] - B['base']
                if pa != pb:
                    if pa >= tailA and pb >= tailB:
                        pass                  # into the tail: checked structurally below
                    elif map_rva(pa) == pb:
                        pass                  # the same datum after the block shift
                    elif depth <= 0 or not equiv(pa, pb, WINDOW, depth - 1):
                        memo[key] = False
                        return False
                i += 4
            else:
                if A['d'][oa + i] != B['d'][ob + i]:
                    memo[key] = False
                    return False
                i += 1
        return True

    compared = 0
    for name, va, vs, rp, rs in A['secs']:
        if name == '.reloc':
            continue
        sb = section(B, name)
        if sb is None:
            problems.append(('section only in A', name))
            continue
        if sb[1] != va or sb[4] != rs:
            problems.append(('section layout differs', name, (va, rs), (sb[1], sb[4])))
            continue
        i = 0
        while i < rs:
            r = va + i
            if name == '.rdata' and iat[0] <= r < iat[0] + iat[1]:
                i += 4
                continue
            rb = map_rva(r) if name == '.rdata' else r
            if rb is None:
                i += 1
                continue
            ob = rva2off(B, rb)
            if r in A['relocs']:
                if rb not in B['relocs']:
                    problems.append(('relocation missing in B', name, hex(r)))
                    i += 4
                    continue
                pa = struct.unpack_from('<I', A['d'], rp + i)[0] - A['base']
                pb = struct.unpack_from('<I', B['d'], ob)[0] - B['base']
                if pa != pb and not (pa >= tailA and pb >= tailB) and map_rva(pa) != pb \
                        and not equiv(pa, pb, WINDOW, MAX_DEPTH):
                    problems.append(('pointer targets differ', name, hex(r), hex(pa), hex(pb)))
                i += 4
                compared += 4
                continue
            if rb in B['relocs']:
                problems.append(('relocation only in B', name, hex(rb)))
                i += 1
                continue
            if A['d'][rp + i] != B['d'][ob]:
                # An image-relative dword (not relocated) into the shifted block - the
                # volatile-metadata header's table RVAs live there - moves by the shift.
                if name == '.rdata' and shift and i % 4 == 0 and i + 4 <= rs:
                    va_ = struct.unpack_from('<I', A['d'], rp + i)[0]
                    vb_ = struct.unpack_from('<I', B['d'], ob)[0]
                    if vb_ - va_ == shift and midA0 <= va_ < tailA:
                        i += 4
                        compared += 4
                        continue
                problems.append(('byte differs', name, hex(r), A['d'][rp + i], B['d'][ob]))
            i += 1
            compared += 1
    for s in B['secs']:
        if section(A, s[0]) is None:
            problems.append(('section only in B', s[0]))

    same_iat = iat_names(A) == iat_names(B)
    same_imp = imports(A) == imports(B)
    same_exp = exports(A) == exports(B)
    same_reloc_count = len(A['relocs']) == len(B['relocs'])
    rs_a = blob(A, 2)
    rs_b = blob(B, 2)

    print('%s\n  vs %s' % (A['path'], B['path']))
    print('  debug directory at 0x%x: %d -> %d bytes; block behind it shifted by %+d; tail at 0x%x / 0x%x'
          % (dbgA[0], dbgA[1], dbgB[1], shift, tailA, tailB))
    print('  bytes compared (code + data, relocations followed): %d; mismatches: %d' % (compared, len(problems)))
    for p in problems[:15]:
        print('    ', p)
    if len(problems) > 15:
        print('     ... %d more' % (len(problems) - 15))
    print('  IAT names identical: %s | imports identical: %s (%d) | exports identical: %s %s'
          % (same_iat, same_imp, len(imports(A)), same_exp, [n.decode('ascii', 'replace') for n in exports(A)[0]]))
    print('  relocation entries: %d / %d' % (len(A['relocs']), len(B['relocs'])))
    if rs_a and rs_b:
        print('  RSDS: %r -> %r' % (rs_a[24:].split(b'\0')[0].decode('ascii', 'replace'),
                                    rs_b[24:].split(b'\0')[0].decode('ascii', 'replace')))
    ok = not problems and same_iat and same_imp and same_exp and same_reloc_count
    print('  VERDICT: %s' % ('EQUIVALENT (same code; only linker metadata differs)' if ok else 'DIFFERS'))
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main(sys.argv))
