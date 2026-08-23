// Decompile the three structural functions: FUN_00003380 (init),
// FUN_0000344c (shutdown), FUN_00002d80 (RPC server thread). Also FUN_00000280
// (largest function — probably contains the actual RegisterRpc call).
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileIopCore extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        long[] targets = {
            0x3380L, 0x344cL, 0x2d80L, 0x0280L,
            0x00b8L, 0x0140L, 0x01c8L, 0x0498L,
            0x06c8L, 0x0760L,    // op 0x05 (avetcp[0x24]) and op 0x06 (avetcp[0x20]) handlers
            0x0794L              // op 0x00 handler
        };
        for (long t : targets) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) {
                println("missing fn @ 0x" + Long.toHexString(t));
                continue;
            }
            println("\n====== " + fn.getName() + " @ " + fn.getEntryPoint() + " ======");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
            else println("DECOMPILE_FAILED");
        }
        ifc.dispose();
    }
}
