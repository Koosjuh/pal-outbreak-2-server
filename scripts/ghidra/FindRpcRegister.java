// Find the sceSifRegisterRpc (sifcmd index 0x16) call in SNIOPINT.IRX and
// extract the RPC server ID argument. Also find sceSifSetRpcQueue (0x11).
// Then walk all callers and identify the RPC service registration site.

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressFactory;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class FindRpcRegister extends GhidraScript {
    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        AddressFactory af = currentProgram.getAddressFactory();

        // === Step 1: find every 8-byte stub in .text matching addiu $0,$0,N for sifcmd ===
        // We know sifcmd imports are at fixed addresses (from hexdump): name @ 0x378c, stubs follow.
        // sifcmd stubs:
        //   0x3794: jr ra
        //   0x3798: addiu $0,$0,0x11   (RpcQueueInit)         -> stub addr 0x3794
        //   0x379c: jr ra
        //   0x37a0: addiu $0,$0,0x13   (ExecRequest)          -> stub addr 0x379c
        //   0x37a4: jr ra
        //   0x37a8: addiu $0,$0,0x16   (RegisterRpc)          -> stub addr 0x37a4 ★
        //   0x37ac: jr ra
        //   0x37b0: addiu $0,$0,0x18   (RemoveRpc)            -> stub addr 0x37ac
        //   0x37b4: jr ra
        //   0x37b8: addiu $0,$0,0x19   (RemoveRpcQueue)       -> stub addr 0x37b4
        //
        // Same approach for avetcp (name @ 0x36bc):
        //   0x36c4: avetcp[4]   ★
        //   0x36cc: avetcp[0x20] ★
        //   0x36d4: avetcp[0x24] ★

        // .text loaded at vaddr 0x0, file offset 0xB0. mem = file - 0xB0.
        long[] sifStubs = {0x36e4L, 0x36ecL, 0x36f4L, 0x36fcL, 0x3704L};
        String[] sifNames = {"RpcQueueInit", "ExecRequest", "RegisterRpc", "RemoveRpc", "RemoveRpcQueue"};
        long[] aveStubs = {0x3614L, 0x361cL, 0x3624L};
        String[] aveNames = {"avetcp[4]", "avetcp[0x20]", "avetcp[0x24]"};

        // Verify the bytes
        println("=== Verifying sifcmd stub layout ===");
        for (int i = 0; i < sifStubs.length; i++) {
            Address a = af.getDefaultAddressSpace().getAddress(sifStubs[i]);
            int w0 = mem.getInt(a);
            int w1 = mem.getInt(a.add(4));
            println(String.format("  %-18s @ 0x%08x  word0=0x%08x  word1=0x%08x",
                sifNames[i], sifStubs[i], w0, w1));
        }
        println("=== Verifying avetcp stub layout ===");
        for (int i = 0; i < aveStubs.length; i++) {
            Address a = af.getDefaultAddressSpace().getAddress(aveStubs[i]);
            int w0 = mem.getInt(a);
            int w1 = mem.getInt(a.add(4));
            println(String.format("  %-18s @ 0x%08x  word0=0x%08x  word1=0x%08x",
                aveNames[i], aveStubs[i], w0, w1));
        }

        // === Step 2: find every JAL targeting any of these addresses ===
        println("\n=== Callers of each stub ===");
        for (int i = 0; i < sifStubs.length; i++) {
            findCallers(sifStubs[i], "sifcmd::" + sifNames[i]);
        }
        for (int i = 0; i < aveStubs.length; i++) {
            findCallers(aveStubs[i], aveNames[i]);
        }

        // === Step 3: decompile any function that calls sceSifRegisterRpc (sifcmd[0x16]) ===
        println("\n=== Decompile of RegisterRpc callers ===");
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Address regAddr = af.getDefaultAddressSpace().getAddress(0x36f4L);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(regAddr);
        java.util.Set<Function> seen = new java.util.HashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (fn == null || !seen.add(fn)) continue;
            println("---- FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() + " ----");
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            }
        }

        // === Step 4: decompile any function that calls avetcp[any] — these are the network ops ===
        println("\n=== Decompile of avetcp[4] callers ===");
        decompileCallers(ifc, 0x3614L);
        println("\n=== Decompile of avetcp[0x20] callers ===");
        decompileCallers(ifc, 0x361cL);
        println("\n=== Decompile of avetcp[0x24] callers ===");
        decompileCallers(ifc, 0x3624L);

        ifc.dispose();
    }

    private void findCallers(long stubAddr, String label) throws Exception {
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(stubAddr);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(a);
        StringBuilder sb = new StringBuilder();
        int n = 0;
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (fn != null) {
                sb.append("    ").append(ref.getFromAddress()).append("  ").append(fn.getName()).append("\n");
                n++;
            }
        }
        println(String.format("  %-25s @ 0x%08x  callers=%d", label, stubAddr, n));
        if (n > 0) println(sb.toString());
    }

    private void decompileCallers(DecompInterface ifc, long stubAddr) throws Exception {
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(stubAddr);
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(a);
        java.util.Set<Function> seen = new java.util.HashSet<>();
        while (rit.hasNext()) {
            Reference ref = rit.next();
            Function fn = currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
            if (fn == null || !seen.add(fn)) continue;
            println("---- FUNCTION " + fn.getName() + " @ " + fn.getEntryPoint() + " ----");
            DecompileResults res = ifc.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted()) println(res.getDecompiledFunction().getC());
        }
    }
}
