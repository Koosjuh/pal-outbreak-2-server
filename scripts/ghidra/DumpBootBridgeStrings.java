import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;

public class DumpBootBridgeStrings extends GhidraScript {
    private static final long[] STRING_TARGETS = {
        0x00245800L,  // context around DAT_00245808 / DAT_00245810 (stage-load triggers)
        0x00245808L,  // DAT_00245808 – "load stage X" trigger (= 3 -> load netwk.bin)
        0x00245810L,  // DAT_00245810 – second stage trigger
        0x00245818L,  // nearby
        0x00230d40L,  // stage destination table continuation (stages 8-15)
    };
    private static final long FUNC_TARGET = 0x001b2b80L;  // FUN_001b2b80 – called from FUN_001b2b20, might set stage triggers

    @Override
    protected void run() throws Exception {
        dumpStrings();
        dumpFunction();
    }

    private void dumpStrings() throws Exception {
        println("======================================================================");
        println("STRING TARGETS");
        println("======================================================================");
        for (long target : STRING_TARGETS) {
            Address addr = toAddr(target);
            println("TARGET " + addr);
            println("ASCII: " + readAscii(addr, 128));
            println("HEX:   " + readHex(addr, 32));
            println("");
        }
    }

    private void dumpFunction() throws Exception {
        Address addr = toAddr(FUNC_TARGET);
        println("======================================================================");
        println("FUNCTION TARGET " + addr);
        println("======================================================================");
        Function fn = getFunctionAt(addr);
        if (fn == null) {
            println("No function at " + addr);
            return;
        }

        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
        DecompileResults results = ifc.decompileFunction(fn, 90, monitor);
        println("DECOMPILE:");
        if (results.decompileCompleted()) {
            println(results.getDecompiledFunction().getC());
        } else {
            println("decompile failed");
        }
        println("");
        println("CALLERS:");
        Set<Address> seen = new HashSet<>();
        for (Reference ref : getReferencesTo(addr)) {
            Function caller = getFunctionContaining(ref.getFromAddress());
            if (caller == null || !seen.add(caller.getEntryPoint())) {
                continue;
            }
            println("- " + caller.getName() + " @ " + caller.getEntryPoint() +
                " via " + ref.getFromAddress());
        }
        ifc.dispose();
    }

    private String readAscii(Address addr, int maxLen) throws Exception {
        Memory mem = currentProgram.getMemory();
        if (!mem.contains(addr)) {
            return "<unmapped>";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < maxLen; i++) {
            byte b = mem.getByte(addr.add(i));
            if (b == 0) {
                break;
            }
            if (b < 0x20 || b > 0x7e) {
                sb.append(String.format("\\x%02x", b & 0xff));
            } else {
                sb.append((char) b);
            }
        }
        return sb.toString();
    }

    private String readHex(Address addr, int len) throws Exception {
        Memory mem = currentProgram.getMemory();
        if (!mem.contains(addr)) {
            return "<unmapped>";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            if (i != 0) {
                sb.append(' ');
            }
            sb.append(String.format("%02x", mem.getByte(addr.add(i)) & 0xff));
        }
        return sb.toString();
    }
}
