import java.util.ArrayList;
import java.util.List;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

public class FindBootServiceCallers extends GhidraScript {
    private static final long TARGET = 0x00100838L;

    @Override
    protected void run() throws Exception {
        Address targetAddr = toAddr(TARGET);
        Function targetFn = getFunctionAt(targetAddr);
        if (targetFn == null) {
            println("No function at " + targetAddr);
            return;
        }

        println("TARGET: " + targetFn.getName() + " @ " + targetAddr);

        DecompInterface ifc = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        ifc.setOptions(options);
        ifc.openProgram(currentProgram);

        List<Function> seen = new ArrayList<>();

        for (Reference ref : getReferencesTo(targetAddr)) {
            Address from = ref.getFromAddress();
            Function caller = getFunctionContaining(from);
            if (caller == null || seen.contains(caller)) {
                continue;
            }
            seen.add(caller);

            println("");
            println("CALLER: " + caller.getName() + " @ " + caller.getEntryPoint());
            println("CALLSITE REF FROM: " + from);
            dumpNearbyInstructions(from);
            dumpArgumentHints(from);
            decompile(ifc, caller);
        }

        ifc.dispose();
    }

    private void dumpNearbyInstructions(Address callAddr) {
        println("NEARBY INSTRUCTIONS:");
        Instruction ins = getInstructionAt(callAddr);
        if (ins == null) {
            println("  no instruction at callsite");
            return;
        }
        Instruction start = ins;
        for (int i = 0; i < 10; i++) {
            Instruction prev = start.getPrevious();
            if (prev == null) {
                break;
            }
            start = prev;
        }
        Instruction cur = start;
        for (int i = 0; i < 24 && cur != null; i++) {
            String marker = cur.getAddress().equals(callAddr) ? ">>" : "  ";
            println(marker + " " + cur.getAddress() + ": " + cur);
            cur = cur.getNext();
        }
    }

    private void dumpArgumentHints(Address callAddr) throws Exception {
        println("ARGUMENT HINTS:");
        Instruction cur = getInstructionAt(callAddr);
        if (cur == null) {
            println("  unavailable");
            return;
        }

        Address a1Addr = null;
        Scalar a2Scalar = null;
        int steps = 0;
        while (cur != null && steps < 18) {
            cur = cur.getPrevious();
            steps++;
            if (cur == null) {
                break;
            }
            Object[] objs = cur.getOpObjects(0);
            if (objs.length == 0 || !(objs[0] instanceof ghidra.program.model.lang.Register)) {
                continue;
            }
            String regName = ((ghidra.program.model.lang.Register) objs[0]).getName();
            if ("a1".equals(regName) && a1Addr == null) {
                a1Addr = resolveAddressOperand(cur);
            }
            if ("a2".equals(regName) && a2Scalar == null) {
                a2Scalar = resolveScalarOperand(cur);
            }
            if (a1Addr != null && a2Scalar != null) {
                break;
            }
        }

        if (a1Addr != null) {
            println("  a1 candidate: " + a1Addr);
            String s = readString(a1Addr);
            if (s != null) {
                println("  a1 string: " + s);
            }
        } else {
            println("  a1 candidate: not resolved");
        }

        if (a2Scalar != null) {
            println("  a2 scalar: 0x" + Long.toHexString(a2Scalar.getUnsignedValue()) +
                " (" + a2Scalar.getUnsignedValue() + ")");
        } else {
            println("  a2 scalar: not resolved");
        }
    }

    private Address resolveAddressOperand(Instruction ins) {
        for (int i = 1; i < ins.getNumOperands(); i++) {
            Object[] objs = ins.getOpObjects(i);
            for (Object obj : objs) {
                if (obj instanceof Address) {
                    return (Address) obj;
                }
                if (obj instanceof Scalar) {
                    long value = ((Scalar) obj).getUnsignedValue();
                    if (value >= 0x1000 && value < 0x300000) {
                        return toAddr(value);
                    }
                }
            }
        }
        return null;
    }

    private Scalar resolveScalarOperand(Instruction ins) {
        for (int i = 1; i < ins.getNumOperands(); i++) {
            Object[] objs = ins.getOpObjects(i);
            for (Object obj : objs) {
                if (obj instanceof Scalar) {
                    return (Scalar) obj;
                }
            }
        }
        return null;
    }

    private String readString(Address addr) throws Exception {
        Memory mem = currentProgram.getMemory();
        if (!mem.contains(addr)) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 96; i++) {
            byte b = mem.getByte(addr.add(i));
            if (b == 0) {
                break;
            }
            if (b < 0x20 || b > 0x7e) {
                return null;
            }
            sb.append((char) b);
        }
        return sb.length() == 0 ? null : sb.toString();
    }

    private void decompile(DecompInterface ifc, Function fn) {
        println("DECOMPILE:");
        DecompileResults results = ifc.decompileFunction(fn, 60, monitor);
        if (!results.decompileCompleted()) {
            println("  decompile failed");
            return;
        }
        println(results.getDecompiledFunction().getC());
    }
}
