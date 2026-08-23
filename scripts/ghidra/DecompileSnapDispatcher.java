// Decompile the SN@P packet dispatcher around 0x1c9c98 (which loads dispatch table 0x248600).
// Also decompile a few of the handlers to identify what packet codes they handle.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileSnapDispatcher extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        long[] targets = {
          0x1c9c98L,  // the dispatcher reference site — find containing function
          // Some handlers to identify what cmd codes they handle:
          0x1c4070L, 0x1c4100L, 0x1c8e90L, 0x1c8ea0L, 0x1c8eb0L, 0x1c91d0L,
          0x1c9030L, 0x1c92d0L, 0x1c95e0L, 0x1c4730L, 0x1c4690L, 0x1c4960L,
          0x1c4d40L, 0x1c45f0L, 0x1c4360L, 0x1c4450L, 0x1c6e80L, 0x1c7680L,
          0x1c70b0L, 0x1c7a70L, 0x1c8790L, 0x1c5a20L, 0x1c6840L, 0x1c67a0L,
        };
        java.util.Set<Long> seen = new java.util.HashSet<>();
        for (long t : targets) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            long entry = fn.getEntryPoint().getOffset();
            if (!seen.add(entry)) continue;
            long size = fn.getBody().getMaxAddress().getOffset() - entry + 1;
            println("\n========== " + fn.getName() + " @ " + fn.getEntryPoint() + "  size=0x" + Long.toHexString(size) + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) {
                String c = r.getDecompiledFunction().getC();
                String[] lines = c.split("\n");
                int max = Math.min(lines.length, 60);
                for (int i = 0; i < max; i++) println(lines[i]);
                if (lines.length > max) println("... (+" + (lines.length-max) + " more)");
            }
        }
        ifc.dispose();
    }
}
