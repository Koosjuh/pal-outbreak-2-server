// Dump:
//   - the string at 0x2592b0 (IP format)
//   - FUN_001e5538 and friends (the parser/serializer)
//   - FUN_001ea8e8 (string formatting)
//   - FUN_001e56c8 (serializer for outgoing 0x41)
//   - bytes around the "SNAP-SWAN" template at state+0x4d4 (default init template — but maybe also see if a static template exists)
// Output: C:/dnas/active/ghidra_exports/udp9090_parser.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class DumpParseFormat extends GhidraScript {

    private static final long[] FNS = {
        0x001e5538L,
        0x001ea8e8L,
        0x001e56c8L,
        0x00109d70L,
        0x00109728L,
        0x0010a050L,
        0x00109eb8L,
    };

    private static final long[] STRS = {
        0x002592b0L, // IP format
        0x0024cbb0L, 0x0024cbd0L, 0x0024cbf0L, 0x0024cc10L, 0x0024cc30L, 0x0024cc40L,
    };

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_parser.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        PrintWriter pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" Parser / format-string dump");
            pw.println("================================================================");

            pw.println();
            pw.println("# strings at fixed addresses");
            for (long a : STRS) {
                try {
                    byte[] buf = new byte[256];
                    currentProgram.getMemory().getBytes(toAddr(a), buf);
                    StringBuilder s = new StringBuilder();
                    for (int i = 0; i < buf.length; i++) {
                        int c = buf[i] & 0xff;
                        if (c == 0) break;
                        if (c < 0x20 || c >= 0x7f) s.append(String.format("\\x%02x", c));
                        else s.append((char) c);
                    }
                    pw.printf("  0x%08x: %s%n", a, s.toString());
                } catch (Exception e) {
                    pw.printf("  0x%08x: read failed: %s%n", a, e.getMessage());
                }
            }

            pw.println();
            pw.println("# scan strings in .rodata for likely parse templates");
            pw.println("# (printable strings >= 8 chars containing '<' or '%')");
            for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
                if (!blk.isInitialized()) continue;
                if (blk.isWrite()) continue; // only rodata-like blocks
                if (blk.getSize() > 0x800000) continue;
                long len = blk.getSize();
                Address start = blk.getStart();
                byte[] buf = new byte[(int) len];
                try { blk.getBytes(start, buf); } catch (Exception ignore) { continue; }
                int sStart = -1;
                int interesting = 0;
                for (int i = 0; i < buf.length; i++) {
                    int c = buf[i] & 0xff;
                    boolean isPrint = (c >= 0x20 && c < 0x7f) || c == '\n' || c == '\t';
                    if (isPrint) {
                        if (sStart < 0) { sStart = i; interesting = 0; }
                        if (c == '<' || c == '%' || c == '>' || c == '?' || c == '/') interesting++;
                    } else {
                        if (sStart >= 0 && (i - sStart) >= 12 && interesting >= 2) {
                            StringBuilder s = new StringBuilder();
                            for (int j = sStart; j < i; j++) s.append((char) (buf[j] & 0xff));
                            pw.printf("  %s: %s%n", start.add(sStart), s.toString());
                        }
                        sStart = -1;
                    }
                }
            }

            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE: parser helpers");
            pw.println("================================================================");
            Set<Long> dumped = new HashSet<>();
            for (long a : FNS) {
                if (dumped.contains(a)) continue;
                dumped.add(a);
                Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(a));
                if (fn == null) { pw.printf("%n---- no function at 0x%08x ----%n", a); continue; }
                long size = fn.getBody().getMaxAddress().getOffset() - a + 1;
                pw.println();
                pw.println("----------------------------------------------------------------");
                pw.printf("FN %s @ 0x%08x  size=0x%x%n", fn.getName(), a, size);
                pw.println("----------------------------------------------------------------");
                try {
                    DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
                    if (r != null && r.decompileCompleted()) {
                        pw.println(r.getDecompiledFunction().getC());
                    } else {
                        pw.println("DECOMPILE_FAILED");
                    }
                } catch (Exception e) {
                    pw.println("DECOMPILE_EXCEPTION: " + e.getMessage());
                }
                pw.flush();
            }
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }
}
