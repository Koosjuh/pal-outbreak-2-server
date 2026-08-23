// Dump FUN_001d9f78 (the actual opcode dispatcher invoked from FUN_001d6dfc)
// and any helpers it calls.  Also dump FUN_001e1c10, FUN_001d63b8.
// Output: C:/dnas/active/ghidra_exports/udp9090_dispatcher.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.ArrayDeque;
import java.util.Deque;

public class DumpD9f78 extends GhidraScript {

    private static final long[] SEEDS = {
        0x001d9f78L,
        0x001e1c10L,
        0x001d63b8L,
        0x001d6468L,
        0x001d5ae4L,
        0x001d6dfcL,
        0x001cac70L, // slot 0x12 handler
        0x001cad10L, // slot 0x14 handler
        0x001cadb0L, // slot 0x13 & 0x15 handler
        0x001cac60L, // helper called from FUN_001cae70
        0x001cac50L, // helper called from FUN_001cae70 / FUN_001cadc0
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_dispatcher.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" PAL EE post-parse dispatcher dump (FUN_001d9f78 + helpers)");
            pw.println("================================================================");

            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            // BFS: dump seeds + their direct callees up to depth 2
            Deque<long[]> queue = new ArrayDeque<>();
            for (long s : SEEDS) queue.add(new long[]{s, 0});
            while (!queue.isEmpty()) {
                long[] e = queue.poll();
                long addr = e[0];
                long depth = e[1];
                if (depth > 1) continue;
                if (dumped.contains(addr)) continue;
                Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(addr));
                if (fn == null) continue;
                decompileOnce(addr);
                if (depth < 1) {
                    for (Function callee : fn.getCalledFunctions(monitor)) {
                        long c = callee.getEntryPoint().getOffset();
                        // Skip libc-ish leafs we already understand
                        if (c == 0x001069a8L || c == 0x00102790L || c == 0x0010a4f0L ||
                            c == 0x00109eb8L) continue;
                        queue.add(new long[]{c, depth + 1});
                    }
                }
            }

            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void decompileOnce(long entry) {
        if (dumped.contains(entry)) return;
        dumped.add(entry);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) {
            pw.printf("%n---- no function at 0x%08x ----%n", entry);
            return;
        }
        long e = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.printf("FN %s @ 0x%08x  size=0x%x%n", fn.getName(), e, size);
        Set<Function> callers = fn.getCallingFunctions(monitor);
        StringBuilder cb = new StringBuilder("  callers:");
        if (callers.isEmpty()) cb.append(" (none)");
        for (Function c : callers) cb.append(" ").append(c.getEntryPoint());
        pw.println(cb);
        Set<Function> callees = fn.getCalledFunctions(monitor);
        StringBuilder eb = new StringBuilder("  callees:");
        if (callees.isEmpty()) eb.append(" (none)");
        for (Function c : callees) eb.append(" ").append(c.getEntryPoint()).append("(").append(c.getName()).append(")");
        pw.println(eb);
        pw.println("----------------------------------------------------------------");
        try {
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) {
                pw.println(r.getDecompiledFunction().getC());
            } else {
                pw.println("DECOMPILE_FAILED: " + (r == null ? "null" : r.getErrorMessage()));
            }
        } catch (Exception ex) {
            pw.println("DECOMPILE_EXCEPTION: " + ex.getMessage());
        }
        pw.flush();
    }
}
