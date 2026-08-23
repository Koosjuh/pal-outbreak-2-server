import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.Memory;

public class DumpBootStubBytes extends GhidraScript {

    private static final long TARGET = 0x00100220L;
    private static final int SIZE = 0x90;

    @Override
    public void run() throws Exception {
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        Address addr = space.getAddress(TARGET);
        byte[] bytes = new byte[SIZE];
        mem.getBytes(addr, bytes);

        println("======================================================================");
        println(String.format("RAW BYTES @ 0x%08x", TARGET));
        println("======================================================================");

        for (int i = 0; i < bytes.length; i += 4) {
            int insn = ((bytes[i + 3] & 0xff) << 24) |
                       ((bytes[i + 2] & 0xff) << 16) |
                       ((bytes[i + 1] & 0xff) << 8) |
                       (bytes[i] & 0xff);
            println(String.format("0x%08x: %08x  %s", TARGET + i, insn, decode(insn)));
        }
    }

    private String decode(int insn) {
        int op = (insn >>> 26) & 0x3f;
        int rs = (insn >>> 21) & 0x1f;
        int rt = (insn >>> 16) & 0x1f;
        int rd = (insn >>> 11) & 0x1f;
        int sa = (insn >>> 6) & 0x1f;
        int funct = insn & 0x3f;
        int imm = insn & 0xffff;
        int simm = (short)imm;
        String[] r = {
            "zero","at","v0","v1","a0","a1","a2","a3",
            "t0","t1","t2","t3","t4","t5","t6","t7",
            "s0","s1","s2","s3","s4","s5","s6","s7",
            "t8","t9","k0","k1","gp","sp","s8","ra"
        };

        if (insn == 0) return "nop";
        if (insn == 0x0000000c) return "syscall";

        switch (op) {
            case 0x00:
                switch (funct) {
                    case 0x08: return "jr $" + r[rs];
                    case 0x09: return "jalr $" + r[rd] + ", $" + r[rs];
                    case 0x21: return "addu $" + r[rd] + ", $" + r[rs] + ", $" + r[rt];
                    case 0x2d: return "daddu $" + r[rd] + ", $" + r[rs] + ", $" + r[rt];
                    case 0x00: return "sll $" + r[rd] + ", $" + r[rt] + ", " + sa;
                    default: return "SPECIAL funct=0x" + Integer.toHexString(funct);
                }
            case 0x02: return String.format("j 0x%08x", (insn & 0x03ffffff) << 2);
            case 0x03: return String.format("jal 0x%08x", (insn & 0x03ffffff) << 2);
            case 0x04: return "beq $" + r[rs] + ", $" + r[rt] + ", " + simm;
            case 0x05: return "bne $" + r[rs] + ", $" + r[rt] + ", " + simm;
            case 0x09: return "addiu $" + r[rt] + ", $" + r[rs] + ", " + simm;
            case 0x0f: return String.format("lui $%s, 0x%x", r[rt], imm);
            case 0x11:
                return "cop1/ps2";
            case 0x19:
                return "cop2/ps2";
            case 0x1f:
                return "special3/ps2";
            case 0x23: return "lw $" + r[rt] + ", " + simm + "($" + r[rs] + ")";
            case 0x2b: return "sw $" + r[rt] + ", " + simm + "($" + r[rs] + ")";
            case 0x37: return "ld $" + r[rt] + ", " + simm + "($" + r[rs] + ")";
            case 0x3f: return "sd $" + r[rt] + ", " + simm + "($" + r[rs] + ")";
            default: return "op=0x" + Integer.toHexString(op);
        }
    }
}
