// Codex-owned focused export for PAL EE SN@P payload helper analysis.
// Output: D:/projects/pal-outbreak-2-server/analysis/ghidra-payload-helpers-export.txt

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
        0x001c3880L, // TCP frame/body receive helper
        0x001c3a60L, // read u8 from payload cursor
        0x001c3ab0L, // read u16 from payload cursor
        0x001c3b10L, // read u32 from payload cursor
        0x001c3b90L, // read/copy variable payload bytes
        0x001c7a70L  // 02 65 04 slot-detail handler
    };

    private final Set<Long> dumped = new HashSet<>();
    private DecompInterface ifc;
    private PrintWriter pw;

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-payload-helpers-export.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE SN@P payload helper focused export");
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
