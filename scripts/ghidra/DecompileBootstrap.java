// Decompile the network bootstrap functions that hold hardcoded URLs/hosts.
// FUN_001c2f80: refs boot URL + snap01 hostname
// FUN_001c2da0: refs app01 hostname

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class DecompileBootstrap extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001c2f80L, // bootstrap: holds /mhweb/index.jsp + snap01 string
        0x001c2da0L, // app01 holder
        0x001c2cc0L, 0x001c2c00L, // neighbors
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        for (long target : FUNCTIONS) {
            Address addr = toAddr(target);
            Function fn = getFunctionContaining(addr);
            if (fn == null) {
                println("============================================================");
                println("NO_FUNCTION at " + addr);
                continue;
            }
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() +
                    "  body=" + fn.getBody());
            DecompileResults res = ifc.decompileFunction(fn, 90, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }

            println("--- callers ---");
            ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
            while (it.hasNext()) {
                Reference r = it.next();
                Function caller = getFunctionContaining(r.getFromAddress());
                println("  <- " + r.getFromAddress() + " in " +
                        (caller == null ? "(no fn)" : caller.getName()) +
                        " (" + r.getReferenceType() + ")");
            }
        }
        ifc.dispose();
    }
}
