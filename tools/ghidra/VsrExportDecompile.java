// VsrExportDecompile.java - headless Ghidra post-script: export a PDB-symbolized decompile
// in the shape of reference/decompiled/strategy02-attempt2/ so runs can be diffed.
//
// Run through tools/ghidra/run_headless.cmd. Script argument: <output directory>.
// Requires the PDB to have been applied (it sits next to the DLL; the PDB analyzer
// picks it up) and Ghidra >= 11.2 for source-line mapping (SourceFileManager);
// without it functions still export, with empty file / line columns.
//
// Outputs:
//   src/<original path>.decomp.c    one file per original source file, functions ordered by line
//   all_functions.tsv               address size user name file minLine maxLine
//   user_functions.tsv              file minLine maxLine address size name signature
//   globals.tsv                     address name type value
//   user_namespaces.txt             namespaces of the project's functions
//   vsr_types.h                     every data type as C (DataTypeWriter)
//   EXPORT_INFO.txt                 program name, image base, Ghidra version, counts
//
//@category VSR
//@author VSR_DLL_Source tools

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.framework.Application;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.data.DataTypeWriter;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolType;

public class VsrExportDecompile extends GhidraScript {

    private static final String PROJECT_PREFIX = "/e:/github/vsr_dll_source/";
    // Strategy02::Execute (4,819 bytes) needs well over 120 s on this machine.
    private static final int DECOMPILE_TIMEOUT_SEC = 1800;

    private static final class FnInfo {
        Function f;
        String file = "";
        int minLine = 0;
        int maxLine = 0;
        boolean user;
        String sig = "";
        long size;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            printerr("usage: VsrExportDecompile.java <outdir>");
            return;
        }
        Path out = Paths.get(args[0]);
        Files.createDirectories(out.resolve("src"));

        Listing listing = currentProgram.getListing();
        Object sfm = sourceFileManager();

