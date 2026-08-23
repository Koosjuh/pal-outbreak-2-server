// Codex-owned instruction dump for initial SN@P callback targets.
// Output: C:/dnas/active/ghidra_exports/codex_snap_initial_callbacks.txt

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DumpSnapInitialCallbacks extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/codex_snap_initial_callbacks.txt";
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            pw.println("PAL EE SN@P initial callback instruction dump");
            pw.println("Program: " + currentProgram.getName());
            dumpRange(pw, 0x001cac40L, 0x001cadc0L);
        }
        println("Done: " + outPath);
    }

    private void dumpRange(PrintWriter pw, long start, long end) {
        pw.printf("%nRange 0x%08x..0x%08x%n", start, end);
        Address addr = toAddr(start);
        while (addr.getOffset() < end && !monitor.isCancelled()) {
            Instruction ins = currentProgram.getListing().getInstructionAt(addr);
            if (ins == null) {
                pw.printf("0x%08x  <no instruction>%n", addr.getOffset());
                addr = addr.add(4);
                continue;
            }
            StringBuilder operands = new StringBuilder();
            for (int i = 0; i < ins.getNumOperands(); i++) {
                if (i > 0) {
                    operands.append(", ");
                }
                operands.append(ins.getDefaultOperandRepresentation(i));
            }
            pw.printf("0x%08x  %-8s %s%n", addr.getOffset(), ins.getMnemonicString(), operands);
            addr = ins.getMaxAddress().add(1);
        }
    }
}
