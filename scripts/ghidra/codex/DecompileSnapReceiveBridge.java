// Codex-owned focused decompile for PAL EE SN@P receive bridge functions.
// Output: C:/dnas/active/ghidra_exports/codex_snap_receive_bridge.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class DecompileSnapReceiveBridge extends GhidraScript {
    private static final long[] TARGETS = {
        0x001d72a8L, // UDP receive pump
        0x001d5460L, // missing receive bridge after reassembly
        0x001d6dfcL, // queue pop -> dispatcher
        0x001d9f78L, // post-parse dispatcher
        0x001d9678L, // REGISTER-OK
        0x001d5288L, // packet allocator
        0x001ed6bcL, // packet serialized bytes pointer
        0x001ed2c0L, // packet append
        0x001ed21cL, // likely packet current end/data pointer helper
        0x001ebca8L, // packet length
        0x001ebd04L, // packet capacity
        0x001ebbd0L, // packet flags OR
        0x001ebcd0L, // packet length setter
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/codex_snap_receive_bridge.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE SN@P receive bridge focused decompile");
            pw.println("Program: " + currentProgram.getName());
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            for (long target : TARGETS) dump(target);
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dump(long entry) throws Exception {
        if (!dumped.add(entry)) return;
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) {
            pw.printf("%n---- no function at 0x%08x ----%n", entry);
            return;
        }
        long e = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.println();
        pw.println("----------------------------------------------------------------");
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
