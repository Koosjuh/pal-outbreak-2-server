import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class DecompileDriveeDatPath extends GhidraScript {

    // Primary targets: the main bridge and the DRIVEE.DAT handler
    private static final long[] DECOMPILE_TARGETS = {
        0x001a2220L,  // FUN_001a2220 – full bootstrap bridge
        0x00116cf0L,  // FUN_00116cf0 – DRIVEE.DAT open/handler
    };

    // Report callers for these functions
    private static final long[] CALLER_TARGETS = {
        0x001a2220L,
        0x00116cf0L,
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        Set<Long> decompiledEntries = new HashSet<>();

        // ── Section 1: decompile primary targets ──────────────────────────
        for (long target : DECOMPILE_TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("DECOMPILE TARGET " + addr);
            println("======================================================================");
            Function fn = getFunctionAt(addr);
            if (fn == null) {
                println("No function at " + addr);
                println("");
                continue;
            }
            println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
            decompile(ifc, fn);
            decompiledEntries.add(fn.getEntryPoint().getOffset());
        }

        // ── Section 2: caller lists ────────────────────────────────────────
        for (long target : CALLER_TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("CALLERS OF " + addr);
            println("======================================================================");
            Function fn = getFunctionAt(addr);
            if (fn == null) {
                println("No function at " + addr);
                println("");
                continue;
            }
            Reference[] refs = getReferencesTo(fn.getEntryPoint());
            if (refs.length == 0) {
                println("NO CALLERS");
            }
            for (Reference ref : refs) {
                Function caller = getFunctionContaining(ref.getFromAddress());
                if (caller != null) {
                    println("CALLER: " + caller.getName() + " @ " + caller.getEntryPoint()
                            + " via " + ref.getFromAddress());
                } else {
                    println("CALLER: <no function> via " + ref.getFromAddress());
                }
            }
            println("");
        }

        // ── Section 3: any function that references 0x25b880 or 0x25b884 ──
        // (cross-check: does any callee of FUN_001a2220 write the boot pointers?)
        long[] bootPtrAddrs = { 0x0025b880L, 0x0025b884L };
        println("======================================================================");
        println("REFS TO uRam0025b880 / 0x25b884 (cross-check)");
        println("======================================================================");
        for (long bpa : bootPtrAddrs) {
            Address bpAddr = toAddr(bpa);
            println("--- " + bpAddr + " ---");
            Reference[] refs = getReferencesTo(bpAddr);
            if (refs.length == 0) {
                println("NO REFS");
            }
            for (Reference ref : refs) {
                Function fn = getFunctionContaining(ref.getFromAddress());
                String fnName = (fn != null) ? fn.getName() + " @ " + fn.getEntryPoint() : "<no function>";
                println("REF type=" + ref.getReferenceType() + " from " + ref.getFromAddress() + " in " + fnName);
                // decompile the containing function if not already done
                if (fn != null && decompiledEntries.add(fn.getEntryPoint().getOffset())) {
                    println("  --> decompiling " + fn.getName());
                    decompile(ifc, fn);
                }
            }
        }
        println("");

        ifc.dispose();
    }

    private void decompile(DecompInterface ifc, Function fn) {
        DecompileResults results = ifc.decompileFunction(fn, 120, monitor);
        if (!results.decompileCompleted()) {
            println("DECOMPILE FAILED: " + fn.getName());
            println("");
            return;
        }
        println(results.getDecompiledFunction().getC());
        println("");
    }
}
