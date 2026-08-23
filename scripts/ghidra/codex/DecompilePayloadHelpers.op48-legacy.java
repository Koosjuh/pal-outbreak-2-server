// Focused opcode 0x48 helper export.
// Copy this over DecompilePayloadHelpers.java when Ghidra script cache refuses a new class.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class DecompilePayloadHelpers extends GhidraScript {
    private static final long[] TARGETS = {
        0x001e094cL,
        0x001d9f78L,
        0x001d8c10L,
        0x001d8710L,
        0x001d81a4L,
        0x001d8b60L,
        0x001d7b30L
    };

    private final Set<Long> dumped = new HashSet<>();
    private DecompInterface ifc;
    private PrintWriter pw;

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-snap-op48-helpers.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE SN@P opcode 0x48 helper export");
            pw.println("Program: " + currentProgram.getName());
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            for (long target : TARGETS) {
                dumpFunction(target);
            }
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dumpFunction(long entry) throws Exception {
        if (!dumped.add(entry)) {
            return;
        }
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        pw.println();
        pw.println("----------------------------------------------------------------");
        if (fn == null) {
            pw.printf("NO_FUNCTION @ 0x%08x%n", entry);
            pw.flush();
            return;
        }
        long e = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.printf("FN %s @ 0x%08x size=0x%x%n", fn.getName(), e, size);
        pw.println("callers:");
        for (Function caller : fn.getCallingFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", caller.getEntryPoint().getOffset(), caller.getName());
        }
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        pw.println("----------------------------------------------------------------");
        DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
        if (r != null && r.decompileCompleted()) {
            pw.println(r.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (r == null ? "null" : r.getErrorMessage()));
        }
        pw.flush();
    }
}
