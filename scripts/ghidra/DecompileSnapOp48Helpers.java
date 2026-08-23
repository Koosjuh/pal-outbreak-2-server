import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileSnapOp48Helpers extends GhidraScript {
    private static final long[] TARGETS = {
        0x001e094cL,
        0x001d9f78L,
        0x001d8c10L,
        0x001d8710L,
        0x001d81a4L,
        0x001d8b60L,
        0x001d7b30L
    };

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-snap-op48-helpers.txt";
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            pw.println("PAL EE SN@P opcode 0x48 helper export");
            pw.println("Program: " + currentProgram.getName());
            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            try {
                for (long target : TARGETS) {
                    dumpFunction(ifc, pw, target);
                }
            } finally {
                ifc.dispose();
            }
        }
        println("Done: " + outPath);
    }

    private void dumpFunction(DecompInterface ifc, PrintWriter pw, long entry) throws Exception {
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        pw.println();
        pw.println("----------------------------------------------------------------");
        if (fn == null) {
            pw.printf("NO_FUNCTION @ 0x%08x%n", entry);
            pw.flush();
            return;
        }
        long start = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - start + 1;
        pw.printf("FN %s @ 0x%08x size=0x%x%n", fn.getName(), start, size);
        pw.println("callers:");
        for (Function caller : fn.getCallingFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", caller.getEntryPoint().getOffset(), caller.getName());
        }
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        pw.println("----------------------------------------------------------------");
        DecompileResults result = ifc.decompileFunction(fn, 90, monitor);
        if (result != null && result.decompileCompleted()) {
            pw.println(result.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (result == null ? "null" : result.getErrorMessage()));
        }
        pw.flush();
    }
}
