// Map IOP IRX imports: decode the import library entries in the data section,
// resolve each 8-byte stub to (library, function_index, stub_address),
// then for each function in the dispatcher's case table, show what it calls.

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import java.util.*;

public class MapIopImports extends GhidraScript {
    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();

        // === 1. Walk .data / .rodata looking for import library headers ===
        // Per IOP IRX convention, each import library starts with:
        //   u32 magic    = 0x41E00000   (J-instruction "jr $ra" disguised)
        //   u32 version  ...
        //   u32 mode     ...
        //   char name[8] "avetcp\0\0"
        //   then func-stub pointers until next 0x41E00000
        //
        // The strings "iopint", "avetcp", "devglue", "intrman", "loadcore",
        // "sifcmd", "stdio", "sysclib", "thbase", "thevent", "thsemap" appear
        // in the file. Find them and decode entries.

        String[] libNames = {"iopint","avetcp","devglue","intrman","loadcore",
                             "sifcmd","stdio","sysclib","thbase","thevent","thsemap"};
        Map<String,List<Long>> libEntries = new LinkedHashMap<>();

        // Scan first 0x4000 bytes for these library names (they're in .data block)
        Address start = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x0000);
        long fileLen = 0x4000;

        for (String name : libNames) {
            for (long off = 0; off < fileLen - name.length(); off++) {
                try {
                    Address a = start.add(off);
                    byte[] b = new byte[name.length() + 1];
                    mem.getBytes(a, b);
                    boolean match = true;
                    for (int i = 0; i < name.length(); i++) {
                        if ((b[i] & 0xff) != name.charAt(i)) { match = false; break; }
                    }
                    if (match && b[name.length()] == 0) {
                        println(String.format("[lib] %-10s name @ 0x%08x", name, a.getOffset()));
                        // Header is 16 bytes BEFORE the name (in PS2 IRX layout): version,mode,?,?
                        // Function stubs come immediately AFTER the name (rounded to 4 bytes).
                        // Stubs are 4-byte pointers each, terminated by ?
                        // Decode 8 stubs
                        long ptrStart = (off + name.length() + 8) & ~3L; // align
                        List<Long> entries = new ArrayList<>();
                        for (int k = 0; k < 12; k++) {
                            try {
                                Address pa = start.add(ptrStart + 4L*k);
                                int val = mem.getInt(pa);
                                long v = val & 0xffffffffL;
                                if (v == 0 || v == 0x41E00000L) break;
                                if (v > 0x10000) break; // not a code stub
                                entries.add(v);
                            } catch (Exception e) { break; }
                        }
                        libEntries.put(name, entries);
                        for (int k = 0; k < entries.size(); k++) {
                            println(String.format("    [%2d] stub @ 0x%08x", k, entries.get(k)));
                        }
                        break;
                    }
                } catch (Exception e) {}
            }
        }

        // === 2. For the 64 RPC handler functions invoked by FUN_00002858, ===
        // list the import stubs each one calls.
        println("\n=== RPC handler functions and their import calls ===");
        long[] handlers = {
            0x794L,0x80cL,0x868L,0x8a8L,0x908L,0x6c8L,0x760L,0xa10L,0xa8cL,0xafcL,
            0xb50L,0xbacL,0xbf0L,0xc34L,0xca8L,0xd28L,0xd8cL,0xde4L,0xf50L,
            0x498L,0x524L,0x610L,0x1248L,0x12c8L,0x14b4L,0xfe0L,0x176cL,0x17c0L,
            0x180cL,0x18b4L,0x1954L,0x19a4L,0x1c04L,0x1c4cL,0x1c88L,0x1cd0L,0x1d24L,
            0x1d78L,0x1e18L,0x1e68L,0x1efcL,0x1f38L,0x1f74L,0x1fb0L,0x2008L,0x2050L,
            0x20a4L,0x20e0L,0x211cL,0x218cL,0x2208L,0x2288L,0x22c4L,0x2314L,0x2364L,
            0x23dcL,0x2418L,0x24f0L,0x2570L,0x25c4L,0x2620L,
            0xf9cL,0x968L,0x9bcL,0x2688L,0x26bcL,0x2700L,0x27d0L,
            0x1eb8L,0x1428L,0x164cL,0x16a8L,0x1728L,0x14f8L,0x2814L
        };
        int[] caseNums = {
            0,1,2,3,4,5,6,7,8,9,
            0xa,0xb,0xc,0xd,0xe,0xf,0x12,0x13,0x14,
            0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,
            0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
            0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
            0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
            0x39,0x3a,0x3b,0x3c,0x3d,0x3e,
            0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,
            0x53,0x54,0x55,0x56,0x57,0x58,0x59
        };

        for (int hi = 0; hi < handlers.length; hi++) {
            Address fnAddr = start.add(handlers[hi]);
            Function fn = currentProgram.getFunctionManager().getFunctionAt(fnAddr);
            if (fn == null) {
                println(String.format("op 0x%02x  FUN_%08x  [not a function?]", caseNums[hi], handlers[hi]));
                continue;
            }
            // Walk instructions, find JAL/JALR/J targets and look up if they map to a stub
            StringBuilder calls = new StringBuilder();
            InstructionIterator it = currentProgram.getListing().getInstructions(fn.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String mn = ins.getMnemonicString();
                if (mn.equals("jal") || mn.equals("j") || mn.equals("jalr") || mn.equals("_jal") || mn.equals("_j") || mn.equals("_jalr")) {
                    for (Reference ref : ins.getReferencesFrom()) {
                        long tgt = ref.getToAddress().getOffset();
                        // Try to find which library/index this maps to
                        for (var e : libEntries.entrySet()) {
                            int idx = e.getValue().indexOf(tgt);
                            if (idx >= 0) {
                                calls.append(String.format(" %s[%d]", e.getKey(), idx));
                            }
                        }
                    }
                }
            }
            println(String.format("op 0x%02x  FUN_%08x  size=0x%x  calls:%s",
                caseNums[hi], handlers[hi],
                fn.getBody().getMaxAddress().getOffset() - handlers[hi] + 1,
                calls.toString().isEmpty() ? " (no recognized import calls)" : calls.toString()));
        }
    }
}
