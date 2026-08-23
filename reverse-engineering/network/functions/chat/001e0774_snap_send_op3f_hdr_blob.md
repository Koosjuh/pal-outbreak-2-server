# 0x001e0774 snap_send_op3f_hdr_blob

| field | value |
|---|---|
| Original address | 0x001e0774 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0774 |
| Resolved name | snap_send_op3f_hdr_blob |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x3f
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0x3f: a 4-byte header (param_2/param_3) followed by a param_4-length blob clamped to 0x368; no completion cb.

## Notes / uncertainty
Reliable op3f: 4-byte header word + body (clamp 0x368), enqueue len = len+4, flags 0xb000. No caller. NOTE quirk: pktbuf_reserve called with len but len+4 bytes written (relies on 0x14 alloc slack) — enqueue length-match guard behavior unverified without trace.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0774.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
