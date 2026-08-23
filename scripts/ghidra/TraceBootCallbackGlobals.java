import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class TraceBootCallbackGlobals extends GhidraScript {

    private static final long[] TARGETS = {
        0x0026ba00L,
        0x0026ba04L
    };

    @Override
    public void run() throws Exception {
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();

        for (long vaddr : TARGETS) {
            Address addr = space.getAddress(vaddr);
            println("======================================================================");
            println(String.format("GLOBAL TARGET 0x%08x", vaddr));
            println("======================================================================");

            ReferenceIterator refs = rm.getReferencesTo(addr);
            boolean saw = false;
            while (refs.hasNext()) {
                saw = true;
                Reference ref = refs.next();
                Function func = fm.getFunctionContaining(ref.getFromAddress());
                println("REF from " + ref.getFromAddress() +
                    (func != null ? (" in " + func.getName() + " @ " + func.getEntryPoint()) : ""));
                if (func != null) {
                    DecompileResults result = decomp.decompileFunction(func, 120, monitor);
                    if (result.decompileCompleted()) {
                        println(result.getDecompiledFunction().getC());
                    } else {
                        println("Decompile failed: " + result.getErrorMessage());
                    }
                }
                println();
            }
            if (!saw) {
                println("NO DIRECT REFS");
            }
        }
    }
}
