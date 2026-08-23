// Codex-owned focused export for PAL EE TCP 10127 cmd 0x1004 analysis.
// Output: D:/projects/pal-outbreak-2-server/analysis/ghidra-cmd1004-export.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileCmd1004 extends GhidraScript {
    private static final long[] TARGETS = {
        0x001c8e90L, // server reply handler entry for 02 10 04 per export
        0x001c8ea0L, // server push/tell table sibling for 10 10 04 per export
        0x001c8eb0L, // next known sibling 10 10 05
        0x001c9030L, // 02 10 07 reply handler, comparison point
        0x001c3a60L,
        0x001c3ab0L,
        0x001c3b90L
    };

    private PrintWriter pw;
    private DecompInterface ifc;

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-cmd1004-export.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE TCP 10127 cmd 0x1004 focused export");
            pw.println("Program: " + currentProgram.getName());
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            for (long target : TARGETS) {
                dumpTarget(target);
            }
            dumpBytes(0x001c8e70L, 0x90);
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dumpTarget(long entry) throws Exception {
        Address a = toAddr(entry);
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.printf("TARGET 0x%08x%n", entry);
        dumpRefs(a);
        dumpInstructions(a, 16);

        Function fn = currentProgram.getFunctionManager().getFunctionAt(a);
        if (fn == null) {
            fn = currentProgram.getFunctionManager().getFunctionContaining(a);
        }
        if (fn == null) {
            try {
                disassemble(a);
                fn = createFunction(a, "codex_cmd1004_" + Long.toHexString(entry));
            } catch (Exception e) {
                pw.println("createFunction failed: " + e.getMessage());
            }
        }

        if (fn == null) {
            pw.println("No function available for decompile.");
            return;
        }

        long e = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.printf("FUNCTION %s @ 0x%08x size=0x%x%n", fn.getName(), e, size);
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
        if (r != null && r.decompileCompleted()) {
            pw.println(r.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (r == null ? "null" : r.getErrorMessage()));
        }
        pw.flush();
    }

    private void dumpRefs(Address a) {
        pw.println("references to:");
        for (Reference ref : getReferencesTo(a)) {
            pw.printf("  from 0x%08x type=%s%n", ref.getFromAddress().getOffset(), ref.getReferenceType());
        }
        pw.println("references from:");
        for (Reference ref : getReferencesFrom(a)) {
            pw.printf("  to   0x%08x type=%s%n", ref.getToAddress().getOffset(), ref.getReferenceType());
        }
    }

    private void dumpInstructions(Address a, int count) {
        pw.println("instructions:");
        Instruction ins = getInstructionAt(a);
        if (ins == null) {
            ins = getInstructionAfter(a.subtract(4));
        }
        for (int i = 0; i < count && ins != null; i++) {
            pw.printf("  0x%08x  %s%n", ins.getAddress().getOffset(), ins.toString());
            ins = ins.getNext();
        }
    }

    private void dumpBytes(long start, int len) throws Exception {
        Memory mem = currentProgram.getMemory();
        byte[] bytes = new byte[len];
        mem.getBytes(toAddr(start), bytes);
        pw.println();
        pw.printf("BYTES 0x%08x len=0x%x%n", start, len);
        for (int i = 0; i < bytes.length; i += 16) {
            pw.printf("  0x%08x  ", start + i);
            int n = Math.min(16, bytes.length - i);
            for (int j = 0; j < n; j++) {
                pw.printf("%02x ", bytes[i + j] & 0xff);
            }
            pw.println();
        }
    }
}
