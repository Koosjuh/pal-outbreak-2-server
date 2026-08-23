import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class FindSifStateUsers extends GhidraScript {
    private static final long[] TARGETS = {
        0x002098b0L,
        0x0011aeb0L,
        0x00115300L,
        0x00114ba0L
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
            Function direct = getFunctionAt(addr);
            if (direct != null) {
                println("FUNCTION: " + direct.getName() + " @ " + direct.getEntryPoint());
                DecompileResults results = ifc.decompileFunction(direct, 90, monitor);
                if (results.decompileCompleted()) {
                    println(results.getDecompiledFunction().getC());
                } else {
                    println("decompile failed");
                }
                println("");
            }

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
                if (dumped.add(fn.getEntryPoint()) && (direct == null || !fn.getEntryPoint().equals(direct.getEntryPoint()))) {
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
