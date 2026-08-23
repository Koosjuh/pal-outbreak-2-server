// Find every function whose decompile output references cRam0035a279
// (the trigger flag for the post-login state machine). One of these is
// who FLIPS it from 0 to 1 — the actual post-login activation.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class FindA279Writers extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int scanned = 0;
        while (fit.hasNext()) {
            Function fn = fit.next();
            DecompileResults res = ifc.decompileFunction(fn, 30, monitor);
            scanned++;
            if (res == null || !res.decompileCompleted()) continue;
            String c = res.getDecompiledFunction().getC();
            if (c.contains("35a279") || c.contains("35a278") || c.contains("0035a279") || c.contains("0035a278")) {
                println("============================================================");
                println("FN " + fn.getName() + " @ " + fn.getEntryPoint());
                println(c);
            }
            if (scanned % 500 == 0) println("(scanned " + scanned + " functions...)");
        }
        println("=== scan done: " + scanned + " functions ===");

        ifc.dispose();
    }
}
