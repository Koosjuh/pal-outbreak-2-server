// Find the SN@P-message dispatch table. FUN_001bf800 has no static callers
// (only invoked via function pointer), so its address must appear as a 4-byte
// value somewhere in the EE ELF data section. Surrounding entries are peer
// handlers for other SN@P message types. Map the whole table.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import java.util.ArrayList;
import java.util.List;

public class FindSnapDispatchTable extends GhidraScript {

    private static final long TARGET = 0x001bf800L;
    // Also dump these neighbors / known-related funcs
    private static final long[] EXTRA_DECOMPILE = {
        0x001bfd00L, // SN@P message buffer reader
        0x001bdc10L, // called by FUN_001bf800 with handle args
        0x001bdbf0L, // also called by FUN_001bf800
        0x001bf580L, // called by FUN_001c0100 case 3 success
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        // === 1. Find every 4-byte LE occurrence of 0x001bf800 ===
        println("=== Scanning all initialized memory for 4-byte LE 0x001bf800 ===");
        byte[] needle = { (byte)0x00, (byte)0xf8, (byte)0x1b, (byte)0x00 };
        List<Long> hits = new ArrayList<>();
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (!block.isInitialized()) continue;
            long start = block.getStart().getOffset();
            long size = block.getEnd().getOffset() - start + 1;
            if (size <= 0 || size > 0x4000000) continue;
            byte[] buf = new byte[(int)Math.min(size, 0x800000)];
            try { block.getBytes(block.getStart(), buf, 0, buf.length); } catch (Exception e) { continue; }
            for (int i = 0; i + 4 <= buf.length; i += 4) {
                if (buf[i] == needle[0] && buf[i+1] == needle[1] &&
                    buf[i+2] == needle[2] && buf[i+3] == needle[3]) {
                    long addr = start + i;
                    println(String.format("  HIT @ 0x%08x in block %s", addr, block.getName()));
                    hits.add(addr);
                }
            }
        }

        // === 2. For each hit, dump surrounding 16 entries (16x4 = 64 bytes back, 64 forward) ===
        println("\n=== Surrounding context (potential dispatch tables) ===");
        for (Long hit : hits) {
            println("\n--- around 0x" + Long.toHexString(hit) + " ---");
            for (int off = -16; off <= 16; off++) {
                long addr = hit + (long)off * 4;
                Address a = toAddr(addr);
                try {
                    int v = currentProgram.getMemory().getInt(a);
                    String marker = (off == 0) ? "  <<< TARGET" : "";
                    Function fn = getFunctionAt(toAddr(v & 0xFFFFFFFFL));
                    String fnName = fn == null ? "" : "  -> " + fn.getName();
                    println(String.format("  +%-4d  0x%08x : 0x%08x%s%s",
                            off * 4, addr, v & 0xFFFFFFFFL, fnName, marker));
                } catch (Exception e) { }
            }
        }

        // === 3. Decompile related neighbor functions ===
        println("\n=== Related function decompiles ===");
        for (long target : EXTRA_DECOMPILE) {
            Address addr = toAddr(target);
            Function fn = getFunctionContaining(addr);
            if (fn == null) {
                println("NO_FUNCTION at " + addr);
                continue;
            }
            println("============================================================");
            println("FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint());
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            }
        }

        ifc.dispose();
    }
}
