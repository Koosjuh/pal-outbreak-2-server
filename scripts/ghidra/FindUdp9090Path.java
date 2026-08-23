// Hunt for the UDP 9090 send/receive handler in the PAL EE binary (SLES_533.19).
//
// We use multiple strategies:
//   1) String references: "%s@cee-auth", "app01.reo.capcom...", "snap01.capcom...",
//      and the 2-char tag bytes "LC", "MR" used inside the 154-byte packet.
//   2) Immediate scan: 16-bit constants 0x2382 (port 9090), 0x07d0 (port 2000),
//      0x9630 (LE half of header 0x3096), 0x9a (size 154), 0x2c (byte at off 3).
//   3) Callers of confirmed AVE-TCP API addresses (0x001bd360 send, 0x001bd940 poll,
//      0x001bda00 peek, 0x001bda30 handler, 0x001bda40 commit, 0x001bdb20 init buf).
//      netaq.bin lives at 0x007DBA00; we want callers that are NOT inside the netaq
//      overlay so we find the main-EE UDP 9090 path.
//   4) For each candidate function, dump decompile so we can study send/recv shape.
//
// Output: C:/dnas/active/ghidra_exports/udp9090_candidates.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeMap;

public class FindUdp9090Path extends GhidraScript {

    // String needles likely involved in the UDP 9090 path.
    private static final String[] NEEDLES = {
        "%s@cee-auth", "cee-auth", "@cee-auth",
        "app01.reo.capcom", "snap01.capcom",
        "yav4.com", "capcom.sf",
        "LC", "MR", // be careful: very short — we'll filter by reference count.
    };

    // Known AVE-TCP API entry points (confirmed by prior agent for netaq).
    // We want CALLERS of these that fall OUTSIDE the netaq overlay 0x007DBA00..0x007DFFFF.
    private static final long[] AVETCP_API = {
        0x001bd360L, // send
        0x001bd940L, // poll
        0x001bda00L, // peek
        0x001bda30L, // handler
        0x001bda40L, // commit
        0x001bdb20L, // init buf
    };

    // netaq overlay range: callers inside this are netaq itself — skip.
    private static final long NETAQ_LO = 0x007DBA00L;
    private static final long NETAQ_HI = 0x007DFFFFL;

    // Immediate constants we want to spot in code.
    private static final long[] IMM_VALUES = {
        0x2382L, // port 9090
        0x07d0L, // port 2000
        0x3096L, // header
        0x9630L, // header LE half
        0x009aL, // size 154
        0x4c43L, // 'LC' tag
        0x434cL, // 'CL' tag
        0x4d52L, // 'MR' tag
        0x524dL, // 'RM' tag
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private Set<Long> alreadyDecompiled = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_candidates.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" PAL EE UDP 9090 path hunt");
            pw.println(" Program: " + currentProgram.getName());
            pw.println(" Min addr: " + currentProgram.getMinAddress());
            pw.println(" Max addr: " + currentProgram.getMaxAddress());
            pw.println("================================================================");

            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            // 1. NEEDLE SCAN
            pw.println();
            pw.println("================================================================");
            pw.println(" 1) STRING NEEDLE SCAN");
            pw.println("================================================================");
            Set<Long> stringCandidates = new LinkedHashSet<>();
            for (String n : NEEDLES) {
                stringCandidates.addAll(scanForString(n));
            }

            // 2. IMMEDIATE SCAN
            pw.println();
            pw.println("================================================================");
            pw.println(" 2) IMMEDIATE SCAN  (ports, header, size, tags)");
            pw.println("================================================================");
            Set<Long> immCandidates = scanForImmediates();

            // 3. AVE-TCP API CALLERS not inside netaq overlay
            pw.println();
            pw.println("================================================================");
            pw.println(" 3) AVE-TCP API CALLERS  (outside netaq overlay)");
            pw.println("================================================================");
            Set<Long> apiCallers = scanForApiCallers();

            // 4. Union & decompile top candidates
            pw.println();
            pw.println("================================================================");
            pw.println(" 4) MERGED CANDIDATE FUNCTIONS  (decompile)");
            pw.println("================================================================");
            Set<Long> all = new LinkedHashSet<>();
            all.addAll(apiCallers);     // strongest signal first
            all.addAll(immCandidates);
            all.addAll(stringCandidates);
            pw.println("total unique candidate functions: " + all.size());
            for (Long fnEntry : all) {
                decompileOnce(fnEntry);
                pw.flush();
            }

