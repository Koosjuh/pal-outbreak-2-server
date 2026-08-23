// Decompile the FUN_001bb1e0/310/440/560/710 handlers — the OTHER callers
// of FUN_001b7b50 (besides FUN_001b42e0 state 0xc). One of these likely
// processes the post-LBS / SN@P-success message that triggers
// FUN_001c0020 → cRam0035a279=1.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class DecompileBbHandlers extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001bb1e0L, 0x001bb310L, 0x001bb440L, 0x001bb560L, 0x001bb710L,
        0x001bf800L, // also a direct caller of FUN_001c0020
        0x001b7b50L, // the common forwarder
        0x001b7ff0L, // calls 4 of the bb* handlers (per earlier output)
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
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint());
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            }
            println("--- callers ---");
            ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
            while (it.hasNext()) {
                Reference r = it.next();
                Function caller = getFunctionContaining(r.getFromAddress());
                println("  <- " + r.getFromAddress() + " in " +
                        (caller == null ? "(no fn)" : caller.getName()));
            }
        }
        ifc.dispose();
    }
}
