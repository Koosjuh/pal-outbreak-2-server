// Find callers of FUN_001c0020 — the activator that flips cRam0035a279 = 1
// to start the post-login state machine. The caller chain leads back to
// what HTML/event triggers "go online" in the in-game browser.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.HashSet;
import java.util.Set;

public class FindC0020Callers extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // Walk caller chain up to 3 levels deep.
        Set<Long> visited = new HashSet<>();
        walk(0x001c0020L, ifc, visited, 0);

        ifc.dispose();
    }

    void walk(long fnAddr, DecompInterface ifc, Set<Long> visited, int depth) throws Exception {
        if (depth > 3 || visited.contains(fnAddr)) return;
        visited.add(fnAddr);

        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(fnAddr));
        if (fn == null) return;

        String pad = "  ".repeat(depth);
        println(pad + "============================================================");
        println(pad + "[depth=" + depth + "] FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint());

        DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
        if (res != null && res.decompileCompleted()) {
            for (String line : res.getDecompiledFunction().getC().split("\\n")) {
                println(pad + "  " + line);
            }
        }

        println(pad + "  --- callers ---");
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
        Set<Long> nextLevel = new HashSet<>();
        while (it.hasNext()) {
            Reference r = it.next();
            Function caller = getFunctionContaining(r.getFromAddress());
            if (caller != null) {
                println(pad + "    <- " + r.getFromAddress() + " in " + caller.getName());
                nextLevel.add(caller.getEntryPoint().getOffset());
            } else {
                println(pad + "    <- " + r.getFromAddress() + " (no fn)");
            }
        }
        for (Long next : nextLevel) walk(next, ifc, visited, depth + 1);
    }
}
