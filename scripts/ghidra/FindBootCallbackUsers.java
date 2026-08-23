import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

public class FindBootCallbackUsers extends GhidraScript {
    private static final long[] TARGETS = {
        0x0011d940L,
        0x0011da50L
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address targetAddr = toAddr(target);
            Function targetFn = getFunctionAt(targetAddr);
            println("======================================================================");
            println("TARGET " + targetAddr);
            println("======================================================================");
            if (targetFn == null) {
                println("No function at " + targetAddr);
                println("");
                continue;
            }
            println("FUNCTION: " + targetFn.getName() + " @ " + targetFn.getEntryPoint());

            Set<Address> seen = new HashSet<>();
            for (Reference ref : getReferencesTo(targetAddr)) {
                Address from = ref.getFromAddress();
                Function caller = getFunctionContaining(from);
                if (caller == null || !seen.add(caller.getEntryPoint())) {
                    continue;
                }
                println("");
                println("CALLER: " + caller.getName() + " @ " + caller.getEntryPoint());
                println("CALLSITE REF FROM: " + from);
                dumpNearby(from);
                decompile(ifc, caller);
            }
            println("");
        }

        ifc.dispose();
    }

    private void dumpNearby(Address callAddr) {
        println("NEARBY INSTRUCTIONS:");
        Instruction cur = getInstructionAt(callAddr);
        if (cur == null) {
            println("  no instruction");
            return;
        }
        Instruction start = cur;
        for (int i = 0; i < 12; i++) {
            Instruction prev = start.getPrevious();
            if (prev == null) {
                break;
            }
            start = prev;
        }
        Instruction ins = start;
        for (int i = 0; i < 30 && ins != null; i++) {
            String marker = ins.getAddress().equals(callAddr) ? ">>" : "  ";
            println(marker + " " + ins.getAddress() + ": " + ins);
            ins = ins.getNext();
        }
    }

    private void decompile(DecompInterface ifc, Function fn) {
        println("DECOMPILE:");
        DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
        if (!results.decompileCompleted()) {
            println("decompile failed");
            return;
        }
        println(results.getDecompiledFunction().getC());
    }
}
