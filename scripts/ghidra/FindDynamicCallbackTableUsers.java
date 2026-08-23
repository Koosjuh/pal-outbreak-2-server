import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class FindDynamicCallbackTableUsers extends GhidraScript {
    private static final long[] TARGETS = {
        0x0020af88L,
        0x0020af8cL
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        Set<Address> dumped = new HashSet<>();
        for (long target : TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("TARGET " + addr);
            println("======================================================================");
            Reference[] refs = getReferencesTo(addr);
            if (refs.length == 0) {
                println("NO DIRECT REFS");
                println("");
                continue;
            }
            for (Reference ref : refs) {
                Function fn = getFunctionContaining(ref.getFromAddress());
                if (fn == null) {
                    println("REF from " + ref.getFromAddress() + " in <no function>");
                    continue;
                }
                println("REF from " + ref.getFromAddress() + " in " + fn.getName() +
                    " @ " + fn.getEntryPoint());
                if (dumped.add(fn.getEntryPoint())) {
                    println("");
                    println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
                    DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
                    if (results.decompileCompleted()) {
                        println(results.getDecompiledFunction().getC());
                    } else {
                        println("decompile failed");
                    }
                    println("");
                }
            }
            println("");
        }

        ifc.dispose();
    }
}
