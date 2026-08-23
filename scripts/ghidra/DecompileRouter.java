// Decompile FUN_0x114f50 (lowest-level message router) and everything it directly calls,
// recursively up to depth 3. Look for any IOP/SIF/DMA register access or SIF RPC patterns.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import java.util.*;

public class DecompileRouter extends GhidraScript {
    static final int MAX_DEPTH = 3;
    Set<Long> seen = new HashSet<>();
    DecompInterface ifc;

    @Override
    public void run() throws Exception {
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        long entry = 0x114f50L;
        decompileRec(entry, 0);

        // Also: scan FUN_0x114f50's deepest callees for any access to IOP-mapped memory
        // (PS2 EE: 0x1C000000-0x1DFFFFFF = IOP RAM; 0x10000000+ = registers; SIF DMA regs are 0x10008000+)
        println("\n=== Searching for IOP RAM / SIF DMA register accesses in router subtree ===");
        for (Long fnAddr : seen) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(fnAddr);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            InstructionIterator iit = currentProgram.getListing().getInstructions(fn.getBody(), true);
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                String mn = ins.getMnemonicString();
                // Detect lui with high half in IOP/SIF region
                if (mn.equals("lui") || mn.equals("_lui")) {
                    Object[] ops = ins.getOpObjects(1);
                    if (ops.length > 0 && ops[0] instanceof Scalar) {
                        long hi = ((Scalar)ops[0]).getUnsignedValue();
                        // Look for SIF DMA registers: 0x10008000..0x1000bfff;
                        // SBUS regs: 0x1000F200..0x1000F2FF
                        // IOP RAM access: 0x1C000000+
                        if (hi == 0x1000 || hi == 0x1c00 || hi == 0xbc00 || hi == 0x1d00) {
                            println(String.format("  %s @ %s in %s: lui 0x%x (IOP/SIF-related!)",
                                mn, ins.getAddress(), fn.getName(), hi));
                        }
                    }
                }
            }
        }

        ifc.dispose();
    }

    void decompileRec(long addr, int depth) throws Exception {
        if (depth > MAX_DEPTH) return;
        if (!seen.add(addr)) return;
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(addr);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
        if (fn == null) { println("  [no fn at 0x" + Long.toHexString(addr) + "]"); return; }
        long size = fn.getBody().getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1;
        StringBuilder indent = new StringBuilder();
        for (int i = 0; i < depth; i++) indent.append("  ");
        println("\n" + indent + "========== [depth " + depth + "] " + fn.getName() + " @ " + fn.getEntryPoint() + "  size=0x" + Long.toHexString(size) + " ==========");

        DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
        if (r != null && r.decompileCompleted()) {
            String c = r.getDecompiledFunction().getC();
            // Print only the first 60 lines of large functions
            String[] lines = c.split("\n");
            int max = Math.min(lines.length, 80);
            for (int i = 0; i < max; i++) println(indent + lines[i]);
            if (lines.length > max) println(indent + "... (" + (lines.length - max) + " more lines)");
        }

        // Find callees (jal targets in this function)
        Set<Long> callees = new TreeSet<>();
        InstructionIterator iit = currentProgram.getListing().getInstructions(fn.getBody(), true);
        while (iit.hasNext()) {
            Instruction ins = iit.next();
            String mn = ins.getMnemonicString();
            if (mn.equals("jal") || mn.equals("_jal")) {
                for (Reference ref : ins.getReferencesFrom()) {
                    callees.add(ref.getToAddress().getOffset());
                }
            }
        }
        // Recurse
        for (Long c : callees) decompileRec(c, depth + 1);
    }
}
