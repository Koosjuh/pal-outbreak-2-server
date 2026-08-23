// Decompile EE FUN_0x115a98 (called from 3.DAT overlay with a1=0x80001101).
// Also decompile FUN_0x115e60 (the polling function called after).
// Also dump strings/data near the call site and look for any SIF/IOP related markers.
// Goal: identify whether 0x80001101 is a sceSifBindRpc service ID, a device handle,
// an event flag, or something else entirely.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressFactory;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.*;

public class DecompileEe115a98 extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        AddressFactory af = currentProgram.getAddressFactory();

        // Memory blocks
        println("=== Memory blocks ===");
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            println(String.format("  %-24s 0x%08x..0x%08x size=0x%x init=%b exec=%b",
                b.getName(), b.getStart().getOffset(), b.getEnd().getOffset(),
                b.getSize(), b.isInitialized(), b.isExecute()));
        }

        // Decompile FUN_0x115a98 and 0x115e60
        long[] targets = {0x115a98L, 0x115e60L};
        for (long t : targets) {
            Address a = af.getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) {
                println("\n!!! No function found at 0x" + Long.toHexString(t));
                // try to create one
                fn = createFunction(a, null);
                if (fn == null) { println("    couldn't create"); continue; }
            }
            println("\n========== FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() + " body=" + fn.getBody() + " ==========");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) {
                println(r.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }

        // Find every JAL targeting 0x115a98 across the whole program — show their calling context
        println("\n=== Callers of FUN_0x115a98 ===");
        Address target = af.getDefaultAddressSpace().getAddress(0x115a98L);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(target);
        Set<Function> seen = new HashSet<>();
        int total = 0;
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function caller = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (caller != null && seen.add(caller)) {
                println(String.format("  caller %s @ %s  (call site %s)", caller.getName(), caller.getEntryPoint(), ref.getFromAddress()));
            }
            total++;
        }
        println("  total references: " + total);

        // For each caller, decompile (limit to 8)
        int n = 0;
        for (Function caller : seen) {
            if (n++ >= 8) break;
            println("\n---- CALLER " + caller.getName() + " ----");
            DecompileResults r = ifc.decompileFunction(caller, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }

        // Also: scan callers of FUN_0x115a98 for the constant 0x80001101 and report which one(s) use it
        println("\n=== Which calls to FUN_0x115a98 pass a1=0x80001101 ===");
        rit = currentProgram.getReferenceManager().getReferencesTo(target);
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Address callSite = ref.getFromAddress();
            // Look backward up to 32 instructions to find lui+ori producing 0x80001101 into $a1
            long ones = scanBackwardForA1Value(callSite, 32, 0x80001101L);
            println(String.format("  call @ %s  -> $a1 value backward-traced: %s",
                callSite, ones == -1 ? "NOT 0x80001101" : "0x" + Long.toHexString(ones)));
        }

        // Look for sceSifBindRpc-like signatures: a function that takes (clientData*, sid, mode)
        // and is called with a constant in the second arg. Search for any call site in the entire
        // program where a1 is loaded with a value in 0x80000000-0x90000000 range and the called
        // function has the right shape.

        ifc.dispose();
    }

    private long scanBackwardForA1Value(Address callSite, int maxBack, long matchVal) throws Exception {
        // Step back through instructions, look for lui+ori/addiu pair targeting $a1 (rt=5)
        var listing = currentProgram.getListing();
        Address pc = callSite;
        // Find most recent lui $a1 going backward
        long highVal = -1;
        Address luiAddr = null;
        for (int i = 0; i <= maxBack; i++) {
            pc = pc.subtract(4);
            Instruction ins = listing.getInstructionAt(pc);
            if (ins == null) continue;
            String mn = ins.getMnemonicString();
            if ((mn.equals("lui") || mn.equals("_lui")) && ins.getOpObjects(0).length > 0) {
                Object rt = ins.getOpObjects(0)[0];
                String rtStr = rt.toString();
                if (rtStr.contains("a1")) {
                    Object[] imm = ins.getOpObjects(1);
                    if (imm.length > 0 && imm[0] instanceof Scalar) {
                        highVal = ((Scalar)imm[0]).getUnsignedValue() << 16;
                        luiAddr = pc;
                        break;
                    }
                }
            }
        }
        if (luiAddr == null) return -1;
        // Now scan forward from luiAddr+4 to callSite for ori/addiu $a1, $a1, imm
        long val = -1;
        Address scanPc = luiAddr.add(4);
        while (!scanPc.equals(callSite)) {
            Instruction ins = listing.getInstructionAt(scanPc);
            if (ins == null) { scanPc = scanPc.add(4); continue; }
            String mn = ins.getMnemonicString();
            if ((mn.equals("ori") || mn.equals("addiu")) && ins.getOpObjects(0).length > 0) {
                if (ins.getOpObjects(0)[0].toString().contains("a1")) {
                    Object[] imm = ins.getOpObjects(2);
                    if (imm.length > 0 && imm[0] instanceof Scalar) {
                        long lo = ((Scalar)imm[0]).getValue();
                        if (mn.equals("ori")) {
                            val = (highVal | (lo & 0xffff)) & 0xffffffffL;
                        } else {
                            val = (highVal + ((short)lo & 0xffffffffL)) & 0xffffffffL;
                        }
                        break;
                    }
                }
            }
            scanPc = scanPc.add(4);
        }
        if (val == matchVal) return val;
        return val == -1 ? -1 : (val & 0xffffffffL);
    }
}
