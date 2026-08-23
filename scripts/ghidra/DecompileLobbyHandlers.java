// Decompile the 02 65 XX (lobby data) and 02 61 XX (user/session) handler families.
// For each handler, identify:
//   - What input bytes it reads from the packet (offsets into param_1)
//   - What state it writes
//   - Any function calls that look like "advance to next state"

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileLobbyHandlers extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // Order matters — print 02 65 family first, then 02 61
        long[] handlers65 = {0x1c6e80L, 0x1c7680L, 0x1c70b0L, 0x1c7a70L, 0x1c8790L};
        String[] codes65 = {"02 65 01", "02 65 02", "02 65 03", "02 65 04", "02 65 10"};
        long[] handlers61 = {0x1c5a20L, 0x1c5c90L, 0x1c5f30L, 0x1c6130L, 0x1c63c0L, 0x1c65c0L, 0x1c6840L, 0x1c67a0L};
        String[] codes61 = {"02 61 01", "02 61 02", "02 61 03", "02 61 04", "02 61 05", "02 61 06", "02 61 10", "10 61 10"};

        println("\n################## 02 65 FAMILY (lobby data) ##################");
        for (int i = 0; i < handlers65.length; i++) decomp(ifc, handlers65[i], codes65[i]);
        println("\n################## 02 61 FAMILY (user/session) ##################");
        for (int i = 0; i < handlers61.length; i++) decomp(ifc, handlers61[i], codes61[i]);

        // Also: the session-verify challenge handler so we know the start of the chain
        println("\n################## 10 60 01 (session-verify challenge handler) ##################");
        decomp(ifc, 0x1c92d0L, "10 60 01");

        ifc.dispose();
    }

    void decomp(DecompInterface ifc, long addr, String code) throws Exception {
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(addr);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
        if (fn == null) { println("\n=== " + code + " @ 0x" + Long.toHexString(addr) + " — no fn ==="); return; }
        long size = fn.getBody().getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1;
        println("\n=== HANDLER " + code + "  " + fn.getName() + " @ " + fn.getEntryPoint() + "  size=0x" + Long.toHexString(size) + " ===");
        DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
        if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        else println("DECOMPILE_FAILED");
    }
}
