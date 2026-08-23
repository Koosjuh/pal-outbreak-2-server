// Find the slot-0x1c REGISTER-reply callback.
//
// We already know FUN_001db7e8 calls FUN_001d4d24(1, 0x1c, param_11) where
// param_11 is the function-pointer the receiver invokes after our reply.
// param_11 comes from FUN_001db7e8's caller(s).  Per refs scan those are
// FUN_001cae70 / FUN_001cadc0 (lobby state machine).
//
// This script:
//   - decompiles FUN_001cae70 / FUN_001cadc0 (the lobby thread/state machine)
//   - finds direct callers of FUN_001db7e8 and FUN_001d4d24 (and the related
//     sender-shells) — extracts the actual function used as the slot callback
//   - decompiles the dispatcher tail of FUN_001d72a8 (slot 0x1c invoke site)
//   - decompiles FUN_001d5460, FUN_001d6468, FUN_001d6dfc (post-parse tail
//     candidates that actually walk the slot table)
//   - decompiles every function whose address is observed to be passed into
//     FUN_001d4d24 as param_3 (the slot-table value).
//
// Output: C:/dnas/active/ghidra_exports/udp9090_callback.txt
//
// Headless invocation:
//   "C:/dnas/tools/ghidra/ghidra/support/analyzeHeadless.bat" \
//     C:/dnas/ghidra_projects ghidra_pal_ee \
//     -process SLES_533.19 -noanalysis -readOnly \
//     -postScript FindSnapCallback.java \
//     -scriptPath C:/dnas/active/ghidra_scripts

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class FindSnapCallback extends GhidraScript {

    private static final long FUN_db7e8 = 0x001db7e8L;
    private static final long FUN_d4d24 = 0x001d4d24L;

    // Lobby state machine & helpers we want full decomp of
    private static final long[] ALWAYS_DUMP = {
        0x001cae70L, // top-level lobby task per recv-path doc
        0x001cadc0L, // companion entry
        0x001ca9d0L, // status helper
        0x001d72a8L, // recv parser tail
        0x001d6988L, // fragment / reassembly handler
        0x001d5460L, // post-parse opcode dispatcher (suspected slot-table user)
        0x001d6468L, // helper called from FUN_001d72a8 timer branch
        0x001d6dfcL, // sub-dispatcher referenced from FUN_001d72a8 fall-through
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_callback.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" PAL EE slot-0x1c REGISTER-reply callback hunt");
            pw.println(" Program: " + currentProgram.getName());
            pw.println("================================================================");

            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            ReferenceManager rm = currentProgram.getReferenceManager();

            // ---- 1) List callers of FUN_001db7e8 ----
            pw.println();
            pw.println("# refs to FUN_001db7e8 (REGISTER sender)");
            Set<Long> regCallers = new LinkedHashSet<>();
            for (ReferenceIterator it = rm.getReferencesTo(toAddr(FUN_db7e8)); it.hasNext(); ) {
                Reference r = it.next();
                Function caller = getFunctionContaining(r.getFromAddress());
                pw.printf("  <- %s  fn=%s%s  type=%s%n",
                        r.getFromAddress(),
                        caller == null ? "(none)" : caller.getName(),
                        caller == null ? "" : "@0x" + Long.toHexString(caller.getEntryPoint().getOffset()),
                        r.getReferenceType());
                if (caller != null) regCallers.add(caller.getEntryPoint().getOffset());
            }

            // ---- 2) List callers of FUN_001d4d24 (slot-table writer) ----
            pw.println();
            pw.println("# refs to FUN_001d4d24 (slot-table writer)");
            Set<Long> slotCallers = new LinkedHashSet<>();
            for (ReferenceIterator it = rm.getReferencesTo(toAddr(FUN_d4d24)); it.hasNext(); ) {
                Reference r = it.next();
                Function caller = getFunctionContaining(r.getFromAddress());
                if (caller != null) slotCallers.add(caller.getEntryPoint().getOffset());
            }
            pw.println("  (will decompile each below)");

            // ---- 3) Walk every FUN_001d4d24 callsite; print the (idx, fnptr) pair ----
            pw.println();
            pw.println("# every FUN_001d4d24(1, idx, fnptr) callsite — extract slot idx + fnptr operand");
            Set<Long> callbackFns = new LinkedHashSet<>();
            for (ReferenceIterator it = rm.getReferencesTo(toAddr(FUN_d4d24)); it.hasNext(); ) {
                Reference r = it.next();
                Address callAddr = r.getFromAddress();
                Function caller = getFunctionContaining(callAddr);
                // Scan backwards up to 24 instructions to harvest register loads
                StringBuilder ctx = new StringBuilder();
                Address cur = callAddr;
                int back = 0;
                long idx = -1, fnptr = -1;
                while (cur != null && back < 30) {
                    Instruction ins = getInstructionAt(cur);
                    if (ins == null) { cur = cur.subtract(4); back++; continue; }
                    ctx.insert(0, String.format("    %s  %-8s %s%n",
                            cur, ins.getMnemonicString(), ins.getDefaultOperandRepresentation(0) +
                                    (ins.getNumOperands() > 1 ? ", " + ins.getDefaultOperandRepresentation(1) : "") +
                                    (ins.getNumOperands() > 2 ? ", " + ins.getDefaultOperandRepresentation(2) : "")));
                    String m = ins.getMnemonicString();
                    if (m.equals("addiu") || m.equals("li") || m.equals("ori")) {
                        // MIPS: addiu $a1, $zero, 0x1c  ->  arg1 = 0x1c (slot idx)
                        // we want to identify $a1 loads (= slot idx) and $a2 (= fnptr if computed)
                        String dst = ins.getDefaultOperandRepresentation(0);
                        try {
                            Scalar sc = ins.getScalar(ins.getNumOperands() - 1);
                            if (sc != null) {
                                if (dst.contains("a1") && idx < 0) idx = sc.getValue() & 0xffffffffL;
                                if (dst.contains("a2") && fnptr < 0) fnptr = sc.getValue() & 0xffffffffL;
                            }
                        } catch (Exception ignore) {}
                    }
                    if (m.equals("lui")) {
                        String dst = ins.getDefaultOperandRepresentation(0);
                        try {
                            Scalar sc = ins.getScalar(ins.getNumOperands() - 1);
                            if (sc != null && dst.contains("a2")) {
                                // Top 16 bits of fnptr — may be combined w/ later addiu/ori
                                fnptr = (sc.getValue() & 0xffffL) << 16;
                            }
                        } catch (Exception ignore) {}
                    }
                    cur = cur.subtract(4);
                    back++;
                }
                pw.printf("%n  ## FUN_001d4d24 call @ %s  in %s%n",
                        callAddr, caller == null ? "(none)" : caller.getName());
                pw.print(ctx);
                pw.printf("    -> idx=0x%x  fnptr_guess=0x%08x%n", idx, fnptr);
                if (fnptr > 0x00100000L && fnptr < 0x00400000L) callbackFns.add(fnptr);
            }

            // ---- 4) Decompile lobby state machine + helpers ----
            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE: lobby state machine & related");
            pw.println("================================================================");
            decompileOnce(0x001cae70L);
            decompileOnce(0x001cadc0L);
            decompileOnce(0x001ca9d0L);

            // ---- 5) Decompile every direct caller of FUN_001db7e8 ----
            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE: direct callers of FUN_001db7e8");
            pw.println("================================================================");
            for (Long c : regCallers) decompileOnce(c);

            // ---- 6) Decompile post-parse dispatcher tail ----
            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE: post-parse dispatcher candidates");
            pw.println("================================================================");
            decompileOnce(0x001d5460L);
            decompileOnce(0x001d6468L);
            decompileOnce(0x001d6dfcL);
            decompileOnce(0x001d53ccL);

            // ---- 7) Decompile every callback function we extracted ----
            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE: callback functions extracted from FUN_001d4d24 args");
            pw.println("================================================================");
            for (Long c : callbackFns) decompileOnce(c);

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
            // Try containing fn
            fn = getFunctionContaining(toAddr(entry));
        }
        if (fn == null) {
            pw.printf("%n---- no function at 0x%08x ----%n", entry);
            return;
        }
        long e = fn.getEntryPoint().getOffset();
        if (e != entry && dumped.contains(e)) return;
        dumped.add(e);
        long size = fn.getBody().getMaxAddress().getOffset() - e + 1;
        pw.println();
        pw.println("----------------------------------------------------------------");
        pw.printf("FN %s @ 0x%08x  size=0x%x%n", fn.getName(), e, size);
        java.util.Set<Function> callers = fn.getCallingFunctions(monitor);
        StringBuilder cb = new StringBuilder("  callers:");
        if (callers.isEmpty()) cb.append(" (none)");
        for (Function c : callers) cb.append(" ").append(c.getEntryPoint());
        pw.println(cb);
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
