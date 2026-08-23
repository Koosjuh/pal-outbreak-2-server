// Find every caller of FUN_001ef310 (the only SNIOPINT-bridge init function in main EE).
// If this function is never called from active game logic, SNIOPINT is never initialized
// → which explains why no SN@P happens.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.*;

public class FindCallersOf1ef310 extends GhidraScript {
    DecompInterface ifc;
    Set<Long> seen = new HashSet<>();

    @Override
    public void run() throws Exception {
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        walk(0x1ef310L, 0);
        ifc.dispose();
    }

    void walk(long addr, int depth) throws Exception {
        if (depth > 3) return;
        if (!seen.add(addr * 100 + depth)) return;
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(addr);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
        if (fn == null) return;
        String indent = "  ".repeat(depth);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
        Set<Function> callers = new LinkedHashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function c = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (c != null && !c.getEntryPoint().equals(fn.getEntryPoint())) callers.add(c);
        }
        println(indent + "[d=" + depth + "] " + fn.getName() + " @ " + fn.getEntryPoint() + "  ←  " + callers.size() + " caller(s)");
        for (Function c : callers) println(indent + "    ← " + c.getName() + " @ " + c.getEntryPoint());
        if (depth <= 2) {
            for (Function c : callers) {
                println("\n" + indent + "---- " + c.getName() + " ----");
                DecompileResults r = ifc.decompileFunction(c, 60, monitor);
                if (r != null && r.decompileCompleted()) {
                    String code = r.getDecompiledFunction().getC();
                    String[] lines = code.split("\n");
                    int max = Math.min(lines.length, 50);
                    for (int i = 0; i < max; i++) println(indent + lines[i]);
                    if (lines.length > max) println(indent + "... (+" + (lines.length-max) + " more)");
                }
                walk(c.getEntryPoint().getOffset(), depth + 1);
            }
        }
    }
}
