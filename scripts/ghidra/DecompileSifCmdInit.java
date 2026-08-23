// Decompile the SIF cmd subsystem init functions around 0x114c00-0x115180.
// These manage the struct at 0x25CA00 which contains uRam0025ca20 (the IOP listener addr).

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileSifCmdInit extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        long[] targets = {0x114c00L, 0x114d30L, 0x114e30L, 0x114f18L, 0x115100L, 0x115150L,
                          0x114d44L, 0x114d98L, 0x114dacL, 0x115420L};  // also sceSifInitCmd callers
        java.util.Set<Long> seenEntries = new java.util.HashSet<>();
        for (long t : targets) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            long entry = fn.getEntryPoint().getOffset();
            if (!seenEntries.add(entry)) continue;
            println("\n========== " + fn.getName() + " @ " + fn.getEntryPoint() + "  size=0x" + Long.toHexString(fn.getBody().getMaxAddress().getOffset()-entry+1) + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }
        ifc.dispose();
    }
}
