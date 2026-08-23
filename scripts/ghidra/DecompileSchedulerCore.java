// Decompile the EE-side scheduler core: FUN_00115088 (post), FUN_00115c68 (read response),
// FUN_001154c8 (slot alloc), FUN_00115570 (slot free), FUN_00115300, FUN_00115250.
// Also dump references to known IOP-side magic numbers and look for any SIF RPC patterns.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import java.util.*;

public class DecompileSchedulerCore extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        long[] targets = {0x115088L, 0x115c68L, 0x1154c8L, 0x115570L, 0x115300L, 0x115250L,
                          // The fixed scheduler target ID 0x80000009 — find where it gets handled
                          0x115a98L};

        for (long t : targets) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) { println("missing fn @ 0x" + Long.toHexString(t)); continue; }
            println("\n========== FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() + " size=0x" + Long.toHexString(fn.getBody().getMaxAddress().getOffset()-fn.getEntryPoint().getOffset()+1) + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
            else println("DECOMPILE_FAILED");
        }

        // Find calls to syscalls or SIF-related functions
        println("\n=== Searching for low-syscall numbers in entire program (these indicate sceSif* or SIF RPC) ===");
        // PS2 EE common syscalls related to SIF:
        // 0x76 (CdInit), 0x77, 0xC0-0xC5 (sif), 0xC6 (sceSifGetMSCmd), ...
        // PS2 EE specific: SIF RPC uses sif_send_cmd via Subscriber pattern
        // Detect: any "syscall N" instruction (op=0, fn=0xc) in the binary

        var fnIter = currentProgram.getFunctionManager().getFunctions(true);
        int found = 0;
        while (fnIter.hasNext() && found < 30) {
            Function f = fnIter.next();
            InstructionIterator iit = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                if (ins.getMnemonicString().equals("syscall")) {
                    long sc = -1;
                    Object[] ops = ins.getOpObjects(0);
                    if (ops.length > 0 && ops[0] instanceof Scalar) sc = ((Scalar)ops[0]).getValue();
                    println(String.format("  syscall @ %s in %s  code=0x%x", ins.getAddress(), f.getName(), sc));
                    found++;
                    if (found >= 30) break;
                }
            }
        }
    }
}
