// Codex-owned focused decompile for PAL EE SN@P state-3 bridge analysis.
// Output: C:/dnas/active/ghidra_exports/codex_snap_state3_bridge.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class DecompileSnapState3Bridge extends GhidraScript {
    private static final long[] TARGETS = {
        0x001d7104L, // per-tick state pump called before recv/select
        0x001d72a8L, // UDP receive pump caller
        0x001d6988L, // inbound packet reassembly/dispatch bridge
        0x001d6dfcL, // queued packet pop -> dispatcher
        0x001d6ee0L, // post-REGISTER bind sender
        0x001d9f78L, // parsed packet dispatcher
        0x001d9678L, // REGISTER-OK handler
        0x001d4d24L, // callback table writer
        0x001cadc0L, // initial callback registration
        0x001cac70L, // initial slot 0x12 callback
        0x001cad10L, // initial slot 0x14 callback
        0x001cadb0L, // initial slots 0x13/0x15 callback
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private final Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/codex_snap_state3_bridge.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE SN@P state-3 bridge focused decompile");
            pw.println("Program: " + currentProgram.getName());
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            for (long target : TARGETS) {
                dump(target);
            }
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dump(long entry) throws Exception {
        if (!dumped.add(entry)) {
            return;
        }
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
