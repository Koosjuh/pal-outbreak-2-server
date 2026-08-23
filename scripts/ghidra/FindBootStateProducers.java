import java.util.HashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class FindBootStateProducers extends GhidraScript {

    // Trace remaining open globals for the PAL async pipeline and BIO-VOL2 late path
    private static final long[] TARGETS = {
        0x00390714L,  // uRam00390714 – must be non-zero for FUN_001f3640 (BIO-VOL2 patch apply)
        0x00388708L,  // iRam00388708 – conditional gate inside FUN_001f3640
        0x003908d4L,  // iRam003908d4 – descriptor table index for PTR_PTR_0024e758
        0x00343650L,  // uRam00343650 – 1st arg to FUN_001f3800 (from FUN_001b41e0)
        0x00343654L,  // uRam00343654 – 2nd arg
        0x00343658L,  // uRam00343658 – 3rd arg
        0x0034363cL,  // uRam0034363c – cleared by FUN_001b9a40/FUN_001b8f30 on fetch success
        0x00343638L,  // uRam00343638 – related fetch-control flag
        0x0037e948L,  // result block written by FUN_001f2938
        0x0036d588L,  // compact browser result published by FUN_001d44f0
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);

        Set<Address> dumped = new HashSet<>();

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("REFS TO " + addr);
            println("======================================================================");

            Reference[] refs = getReferencesTo(addr);
            if (refs.length == 0) {
                println("NO DIRECT REFS");
                println("");
                continue;
            }

            for (Reference ref : refs) {
                Function fn = getFunctionContaining(ref.getFromAddress());
                if (fn == null) {
                    println("REF type=" + ref.getReferenceType()
                        + " from " + ref.getFromAddress() + " in <no function>");
                    continue;
                }
                println("REF type=" + ref.getReferenceType()
                    + " from " + ref.getFromAddress()
                    + " in " + fn.getName() + " @ " + fn.getEntryPoint());
                if (dumped.add(fn.getEntryPoint())) {
                    DecompileResults results = ifc.decompileFunction(fn, 120, monitor);
                    if (results.decompileCompleted()) {
                        println(results.getDecompiledFunction().getC());
                    } else {
                        println("decompile failed");
                    }
                }
            }
            println("");
        }

        ifc.dispose();
    }
}
