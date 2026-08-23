import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class DecompileNameHelpers extends GhidraScript {
    private static final long[] TARGETS = {
        0x001384c8L,
        0x00138c80L
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
            decompile(ifc, fn);

            println("CALLERS:");
            Set<Address> seen = new HashSet<>();
            for (Reference ref : getReferencesTo(addr)) {
                Function caller = getFunctionContaining(ref.getFromAddress());
                if (caller == null || !seen.add(caller.getEntryPoint())) {
                    continue;
                }
                println("- " + caller.getName() + " @ " + caller.getEntryPoint() +
                    " via " + ref.getFromAddress());
            }
            println("");
        }

        ifc.dispose();
    }

    private void decompile(DecompInterface ifc, Function fn) {
        println("");
        println("DECOMPILE:");
        DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
        if (!results.decompileCompleted()) {
            println("decompile failed");
            return;
        }
        println(results.getDecompiledFunction().getC());
        println("");
    }
}
