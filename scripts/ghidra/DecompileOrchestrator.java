// Full decompile of FUN_001b42e0 (orchestrator) + FUN_001b7b50 (message setup),
// AND raw disassembly around 0x001b7c00..0x001b7d00 to see the 3 conditional
// FUN_001c0020 call sites' guards.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

public class DecompileOrchestrator extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setSimplificationStyle("decompile");

        // 1) Full decompile of FUN_001b42e0
        decompileFull(ifc, 0x001b42e0L);

        // 2) Full decompile of FUN_001b7b50 (with longer timeout)
        decompileFull(ifc, 0x001b7b50L);

        // 3) Raw disassembly of FUN_001b7b50 around 0x7c00..0x7d00 (the tail)
        println("============================================================");
        println("=== Raw disassembly FUN_001b7b50 tail (0x001b7be0..0x001b7cb0) ===");
        InstructionIterator it = currentProgram.getListing().getInstructions(toAddr(0x001b7be0L), true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            long addr = ins.getAddress().getOffset();
            if (addr > 0x001b7cb0L) break;
            // Mark known FUN_001c0020 call sites
            String marker = "";
            if (addr == 0x001b7c18L || addr == 0x001b7c3cL || addr == 0x001b7c8cL) {
                marker = "  ★★★ FUN_001c0020 CALL SITE";
            }
            println(String.format("  %08x  %-30s %s%s",
                    addr, ins.toString(), ins.getMnemonicString(), marker));
        }

        ifc.dispose();
    }

    void decompileFull(DecompInterface ifc, long addr) throws Exception {
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(addr));
        if (fn == null) {
            println("NO FUNCTION at 0x" + Long.toHexString(addr));
            return;
        }
        println("============================================================");
        println("=== " + fn.getName() + " @ " + fn.getEntryPoint() + " body=" + fn.getBody() + " ===");
        DecompileResults res = ifc.decompileFunction(fn, 180, monitor);
        if (res != null && res.decompileCompleted()) {
            println(res.getDecompiledFunction().getC());
        } else {
            println("DECOMPILE FAILED: " + (res == null ? "null" : res.getErrorMessage()));
        }
    }
}
