// Find all hardcoded URL/host strings in the PAL EE ELF that hint at the
// browser flow — specifically endpoints beyond /mhweb/login + /mhweb/enterareas
// the game's Y/K browser knows how to navigate to.

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.mem.MemoryAccessException;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.listing.Function;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindMhwebUrls extends GhidraScript {

    private static final String[] NEEDLES = {
        "/mhweb/", "mhweb", "stage6", "sega.com", "capcom", "snap01", "yav4",
        "CRS-", "CRS_", "POST", "GET", ".jsp", "REFRESH",
        "lbs.jsp", "login.jsp", "enterareas", "enterlobby", "logout",
        "create.jsp", "sethandle", "startsession",
        "lobby", "online", "session"
    };

    @Override
    public void run() throws Exception {
        println("=== Scanning all memory blocks for ASCII strings matching needles ===");
        for (String needle : NEEDLES) {
            println("\n# needle: \"" + needle + "\"");
            scanForNeedle(needle);
        }
    }

    void scanForNeedle(String needle) throws MemoryAccessException {
        byte[] target = needle.getBytes();
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (!block.isInitialized()) continue;
            long start = block.getStart().getOffset();
            long end = block.getEnd().getOffset();
            long size = end - start + 1;
            if (size <= 0 || size > 0x4000000) continue;

            byte[] buf = new byte[(int)Math.min(size, 0x800000)];
            try {
                block.getBytes(block.getStart(), buf, 0, buf.length);
            } catch (Exception e) { continue; }

            for (int i = 0; i + target.length <= buf.length; i++) {
                boolean match = true;
                for (int j = 0; j < target.length; j++) {
                    if (buf[i + j] != target[j]) { match = false; break; }
                }
                if (!match) continue;

                long hitAddr = start + i;

                int strStart = i;
                while (strStart > 0 && isPrintable(buf[strStart - 1])) strStart--;
                int strEnd = i + target.length;
                while (strEnd < buf.length && isPrintable(buf[strEnd])) strEnd++;
                String surround = new String(buf, strStart, strEnd - strStart);

                Address a = toAddr(start + strStart);
                println(String.format("  HIT @ 0x%08x  (start of run @ 0x%08x): \"%s\"",
                        hitAddr, a.getOffset(), surround));

                ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(a);
                int refCount = 0;
                while (it.hasNext() && refCount < 8) {
                    Reference r = it.next();
                    Function caller = getFunctionContaining(r.getFromAddress());
                    println(String.format("    <- %s in %s (%s)",
                            r.getFromAddress(), caller == null ? "(no fn)" : caller.getName(),
                            r.getReferenceType()));
                    refCount++;
                }
            }
        }
    }

    boolean isPrintable(byte b) {
        return (b >= 0x20 && b < 0x7f);
    }
}
