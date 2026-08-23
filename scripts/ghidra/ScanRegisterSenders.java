// Find every callsite of FUN_001e180c (AVE-TCP frame queue) with opcode = 0x2c
// (REGISTER) and dump the calling function + its callers chain.
//
// Also find any data-table containing pointers to known sender functions —
// this is where 0x1db7e8 might be referenced indirectly.
//
// Output: C:/dnas/active/ghidra_exports/udp9090_register_senders.txt

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class ScanRegisterSenders extends GhidraScript {

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_register_senders.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        PrintWriter pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" Scan: FUN_001e180c callsites with opcode 0x2c (REGISTER)");
            pw.println("================================================================");

            ReferenceManager rm = currentProgram.getReferenceManager();
            Address sendBuf = toAddr(0x001e180cL);

            Set<Long> callers = new LinkedHashSet<>();
            for (ReferenceIterator it = rm.getReferencesTo(sendBuf); it.hasNext(); ) {
                Reference r = it.next();
                Instruction jal = currentProgram.getListing().getInstructionAt(r.getFromAddress());
                if (jal == null) continue;
                Function caller = getFunctionContaining(jal.getAddress());
                // Scan backwards up to 12 insns; look for `li t0, 0x2c` (op = 0x2c)
                Address cur = jal.getAddress();
                long opcode = -1;
                long kind = -1;
                long bodyLen = -1;
                int back = 0;
                StringBuilder ctx = new StringBuilder();
                while (cur != null && back < 16) {
                    Instruction ins = currentProgram.getListing().getInstructionAt(cur);
                    if (ins != null) {
                        String m = ins.getMnemonicString();
                        StringBuilder ops = new StringBuilder();
                        for (int o = 0; o < ins.getNumOperands(); o++) {
                            if (o > 0) ops.append(", ");
                            ops.append(ins.getDefaultOperandRepresentation(o));
                        }
                        ctx.insert(0, String.format("    %s  %-8s %s%n", cur, m, ops));
                        if (m.equals("li") || m.equals("ori") || m.equals("addiu")) {
                            String dst = ins.getDefaultOperandRepresentation(0);
                            try {
                                Scalar sc = ins.getScalar(ins.getNumOperands() - 1);
                                if (sc != null) {
                                    if (dst.contains("t0") && opcode < 0) opcode = sc.getValue() & 0xff;
                                    if (dst.contains("a2") && kind < 0) kind = sc.getValue() & 0xffff;
                                    if (dst.contains("a3") && bodyLen < 0) bodyLen = sc.getValue() & 0xffff;
                                }
                            } catch (Exception ignore) {}
                        }
                    }
                    cur = cur.subtract(4);
                    back++;
                }
                // Only print if opcode == 0x2c
                if (opcode == 0x2c) {
                    pw.printf("%n  ## FUN_001e180c @ %s in %s  op=0x%x kind=0x%x bodyLen=0x%x%n",
                            r.getFromAddress(),
                            caller == null ? "(none)" : caller.getName() + "@" + caller.getEntryPoint(),
                            opcode, kind, bodyLen);
                    pw.print(ctx);
                    if (caller != null) callers.add(caller.getEntryPoint().getOffset());
                } else if (opcode == 0x1c) {
                    pw.printf("%n  ## FUN_001e180c @ %s in %s  op=0x%x kind=0x%x bodyLen=0x%x  [op 0x1c]%n",
                            r.getFromAddress(),
                            caller == null ? "(none)" : caller.getName() + "@" + caller.getEntryPoint(),
                            opcode, kind, bodyLen);
                    pw.print(ctx);
                    if (caller != null) callers.add(caller.getEntryPoint().getOffset());
                }
            }

            pw.println();
            pw.println("================================================================");
            pw.println(" CALLERS of those functions (BFS one level)");
            pw.println("================================================================");
            for (Long f : callers) {
                pw.printf("%n# FUN_%08x callers:%n", f);
                Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(f));
                if (fn == null) { pw.println("  (no fn)"); continue; }
                for (Function c : fn.getCallingFunctions(monitor)) {
                    pw.printf("  <- %s @ %s%n", c.getName(), c.getEntryPoint());
                }
                // Also do raw JAL scan
                Listing listing = currentProgram.getListing();
                for (InstructionIterator it = listing.getInstructions(true); it.hasNext(); ) {
                    Instruction ins = it.next();
                    if (!ins.getMnemonicString().equals("jal")) continue;
                    try {
                        Scalar sc = ins.getScalar(0);
                        if (sc == null) continue;
                        if ((sc.getValue() & 0xffffffffL) == f) {
                            Function cc = getFunctionContaining(ins.getAddress());
                            pw.printf("    jal at %s in %s%n", ins.getAddress(),
                                    cc == null ? "(none)" : cc.getName() + "@" + cc.getEntryPoint());
                        }
                    } catch (Exception ignore) {}
                }
            }

            pw.println();
            pw.println("================================================================");
            pw.println(" Memory scan: words equal to each REGISTER-sender fn address");
            pw.println("================================================================");
            Set<Long> targets = new HashSet<>(callers);
            for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
                if (!blk.isInitialized()) continue;
                long len = blk.getSize();
                if (len > 0x800000) continue;
                Address start = blk.getStart();
                byte[] buf = new byte[(int) len];
                try { blk.getBytes(start, buf); } catch (Exception ignore) { continue; }
                ByteBuffer bb = ByteBuffer.wrap(buf).order(ByteOrder.LITTLE_ENDIAN);
                for (int off = 0; off + 4 <= buf.length; off += 4) {
                    long w = ((long) bb.getInt(off)) & 0xffffffffL;
                    if (targets.contains(w)) {
                        Address a = start.add(off);
                        Function cf = getFunctionContaining(a);
                        pw.printf("  %s = 0x%08x  blk=%s%s%n", a, w, blk.getName(),
                                cf == null ? "" : "  (in " + cf.getName() + ")");
                    }
                }
            }

            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }
}
