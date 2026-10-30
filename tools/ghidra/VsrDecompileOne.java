// VsrDecompileOne.java - decompile a single function with a chosen simplification style and
// timeout, for functions the full export cannot finish (Strategy02::Execute under Ghidra 12.2).
//
// Args: <address hex> <style: decompile|normalize|firstpass|register|paramid> <timeout sec> <out file>
// Run with analyzeHeadless ... -process <program> -noanalysis -postScript VsrDecompileOne.java ...
//
//@category VSR

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class VsrDecompileOne extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 4) {
            printerr("usage: VsrDecompileOne.java <addr> <style> <timeoutSec> <outfile>");
            return;
        }
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) {
            printerr("no function at " + a[0]);
            return;
        }
        // optional 5th arg "strip-locals": remove PDB-applied local variables (not parameters)
        // before decompiling, to test whether the PDB function internals trigger the hang
        if (a.length >= 5 && a[4].equals("strip-locals")) {
            int n = 0;
            for (ghidra.program.model.listing.Variable v : f.getLocalVariables()) {
                f.removeVariable(v);
                n++;
            }
            println("stripped " + n + " local variables from " + f.getName(true));
        }
        DecompInterface d = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.setMaxPayloadMBytes(256);
        d.setOptions(opts);
        d.toggleCCode(true);
        d.toggleSyntaxTree(false);
        d.setSimplificationStyle(a[1]);
        if (!d.openProgram(currentProgram)) {
            printerr("open failed: " + d.getLastMessage());
            return;
        }
        long t0 = System.currentTimeMillis();
        DecompileResults r = d.decompileFunction(f, Integer.parseInt(a[2]), monitor);
        long ms = System.currentTimeMillis() - t0;
        String text;
        if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
            text = r.getDecompiledFunction().getC();
            println("OK " + f.getName(true) + " style=" + a[1] + " in " + ms + " ms, " + text.length() + " chars");
        } else {
            text = "/* DECOMPILE FAILED (" + a[1] + ", " + ms + " ms): " + (r != null ? r.getErrorMessage() : "null") + " */\n";
            println("FAIL " + f.getName(true) + " style=" + a[1] + " in " + ms + " ms: " + (r != null ? r.getErrorMessage() : "null"));
        }
        d.dispose();
        Path out = Paths.get(a[3]);
        Files.createDirectories(out.getParent());
        Files.write(out, text.getBytes(StandardCharsets.UTF_8));
    }
}
