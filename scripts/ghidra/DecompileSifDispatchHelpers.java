import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class DecompileSifDispatchHelpers extends GhidraScript {
    private static final long[] TARGETS = {
        0x00112d20L,
        0x00112cb0L,
        0x00112b70L
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
            println("");
            println("DECOMPILE:");
            DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
            if (results.decompileCompleted()) {
                println(results.getDecompiledFunction().getC());
            } else {
                println("decompile failed");
            }

            println("");
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
}