            pw.println();
            pw.println("================================================================");
            pw.println(" DONE.  alreadyDecompiled size = " + alreadyDecompiled.size());
            pw.println("================================================================");

            ifc.dispose();
            println("Hunt complete. Output: " + outPath);
        } finally {
            pw.close();
        }
    }

    // ------------------------------------------------------------------
    // 1) String scan: find each occurrence of the needle in initialised
    // memory, then list any references to that address and the function
    // that contains the reference.
    private Set<Long> scanForString(String needle) {
        Set<Long> result = new LinkedHashSet<>();
        byte[] target = needle.getBytes();
        pw.println();
        pw.println("# needle: \"" + needle + "\"");
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (!block.isInitialized()) continue;
            long start = block.getStart().getOffset();
            long end = block.getEnd().getOffset();
            long size = end - start + 1;
            if (size <= 0 || size > 0x4000000L) continue;
            byte[] buf = new byte[(int)Math.min(size, 0x800000L)];
            try {
                block.getBytes(block.getStart(), buf, 0, buf.length);
            } catch (Exception e) { continue; }

            for (int i = 0; i + target.length <= buf.length; i++) {
                boolean match = true;
                for (int j = 0; j < target.length; j++) {
                    if (buf[i + j] != target[j]) { match = false; break; }
                }
                if (!match) continue;
                // Heuristic for very short tags like "LC"/"MR": require alignment
                // and surrounding non-printable so we don't match every substring.
                if (needle.length() <= 2) {
                    if ((i & 1) != 0) continue;
                    boolean leftOk = (i == 0) || !isPrintable(buf[i - 1]);
                    boolean rightOk = (i + target.length == buf.length) || !isPrintable(buf[i + target.length]);
                    if (!(leftOk && rightOk)) continue;
                }

                long hitAddr = start + i;
                int sS = i, sE = i + target.length;
                while (sS > 0 && isPrintable(buf[sS-1])) sS--;
                while (sE < buf.length && isPrintable(buf[sE])) sE++;
                String surround = new String(buf, sS, sE - sS);

                Address a = toAddr(hitAddr);
                pw.printf("  HIT @ 0x%08x : \"%s\"%n", hitAddr, surround);

                ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(a);
                int refCount = 0;
                while (it.hasNext() && refCount < 16) {
                    Reference r = it.next();
                    Function caller = getFunctionContaining(r.getFromAddress());
                    pw.printf("    <- ref from %s in %s (%s)%n",
                            r.getFromAddress(),
                            caller == null ? "(no fn)" : caller.getName() + "@" + caller.getEntryPoint(),
                            r.getReferenceType());
                    if (caller != null) {
                        result.add(caller.getEntryPoint().getOffset());
                    }
                    refCount++;
                }
                if (refCount == 0) {
                    // Also try reference to the run-start address (sS) — some
                    // strings are referenced from their start, not from the
                    // location of the needle.
                    Address runStart = toAddr(start + sS);
                    if (!runStart.equals(a)) {
                        ReferenceIterator it2 = currentProgram.getReferenceManager().getReferencesTo(runStart);
                        while (it2.hasNext() && refCount < 16) {
                            Reference r = it2.next();
                            Function caller = getFunctionContaining(r.getFromAddress());
                            pw.printf("    <- ref from %s in %s (%s) [runStart]%n",
                                    r.getFromAddress(),
                                    caller == null ? "(no fn)" : caller.getName() + "@" + caller.getEntryPoint(),
                                    r.getReferenceType());
                            if (caller != null) {
                                result.add(caller.getEntryPoint().getOffset());
                            }
                            refCount++;
                        }
                    }
                }
            }
        }
        return result;
    }

    private boolean isPrintable(byte b) {
        return (b >= 0x20 && b < 0x7f);
    }

    // ------------------------------------------------------------------
    // 2) Immediate scan: walk every instruction in the listing; flag those
    // whose textual form contains any of our magic constants. Cluster them
    // by containing function for the merged-decompile pass.
    private Set<Long> scanForImmediates() {
        Set<Long> result = new LinkedHashSet<>();
        Listing listing = currentProgram.getListing();
        InstructionIterator it = listing.getInstructions(currentProgram.getMemory(), true);
        TreeMap<Long, List<String>> perFn = new TreeMap<>();
        int totalHits = 0;
        while (it.hasNext()) {
            Instruction ins = it.next();
            String s = ins.toString();
            String hitLabel = null;
            for (long v : IMM_VALUES) {
                String hex1 = String.format("0x%x", v);
                String hex2 = String.format("0x%X", v);
                String pad1 = String.format("0x%04x", v);
                String pad2 = String.format("0x%04X", v);
                if (s.contains(hex1) || s.contains(hex2) || s.contains(pad1) || s.contains(pad2)) {
                    hitLabel = "imm " + hex1;
                    break;
                }
            }
            if (hitLabel == null) continue;
            Function fn = getFunctionContaining(ins.getAddress());
            long key = (fn != null) ? fn.getEntryPoint().getOffset() : 0L;
            perFn.computeIfAbsent(key, k -> new ArrayList<>())
                 .add(String.format("    %s  %s", ins.getAddress(), s));
            totalHits++;
            if (totalHits > 4000) break;
        }
        pw.println("total immediate hits: " + totalHits + "  across " + perFn.size() + " functions");
        for (var entry : perFn.entrySet()) {
            long fnEntry = entry.getKey();
            if (fnEntry == 0L) continue;
            if (isInNetaq(fnEntry)) continue;
            Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(fnEntry));
            pw.printf("  FN %s @ 0x%08x   (%d immediate hits)%n",
                    fn == null ? "?" : fn.getName(), fnEntry, entry.getValue().size());
            int show = Math.min(8, entry.getValue().size());
            for (int i = 0; i < show; i++) pw.println(entry.getValue().get(i));
            result.add(fnEntry);
        }
        return result;
    }

    private boolean isInNetaq(long addr) {
        return addr >= NETAQ_LO && addr <= NETAQ_HI;
    }

    // ------------------------------------------------------------------
    // 3) AVE-TCP API callers (excluding callers in netaq overlay)
    private Set<Long> scanForApiCallers() {
        Set<Long> result = new LinkedHashSet<>();
        ReferenceManager rm = currentProgram.getReferenceManager();
        for (long api : AVETCP_API) {
            pw.printf("# API 0x%08x%n", api);
            Address apiAddr = toAddr(api);
            ReferenceIterator it = rm.getReferencesTo(apiAddr);
            while (it.hasNext()) {
                Reference r = it.next();
                Address from = r.getFromAddress();
                Function caller = getFunctionContaining(from);
                long fnEntry = (caller != null) ? caller.getEntryPoint().getOffset() : from.getOffset();
                boolean inNetaq = isInNetaq(fnEntry);
                pw.printf("  <- %s  fn=%s@0x%08x  type=%s%s%n",
                        from,
                        caller == null ? "(none)" : caller.getName(),
                        fnEntry,
                        r.getReferenceType(),
                        inNetaq ? "   [NETAQ — skipped]" : "");
                if (!inNetaq && caller != null) {
                    result.add(fnEntry);
                }
            }
        }
        return result;
    }

    // ------------------------------------------------------------------
    private void decompileOnce(long entry) {
        if (alreadyDecompiled.contains(entry)) return;
        alreadyDecompiled.add(entry);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry));
        if (fn == null) {
            pw.printf("%n---- no function at 0x%08x ----%n", entry);
            return;
        }
        long size = fn.getBody().getMaxAddress().getOffset() - entry + 1;
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.printf("FN %s @ 0x%08x  size=0x%x%n", fn.getName(), entry, size);

        java.util.Set<Function> callers = fn.getCallingFunctions(monitor);
        java.util.Set<Function> callees = fn.getCalledFunctions(monitor);
        StringBuilder cb = new StringBuilder("  callers:");
        if (callers.isEmpty()) cb.append(" (none)");
        for (Function c : callers) cb.append(" ").append(c.getEntryPoint());
        pw.println(cb);
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
        } catch (Exception e) {
            pw.println("DECOMPILE_EXCEPTION: " + e.getMessage());
        }
    }
}
