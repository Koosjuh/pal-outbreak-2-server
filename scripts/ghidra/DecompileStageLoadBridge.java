// Decompile FUN_001afa30 + FUN_001af7a0 + FUN_001af990 + FUN_001af870.
// These are the stage-load bridge functions called from FUN_001b42e0 state 0xc.
// Per observation, FUN_001b42e0 IS reaching state 0xc but the post-LBS chain
// doesn't activate, so the break is in this bridge.
//
// Also dump what's at 0x5ac380 (passed to FUN_001af7a0) and search for
// readers of DAT_00245808 / DAT_00245810 (the flags FUN_001af990 sets).

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.mem.MemoryBlock;

public class DecompileStageLoadBridge extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001afa30L, 0x001af7a0L, 0x001af990L, 0x001af870L,
        0x001a7e20L, 0x001a7e90L,  // referenced from state 0xc
        0x001b25a0L, 0x001b3ad0L, 0x001cbae0L, 0x001d1050L,
        0x001b41e0L, 0x001d4200L,  // also in state 7/0xc paths
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        for (long target : FUNCTIONS) {
            Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(target));
            if (fn == null) {
                println("============================================================");
                println("NO FUNCTION at 0x" + Long.toHexString(target));
                continue;
            }
            println("============================================================");
            println("=== " + fn.getName() + " @ " + fn.getEntryPoint() + " body=" + fn.getBody() + " ===");
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            }
        }

        // Dump 0x5ac380 region — likely a callback table or struct ptr
        println("============================================================");
        println("=== 0x005ac380 region (passed to FUN_001af7a0) ===");
        for (int off = 0; off < 0x80; off += 4) {
            long addr = 0x005ac380L + off;
            try {
                int v = currentProgram.getMemory().getInt(toAddr(addr));
                Function fn = getFunctionAt(toAddr(v & 0xFFFFFFFFL));
                String fnName = fn == null ? "" : "  -> " + fn.getName();
                println(String.format("  +%-3x  0x%08x : 0x%08x%s",
                        off, addr, v & 0xFFFFFFFFL, fnName));
            } catch (Exception e) { }
        }

        // Find readers of DAT_00245808 / DAT_00245810 (FUN_001af990's outputs)
        println("============================================================");
        println("=== Functions referencing 0x245808 or 0x245810 ===");
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int hits = 0;
        while (fit.hasNext()) {
            Function fn = fit.next();
            DecompileResults res = ifc.decompileFunction(fn, 30, monitor);
            if (res == null || !res.decompileCompleted()) continue;
            String c = res.getDecompiledFunction().getC();
            if (c.contains("245808") || c.contains("245810")) {
                println("FN " + fn.getName() + " @ " + fn.getEntryPoint());
                hits++;
                if (hits > 20) { println("(more results truncated)"); break; }
            }
        }

        ifc.dispose();
    }
}
