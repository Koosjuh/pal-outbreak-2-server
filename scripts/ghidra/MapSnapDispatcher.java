// Find SN@P packet dispatcher. Two known handlers:
//   0x1c95e0 — cmd 02 60 02 ("Go Online")
//   0x1c4730 — cmd 02 62 10 (state-7 confirm)
// Find the function that CALLS both — that's the dispatcher. From the dispatcher,
// extract ALL handler addresses + packet codes — the complete protocol surface.

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

public class MapSnapDispatcher extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        long[] handlers = {0x1c95e0L, 0x1c4730L};

        // Find callers of each handler — intersect to find the dispatcher
        Set<Function> callers0 = callersOf(handlers[0]);
        Set<Function> callers1 = callersOf(handlers[1]);
        println("=== Callers of 0x1c95e0 (cmd 02 60 02) ===");
        for (Function f : callers0) println("  " + f.getName() + " @ " + f.getEntryPoint());
        println("\n=== Callers of 0x1c4730 (cmd 02 62 10) ===");
        for (Function f : callers1) println("  " + f.getName() + " @ " + f.getEntryPoint());

        Set<Function> common = new LinkedHashSet<>(callers0);
        common.retainAll(callers1);
        println("\n=== Common callers (likely dispatcher) ===");
        for (Function f : common) println("  ★ " + f.getName() + " @ " + f.getEntryPoint());

        // Decompile each common caller
        for (Function fn : common) {
            println("\n========== " + fn.getName() + " @ " + fn.getEntryPoint() + " size=0x" + Long.toHexString(fn.getBody().getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1) + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 120, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
            else println("DECOMPILE_FAILED");

            // Extract every JAL target in this function — those are all packet handlers
            println("\n  JAL targets (potential handlers):");
            InstructionIterator iit = currentProgram.getListing().getInstructions(fn.getBody(), true);
            Set<Long> targets = new TreeSet<>();
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                String mn = ins.getMnemonicString();
                if (mn.equals("jal") || mn.equals("_jal")) {
                    for (Reference ref : ins.getReferencesFrom()) {
                        targets.add(ref.getToAddress().getOffset());
                    }
                }
            }
            for (Long t : targets) {
                Function f = currentProgram.getFunctionManager().getFunctionAt(currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t));
                println(String.format("    0x%08x  %s", t, f != null ? f.getName() : "(no fn)"));
            }
        }

        // Also decompile the two known handlers themselves
        for (long h : handlers) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(h);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            println("\n========== HANDLER " + fn.getName() + " @ " + fn.getEntryPoint() + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }
        ifc.dispose();
    }

    private Set<Function> callersOf(long addr) {
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(addr);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(a);
        Set<Function> out = new LinkedHashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function f = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (f != null) out.add(f);
        }
        return out;
    }
}
