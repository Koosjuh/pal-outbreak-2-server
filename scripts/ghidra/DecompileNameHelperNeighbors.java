import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileNameHelperNeighbors extends GhidraScript {
    private static final long[] TARGETS = {
        0x00137aa8L,
        0x00139048L
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            Function fn = getFunctionAt(addr);
            println("======================================================================");
            println("TARGET " + addr);
            println("======================================================================");
            if (fn == null) {
                println("No function at " + addr);
                continue;
            }
            println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
            DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
            if (!results.decompileCompleted()) {
                println("decompile failed");
                continue;
            }
            println(results.getDecompiledFunction().getC());
            println("");
        }

        ifc.dispose();
    }
}
