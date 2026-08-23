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

public class DecompileBootCallback extends GhidraScript {

    private static final long[] TARGETS = {
        0x00100220L,
        0x00100d78L,
        0x0011b8e0L,
        0x0011b938L
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
            Function func = fm.getFunctionContaining(addr);

            println("======================================================================");
            println(String.format("TARGET 0x%08x", vaddr));
            println("======================================================================");

            if (func == null) {
                println("NO FUNCTION CONTAINING TARGET");
                continue;
            }

            println(String.format("FUNCTION: %s @ %s", func.getName(), func.getEntryPoint()));
            println("-- REFERENCES TO ENTRY --");
            ReferenceIterator refs = rm.getReferencesTo(func.getEntryPoint());
            boolean saw = false;
            while (refs.hasNext()) {
                saw = true;
                Reference ref = refs.next();
                println("REF from " + ref.getFromAddress());
            }
            if (!saw) {
                println("NO DIRECT REFS");
            }

            println("-- DECOMPILE --");
            DecompileResults result = decomp.decompileFunction(func, 120, monitor);
            if (result.decompileCompleted()) {
                println(result.getDecompiledFunction().getC());
            } else {
                println("Decompile failed: " + result.getErrorMessage());
            }
            println();
        }
    }
}
