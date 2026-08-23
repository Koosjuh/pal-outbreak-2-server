// Scan all instructions for jal/jalr to FUN_001db7e8 (REGISTER sender) and to
// the other "send-shell" functions in the same family.  Output every callsite
// and the param_11 (a7 / stack-passed) origin.  Also produce a separate scan
// for *every* 4-byte aligned word in .text/.data that contains the value
// 0x001db7e8 — if it's in a dispatch table the table entry will be visible.
//
// Outputs to C:/dnas/active/ghidra_exports/udp9090_db7e8_callers.txt

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class ScanJalToDb7e8 extends GhidraScript {

    private static final long[] TARGETS = {
        0x001db7e8L, // REGISTER (op 0x2c)
        0x001dbefcL, // related send-shell
        0x001dbd0cL, // related send-shell
    };

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_db7e8_callers.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        PrintWriter pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" Scan: callsites of REGISTER sender FUN_001db7e8 + family");
            pw.println("================================================================");

            Listing listing = currentProgram.getListing();
            InstructionIterator it = listing.getInstructions(true);
            int count = 0;
            while (it.hasNext() && count < 5000) {
                Instruction ins = it.next();
                String m = ins.getMnemonicString();
                if (!m.equals("jal") && !m.equals("j")) continue;
                try {
                    Scalar sc = ins.getScalar(0);
                    if (sc == null) {
                        Address ref = ins.getAddress(0);
                        if (ref != null) {
                            long t = ref.getOffset();
                            for (long tgt : TARGETS) if (t == tgt) report(pw, ins, t);
                        }
                        continue;
                    }
                    long t = sc.getValue() & 0xffffffffL;
                    for (long tgt : TARGETS) if (t == tgt) { report(pw, ins, t); count++; }
                } catch (Exception ignore) {}
            }

            // Also scan all bytes for the word value
            pw.println();
            pw.println("================================================================");
            pw.println(" Memory scan: words equal to 0x001db7e8 (dispatch-table refs)");
            pw.println("================================================================");
            for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
                if (!blk.isInitialized()) continue;
                Address start = blk.getStart();
                long len = blk.getSize();
                if (len > 0x800000) continue;
                byte[] buf = new byte[(int) len];
                try {
                    blk.getBytes(start, buf);
                } catch (Exception ignore) { continue; }
                ByteBuffer bb = ByteBuffer.wrap(buf).order(ByteOrder.LITTLE_ENDIAN);
                for (int off = 0; off + 4 <= buf.length; off += 4) {
                    int w = bb.getInt(off);
                    long wl = ((long) w) & 0xffffffffL;
                    for (long tgt : TARGETS) {
                        if (wl == tgt) {
                            Address a = start.add(off);
                            Function containing = getFunctionContaining(a);
                            pw.printf("  %s = 0x%08x  (in %s)%n", a, tgt,
                                    containing == null ? "(data/none)" : containing.getName() + "@" + containing.getEntryPoint());
                        }
                    }
                }
            }

            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void report(PrintWriter pw, Instruction ins, long t) {
        Function caller = getFunctionContaining(ins.getAddress());
        pw.printf("  %s  %s  -> 0x%08x   in %s%n",
                ins.getAddress(), ins.getMnemonicString(), t,
                caller == null ? "(none)" : caller.getName() + "@" + caller.getEntryPoint());
        // Print 16 instructions of context
        Address cur = ins.getAddress().subtract(16 * 4);
        for (int i = 0; i < 24; i++) {
            Instruction ctx = currentProgram.getListing().getInstructionAt(cur);
            if (ctx != null) {
                StringBuilder ops = new StringBuilder();
                for (int o = 0; o < ctx.getNumOperands(); o++) {
                    if (o > 0) ops.append(", ");
                    ops.append(ctx.getDefaultOperandRepresentation(o));
                }
                pw.printf("    %s  %-8s %s%n", cur, ctx.getMnemonicString(), ops);
            }
            cur = cur.add(4);
        }
        pw.println();
    }
}
