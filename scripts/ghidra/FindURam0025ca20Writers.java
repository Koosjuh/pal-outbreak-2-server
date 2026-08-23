// Find every write to uRam0025ca20 in the EE binary. The value stored is the IOP RAM
// address where the custom message-bus listener resides. Knowing this address tells us
// what IOP code is processing the game's network messages.

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

public class FindURam0025ca20Writers extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address target = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x25ca20L);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(target);
        Set<Function> writerFns = new LinkedHashSet<>();
        Set<Function> readerFns = new LinkedHashSet<>();
        println("=== References to 0x0025ca20 ===");
        while (rit.hasNext()) {
            Reference ref = rit.next();
            String type = ref.getReferenceType().toString();
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            String fname = fn != null ? fn.getName() : "(no fn)";
            println(String.format("  %s @ %s in %s", type, ref.getFromAddress(), fname));
            if (fn == null) continue;
            // Look at the instruction at the reference to see if it's a write (sw / sh / sb)
            Instruction ins = currentProgram.getListing().getInstructionAt(ref.getFromAddress());
            if (ins != null) {
                String mn = ins.getMnemonicString();
                if (mn.startsWith("s") && (mn.equals("sw") || mn.equals("sh") || mn.equals("sb") || mn.equals("sd"))) {
                    writerFns.add(fn);
                } else {
                    readerFns.add(fn);
                }
            }
        }

        // Decompile writers
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        println("\n=== WRITERS of uRam0025ca20 ===");
        for (Function fn : writerFns) {
            println("\n---- " + fn.getName() + " @ " + fn.getEntryPoint() + " ----");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }

        println("\n=== READERS (top 5) ===");
        int n = 0;
        for (Function fn : readerFns) {
            if (n++ >= 5) break;
            println("\n---- " + fn.getName() + " ----");
            DecompileResults r = ifc.decompileFunction(fn, 30, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }
        ifc.dispose();
    }
}
