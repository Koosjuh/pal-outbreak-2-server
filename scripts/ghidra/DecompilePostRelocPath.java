import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;

public class DecompilePostRelocPath extends GhidraScript {

    // Targets: functions that set cRam0036d648 (0x36d648) and iRam0036d644 (0x36d644)
    private static final long[] DECOMPILE_TARGETS = {
        0x001f30d0L,  // FUN_001f30d0 – called from FUN_001f2938 after slot match; likely sets 0x36d648
        0x001f2fc8L,  // FUN_001f2fc8 – called at start of FUN_001f2938 processing
        0x001f2ff8L,  // FUN_001f2ff8 – sends slot update; may update 0x36d644
        0x001f3068L,  // FUN_001f3068 – called from FUN_001f2938 on bRam0037ea81==0 path
        0x001f2a60L,  // nearby in the 0x1f2xxx cluster
        0x001f2b40L,  // nearby
        0x001f2ba0L,  // nearby
        0x001af870L,  // FUN_001af870 – slot cleanup
        0x001af570L,  // FUN_001af570 - stage-trigger consumer
        0x001af800L,  // slot registration helper
        0x001afa00L,  // small wrapper around FUN_001af990
        0x001afa30L,  // wrapper around FUN_001af990 used after browser success
        0x001afa60L,  // small wrapper around FUN_001af990
        0x001afba0L,  // called from FUN_001b2b80; possible bridge into stage-3 queue
        0x001afac0L,  // small wrapper around FUN_001af990
        0x001afb00L,  // small wrapper around FUN_001af990
        0x001afc40L,  // multi-call state handler candidate around browser flow
        0x001b1fb0L,  // FUN_001b1fb0 - registered in slot 14 during DNAS auth wait
        0x001b3ef0L,  // initial browser state path that may gate result publication
        0x001b3ba0L,  // FUN_001b3ba0 – called from FUN_001b3720 (post-boot network state setup)
        0x001b4920L,  // FUN_001b4920 – used in FUN_001b3ef0 via FUN_001af970(0, 0x1b4920)
        0x001afb40L,  // FUN_001afb40 – called from FUN_001af570 (state machine), checks something
        0x001a7f40L,  // FUN_001a7f40 – called from FUN_001af570 on condition
        0x001b3750L,  // FUN_001b3750 – called from FUN_001af570 on condition
        0x001a78a0L,  // browser-side setup path that reaches FUN_001b48b0
        0x001b3f70L,  // browser-side helper that reaches FUN_001b48b0
        0x0017e470L,  // imported callback iterator run after staged blob import
        0x001a02d0L,  // browser-launch-side setup called by the late package reset wrapper
        0x001a0320L,  // small stage-control helper on the 4/6 path
        0x001a0000L,  // staged BIN resource loader helper
        0x001a00a0L,  // staged BIN importer
        0x001a73a0L,  // immediate pre-reset setup called from FUN_001b2810
        0x001b2720L,  // helper called just before selector-driven staged import re-entry
        0x001b41e0L,  // late failure/recovery branch
        0x001b7ff0L,  // shared dispatcher that chooses between the upstream selector-seed consumers
        0x001b8f30L,  // async launcher used by browser/state dispatcher
        0x001b96f0L,  // async launcher used by browser/state dispatcher
        0x001b84e0L,  // caller of FUN_001bc5c0; upstream record-selection path
        0x001b8a80L,  // caller of FUN_001bc5c0; alternate upstream record-selection path
        0x001f4770L,  // async request helper used after selector-seed record consumption
        0x001f4980L,  // async request launcher used before waiting on FUN_001f5620
        0x001f50c0L,  // async mode/control helper used around success transitions
        0x001f5620L,  // async completion/status poller used by 001b84e0/001b8a80
        0x001f5630L,  // sibling poll/helper used by 001b8a80
        0x001bc470L,  // small stage-control/helper path referenced near the 4/6 flow
        0x001bc4b0L,  // secondary helper fed from record+0x30 after FUN_001bc470
        0x001bc5c0L,  // caller that feeds FUN_001bc470 with the 16-byte selector seed block
        0x001bc620L,  // thin wrapper around FUN_001bcac0
        0x001bc650L,  // thin wrapper around FUN_001bcac0
        0x001bc6a0L,  // thin wrapper around FUN_001bcac0
        0x001bc720L,  // thin wrapper around FUN_001bcac0
        0x001bca00L,  // special-case validator used by FUN_001bcac0 when param_3 == 5
        0x001bcac0L,  // validator/locator used before the selector seed is consumed
        0x001bc1c0L,  // follow-up called when FUN_001f3800 succeeds
        0x001c4100L,  // upstream consumer of the 0x245e38 version token block
        0x001d1110L,  // nearby profile/content loader previously seen in the browser success path
        0x001d12c0L,  // called during browser online-mode setup from FUN_001b3f70
        0x001f15b0L,  // nearby 1fxxxx family user of the same compare primitive
        0x001f35c0L,  // adjacent setup helper using the same 0x245e38 block
        0x001f3600L,  // immediate neighbor inside the package cluster
        0x001f3640L,  // stage helper reused by the late setter path
        0x001f37d0L,  // close neighbor used on the browser launch path
        0x001f3800L,  // direct late setter source for iRam00343690
        0x001f3890L,  // immediate post-3800 neighbor
        0x001f3940L,  // immediate post-3800 neighbor
        0x001f3a00L,  // next likely function boundary after FUN_001f3800
        0x001f3b00L,  // wider neighbor in the same cluster
        0x001f3c00L,  // wider neighbor in the same cluster
        0x001f3a70L,  // helper used by FUN_001f3ab0
        0x001f3cd0L,  // helper used by the 1f47xx..1f55xx async family
        0x001f3dc0L,  // helper used by the 1f47xx..1f55xx async family
        0x001f3f00L,  // helper used by FUN_001f4d50
        0x001f4720L,  // caller of FUN_001f3ab0
        0x001f4810L,  // caller of FUN_001f3ab0
        0x001f4a40L,  // caller of FUN_001f3ab0
        0x001f4d50L,  // caller of FUN_001f3ab0
        0x001f52d0L,  // caller of FUN_001f3ab0
        0x001f5520L,  // caller of FUN_001f3ab0
        0x001f5ca0L,  // lower async helper used by FUN_001f3dc0
        0x001f5dc8L,  // lower async helper used by FUN_001f3f00
        0x001f5e00L,  // lower async helper used by FUN_001f3dc0
        0x001f5b08L,  // async completion callback used by 1f5ca0/1f65d8
        0x001f6038L,  // lower async helper used by FUN_001f3dc0
        0x001f62c8L,  // lower async helper used by FUN_001f3a70
        0x001f63e8L,  // lower async helper used by FUN_001f3ab0
        0x001f6390L,  // async completion callback used by 1f63e8
        0x001f65d8L,  // lower async helper used by FUN_001f3cd0
        0x0010a338L,  // comparator/check used after async completion
        0x001069a8L,  // memory copy helper used to canonicalize buffers
    };

