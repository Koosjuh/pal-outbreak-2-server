// Find callers of FUN_001b7ff0 (central message-flow state machine)
// AND FUN_001b7b50 (sets up type/subtype before state machine runs).
// Together these tell us what code invokes the post-login protocol chain.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.HashSet;
import java.util.Set;

public class FindB7ff0Callers extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        Set<Long> visited = new HashSet<>();
        long[] roots = { 0x001b7ff0L, 0x001b7b50L };
        for (long r : roots) walk(r, ifc, visited, 0);

        // Also: scan EE ELF data section for 0x001b7ff0 as a 4-byte LE value
        // (in case it's registered in a callback table)
        println("\n=== Memory scan for 0x001b7ff0 (4-byte LE) ===");
        scanForAddr(0x001b7ff0L);
        println("\n=== Memory scan for 0x001b7b50 (4-byte LE) ===");
        scanForAddr(0x001b7b50L);

        ifc.dispose();
    }

    void walk(long fnAddr, DecompInterface ifc, Set<Long> visited, int depth) throws Exception {
        if (depth > 2 || visited.contains(fnAddr)) return;
        visited.add(fnAddr);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(fnAddr));
        if (fn == null) return;
        String pad = "  ".repeat(depth);
        println(pad + "============================================================");
        println(pad + "[depth=" + depth + "] " + fn.getName() + " @ " + fn.getEntryPoint());
        if (depth <= 1) {
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                String c = res.getDecompiledFunction().getC();
                String[] lines = c.split("\\n");
                int max = Math.min(lines.length, 80);
                for (int i = 0; i < max; i++) println(pad + "  " + lines[i]);
                if (lines.length > max) println(pad + "  ... (" + (lines.length - max) + " more lines)");
            }
        }
        println(pad + "  --- callers ---");
        Set<Long> next = new HashSet<>();
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(fn.getEntryPoint());
        while (it.hasNext()) {
            Reference r = it.next();
            Function caller = getFunctionContaining(r.getFromAddress());
            if (caller != null) {
                println(pad + "    <- " + r.getFromAddress() + " in " + caller.getName());
                next.add(caller.getEntryPoint().getOffset());
            } else {
                println(pad + "    <- " + r.getFromAddress() + " (no fn)");
            }
        }
        for (Long n : next) walk(n, ifc, visited, depth + 1);
    }

    void scanForAddr(long target) throws Exception {
        byte[] needle = {
            (byte)(target & 0xff), (byte)((target >> 8) & 0xff),
            (byte)((target >> 16) & 0xff), (byte)((target >> 24) & 0xff)
        };
        for (var block : currentProgram.getMemory().getBlocks()) {
            if (!block.isInitialized()) continue;
            long start = block.getStart().getOffset();
            long size = block.getEnd().getOffset() - start + 1;
            if (size <= 0 || size > 0x4000000) continue;
            byte[] buf = new byte[(int)Math.min(size, 0x800000)];
            try { block.getBytes(block.getStart(), buf, 0, buf.length); } catch (Exception e) { continue; }
            for (int i = 0; i + 4 <= buf.length; i += 4) {
                if (buf[i] == needle[0] && buf[i+1] == needle[1] &&
                    buf[i+2] == needle[2] && buf[i+3] == needle[3]) {
                    println(String.format("  HIT @ 0x%08x in block %s", start + i, block.getName()));
                }
            }
        }
    }
}
