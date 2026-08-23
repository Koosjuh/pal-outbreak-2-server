// Find function containing 0x1c0220 (which J's to 0x1bf5e0) — then trace its callers up.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.*;

public class TraceFromJ extends GhidraScript {
    DecompInterface ifc;
    Set<Long> seen = new HashSet<>();

    @Override
    public void run() throws Exception {
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Address jAddr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x1c0220L);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(jAddr);
        if (fn == null) { println("no function at 0x1c0220"); return; }
        println("J site 0x1c0220 is in: " + fn.getName() + " @ " + fn.getEntryPoint());
        walk(fn, 0);
    }

    void walk(Function fn, int depth) throws Exception {
        if (depth > 4) return;
        if (!seen.add(fn.getEntryPoint().getOffset())) return;
        String indent = "  ".repeat(depth);
        long size = fn.getBody().getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1;
        println("\n" + indent + "========== [d=" + depth + "] " + fn.getName() + " @ " + fn.getEntryPoint() + " size=0x" + Long.toHexString(size) + " ==========");
        DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
        if (r != null && r.decompileCompleted()) {
            String c = r.getDecompiledFunction().getC();
            String[] lines = c.split("\n");
            int max = Math.min(lines.length, 60);
            for (int i = 0; i < max; i++) println(indent + lines[i]);
            if (lines.length > max) println(indent + "... (+" + (lines.length-max) + " more)");
        }
        // Find callers
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
        Set<Function> callers = new LinkedHashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function c2 = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (c2 != null && !c2.getEntryPoint().equals(fn.getEntryPoint())) callers.add(c2);
        }
        println(indent + "  callers: " + callers.size());
        for (Function c2 : callers) println(indent + "    ← " + c2.getName() + " @ " + c2.getEntryPoint());
        for (Function c2 : callers) walk(c2, depth + 1);
    }
}
