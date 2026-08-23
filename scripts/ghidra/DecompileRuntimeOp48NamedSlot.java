import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileRuntimeOp48NamedSlot extends GhidraScript {
    private static final long[] TARGETS = {
        0x005bca90L,
        0x005bc990L,
        0x005bca14L,
        0x005bca30L,
        0x005bdc70L,
        0x005bdf90L,
        0x005c5060L,
        0x005c7e30L
    };

    private static final long[] DATA_TARGETS = {
        0x0087f7f8L,
        0x0087f800L,
        0x00374fa0L,
        0x003797a8L,
        0x003797f8L
    };

    @Override
    public void run() throws Exception {
        String outPath = "D:/projects/pal-outbreak-2-server/analysis/ghidra-runtime-op48-namedslot.txt";
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            pw.println("PAL EE runtime opcode 0x48 named-slot export");
            pw.println("Program: " + currentProgram.getName());
            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            try {
                for (long target : TARGETS) {
                    dumpAddress(ifc, pw, target);
                }
                pw.println();
                pw.println("================================================================");
                pw.println("DATA REFERENCES");
                pw.println("================================================================");
                for (long target : DATA_TARGETS) {
                    dumpReferences(pw, target);
                }
            } finally {
                ifc.dispose();
            }
        }
        println("Done: " + outPath);
    }

    private void dumpAddress(DecompInterface ifc, PrintWriter pw, long entry) throws Exception {
        Address addr = toAddr(entry);
        Function fn = currentProgram.getFunctionManager().getFunctionContaining(addr);
        pw.println();
        pw.println("================================================================");
        pw.printf("TARGET 0x%08x%n", entry);
        if (fn == null) {
            pw.println("NO_CONTAINING_FUNCTION");
            dumpInstructions(pw, addr, 48);
            dumpReferences(pw, entry);
            pw.flush();
            return;
        }
        long start = fn.getEntryPoint().getOffset();
        long size = fn.getBody().getMaxAddress().getOffset() - start + 1;
        pw.printf("FN %s @ 0x%08x size=0x%x%n", fn.getName(), start, size);
        pw.println("callers:");
        for (Function caller : fn.getCallingFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", caller.getEntryPoint().getOffset(), caller.getName());
        }
        pw.println("callees:");
        for (Function callee : fn.getCalledFunctions(monitor)) {
            pw.printf("  0x%08x %s%n", callee.getEntryPoint().getOffset(), callee.getName());
        }
        pw.println();
        pw.println("references to target:");
        for (Reference ref : currentProgram.getReferenceManager().getReferencesTo(addr)) {
            pw.printf("  from 0x%08x type=%s%n", ref.getFromAddress().getOffset(), ref.getReferenceType());
        }
        pw.println();
        pw.println("decompile:");
        DecompileResults result = ifc.decompileFunction(fn, 90, monitor);
        if (result != null && result.decompileCompleted()) {
            pw.println(result.getDecompiledFunction().getC());
        } else {
            pw.println("DECOMPILE_FAILED: " + (result == null ? "null" : result.getErrorMessage()));
        }
        pw.println();
        pw.println("instructions near target:");
        dumpInstructions(pw, addr, 96);
        pw.flush();
    }

    private void dumpInstructions(PrintWriter pw, Address start, int count) {
        Instruction instr = currentProgram.getListing().getInstructionAt(start);
        if (instr == null) {
            instr = currentProgram.getListing().getInstructionAfter(start);
        }
        for (int i = 0; i < count && instr != null; i++) {
            pw.printf("  0x%08x  %-10s %s%n",
                instr.getAddress().getOffset(),
                instr.getMnemonicString(),
                instr.toString());
            instr = instr.getNext();
        }
    }

    private void dumpReferences(PrintWriter pw, long target) {
        Address addr = toAddr(target);
        pw.printf("%n0x%08x references:%n", target);
        int n = 0;
        for (Reference ref : currentProgram.getReferenceManager().getReferencesTo(addr)) {
            CodeUnit cu = currentProgram.getListing().getCodeUnitAt(ref.getFromAddress());
            pw.printf("  from 0x%08x type=%s unit=%s%n",
                ref.getFromAddress().getOffset(),
                ref.getReferenceType(),
                cu == null ? "" : cu.toString());
            n++;
            if (n >= 80) {
                pw.println("  ... truncated");
                break;
            }
        }
        if (n == 0) {
            pw.println("  (none)");
        }
    }
}
