// Decompile the helpers used by the FUN_001ee1e0 dispatcher and find what
// resets iRam0037a298 (the dispatcher result byte) so we know which path the
// game expects to clear after the post-nethttp transaction.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class DecompileEe1Helpers extends GhidraScript {

    private static final long[] FUNCTIONS = {
        0x001ee160L, // gate inside FUN_001ee1e0
        0x001eeb50L, // helper for param_1==2/3 path
        0x001eef00L, // helper for param_1==1 path
        0x001ef0d0L, // helper for param_1==1 secondary
        0x001ef1c0L, // helper sets iRam0037a298=2 when ==1
        0x001ee1a0L, // returns iRam0037a288 == 3 (already known)
    };

    private static final long[] WRITES_TO = {
        0x0037a288L, 0x0037a290L, 0x0037a298L,
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        for (long target : FUNCTIONS) {
            Address addr = toAddr(target);
            Function fn = getFunctionContaining(addr);
            if (fn == null) {
                println("============================================================");
                println("NO_FUNCTION at " + addr);
                continue;
            }
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint());
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }

        // Find every store instruction targeting 0x37a288/290/298 by scanning
        // all instructions for an effective address that resolves to those.
        println("============================================================");
        println("=== STORES TO 0x37a288/290/298 (instruction scan) ===");
        InstructionIterator iter = currentProgram.getListing().getInstructions(true);
        while (iter.hasNext()) {
            Instruction ins = iter.next();
            String mnem = ins.getMnemonicString();
            if (!mnem.startsWith("s")) continue;       // sw, sh, sb, sd
            if (mnem.equals("syscall") || mnem.equals("sync") || mnem.equals("slt") || mnem.equals("sll") || mnem.equals("srl") || mnem.equals("sra") || mnem.equals("sub") || mnem.equals("sllv") || mnem.equals("srlv") || mnem.equals("srav") || mnem.equals("subu") || mnem.equals("slti") || mnem.equals("sltiu") || mnem.equals("sltu")) continue;
            Reference[] refs = ins.getReferencesFrom();
            for (Reference r : refs) {
                if (r.getReferenceType().isWrite()) {
                    long off = r.getToAddress().getOffset();
                    for (long target : WRITES_TO) {
                        if (off == target) {
                            Function caller = getFunctionContaining(ins.getAddress());
                            String callerName = caller == null ? "(no fn)" : caller.getName();
                            println(String.format("STORE %s %s -> 0x%08x in %s @ %s",
                                    mnem, ins.toString(), off, callerName, ins.getAddress()));
                        }
                    }
                }
            }
        }

        ifc.dispose();
    }
}
