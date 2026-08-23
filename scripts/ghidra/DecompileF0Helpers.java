// Decompile the F0xxx helpers reached through FUN_001ee1e0 dispatcher.
// FUN_001f0d90 is the suspected blocker (returns 0 → dispatcher stays at 0).

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class DecompileF0Helpers extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001ef2e0L, // wrapped by FUN_001ee160 (outer gate)
        0x001f0a80L, // wrapped by FUN_001ef0d0
        0x001f0d90L, // wrapped by FUN_001ef1c0 — THE blocker
        0x001f0f10L, // wrapped by FUN_001eef00
        0x001f04a0L, // used by FUN_001eeb50 (status decoder)
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        for (long target : FUNCTIONS) {
            Address addr = toAddr(target);
            Function fn = getFunctionContaining(addr);
            if (fn == null) {
                println("============================================================");
                println("NO_FUNCTION at " + addr);
                continue;
            }
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() +
                    "  body=" + fn.getBody());
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }

        // Find functions that READ iRam0037a298 (post-nethttp dispatcher result)
        // and cRam0037a278 (FUN_001ef1c0 cache flag).
        long[] readTargets = { 0x37a298L, 0x37a290L, 0x37a288L, 0x37a278L, 0x37a280L };
        println("============================================================");
        println("=== FUNCTIONS REFERENCING 0x37a288/278/280/290/298 (decompile substring scan) ===");
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int scanned = 0, hits = 0;
        while (fit.hasNext()) {
            Function fn = fit.next();
            DecompileResults res = ifc.decompileFunction(fn, 30, monitor);
            scanned++;
            if (res == null || !res.decompileCompleted()) continue;
            String c = res.getDecompiledFunction().getC();
            boolean hit = false;
            StringBuilder which = new StringBuilder();
            for (long t : readTargets) {
                String hex = String.format("%x", t);
                if (c.contains(hex)) { hit = true; which.append(' ').append(hex); }
            }
            if (hit) {
                hits++;
                println("FN " + fn.getName() + " @ " + fn.getEntryPoint() + " refs:" + which);
            }
            if (scanned % 200 == 0) println("(scanned " + scanned + " functions...)");
        }
        println("=== scan done: " + hits + " hits over " + scanned + " functions ===");

        ifc.dispose();
    }
}
