// Decompile every function discovered in the netaq.bin overlay image.
// Output is written to C:/dnas/active/ghidra_exports/netaq_all_functions.txt
//
// netaq.bin payload starts at file offset 0x40 in BIN/9.DAT.
// Loaded base address: 0x007DBA00, size 17856 bytes => spans 0x007DBA00..0x007DFFFF.
// Processor: MIPS:LE:32:R5900.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileNetaq extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/netaq_all_functions.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        PrintWriter pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println("netaq.bin (BIN/9.DAT minus 0x40 MWo3 header) decompile dump");
            pw.println("Base: 0x007DBA00  Size: 17856 (0x4580)  Processor: MIPS:LE:32:R5900");
            pw.println("================================================================");

            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            FunctionIterator fnIter = currentProgram.getFunctionManager().getFunctions(true);
            int count = 0;
            int decompiled = 0;
            int failed = 0;

            // First pass: produce a table of contents.
            pw.println();
            pw.println("---- FUNCTION TABLE OF CONTENTS ----");
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                AddressSetView body = fn.getBody();
                long size = body.getMaxAddress().getOffset() - fn.getEntryPoint().getOffset() + 1;
                pw.printf("  %-40s  entry=%s  size=0x%x%n",
                    fn.getName(),
                    fn.getEntryPoint().toString(),
                    size);
                count++;
            }
            pw.println("---- " + count + " functions ----");
            pw.println();

            // Second pass: decompile each.
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                long entry = fn.getEntryPoint().getOffset();
                long size = fn.getBody().getMaxAddress().getOffset() - entry + 1;
                pw.println();
                pw.println("================================================================");
                pw.printf("FN %s @ 0x%08x  size=0x%x%n", fn.getName(), entry, size);

                // Caller / callee summary
                java.util.Set<Function> callers = fn.getCallingFunctions(monitor);
                java.util.Set<Function> callees = fn.getCalledFunctions(monitor);
                StringBuilder cb = new StringBuilder();
                cb.append("  callers:");
                if (callers.isEmpty()) cb.append(" (none)");
                for (Function c : callers) {
                    cb.append(" ").append(c.getEntryPoint().toString());
                }
                pw.println(cb.toString());
                StringBuilder eb = new StringBuilder();
                eb.append("  callees:");
                if (callees.isEmpty()) eb.append(" (none)");
                for (Function c : callees) {
                    eb.append(" ").append(c.getEntryPoint().toString()).append("(").append(c.getName()).append(")");
                }
                pw.println(eb.toString());
                pw.println("================================================================");

                DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
                if (r != null && r.decompileCompleted()) {
                    pw.println(r.getDecompiledFunction().getC());
                    decompiled++;
                } else {
                    String msg = (r != null) ? r.getErrorMessage() : "null";
                    pw.println("DECOMPILE_FAILED: " + msg);
                    failed++;
                }
                pw.flush();
            }

            // Third pass: every immediate that loads 0x2382 (9090) or 0x21CD (8653)
            // or other interesting magic. We scan instructions.
            pw.println();
            pw.println("---- IMMEDIATE SCAN: ports / magics ----");
            Listing listing = currentProgram.getListing();
            ghidra.program.model.listing.InstructionIterator instIter =
                listing.getInstructions(currentProgram.getMemory(), true);
            int hits = 0;
            while (instIter.hasNext() && hits < 200) {
                ghidra.program.model.listing.Instruction ins = instIter.next();
                String s = ins.toString();
                if (s.contains("0x2382") || s.contains("0x21cd") || s.contains("0x21CD")
                    || s.contains("0x3096") || s.contains("0x9630")
                    || s.contains("0x2c,") || s.contains(",0x2c")
                    || s.contains("0x96,") || s.contains(",0x96")
                    || s.contains("0x30,") || s.contains(",0x30")) {
                    pw.printf("  %s  %s%n", ins.getAddress().toString(), s);
                    hits++;
                }
            }
            pw.println("---- " + hits + " immediate hits ----");

            // Fourth pass: strings table within image.
            pw.println();
            pw.println("---- DEFINED STRINGS ----");
            ghidra.program.model.listing.DataIterator dit = listing.getDefinedData(true);
            int strCount = 0;
            while (dit.hasNext() && strCount < 200) {
                ghidra.program.model.listing.Data d = dit.next();
                Object v = d.getValue();
                if (v instanceof String) {
                    String sv = (String) v;
                    if (sv.length() >= 3) {
                        pw.printf("  %s  \"%s\"%n", d.getAddress().toString(), sv);
                        strCount++;
                    }
                }
            }
            pw.println("---- " + strCount + " strings ----");

            pw.println();
            pw.printf("SUMMARY: total=%d  decompiled=%d  failed=%d%n", count, decompiled, failed);
            ifc.dispose();
            println("Decompile complete: " + decompiled + " / " + count + " functions. Output: " + outPath);
        } finally {
            pw.close();
        }
    }
}
