// Decompile the high-address callers of FUN_0x115a98 — likely the network senders.
// FUN_001f58b8 sends 0x80000400
// FUN_001f1fe0 sends 0x80000211
// FUN_001ef310 sends ? (NOT 0x80001101)
// FUN_0019dee0 sends ? (NOT 0x80001101)
// FUN_00137578 sends ? (NOT 0x80001101)
// Also FUN_00116a20 / 00119aa8 / 00119ff8 send 0x80000001/3/6 — system control
// Let's also include the cluster of callers FUN_00100838/b70/e88/1010a8/101388/101580/101640
// passing 0x80000592-9c — likely the same subsystem

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;

public class DecompileHighSenders extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        long[] targets = {
            // High-addr callers — likely network
            0x1f58b8L, 0x1f1fe0L, 0x1ef310L, 0x19dee0L, 0x137578L,
            // System control
            0x116a20L, 0x119aa8L, 0x119ff8L,
            // Cluster 0x80000592-9c
            0x100838L, 0x100b70L, 0x100e88L, 0x1010a8L, 0x101388L, 0x101580L, 0x1ee60L,
        };
        for (long t : targets) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(t);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            println("\n========== " + fn.getName() + " @ " + fn.getEntryPoint() + " size=0x" + Long.toHexString(fn.getBody().getMaxAddress().getOffset()-fn.getEntryPoint().getOffset()+1) + " ==========");
            // Print referenced strings
            InstructionIterator iit = currentProgram.getListing().getInstructions(fn.getBody(), true);
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                for (Reference ref : ins.getReferencesFrom()) {
                    Address to = ref.getToAddress();
                    long off = to.getOffset();
                    if (off < 0x100000 || off > 0x300000) continue;
                    try {
                        byte[] bytes = new byte[100];
                        currentProgram.getMemory().getBytes(to, bytes);
                        StringBuilder s = new StringBuilder();
                        for (int i = 0; i < bytes.length; i++) {
                            byte b = bytes[i];
                            if (b == 0) break;
                            if (b >= 0x20 && b < 0x7f) s.append((char)b);
                            else { s.setLength(0); break; }
                        }
                        if (s.length() >= 4) println("  STR @ " + to + ": \"" + s + "\"");
                    } catch (Exception e) {}
                }
            }
            // Decompile
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }
        ifc.dispose();
    }
}
