// Decompile the post-nethttp handoff bridge in the main PAL EE ELF.
// Target: 0x001ee1c0 — where nethttp dispatcher states 0x0a (terminal success)
// and 0x0c jump after writing *(s0+0x68)=2. Neighbors 0x001ee1a0 and
// 0x001ee1e0 are called from the FUN_0019fd10 main loop.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.RefType;

public class DecompileEe1Bridge extends GhidraScript {

    private static final long[] TARGETS = {
        0x001ee1a0L, // called in FUN_0019fd10 main loop, returns advance flag
        0x001ee1c0L, // jump target from nethttp state 0x0a + 0x0c (THIS IS THE BRIDGE)
        0x001ee1e0L, // called in FUN_0019fd10 main loop, dispatch screen state
        0x001ee1c4L, // possible mid-function in case 0x1c0 is not a function start
        0x001ee100L, // surrounding context
        0x001ee150L,
        0x001ee200L,
        0x001ee250L,
        0x001ee2a0L,
        0x001ee300L,
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // 1. Decompile each target function (or the function containing it).
        for (long target : TARGETS) {
            Address addr = toAddr(target);
            Function fn = getFunctionContaining(addr);
            if (fn == null) {
                println("============================================================");
                println("NO_FUNCTION at " + addr + " — attempting createFunction");
                fn = createFunction(addr, "ee1_" + Long.toHexString(target));
                if (fn == null) {
                    println("could not create function at " + addr);
                    continue;
                }
            }
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() +
                    "  body=" + fn.getBody() + "  hit_addr=" + addr);
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED: " + (res == null ? "null result" : res.getErrorMessage()));
            }
        }

        // 2. List all references (callers / jumpers) into 0x001ee1c0.
        Address bridge = toAddr(0x001ee1c0L);
        println("============================================================");
        println("REFERENCES TO 0x001ee1c0:");
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(bridge);
        while (it.hasNext()) {
            Reference r = it.next();
            Address from = r.getFromAddress();
            Function caller = getFunctionContaining(from);
            String callerName = caller == null ? "(no fn)" : caller.getName();
            println("  REF from " + from + " in " + callerName + " type=" + r.getReferenceType());
        }

        // 3. List all references INTO functions in 0x001ee100-0x001ee400 range
        // (catches cross-references the inactive nethttp project couldn't see).
        println("============================================================");
        println("REFERENCES INTO 0x001ee100..0x001ee400:");
        long lo = 0x001ee100L, hi = 0x001ee400L;
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        while (fit.hasNext()) {
            Function fn = fit.next();
            long start = fn.getEntryPoint().getOffset();
            if (start >= lo && start < hi) {
                println("FN " + fn.getName() + " @ " + fn.getEntryPoint());
                ReferenceIterator rit = currentProgram.getReferenceManager()
                        .getReferencesTo(fn.getEntryPoint());
                while (rit.hasNext()) {
                    Reference r = rit.next();
                    Function caller = getFunctionContaining(r.getFromAddress());
                    println("    <- " + r.getFromAddress() +
                            " in " + (caller == null ? "(no fn)" : caller.getName()) +
                            " (" + r.getReferenceType() + ")");
                }
            }
        }

        ifc.dispose();
    }
}
