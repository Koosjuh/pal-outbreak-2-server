import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class InspectBootArgRegion extends GhidraScript {

    private static final long[] TARGETS = {
        0x00100220L,
        0x0025b880L,
        0x0025b884L,
        0x0029f200L
    };

    @Override
    public void run() throws Exception {
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        ReferenceManager rm = currentProgram.getReferenceManager();
        FunctionManager fm = currentProgram.getFunctionManager();

        for (long vaddr : TARGETS) {
            Address addr = space.getAddress(vaddr);
            println("======================================================================");
            println(String.format("TARGET 0x%08x", vaddr));
            println("======================================================================");

            println("-- REFERENCES TO TARGET --");
            ReferenceIterator refs = rm.getReferencesTo(addr);
            boolean saw = false;
            while (refs.hasNext()) {
                saw = true;
                Reference ref = refs.next();
                Function f = fm.getFunctionContaining(ref.getFromAddress());
                println("REF from " + ref.getFromAddress() +
                    (f != null ? (" in " + f.getName() + " @ " + f.getEntryPoint()) : ""));
            }
            if (!saw) {
                println("NO DIRECT REFS");
            }

            println("-- RAW WORDS (0x80 bytes) --");
            byte[] bytes = new byte[0x80];
            try {
                mem.getBytes(addr, bytes);
            } catch (Exception e) {
                println("READ FAILED: " + e.getMessage());
                println();
                continue;
            }

            for (int i = 0; i < bytes.length; i += 4) {
                int word = ((bytes[i + 3] & 0xff) << 24) |
                           ((bytes[i + 2] & 0xff) << 16) |
                           ((bytes[i + 1] & 0xff) << 8) |
                           (bytes[i] & 0xff);
                String ascii = "";
                for (int j = 0; j < 4; j++) {
                    int b = bytes[i + j] & 0xff;
                    ascii += (b >= 0x20 && b <= 0x7e) ? (char)b : '.';
                }
                println(String.format("0x%08x: %08x  %s", (int)(vaddr + i), word, ascii));
            }

            println("-- ASCII RUNS --");
            StringBuilder current = new StringBuilder();
            long runStart = vaddr;
            for (int i = 0; i < bytes.length; i++) {
                int b = bytes[i] & 0xff;
                if (b >= 0x20 && b <= 0x7e) {
                    if (current.length() == 0) {
                        runStart = vaddr + i;
                    }
                    current.append((char)b);
                } else {
                    if (current.length() >= 3) {
                        println(String.format("0x%08x: %s", runStart, current.toString()));
                    }
                    current.setLength(0);
                }
            }
            if (current.length() >= 3) {
                println(String.format("0x%08x: %s", runStart, current.toString()));
            }
            println();
        }
    }
}
