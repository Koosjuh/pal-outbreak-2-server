// Find all callers of FUN_001c0100 (post-login outer state machine)
// and decompile each to find what triggers them.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class FindC0100Callers extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        Address target = toAddr(0x001c0100L);
        println("=== References to FUN_001c0100 ===");
        Set<Address> callerEntries = new HashSet<>();
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(target);
        while (it.hasNext()) {
            Reference r = it.next();
            Function caller = getFunctionContaining(r.getFromAddress());
            String name = caller == null ? "(no fn)" : caller.getName();
            println("  <- " + r.getFromAddress() + " in " + name + " (" + r.getReferenceType() + ")");
            if (caller != null) callerEntries.add(caller.getEntryPoint());
        }

        println("\n=== Decompile of each caller ===");
        for (Address e : callerEntries) {
            Function fn = currentProgram.getFunctionManager().getFunctionAt(e);
            if (fn == null) continue;
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() +
                    "  body=" + fn.getBody());
            DecompileResults res = ifc.decompileFunction(fn, 90, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            }
            println("--- callers of " + fn.getName() + " ---");
            ReferenceIterator it2 = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
            while (it2.hasNext()) {
                Reference r = it2.next();
                Function c = getFunctionContaining(r.getFromAddress());
                println("  <- " + r.getFromAddress() + " in " +
                        (c == null ? "(no fn)" : c.getName()) +
                        " (" + r.getReferenceType() + ")");
            }
        }

        ifc.dispose();
    }
}
