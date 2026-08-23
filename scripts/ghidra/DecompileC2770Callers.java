// Decompile callers of FUN_001c2770 (the browser state machine driver)
// to find the addresses of the state byte and timer they pass in.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileC2770Callers extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001c0f40L, // calls FUN_001c2770 at 0x001c196c
        0x001c19e0L, // calls FUN_001c2770 at 0x001c25f4
        0x001c2670L, // calls FUN_001c2770 at 0x001c270c
        0x001c0100L, // calls FUN_001c2770 at 0x001c01dc
        0x001eef50L, // state 0x06 success action
        0x001eef80L, // state 0x08 default action
        0x001eed60L, // state 0x06 alt action (flag=2)
        0x001eed90L, // state default helper
        0x001eeb30L, // state 0x03 helper
        0x001ef000L, // state 0x03 main action (likely sends HTTP)
        0x001eeec0L, // state 0x03 followup
        0x001ef070L, // state 0x05 advance helper
        0x001ef190L, // state 0x04 gate
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
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }
        ifc.dispose();
    }
}
