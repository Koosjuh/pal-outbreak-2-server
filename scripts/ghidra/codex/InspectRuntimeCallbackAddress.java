// Codex-owned probe for runtime callback address 0x00626730.
// Output: C:/dnas/active/ghidra_exports/codex_runtime_callback_00626730.txt

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class InspectRuntimeCallbackAddress extends GhidraScript {
    private static final long TARGET = 0x00626730L;

    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/codex_runtime_callback_00626730.txt";
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            pw.println("Runtime callback probe: 0x00626730");
            pw.println("Program: " + currentProgram.getName());
            pw.println();

            pw.println("Memory blocks:");
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                pw.printf("  %-24s 0x%08x..0x%08x exec=%s read=%s write=%s%n",
                    block.getName(),
                    block.getStart().getOffset(),
                    block.getEnd().getOffset(),
                    block.isExecute(),
                    block.isRead(),
                    block.isWrite());
            }
            pw.println();

            Address target = toAddr(TARGET);
            MemoryBlock containing = currentProgram.getMemory().getBlock(target);
            pw.println("Target block: " + (containing == null ? "<none>" : containing.getName()));

            Function exact = currentProgram.getFunctionManager().getFunctionAt(target);
            Function containingFn = currentProgram.getFunctionManager().getFunctionContaining(target);
            pw.println("Function at target: " + fmtFunction(exact));
            pw.println("Function containing target: " + fmtFunction(containingFn));
            pw.println();

            if (containing != null) {
                pw.println("Instructions around target:");
                Address start = target.subtract(0x40);
                Address end = target.add(0x80);
                Address addr = start;
                while (addr.compareTo(end) <= 0 && !monitor.isCancelled()) {
                    Instruction ins = currentProgram.getListing().getInstructionAt(addr);
                    if (ins == null) {
                        pw.printf("0x%08x  <no instruction>%n", addr.getOffset());
                        addr = addr.add(4);
                        continue;
                    }
                    StringBuilder ops = new StringBuilder();
                    for (int i = 0; i < ins.getNumOperands(); i++) {
                        if (i > 0) ops.append(", ");
                        ops.append(ins.getDefaultOperandRepresentation(i));
                    }
                    pw.printf("0x%08x  %-8s %s%n", addr.getOffset(), ins.getMnemonicString(), ops);
                    addr = ins.getMaxAddress().add(1);
                }
                pw.println();

                Function toDecompile = exact != null ? exact : containingFn;
                if (toDecompile != null) {
                    DecompInterface ifc = new DecompInterface();
                    ifc.openProgram(currentProgram);
                    DecompileResults res = ifc.decompileFunction(toDecompile, 90, monitor);
                    pw.println("Decompile:");
                    if (res != null && res.decompileCompleted()) {
                        pw.println(res.getDecompiledFunction().getC());
                    } else {
                        pw.println("DECOMPILE_FAILED: " + (res == null ? "null" : res.getErrorMessage()));
                    }
                    ifc.dispose();
                }
            }
        }
        println("Done: " + outPath);
    }

    private String fmtFunction(Function fn) {
        if (fn == null) return "<none>";
        return fn.getName() + " @ 0x" + Long.toHexString(fn.getEntryPoint().getOffset());
    }
}
