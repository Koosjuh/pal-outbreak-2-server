// Codex-owned focused export for PAL EE TCP 10127 cmd 0x1007 analysis.
// Output: D:/projects/pal-outbreak-2-server/analysis/ghidra-cmd1007-export.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class DecompileCmd1007 extends GhidraScript {
    private static final long[] TARGETS = {
        0x001c4100L, // builds first TCP 10127 cmd 0x1007 client packet
        0x001c9030L, // handles server reply 02 10 07
        0x001c3c90L, // packet header builder
        0x001c4020L, // append encoded block/string
        0x001c3da0L, // append one payload byte
        0x001c3840L, // send/flush helper
        0x001c3a60L, // read one payload byte
        0x001c3b90L, // read payload bytes
        0x001bf2e0L  // network/config helper used in 0x1007 payload
    };

    private static final long[] DATA_TARGETS = {
        0x003c9580L,
        0x00245e38L,
        0x0035ba80L,
        0x0035ccb0L,
        0x00365dc0L
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private final Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-cmd1007-export.txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            pw.println("PAL EE TCP 10127 cmd 0x1007 focused export");
            pw.println("Program: " + currentProgram.getName());
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            for (long target : TARGETS) {
                dumpFunction(target);
            }
            dumpData();
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dumpFunction(long entry) throws Exception {
        if (!dumped.add(entry)) {
            return;
        }
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) {
            pw.printf("%n---- no function at 0x%08x ----%n", entry);
            return;
        }
        long e = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.printf("FN %s @ 0x%08x size=0x%x%n", fn.getName(), e, size);
        pw.println("callers:");
        for (Function caller : fn.getCallingFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", caller.getEntryPoint().getOffset(), caller.getName());
        }
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        pw.println("----------------------------------------------------------------");
        DecompileResults r = ifc.decompileFunction(fn, 90, monitor);
        if (r != null && r.decompileCompleted()) {
            pw.println(r.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (r == null ? "null" : r.getErrorMessage()));
        }
        pw.flush();
    }

    private void dumpData() throws Exception {
        Memory mem = currentProgram.getMemory();
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.println("DATA BYTES");
        for (long target : DATA_TARGETS) {
            Address a = toAddr(target);
            pw.printf("%n0x%08x:%n", target);
            byte[] bytes = new byte[128];
            try {
                mem.getBytes(a, bytes);
                for (int i = 0; i < bytes.length; i += 16) {
                    pw.printf("  +0x%02x  ", i);
                    for (int j = 0; j < 16; j++) {
                        pw.printf("%02x ", bytes[i + j] & 0xff);
                    }
                    pw.print(" ");
                    for (int j = 0; j < 16; j++) {
                        int b = bytes[i + j] & 0xff;
                        pw.print((b >= 0x20 && b < 0x7f) ? (char)b : '.');
                    }
                    pw.println();
                }
            } catch (Exception e) {
                pw.println("  READ_FAILED: " + e.getMessage());
            }
        }
        pw.flush();
    }
}
