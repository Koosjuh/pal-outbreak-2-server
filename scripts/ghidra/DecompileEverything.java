// Complete decompile of every active SN@P handler + key helpers.
// Output: ee_everything.txt with all 30+ handler decompiles.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileEverything extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // Every active handler from the dispatch table:
        long[][] handlers = {
            // boot/init
            {0x1c4070L, 1}, {0x1c4100L, 2},
            {0x1c8e90L, 3}, {0x1c8ea0L, 4}, {0x1c8eb0L, 5},
            {0x1c91d0L, 6}, {0x1c9030L, 7},
            // session-verify
            {0x1c92d0L, 8},
            // 02 60 (Go Online)
            {0x1c95e0L, 9},
            // 02 62 (state-7, transitions)
            {0x1c4730L,10}, {0x1c4690L,11}, {0x1c4960L,12}, {0x1c4d40L,13},
            {0x1c45f0L,14}, {0x1c4360L,15}, {0x1c4450L,16},
            {0x1c6a50L,17}, {0x1c6c60L,18},
            // 02 65 (lobby data)
            {0x1c6e80L,19}, {0x1c7680L,20}, {0x1c70b0L,21}, {0x1c7a70L,22}, {0x1c8790L,23},
            // 02 61 (user/session)
            {0x1c5a20L,24}, {0x1c5c90L,25}, {0x1c5f30L,26}, {0x1c6130L,27},
            {0x1c63c0L,28}, {0x1c65c0L,29}, {0x1c6840L,30}, {0x1c67a0L,31},
            // 02 63 (system)
            {0x1c8d00L,32}, {0x1c8db0L,33}, {0x1c8ae0L,34}, {0x1c8b00L,35},
            // 02 64
            {0x1c5040L,36}, {0x1c5260L,37}, {0x1c5510L,38}, {0x1c56f0L,39},
            // helpers — extracted from 02 65 01/02 references
            {0x1c3a60L,100},  // "what's my read state?"
            {0x1c3b10L,101},  // "read u32 from packet"
            {0x1c3420L,102},  // appears in dispatcher loop (timeout transition)
            {0x1c3880L,103},  // appears in dispatcher 0x1c9b00 (data-check)
            {0x1c9780L,104},  // appears in dispatcher
            // 0x1c9b00 is the per-tick state-machine; analyzed earlier but include for completeness
        };
        String[] labels = {
            "","02/01 10 01","02/01 10 02","02 10 04","10 10 04","10 10 05","10 10 06","02 10 07",
            "10 60 01 (session-verify challenge)","02 60 02 (Go Online enable)",
            "02 62 10 (state-7 confirm)","10 62 10","02 62 03","02 62 04","02 62 11","02 62 12","02 62 13",
            "02 62 20","02 62 21",
            "02 65 01 (lobby header)","02 65 02 (lobby slot)","02 65 03","02 65 04","02 65 10",
            "02 61 01","02 61 02","02 61 03","02 61 04","02 61 05","02 61 06","02 61 10","10 61 10",
            "02 63 01","02 63 07","02 63 20","02 63 21",
            "02 64 01","02 64 02","02 64 03","02 64 04",
        };

        java.util.Set<Long> seen = new java.util.HashSet<>();
        for (long[] h : handlers) {
            long addr = h[0]; int idx = (int)h[1];
            String label = (idx < labels.length) ? labels[idx] : ("helper_idx_" + idx);
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(addr);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) { println("\n###### " + label + " @ 0x" + Long.toHexString(addr) + " — no fn ######"); continue; }
            if (!seen.add(fn.getEntryPoint().getOffset())) continue;
            long size = fn.getBody().getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1;
            println("\n###### " + label + " — " + fn.getName() + " @ " + fn.getEntryPoint() + "  size=0x" + Long.toHexString(size) + " ######");
            DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
            else println("DECOMPILE_FAILED");
        }
        ifc.dispose();
    }
}
