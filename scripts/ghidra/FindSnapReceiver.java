// Follow-up scan: find the UDP 9090 RECEIVE handler.
//
// The SN@P state struct is at DAT_0025b78c.  The send function FUN_001db7e8
// stores headers into iVar1+0x84..0xa4 then calls AVE-TCP send.
// Look for:
//   - callers / readers of DAT_0025b78c outside FUN_001d46ec/FUN_001db7e8
//   - callers of FUN_001ebed0 (socket alloc) and the dispatcher tied to its
//     handle (stored at puVar1[0x148]).
//   - functions that read short patterns: byte at off 2 / 3 of incoming packet
//     (which corresponds to packet type 0x86 we just sent), or extract LC/MR tags.
//
// Also dump the AVE-TCP API stubs themselves so we know which call is recv.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
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
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeMap;

public class FindSnapReceiver extends GhidraScript {

    // Read targets: addresses we want to find readers/writers of.
    private static final long[] TARGETS = {
        0x0025b78cL, // SN@P state pointer
        0x0025b790L, // SN@P last error code
        0x001ebed0L, // socket-alloc helper
        0x001ed2c0L, // peek/get-buffer helper (?)
        0x001e180cL, // AVE-TCP send-buf
        0x001bd360L, // AVE-TCP send
        0x001bd940L, // AVE-TCP poll
        0x001bda00L, // AVE-TCP peek
        0x001bda30L, // AVE-TCP handler
        0x001bda40L, // AVE-TCP commit
        0x001bdb20L, // AVE-TCP init buf
    };

    // Functions whose decompile we always want to see (these *are* the helpers
    // the send path uses; the receive path will use related ones).
    private static final long[] ALWAYS_DUMP = {
        0x001ebed0L, // socket alloc
        0x001ed2c0L, // ?
        0x001ed74cL, // peek in send path
        0x001eabc0L, 0x001eac0cL, 0x001ead70L, 0x001eaddcL, // TLV build helpers
        0x001e180cL, // send-buf
        0x001e2304L, 0x001e2928L, // byte-swap helpers
        0x001d507cL, // socket bind
        0x001d5288L, // socket-something
        0x001d533cL, 0x001d53ccL, // dispatch
        0x001d4d24L, // event post
    };

    private PrintWriter pw;
    private DecompInterface ifc;
    private Set<Long> dumped = new HashSet<>();

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_recv.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        pw = new PrintWriter(bw);

        try {
            pw.println("================================================================");
            pw.println(" PAL EE UDP 9090 receive-path hunt");
            pw.println(" Program: " + currentProgram.getName());
            pw.println("================================================================");

            ifc = new DecompInterface();
            ifc.openProgram(currentProgram);

            ReferenceManager rm = currentProgram.getReferenceManager();

            // 1) For each target address, list all references and the
            //    containing function.
            Set<Long> fnsToDump = new LinkedHashSet<>();
            for (long tgt : TARGETS) {
                pw.printf("%n# refs to 0x%08x%n", tgt);
                Address a = toAddr(tgt);
                ReferenceIterator it = rm.getReferencesTo(a);
                int count = 0;
                while (it.hasNext()) {
                    Reference r = it.next();
                    Function caller = getFunctionContaining(r.getFromAddress());
                    pw.printf("  <- %s  fn=%s%s  type=%s%n",
                            r.getFromAddress(),
                            caller == null ? "(none)" : caller.getName(),
                            caller == null ? "" : "@0x" + Long.toHexString(caller.getEntryPoint().getOffset()),
                            r.getReferenceType());
                    if (caller != null) fnsToDump.add(caller.getEntryPoint().getOffset());
                    count++;
                    if (count > 50) { pw.println("  ... (truncated)"); break; }
                }
            }

            // 2) Also dump the always-dump set
            for (long a : ALWAYS_DUMP) fnsToDump.add(a);

            // 3) Decompile each
            pw.println();
            pw.println("================================================================");
            pw.println(" DECOMPILE  (" + fnsToDump.size() + " functions)");
            pw.println("================================================================");
            for (Long entry : fnsToDump) decompileOnce(entry);

            ifc.dispose();
            println("Receiver hunt complete. Output: " + outPath);
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
        pw.flush();
    }
}
