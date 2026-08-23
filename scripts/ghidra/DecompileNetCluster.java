// Decompile FUN_0x0017ee60 (sends msg_ids 0x80001300, 0x8000131b, 0x8000131c).
// Then walk callers up 2 levels — what state must be true to reach this function?
// Then identify any string refs (URLs/keys) inside this code.

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

public class DecompileNetCluster extends GhidraScript {
    DecompInterface ifc;
    Set<Long> seen = new HashSet<>();

    @Override
    public void run() throws Exception {
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // 1. Decompile target function fully
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x17ee60L);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
        if (fn == null) { println("no function"); return; }
        println("========== TARGET FUN_0017ee60 @ " + fn.getEntryPoint() + " size=0x" + Long.toHexString(fn.getBody().getMaxAddress().getOffset()-fn.getEntryPoint().getOffset()+1) + " ==========");
        DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
        if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        seen.add(fn.getEntryPoint().getOffset());

        // 2. Find string refs from this function
        println("\n=== Strings referenced from FUN_0017ee60 (within body) ===");
        InstructionIterator iit = currentProgram.getListing().getInstructions(fn.getBody(), true);
        while (iit.hasNext()) {
            Instruction ins = iit.next();
            for (Reference ref : ins.getReferencesFrom()) {
                Address to = ref.getToAddress();
                if (to.getOffset() < 0x100000 || to.getOffset() > 0x300000) continue;
                // Try to read string at this address
                try {
                    byte[] bytes = new byte[80];
                    currentProgram.getMemory().getBytes(to, bytes);
                    StringBuilder s = new StringBuilder();
                    for (int i = 0; i < bytes.length; i++) {
                        byte b = bytes[i];
                        if (b == 0) break;
                        if (b >= 0x20 && b < 0x7f) s.append((char)b);
                        else { s.setLength(0); break; }
                    }
                    if (s.length() >= 4) println("  " + to + " from " + ins.getAddress() + ": \"" + s + "\"");
                } catch (Exception e) {}
            }
        }

        // 3. Walk callers up to depth 2
        println("\n=== Caller tree (depth 2) ===");
        walkCallers(fn, 0);

        ifc.dispose();
    }

    private void walkCallers(Function fn, int depth) throws Exception {
        if (depth >= 3) return;
        if (!seen.add(fn.getEntryPoint().getOffset() + depth * 0x100000000L)) return; // allow re-visit at diff depth
        StringBuilder indent = new StringBuilder();
        for (int i = 0; i < depth; i++) indent.append("  ");
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
        Set<Function> callers = new LinkedHashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function c = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (c != null && !c.getEntryPoint().equals(fn.getEntryPoint())) callers.add(c);
        }
        println(indent + "FUN_" + fn.getEntryPoint() + " ← " + callers.size() + " caller(s)");
        for (Function caller : callers) {
            println(indent + "  ← " + caller.getName() + " @ " + caller.getEntryPoint());
        }
        // Decompile each caller at depth 0 & 1
        if (depth <= 1) {
            for (Function caller : callers) {
                if (caller.getEntryPoint().equals(fn.getEntryPoint())) continue;
                println("\n" + indent + "----[depth " + (depth+1) + "] " + caller.getName() + " @ " + caller.getEntryPoint() + " ----");
                DecompileResults r = ifc.decompileFunction(caller, 60, monitor);
                if (r != null && r.decompileCompleted()) {
                    String c = r.getDecompiledFunction().getC();
                    String[] lines = c.split("\n");
                    int max = Math.min(lines.length, 70);
                    for (int i = 0; i < max; i++) println(indent + lines[i]);
                    if (lines.length > max) println(indent + "... (" + (lines.length-max) + " more lines)");
                }
                walkCallers(caller, depth + 1);
            }
        }
    }
}
