// Analyze SNIOPINT.IRX (PS2 IOP module) — find:
// 1. Imports table (external symbols used — sif*, dma*, etc)
// 2. Exports table (functions this module provides)
// 3. All function decompiles
// 4. Calls to sif/RPC functions that suggest the dispatch path

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;

public class AnalyzeSnIopint extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // 1. List memory blocks
        println("=== Memory blocks ===");
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            println(String.format("  %-16s 0x%08x..0x%08x  size=0x%x  init=%s exec=%s",
                    b.getName(), b.getStart().getOffset(), b.getEnd().getOffset(),
                    b.getSize(), b.isInitialized(), b.isExecute()));
        }

        // 2. List symbols (often the IRX import/export names appear here)
        println("\n=== Symbols (top 80) ===");
        SymbolTable st = currentProgram.getSymbolTable();
        SymbolIterator sit = st.getAllSymbols(false);
        int count = 0;
        while (sit.hasNext() && count < 200) {
            Symbol s = sit.next();
            if (s.getSource().toString().equals("DEFAULT")) continue;
            println(String.format("  %-32s @ %s (%s)",
                    s.getName(), s.getAddress(), s.getSource()));
            count++;
        }

        // 3. Functions list
        println("\n=== Functions (all) ===");
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int fnCount = 0;
        while (fit.hasNext()) {
            Function fn = fit.next();
            println(String.format("  %s @ %s  body=%s", fn.getName(), fn.getEntryPoint(), fn.getBody()));
            fnCount++;
        }
        println("  total: " + fnCount);

        // 4. Decompile every function (file is small, only 22KB)
        println("\n=== Decompiles ===");
        fit = currentProgram.getFunctionManager().getFunctions(true);
        while (fit.hasNext()) {
            Function fn = fit.next();
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() + " body=" + fn.getBody());
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }

        ifc.dispose();
    }
}
