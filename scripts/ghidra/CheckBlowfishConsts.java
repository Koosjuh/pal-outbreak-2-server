// Look for the standard Blowfish P-array initial constants in the binary.
// These are derived from pi: 0x243F6A88, 0x85A308D3, 0x13198A2E, ...
//
// If present, the cipher is confirmed Blowfish (standard, not custom).
//
// Output: append findings to console output.

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;

import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class CheckBlowfishConsts extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outPath = "C:/dnas/active/ghidra_exports/udp9090_blowfish_check.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        PrintWriter pw = new PrintWriter(bw);

        try {
            int[] BF_P = {0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344};
            int[] BF_S = {0xD1310BA6, 0x98DFB5AC, 0x2FFD72DB, 0xD01ADFB7};

            for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
                if (!blk.isInitialized()) continue;
                long len = blk.getSize();
                if (len > 0x800000) continue;
                byte[] buf = new byte[(int) len];
                try { blk.getBytes(blk.getStart(), buf); } catch (Exception e) { continue; }
                // Search for the P-array sequence in BOTH little-endian and big-endian
                for (ByteOrder bo : new ByteOrder[]{ ByteOrder.LITTLE_ENDIAN, ByteOrder.BIG_ENDIAN }) {
                    ByteBuffer bb = ByteBuffer.wrap(buf).order(bo);
                    for (int off = 0; off + 16 <= buf.length; off += 4) {
                        if (bb.getInt(off) == BF_P[0] && bb.getInt(off + 4) == BF_P[1] &&
                            bb.getInt(off + 8) == BF_P[2] && bb.getInt(off + 12) == BF_P[3]) {
                            pw.printf("  P-array (%s) at %s in block %s%n", bo, blk.getStart().add(off), blk.getName());
                        }
                        if (bb.getInt(off) == BF_S[0] && bb.getInt(off + 4) == BF_S[1] &&
                            bb.getInt(off + 8) == BF_S[2] && bb.getInt(off + 12) == BF_S[3]) {
                            pw.printf("  S-box (%s) at %s in block %s%n", bo, blk.getStart().add(off), blk.getName());
                        }
                    }
                }
            }
            println("Done: " + outPath);
        } finally {
            pw.close();
        }
    }
}
