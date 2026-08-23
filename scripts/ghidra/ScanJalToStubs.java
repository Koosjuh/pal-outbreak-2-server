// Manually decode every JAL instruction in .text and check if its target
// falls inside the import stub region (0x3614..0x3728). This bypasses
// Ghidra's xref tracking which appears to miss the stub calls.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import java.util.*;

public class ScanJalToStubs extends GhidraScript {
    @Override
    public void run() throws Exception {
        // Label every import stub by name
        Map<Long,String> stubs = new LinkedHashMap<>();
        stubs.put(0x3500L,"iopint_entry");       // _start
        stubs.put(0x3508L,"iopint_init?");
        stubs.put(0x3510L,"iopint_shutdown?");
        stubs.put(0x3518L,"iopint_unk4?");
        stubs.put(0x3614L,"avetcp[4]");
        stubs.put(0x361cL,"avetcp[0x20]");
        stubs.put(0x3624L,"avetcp[0x24]");
        stubs.put(0x3648L,"devglue[4]");
        stubs.put(0x3650L,"devglue[5]");
        stubs.put(0x3658L,"devglue[6]");
        stubs.put(0x3660L,"devglue[7]");
        stubs.put(0x3668L,"devglue[8]");
        stubs.put(0x368cL,"intrman_CpuSuspendIntr");
        stubs.put(0x3694L,"intrman_CpuResumeIntr");
        stubs.put(0x36b8L,"loadcore[6]");
        stubs.put(0x36c0L,"loadcore[7]");
        stubs.put(0x36e4L,"sif_RpcQueueInit");
        stubs.put(0x36ecL,"sif_ExecRequest");
        stubs.put(0x36f4L,"sif_RegisterRpc");
        stubs.put(0x36fcL,"sif_RemoveRpc");
        stubs.put(0x3704L,"sif_RemoveRpcQueue");
        stubs.put(0x3728L,"stdio[4]");
        stubs.put(0x374cL,"sysclib[0xc]");
        stubs.put(0x3754L,"sysclib[0x1e]");
        stubs.put(0x3778L,"thbase[4]");
        stubs.put(0x3780L,"thbase[5]");
        stubs.put(0x3788L,"thbase[6]");
        stubs.put(0x3790L,"thbase[8]");
        stubs.put(0x3798L,"thbase[0xa]");
        stubs.put(0x37a0L,"thbase[0x14]");
        stubs.put(0x37c4L,"thevent[4]");
        stubs.put(0x37ccL,"thevent[5]");
        stubs.put(0x37d4L,"thevent[6]");
        stubs.put(0x37dcL,"thevent[0xa]");
        stubs.put(0x3800L,"thsemap[4]");
        stubs.put(0x3808L,"thsemap[5]");
        stubs.put(0x3810L,"thsemap[6]");
        stubs.put(0x3818L,"thsemap[8]");

        // Map: stub -> list of (caller_fn, call_addr)
        Map<Long,List<String>> callers = new LinkedHashMap<>();
        for (Long s : stubs.keySet()) callers.put(s, new ArrayList<>());

        // Walk every function and its instructions
        var fnMgr = currentProgram.getFunctionManager();
        for (Function fn : (Iterable<Function>) (() -> fnMgr.getFunctions(true))) {
            long entry = fn.getEntryPoint().getOffset();
            if (entry >= 0x3500) continue; // skip the stubs themselves
            for (Instruction ins : (Iterable<Instruction>) (() -> currentProgram.getListing().getInstructions(fn.getBody(), true))) {
                String mn = ins.getMnemonicString();
                if (!mn.equals("jal") && !mn.equals("j") && !mn.equals("_jal") && !mn.equals("_j")) continue;
                Object[] os = ins.getOpObjects(0);
                if (os.length == 0) continue;
                Object o = os[0];
                long tgt = -1;
                if (o instanceof ghidra.program.model.address.Address) {
                    tgt = ((Address)o).getOffset();
                } else if (o instanceof ghidra.program.model.scalar.Scalar) {
                    tgt = ((ghidra.program.model.scalar.Scalar)o).getUnsignedValue();
                }
                if (tgt < 0) continue;
                if (callers.containsKey(tgt)) {
                    callers.get(tgt).add(String.format("0x%08x in %s", ins.getAddress().getOffset(), fn.getName()));
                }
            }
        }

        // Report
        println("=== JAL targets to import stubs ===");
        for (var e : stubs.entrySet()) {
            List<String> cs = callers.get(e.getKey());
            println(String.format("0x%08x  %-26s  %d caller(s)", e.getKey(), e.getValue(), cs.size()));
            for (String c : cs) println("    " + c);
        }

        // Also: decompile any function that calls sif_RegisterRpc / RpcQueueInit / ExecRequest
        println("\n=== Decompile of callers of sif_RegisterRpc / RpcQueueInit / ExecRequest ===");
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Set<Long> seen = new HashSet<>();
        long[] keys = {0x36e4L, 0x36ecL, 0x36f4L};
        for (long k : keys) {
            for (String c : callers.get(k)) {
                String[] parts = c.split(" in ");
                String fname = parts[1];
                Function fn = null;
                for (Function f : (Iterable<Function>) (() -> fnMgr.getFunctions(true))) {
                    if (f.getName().equals(fname)) { fn = f; break; }
                }
                if (fn == null || !seen.add(fn.getEntryPoint().getOffset())) continue;
                println("---- " + fn.getName() + " (calls " + stubs.get(k) + ") ----");
                DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
                if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
            }
        }
        ifc.dispose();
    }
}
