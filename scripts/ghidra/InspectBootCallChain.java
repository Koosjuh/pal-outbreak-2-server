import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

public class InspectBootCallChain extends GhidraScript {
    private static final long[] TARGETS = {
        0x00100008L, // entry
        0x0011bb88L, // boot helper dispatcher
        0x0011d898L  // last callee in current decompile
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("TARGET " + addr);
            println("======================================================================");

            Function fn = getFunctionAt(addr);
            if (fn == null) {
                println("No function at " + addr);
            } else {
                println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
                println("");
                println("DECOMPILE:");
                DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
                if (results.decompileCompleted()) {
                    println(results.getDecompiledFunction().getC());
                } else {
                    println("decompile failed");
                }
            }

            println("");
            println("DISASSEMBLY:");
            dumpInstructions(addr, 80);
            println("");
        }

        ifc.dispose();
    }

    private void dumpInstructions(Address start, int count) {
        Instruction cur = getInstructionAt(start);
        if (cur == null) {
            cur = getInstructionAfter(start);
        }
        for (int i = 0; i < count && cur != null; i++) {
            println(cur.getAddress() + ": " + cur);
            cur = cur.getNext();
        }
    }
}
