import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

public class FindBootWrapperCallers extends GhidraScript {
    private static final long[] TARGETS = { 0x001378a8L, 0x00100b50L };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            Function fn = getFunctionAt(addr);
            if (fn == null) {
                println("No function at " + addr);
                continue;
            }

            println("");
            println("TARGET: " + fn.getName() + " @ " + addr);

            Set<Address> seen = new HashSet<>();
            for (Reference ref : getReferencesTo(addr)) {
                Address from = ref.getFromAddress();
                Function caller = getFunctionContaining(from);
                if (caller == null || !seen.add(caller.getEntryPoint())) {
                    continue;
                }
                println("");
                println("CALLER: " + caller.getName() + " @ " + caller.getEntryPoint());
                println("CALLSITE REF FROM: " + from);
                dumpNearbyInstructions(from);
                dumpArgumentHints(from);
                decompile(ifc, caller);
            }
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
        for (int i = 0; i < 12; i++) {
            Instruction prev = start.getPrevious();
            if (prev == null) {
                break;
            }
            start = prev;
        }
        Instruction cur = start;
        for (int i = 0; i < 28 && cur != null; i++) {
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

        Address a0Addr = null;
        Address a1Addr = null;
        Long a2Value = null;
        Long a3Value = null;

        int steps = 0;
        while (cur != null && steps < 24) {
            cur = cur.getPrevious();
            steps++;
            if (cur == null) {
                break;
            }

            Object[] objs = cur.getOpObjects(0);
            if (objs.length == 0 || !(objs[0] instanceof Register)) {
                continue;
            }
            String regName = ((Register) objs[0]).getName();
            if ("a0".equals(regName) && a0Addr == null) {
                a0Addr = resolveAddressOperand(cur);
            } else if ("a1".equals(regName) && a1Addr == null) {
                a1Addr = resolveAddressOperand(cur);
            } else if ("a2".equals(regName) && a2Value == null) {
                a2Value = resolveScalarValue(cur);
            } else if ("a3".equals(regName) && a3Value == null) {
                a3Value = resolveScalarValue(cur);
            }

            if (a0Addr != null && a1Addr != null && a2Value != null && a3Value != null) {
                break;
            }
        }

        printAddressHint("a0", a0Addr);
        printAddressHint("a1", a1Addr);
        printScalarHint("a2", a2Value);
        printScalarHint("a3", a3Value);
    }

    private void printAddressHint(String label, Address addr) throws Exception {
        if (addr == null) {
            println("  " + label + " candidate: not resolved");
            return;
        }
        println("  " + label + " candidate: " + addr);
        String s = readString(addr);
        if (s != null) {
            println("  " + label + " string: " + s);
        }
    }

    private void printScalarHint(String label, Long value) {
        if (value == null) {
            println("  " + label + " scalar: not resolved");
            return;
        }
        println("  " + label + " scalar: 0x" + Long.toHexString(value) + " (" + value + ")");
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

    private Long resolveScalarValue(Instruction ins) {
        for (int i = 1; i < ins.getNumOperands(); i++) {
            Object[] objs = ins.getOpObjects(i);
            for (Object obj : objs) {
                if (obj instanceof Scalar) {
                    return ((Scalar) obj).getUnsignedValue();
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
