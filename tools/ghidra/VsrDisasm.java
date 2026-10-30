// VsrDisasm.java - print the disassembly of an address range (for the few places where the
// decompiler drops information, e.g. variadic arguments). Args: <start hex> <end hex> [outfile]
//@category VSR

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

public class VsrDisasm extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Address end = currentProgram.getAddressFactory().getAddress(a[1]);
        StringBuilder sb = new StringBuilder();
        InstructionIterator it = currentProgram.getListing().getInstructions(start, true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            sb.append(ins.getAddress()).append("  ").append(ins.toString());
            // annotate references (calls / data)
            for (ghidra.program.model.symbol.Reference r : ins.getReferencesFrom()) {
                ghidra.program.model.symbol.Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(r.getToAddress());
                if (s != null) sb.append("   ; ").append(s.getName(true));
            }
            sb.append('\n');
        }
        if (a.length >= 3) {
            Path out = Paths.get(a[2]);
            Files.createDirectories(out.getParent());
            Files.write(out, sb.toString().getBytes(StandardCharsets.UTF_8));
        }
        println("\n" + sb);
    }
}
