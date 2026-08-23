import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileBootBridgeHelpers extends GhidraScript {
    private static final long[] TARGETS = {
        0x001154a0L,
        0x00119aa8L,
        0x0011a188L
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("TARGET " + addr);
            println("======================================================================");
            Function fn = getFunctionAt(addr);
            if (fn == null) {
                println("No function at " + addr);
                println("");
                continue;
            }
            println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
            DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
            if (results.decompileCompleted()) {
                println(results.getDecompiledFunction().getC());
            } else {
                println("decompile failed");
            }
            println("");
        }

        ifc.dispose();
    }
}
