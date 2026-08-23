// Codex-owned focused export for no-PINE unlock gate mapping.
// Output: D:/projects/pal-outbreak-2-server/analysis/ghidra-unlock-gates-export.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class MapUnlockGates extends GhidraScript {
    private static final long[] DUMP_FUNCTIONS = {
        0x0019fdd0L, 0x0019fe50L, 0x0019fe90L, 0x001a3400L,
        0x001a37f0L, 0x001a9350L, 0x001b42e0L, 0x001c0020L
    };

    private static final long[] TARGET_ADDRS = {
        0x0029f280L, 0x0035a279L, 0x00701f28L, 0x00701f30L, 0x00870870L
    };

    private static final long[] TARGET_SCALARS = {
        0x29f280L, 0x35a279L, 0x701f28L, 0x701f30L, 0x870870L, 0x1a5dfL,
        0xf280L, 0xa279L, 0x1f28L, 0x1f30L, 0x0870L, 0x0070L, 0x0035L, 0x0029L
    };

    private PrintWriter pw;
    private DecompInterface ifc;

    @Override
    public void run() throws Exception {
        String safeName = currentProgram.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-unlock-gates-" + safeName + ".txt";
        pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)));
        try {
            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            pw.println("No-PINE unlock gate focused export");
            pw.println("Program: " + currentProgram.getName());
            dumpBlocks();
            dumpDirectRefs();
            dumpKnownFunctions();
            scanDecompilerText();
            scanInstructionScalars();
            walkCallers(0x001c0020L, 0, new HashSet<Long>());
            ifc.dispose();
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }

    private void dumpBlocks() {
        pw.println();
        pw.println("=== MEMORY BLOCKS ===");
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            pw.printf("  %-24s 0x%08x..0x%08x init=%s exec=%s read=%s write=%s%n",
                b.getName(), b.getStart().getOffset(), b.getEnd().getOffset(),
                b.isInitialized(), b.isExecute(), b.isRead(), b.isWrite());
        }
    }

    private void dumpDirectRefs() {
        pw.println();
        pw.println("=== DIRECT REFERENCES TO TARGET ADDRESSES ===");
        for (long target : TARGET_ADDRS) {
            Address a = toAddr(target);
            pw.printf("TARGET 0x%08x%n", target);
            int count = 0;
            for (Reference r : getReferencesTo(a)) {
                Function fn = getFunctionContaining(r.getFromAddress());
                pw.printf("  from 0x%08x type=%s fn=%s%n",
                    r.getFromAddress().getOffset(), r.getReferenceType(), fmt(fn));
                count++;
            }
            if (count == 0) {
                pw.println("  <none>");
            }
        }
    }

    private void dumpKnownFunctions() throws Exception {
        pw.println();
        pw.println("=== KNOWN FOCUS FUNCTIONS ===");
        for (long entry : DUMP_FUNCTIONS) {
            dumpFunction(entry);
        }
    }

    private void scanDecompilerText() throws Exception {
        pw.println();
        pw.println("=== DECOMPILER TEXT MATCHES ===");
        String[] needles = {
            "29f280", "cRam0029f280", "35a279", "cRam0035a279",
            "701f28", "701f30", "870870", "1a5df", "cRam00343563",
            "pcRam0029a528", "uRam0029a498"
        };
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        int scanned = 0;
        while (fit.hasNext() && !monitor.isCancelled()) {
            Function fn = fit.next();
            scanned++;
            DecompileResults res = ifc.decompileFunction(fn, 25, monitor);
            if (res == null || !res.decompileCompleted()) {
                continue;
            }
            String c = res.getDecompiledFunction().getC();
            boolean hit = false;
            for (String n : needles) {
                if (c.toLowerCase().contains(n.toLowerCase())) {
                    hit = true;
                    break;
                }
            }
            if (!hit) {
                continue;
            }
            pw.println();
            pw.printf("MATCH %s @ 0x%08x%n", fn.getName(), fn.getEntryPoint().getOffset());
            for (String line : c.split("\\n")) {
                String low = line.toLowerCase();
                boolean lineHit = false;
                for (String n : needles) {
                    if (low.contains(n.toLowerCase())) {
                        lineHit = true;
                        break;
                    }
                }
                if (lineHit) {
                    pw.println("  " + line.trim());
                }
            }
        }
        pw.println("scanned functions: " + scanned);
    }

    private void scanInstructionScalars() {
        pw.println();
        pw.println("=== INSTRUCTION SCALAR MATCHES ===");
        Set<String> seen = new LinkedHashSet<>();
        Instruction ins = currentProgram.getListing().getInstructions(true).next();
        while (ins != null && !monitor.isCancelled()) {
            for (int op = 0; op < ins.getNumOperands(); op++) {
                for (Object obj : ins.getOpObjects(op)) {
                    if (!(obj instanceof Scalar)) continue;
                    long v = ((Scalar)obj).getUnsignedValue();
                    for (long t : TARGET_SCALARS) {
                        if (v == t) {
                            Function fn = getFunctionContaining(ins.getAddress());
                            String key = String.format("0x%08x", ins.getAddress().getOffset());
                            if (seen.add(key)) {
                                pw.printf("  0x%08x %-10s %-32s scalar=0x%x fn=%s%n",
                                    ins.getAddress().getOffset(), ins.getMnemonicString(),
                                    ins.toString(), v, fmt(fn));
                            }
                        }
                    }
                }
            }
            ins = ins.getNext();
        }
    }

    private void walkCallers(long entry, int depth, Set<Long> seen) throws Exception {
        if (depth > 4 || !seen.add(entry)) return;
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) return;
        pw.println();
        pw.printf("=== CALLER WALK depth=%d %s @ 0x%08x ===%n",
            depth, fn.getName(), fn.getEntryPoint().getOffset());
        dumpFunction(entry);
        Set<Long> next = new LinkedHashSet<>();
        for (Reference r : getReferencesTo(fn.getEntryPoint())) {
            Function caller = getFunctionContaining(r.getFromAddress());
            pw.printf("  caller ref 0x%08x fn=%s%n", r.getFromAddress().getOffset(), fmt(caller));
            if (caller != null) next.add(caller.getEntryPoint().getOffset());
        }
        for (Long n : next) {
            walkCallers(n, depth + 1, seen);
        }
    }

    private void dumpFunction(long entry) throws Exception {
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) fn = getFunctionContaining(toAddr(entry));
        pw.println();
        pw.printf("FUNCTION request=0x%08x fn=%s%n", entry, fmt(fn));
        if (fn == null) return;
        pw.println("callers:");
        for (Function caller : fn.getCallingFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", caller.getEntryPoint().getOffset(), caller.getName());
        }
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        DecompileResults res = ifc.decompileFunction(fn, 90, monitor);
        if (res != null && res.decompileCompleted()) {
            pw.println(res.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (res == null ? "null" : res.getErrorMessage()));
        }
    }

    private String fmt(Function fn) {
        if (fn == null) return "<none>";
        return fn.getName() + " @ 0x" + Long.toHexString(fn.getEntryPoint().getOffset());
    }
}
