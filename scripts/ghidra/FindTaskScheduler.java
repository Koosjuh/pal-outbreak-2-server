// Find the task scheduler that dispatches entries in the table at 0x337ac0.
// FUN_001af7a0 puts (type, callback) into slot N. Some scheduler must read
// each slot's type and dispatch the callback.
//
// Also: examine 0x5ac380 — is this a function in the main ELF, or in unmapped
// memory (overlay-loaded code)?

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;

public class FindTaskScheduler extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // 1. What's at 0x5ac380? Is it mapped/code/data?
        println("=== Probing 0x005ac380 ===");
        Address callback = toAddr(0x005ac380L);
        boolean inMem = false;
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.contains(callback)) {
                inMem = true;
                println("  in block: " + b.getName() +
                        "  initialized=" + b.isInitialized() +
                        "  exec=" + b.isExecute() +
                        "  read=" + b.isRead() +
                        "  write=" + b.isWrite());
                break;
            }
        }
        if (!inMem) println("  NOT IN ANY MAPPED BLOCK — overlay/heap-loaded");
        Function fnAt = getFunctionAt(callback);
        println("  function at: " + (fnAt == null ? "NONE" : fnAt.getName()));
        Function fnContaining = getFunctionContaining(callback);
        println("  function containing: " + (fnContaining == null ? "NONE" : fnContaining.getName()));

        if (inMem) {
            try {
                int v = currentProgram.getMemory().getInt(callback);
                println(String.format("  value at 0x5ac380 = 0x%08x", v & 0xFFFFFFFFL));
            } catch (Exception e) { println("  cannot read: " + e.getMessage()); }
        }

        // 2. Search for functions referencing 0x337ac0 (the task table)
        // and 0x245808 (the flag). These are likely the scheduler.
        println("\n=== Functions referencing 0x337ac0 (task table) or 0x245808 (flag) ===");
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int hits = 0;
        while (fit.hasNext()) {
            Function fn = fit.next();
            DecompileResults res = ifc.decompileFunction(fn, 30, monitor);
            if (res == null || !res.decompileCompleted()) continue;
            String c = res.getDecompiledFunction().getC();
            boolean hitTbl = c.contains("337ac0") || c.contains("337ac4") || c.contains("337ad4");
            boolean hitFlag = c.contains("245808") || c.contains("245810");
            if (hitTbl || hitFlag) {
                println("============================================================");
                println("FN " + fn.getName() + " @ " + fn.getEntryPoint() +
                        (hitTbl ? "  [TASK TABLE]" : "") + (hitFlag ? "  [FLAG]" : ""));
                println(c);
                hits++;
                if (hits > 12) { println("(truncated)"); break; }
            }
        }
        println("\n=== scan done: " + hits + " hits ===");

        ifc.dispose();
    }
}
