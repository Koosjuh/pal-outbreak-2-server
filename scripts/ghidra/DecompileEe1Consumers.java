// Decompile the functions that READ iRam0037a298 (post-nethttp dispatcher result).
// These tell us what advancing 0x37a298 from 0 to 2 actually triggers in the game.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileEe1Consumers extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001ee110L, // refs 37a290 37a288 37a278 37a280 — likely "init/reset" routine
        0x001ee360L, // refs 37a298 — primary consumer
        0x001ee6e0L, // refs 37a298 37a288
        0x001eeb00L, // refs 37a298 37a288
        0x001eee90L, // refs 37a298 37a288
        0x001ee190L, // refs 37a288
        0x001ee430L, 0x001ee560L, 0x001ee590L, // neighbors
        0x001ee650L, 0x001ee680L, 0x001ee5f0L, 0x001ee3f0L,
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