        // ---- collect functions
        List<FnInfo> fns = new ArrayList<>();
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            FnInfo fi = new FnInfo();
            fi.f = f;
            fi.size = f.getBody().getNumAddresses();
            fi.sig = f.getSignature().getPrototypeString(true);
            lineRange(sfm, f, fi);
            fi.user = fi.file.startsWith(PROJECT_PREFIX);
            fns.add(fi);
        }
        fns.sort(Comparator.comparing(a -> a.f.getEntryPoint()));

        // ---- all_functions.tsv / user_functions.tsv / namespaces
        try (PrintWriter all = utf8(out.resolve("all_functions.tsv"));
             PrintWriter user = utf8(out.resolve("user_functions.tsv"))) {
            all.println("address\tsize\tuser\tname\tfile\tminLine\tmaxLine");
            user.println("file\tminLine\tmaxLine\taddress\tsize\tname\tsignature");
            for (FnInfo fi : fns) {
                String addr = fi.f.getEntryPoint().toString();
                String name = fi.f.getName(true);
                all.println(addr + "\t" + fi.size + "\t" + (fi.user ? "Y" : "N") + "\t" + tsv(name) + "\t" + fi.file + "\t"
                        + (fi.minLine > 0 ? fi.minLine : "") + "\t" + (fi.maxLine > 0 ? fi.maxLine : ""));
                if (fi.user) {
                    String rel = fi.file.substring(PROJECT_PREFIX.length());
                    user.println(rel + "\t" + fi.minLine + "\t" + fi.maxLine + "\t" + addr + "\t" + fi.size + "\t" + tsv(name) + "\t" + tsv(fi.sig));
                }
            }
        }
        TreeSet<String> namespaces = new TreeSet<>();
        for (FnInfo fi : fns) {
            if (!fi.user) continue;
            Namespace ns = fi.f.getParentNamespace();
            while (ns != null && !ns.isGlobal()) {
                namespaces.add(ns.getName(true));
                ns = ns.getParentNamespace();
            }
        }
        Files.write(out.resolve("user_namespaces.txt"), String.join("\n", namespaces).concat("\n").getBytes(StandardCharsets.UTF_8));

        // ---- decompile user functions grouped by original file, ordered by line
        Map<String, List<FnInfo>> byFile = new TreeMap<>();
        for (FnInfo fi : fns) {
            if (!fi.user) continue;
            byFile.computeIfAbsent(fi.file, k -> new ArrayList<>()).add(fi);
        }
        DecompInterface decomp = new DecompInterface();
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(false);
        decomp.setSimplificationStyle("decompile");
        if (!decomp.openProgram(currentProgram)) {
            printerr("decompiler failed to open: " + decomp.getLastMessage());
            return;
        }
        String dllName = currentProgram.getName();
        String pdbName = dllName.replaceAll("(?i)\\.dll$", ".pdb");
        int decompiled = 0, failed = 0;
        try {
            for (Map.Entry<String, List<FnInfo>> e : byFile.entrySet()) {
                String rel = e.getKey().substring(PROJECT_PREFIX.length());
                Path target = out.resolve("src").resolve(rel + ".decomp.c");
                Files.createDirectories(target.getParent());
                List<FnInfo> list = e.getValue();
                list.sort(Comparator.comparingInt((FnInfo a) -> a.minLine).thenComparing(a -> a.f.getEntryPoint()));
                try (PrintWriter w = utf8(target)) {
                    w.println("// Reconstructed by Ghidra from " + dllName + " + " + pdbName);
                    w.println("// Original source file: " + e.getKey());
                    w.println("// Functions are ordered by original source line. This is decompiler");
                    w.println("// output, not the author's source: names/types come from the PDB,");
                    w.println("// local variable names and control flow are reconstructed.");
                    w.println();
                    for (FnInfo fi : list) {
                        if (monitor.isCancelled()) return;
                        w.println();
                        w.println("// ---------------------------------------------------------------------");
                        w.println("// " + fi.f.getName(true) + "  @ " + fi.f.getEntryPoint() + "  lines " + fi.minLine + "-" + fi.maxLine);
                        w.println();
                        DecompileResults res = decomp.decompileFunction(fi.f, DECOMPILE_TIMEOUT_SEC, monitor);
                        if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                            w.print(res.getDecompiledFunction().getC());
                            decompiled++;
                        } else {
                            w.println("/* DECOMPILE FAILED: " + (res != null ? res.getErrorMessage() : "null result") + " */");
                            failed++;
                        }
                    }
                }
            }
        } finally {
            decomp.dispose();
        }

        // ---- globals.tsv: every non-function symbol at an address
        int globals = 0;
        try (PrintWriter g = utf8(out.resolve("globals.tsv"))) {
            g.println("address\tname\ttype\tvalue");
            SymbolIterator si = currentProgram.getSymbolTable().getAllSymbols(true);
            while (si.hasNext() && !monitor.isCancelled()) {
                Symbol s = si.next();
                SymbolType t = s.getSymbolType();
                if (t != SymbolType.LABEL && t != SymbolType.GLOBAL_VAR) continue;
                if (s.getAddress() == null || !s.getAddress().isMemoryAddress()) continue;
                if (listing.getFunctionAt(s.getAddress()) != null) continue;
                Data d = listing.getDefinedDataAt(s.getAddress());
                String type = d != null ? d.getDataType().getName() : "";
                String value = "";
                if (d != null) {
                    try {
                        Object v = d.getValue();
                        if (v instanceof String) value = (String) v;
                        else if (d.getDataType().getName().contains("String") || d.hasStringValue()) value = d.getDefaultValueRepresentation();
                    } catch (Exception ignore) { }
                }
                g.println(s.getAddress() + "\t" + tsv(s.getName(true)) + "\t" + tsv(type) + "\t" + tsv(value));
                globals++;
            }
        }

        // ---- vsr_types.h
        try (Writer tw = new OutputStreamWriter(Files.newOutputStream(out.resolve("vsr_types.h")), StandardCharsets.UTF_8)) {
            DataTypeWriter dtw = new DataTypeWriter(currentProgram.getDataTypeManager(), tw);
            dtw.write(currentProgram.getDataTypeManager().getRootCategory(), monitor);
        }

        // ---- EXPORT_INFO.txt
        long userCount = fns.stream().filter(x -> x.user).count();
        try (PrintWriter info = utf8(out.resolve("EXPORT_INFO.txt"))) {
            info.println("program: " + dllName);
            info.println("image_base: " + currentProgram.getImageBase());
            info.println("executable_md5: " + currentProgram.getExecutableMD5());
            info.println("executable_sha256: " + currentProgram.getExecutableSHA256());
            info.println("ghidra: " + Application.getApplicationVersion());
            info.println("source_map_api: " + (sfm != null ? "yes" : "no"));
            info.println("functions: " + fns.size() + " (user " + userCount + ")");
            info.println("decompiled: " + decompiled + " failed: " + failed);
            info.println("files: " + byFile.size());
            info.println("globals: " + globals);
        }
        println("VsrExportDecompile: " + fns.size() + " functions (" + userCount + " user), " + byFile.size() + " files, "
                + decompiled + " decompiled, " + failed + " failed, " + globals + " globals -> " + out);
    }

    // ---- source line mapping via reflection so the script also loads on Ghidra < 11.2
    private Object sourceFileManager() {
        try {
            return currentProgram.getClass().getMethod("getSourceFileManager").invoke(currentProgram);
        } catch (Throwable t) {
            return null;
        }
    }

    private void lineRange(Object sfm, Function f, FnInfo fi) {
        if (sfm == null) return;
        try {
            java.lang.reflect.Method getEntries = sfm.getClass().getMethod("getSourceMapEntries", Address.class);
            AddressSetView body = f.getBody();
            int min = Integer.MAX_VALUE, max = 0;
            String file = "";
            // sample every address of the body is too slow for big functions; walk instructions
            ghidra.program.model.listing.InstructionIterator ii = currentProgram.getListing().getInstructions(body, true);
            while (ii.hasNext()) {
                Address a = ii.next().getAddress();
                @SuppressWarnings("unchecked")
                List<Object> entries = (List<Object>) getEntries.invoke(sfm, a);
                for (Object e : entries) {
                    int line = (int) e.getClass().getMethod("getLineNumber").invoke(e);
                    Object sf = e.getClass().getMethod("getSourceFile").invoke(e);
                    String path = (String) sf.getClass().getMethod("getPath").invoke(sf);
                    if (line <= 0) continue;
                    if (file.isEmpty()) file = path.toLowerCase();
                    if (!path.toLowerCase().equals(file)) continue; // inlined code from another file
                    if (line < min) min = line;
                    if (line > max) max = line;
                }
            }
            if (max > 0) {
                fi.file = file;
                fi.minLine = min;
                fi.maxLine = max;
            }
        } catch (Throwable t) {
            // no line info for this function
        }
    }

    private static PrintWriter utf8(Path p) throws IOException {
        return new PrintWriter(new OutputStreamWriter(Files.newOutputStream(p), StandardCharsets.UTF_8), false);
    }

    private static String tsv(String s) {
        // escape like the received attempt2 export so string tables diff cleanly
        return s == null ? "" : s.replace("\\", "\\\\").replace("\t", "\\t").replace("\r", "\\r").replace("\n", "\\n");
    }
}
