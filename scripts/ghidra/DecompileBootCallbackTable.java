import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileBootCallbackTable extends GhidraScript {
    private static final long[] TARGETS = {
        0x0011d940L,
        0x0011da50L
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
            DecompileResults results = ifc.decompileFunction(fn, 120, monitor);
            if (!results.decompileCompleted()) {
                println("decompile failed");
                println("");
                continue;
            }
            println(results.getDecompiledFunction().getC());
            println("");
        }

        ifc.dispose();
    }
}
