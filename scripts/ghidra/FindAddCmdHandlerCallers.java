// Find every caller of sceSifAddCmdHandler (stub @ 0x00112cf0) and dump:
//   - the cmd code registered (1st arg)
//   - the handler function (2nd arg)
//   - the user data ptr (3rd arg)
// Each registered handler is an EE function that receives IOP→EE SIF commands.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.util.*;

public class FindAddCmdHandlerCallers extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        Address stub = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x112cf0L);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(stub);
        Set<Function> callers = new LinkedHashSet<>();
        List<Address> sites = new ArrayList<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            sites.add(ref.getFromAddress());
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (fn != null) callers.add(fn);
        }
        println("=== Callers of sceSifAddCmdHandler (stub 0x112cf0) ===");
        println("  total call sites: " + sites.size());
        for (Address site : sites) println("  site @ " + site);

        // Backward-trace each call site to get a0/a1/a2 values
        println("\n=== Call site argument extraction ===");
        for (Address site : sites) {
            long a0 = backTrace(site, 0);
            long a1 = backTrace(site, 1);
            long a2 = backTrace(site, 2);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(site);
            println(String.format("  site @ %s in %s  ->  sceSifAddCmdHandler(cmd=0x%x, handler=0x%x, userdata=0x%x)",
                site, fn != null ? fn.getName() : "?", a0, a1, a2));
        }

        // Decompile each handler function (a1 value) and each caller
        println("\n=== Decompiled handlers ===");
        Set<Long> handlerAddrs = new LinkedHashSet<>();
        for (Address site : sites) {
            long h = backTrace(site, 1);
            if (h > 0x100000 && h < 0x300000) handlerAddrs.add(h);
        }
        for (Long h : handlerAddrs) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(h);
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(a);
            if (fn == null) continue;
            println("\n---- HANDLER " + fn.getName() + " @ " + fn.getEntryPoint() + " ----");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }

        println("\n=== Decompiled callers ===");
        for (Function fn : callers) {
            println("\n---- CALLER " + fn.getName() + " ----");
            DecompileResults r = ifc.decompileFunction(fn, 60, monitor);
            if (r != null && r.decompileCompleted()) println(r.getDecompiledFunction().getC());
        }
        ifc.dispose();
    }

    private long backTrace(Address site, int argIdx) throws Exception {
        // Scan backward up to 24 instr for lui+ori/addiu/li targeting $a{argIdx}
        int rt = 4 + argIdx; // $a0=4, $a1=5, $a2=6
        var listing = currentProgram.getListing();
        Address pc = site;
        long hi = -1;
        Address luiAddr = null;
        for (int i = 0; i <= 24; i++) {
            pc = pc.subtract(4);
            Instruction ins = listing.getInstructionAt(pc);
            if (ins == null) continue;
            String mn = ins.getMnemonicString();
            // Single-instruction load: addiu $rt, $zr, imm
            if (mn.equals("addiu") || mn.equals("_addiu")) {
                Object[] os = ins.getOpObjects(0);
                if (os.length > 0 && os[0].toString().contains("a" + argIdx)) {
                    Object[] base = ins.getOpObjects(1);
                    if (base.length > 0 && base[0].toString().contains("zero")) {
                        Object[] imm = ins.getOpObjects(2);
                        if (imm.length > 0 && imm[0] instanceof Scalar) {
                            return ((Scalar)imm[0]).getSignedValue() & 0xffffffffL;
                        }
                    }
                }
            }
            if (mn.equals("lui") || mn.equals("_lui")) {
                Object[] os = ins.getOpObjects(0);
                if (os.length > 0 && os[0].toString().contains("a" + argIdx)) {
                    Object[] imm = ins.getOpObjects(1);
                    if (imm.length > 0 && imm[0] instanceof Scalar) {
                        hi = ((Scalar)imm[0]).getUnsignedValue() << 16;
                        luiAddr = pc;
                    }
                }
            }
        }
        if (luiAddr == null) return 0;
        // Forward scan from luiAddr+4 to site for ori/addiu $a{argIdx}, $a{argIdx}, imm
        Address sp = luiAddr.add(4);
        while (!sp.equals(site)) {
            Instruction ins = listing.getInstructionAt(sp);
            if (ins == null) { sp = sp.add(4); continue; }
            String mn = ins.getMnemonicString();
            if (mn.equals("ori") || mn.equals("addiu") || mn.equals("_ori") || mn.equals("_addiu")) {
                Object[] os = ins.getOpObjects(0);
                if (os.length > 0 && os[0].toString().contains("a" + argIdx)) {
                    Object[] imm = ins.getOpObjects(2);
                    if (imm.length > 0 && imm[0] instanceof Scalar) {
                        long lo = ((Scalar)imm[0]).getValue();
                        if (mn.contains("ori")) return (hi | (lo & 0xffff)) & 0xffffffffL;
                        return ((hi + (short)lo) & 0xffffffffL);
                    }
                }
            }
            sp = sp.add(4);
        }
        return hi;
    }
}
