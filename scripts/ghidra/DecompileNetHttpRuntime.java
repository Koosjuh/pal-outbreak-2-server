// Decompile the PAL nethttp.bin overlay functions observed at runtime.
// Import BIN\5.DAT as raw MIPS:LE:64 at image base 0x011c0000 before running.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileNetHttpRuntime extends GhidraScript {
    private static final long[] TARGETS = {
        0x011c43c0L, // option/config parser around callback fields
        0x011c0330L,
        0x011c0588L,
        0x011c06b8L,
        0x011c0b68L,
        0x011c0ca0L,
        0x011c0ea0L,
        0x011c10d0L,
        0x011c1d88L,
        0x011c2cc0L,
        0x011c2d10L, // state 05 worker that returns -1 in live run
        0x011c2e88L, // state 05 async launcher
        0x011c3058L, // state 06 response/body accessor
        0x011c4d90L, // cancel/cleanup helper
        0x011c4df8L, // async callback marks bit 0x04 and wakes semaphore
        0x011c4e30L, // line/body receive helper
        0x011c4f90L, // response parser helper
        0x011c5440L, // runtime thread entry seen in PCSX2 during login
        0x011c56c0L, // caller of 0x011c5440 when no async callback is configured
        0x011c5818L,
        0x011c5918L,
        0x011c5a08L,
        0x011c5af8L, // runtime worker thread seen in PCSX2 during login
        0x011c5ba8L, // runtime worker thread seen in PCSX2 during login
        0x011c6050L,
        0x011c6198L,
        0x011c62e0L,
        0x011ca7c0L,
        0x01212a80L, // callback dispatcher / jump table nearby observed callback
        0x01212aa0L, // observed callback target, stores result byte to *a2
        0x01212ab0L,
        0x01212ac0L,
        0x01213710L, // dispatcher state 04
        0x01213980L, // dispatcher state 05
        0x01213be0L, // dispatcher state 06
        0x01213cd0L, // dispatcher state 07
        0x01213e30L,
        0x01213ef4L,
        0x01213f48L,
        0x01214000L,
        0x01214100L,
        0x01214400L,
        0x01214570L,
        0x01214580L,
        0x012147b0L,
        0x012147c0L,
        0x01214890L,
        0x01214950L,
        0x01214960L,
        0x01214980L,
        0x01214990L,
        0x012149f0L,
        0x01214a00L
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        for (long target : TARGETS) {
            Address addr = toAddr(target);
            Function fn = getFunctionAt(addr);
            if (fn == null) {
                fn = createFunction(addr, "nethttp_" + Long.toHexString(target));
            }

            println("============================================================");
            println(fn.getName() + " @ " + addr);
            DecompileResults res = ifc.decompileFunction(fn, 30, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED: " + (res == null ? "null result" : res.getErrorMessage()));
            }
        }

        ifc.dispose();
    }
}
