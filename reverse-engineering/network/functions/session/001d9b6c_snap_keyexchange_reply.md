# 0x001d9b6c snap_keyexchange_reply

| field | value |
|---|---|
| Original address | 0x001d9b6c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9b6c |
| Resolved name | snap_keyexchange_reply |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001069a8, FUN_00109eb8, FUN_0010a050, FUN_001d507c, FUN_001d533c, FUN_001e180c, FUN_001e5538, FUN_001e56c8, FUN_001ea8e8, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** conn+0x484(crypto key); conn+0x4d4(crypto key); conn+0x520(subpool); conn+0x7c; 0x0025b790(errno)
**Referenced strings:** —
**Referenced opcodes:** 0x3d, 0x41
**State vars:** 0x7c(timeout); DAT_0025b790(errno)

## Behavioral explanation
Secure-handshake responder: decrypts incoming (FUN_001e5538 key conn+0x4d4), runs DH/crypto step FUN_001ea8e8 against conn+0x484, builds an 0x88-byte encrypted reply (FUN_001e56c8) and sends it reliably with opcode 0x41; sets errno 0x65/0x66 on alloc/send failure.

## Notes / uncertainty
op0x3d challenge -> op0x41 reply: decrypt (conn+0x4d4), DH-style derive (FUN_001ea8e8) vs conn+0x484, encrypt 0x88 reply, send who 0xb000; errno 0x65/0x66. Exact crypto (FUN_001ea8e8/e56c8) opaque.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9b6c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
