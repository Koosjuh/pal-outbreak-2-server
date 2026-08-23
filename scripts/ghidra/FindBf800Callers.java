// Find what calls FUN_001bf800 — the handle-setup function that fires
// FUN_001c0020 from received SN@P data.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.HashSet;
import java.util.Set;

public class FindBf800Callers extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Set<Long> visited = new HashSet<>();
        walk(0x001bf800L, ifc, visited, 0);
        ifc.dispose();
    }
    void walk(long fnAddr, DecompInterface ifc, Set<Long> visited, int depth) throws Exception {
        if (depth > 3 || visited.contains(fnAddr)) return;
        visited.add(fnAddr);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(fnAddr));
        if (fn == null) return;
        String pad = "  ".repeat(depth);
        println(pad + "============================================================");
        println(pad + "[depth=" + depth + "] " + fn.getName() + " @ " + fn.getEntryPoint());
        if (depth <= 2) {
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                for (String line : res.getDecompiledFunction().getC().split("\\n")) println(pad + "  " + line);
            }
        }
        println(pad + "  --- callers ---");
        Set<Long> nextLevel = new HashSet<>();
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
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
        for (Long n : nextLevel) walk(n, ifc, visited, depth + 1);
    }
}