    private static final long[] DATA_REFS = {
        0x00245808L,  // DAT_00245808 - stage trigger consumed by FUN_001af570
        0x00245810L,  // DAT_00245810 - second stage trigger consumed by FUN_001af570
        0x0024e758L,  // PTR_PTR_0024e758 – descriptor table indexed by iRam003908d4
        0x0024e770L,  // 0x24e770 – second arg to FUN_00109728 (request format descriptor?)
        0x0024e790L,  // nearby descriptor entry
        0x00230d30L,  // stage destination table used by FUN_001a00a0
        0x00230d70L,  // stage-status block updated by FUN_001a00a0
        0x00230d90L,  // "BIN\\%d.DAT" format string
        0x003ab700L,  // stage 0 destination from DAT_00230d30
        0x005ac300L,  // stage 1..3 destination from DAT_00230d30
        0x007dba00L,  // stage 7 destination from DAT_00230d30
        0x011c0000L,  // stage 4..6 destination from DAT_00230d30
        0x00343340L,  // 16-byte block copied by FUN_001bc470 before stage re-entry
        0x0034359dL,  // stage selector byte used as (bRam0034359d + 9)
        0x00245e38L,  // version/build token block mirrored into 0x390700
        0x0024e438L,  // 4-byte seed copied into 0x39070a during package reset
        0x0024e440L,  // BIO-VOL2 package signature checked by FUN_001f3640
    };

    // Raw LE patterns for the stage-3 wrapper entry points.
    // If any of these appear in data, that table may be the hidden installer.
    private static final long[] RAW_SEARCH_VALUES = {
        0x001afac0L,  // FUN_001afac0 - stage-3 queue site
        0x001afb00L,  // FUN_001afb00 - stage-3 queue site
        0x001afa30L,  // browser-success stage-1 wrapper
        0x001afa00L,  // sibling wrapper around FUN_001af990
        0x001af800L,  // shared slot registration helper
    };

    // Callers to trace
    private static final long[] CALLER_TARGETS = {
        0x001af570L,
        0x001af990L,
        0x001afa00L,
        0x001afa30L,
        0x001afa60L,
        0x001afac0L,
        0x001afb00L,
        0x00109728L,  // who calls the async submitter (= what async contexts exist)
        0x001b8f30L,
        0x001b96f0L,
        0x001b9a40L,
        0x001ba300L,
        0x001ba890L,
        0x001baa50L,
        0x001badf0L,
        0x0017e470L,
        0x001a02d0L,
        0x001a0320L,
        0x001a0000L,
        0x001a00a0L,
        0x001a73a0L,
        0x001b2720L,
        0x001b41e0L,
        0x001b7ff0L,
        0x001b8f30L,
        0x001b96f0L,
        0x001b84e0L,
        0x001b8a80L,
        0x001f4770L,
        0x001f4980L,
        0x001f50c0L,
        0x001f5620L,
        0x001f5630L,
        0x001bc470L,
        0x001bc4b0L,
        0x001bc5c0L,
        0x001bc620L,
        0x001bc650L,
        0x001bc6a0L,
        0x001bc720L,
        0x001bca00L,
        0x001bcac0L,
        0x001bc1c0L,
        0x001c4100L,
        0x001d1110L,
        0x001d12c0L,
        0x001f15b0L,
        0x001f35c0L,
        0x001f3600L,
        0x001f3640L,
        0x001f37d0L,
        0x001f3800L,
        0x001f3890L,
        0x001f3940L,
        0x001f3a00L,
        0x001f3b00L,
        0x001f3c00L,
        0x001f3a70L,
        0x001f3cd0L,
        0x001f3dc0L,
        0x001f3f00L,
        0x001f4720L,
        0x001f4810L,
        0x001f4a40L,
        0x001f4d50L,
        0x001f52d0L,
        0x001f5520L,
        0x001f5ca0L,
        0x001f5dc8L,
        0x001f5e00L,
        0x001f5b08L,
        0x001f6038L,
        0x001f62c8L,
        0x001f63e8L,
        0x001f6390L,
        0x001f65d8L,
        0x0010a338L,
    };

    @Override
    protected void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(new DecompileOptions());
        ifc.openProgram(currentProgram);
        Memory mem = currentProgram.getMemory();

        for (long target : DECOMPILE_TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("DECOMPILE TARGET " + addr);
            println("======================================================================");
            Function fn = ensureFunction(addr);
            if (fn == null) {
                println("No function at or containing " + addr);
                println("");
                continue;
            }
            println("FUNCTION: " + fn.getName() + " @ " + fn.getEntryPoint());
            decompile(ifc, fn);
        }

        for (long target : CALLER_TARGETS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("CALLERS OF " + addr);
            println("======================================================================");
            Function fn = ensureFunction(addr);
            if (fn == null) {
                println("No function at or containing " + addr);
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

        for (long target : DATA_REFS) {
            Address addr = toAddr(target);
            println("======================================================================");
            println("DATA REFS TO " + addr);
            println("======================================================================");
            Reference[] refs = getReferencesTo(addr);
            if (refs.length == 0) {
                println("NO DIRECT REFS");
                println("");
                continue;
            }
            for (Reference ref : refs) {
                Function fn = getFunctionContaining(ref.getFromAddress());
                if (fn != null) {
                    println("REF: " + fn.getName() + " @ " + fn.getEntryPoint()
                        + " via " + ref.getFromAddress());
                } else {
                    println("REF: <no function> via " + ref.getFromAddress());
                }
            }
            println("");
        }

        for (long target : RAW_SEARCH_VALUES) {
            byte[] pattern = new byte[]{
                (byte)(target & 0xFF),
                (byte)((target >> 8) & 0xFF),
                (byte)((target >> 16) & 0xFF),
                (byte)((target >> 24) & 0xFF)
            };
            println("======================================================================");
            println("RAW SEARCH FOR " + String.format("0x%08x", target));
            println("======================================================================");
            Address searchStart = toAddr(0x100000L);
            int hitCount = 0;
            while (true) {
                Address found = mem.findBytes(searchStart, pattern, null, true, monitor);
                if (found == null) {
                    break;
                }
                hitCount++;
                Function fn = getFunctionContaining(found);
                if (fn != null) {
                    println("HIT: " + found + " in " + fn.getName() + " @ " + fn.getEntryPoint());
                } else {
                    println("HIT: " + found + " in <no function>");
                }
                searchStart = found.add(1);
                if (hitCount >= 20) {
                    println("(truncated after 20 hits)");
                    break;
                }
            }
            if (hitCount == 0) {
                println("NO HITS");
            }
            println("");
        }

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

    private Function ensureFunction(Address addr) throws Exception {
        Function fn = getFunctionAt(addr);
        if (fn != null) {
            return fn;
        }
        fn = getFunctionContaining(addr);
        if (fn != null) {
            return fn;
        }
        disassemble(addr);
        fn = getFunctionAt(addr);
        if (fn != null) {
            return fn;
        }
        try {
            fn = createFunction(addr, null);
        } catch (Exception e) {
            // ignore and fall through to final lookup
        }
        if (fn != null) {
            return fn;
        }
        return getFunctionContaining(addr);
    }
}
