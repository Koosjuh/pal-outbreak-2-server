# 0x001ddee8 snap_send_op0a_memberlist_req

| field | value |
|---|---|
| Original address | 0x001ddee8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ddee8 |
| Resolved name | snap_send_op0a_memberlist_req |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0xa with a single htonl u32 (room id) — member-list request; completion cb 0x19, seq arg 0.

## Notes / uncertainty
Clean op0a member-list request: 4-byte htonl(room_id) body, who 0xb000 (reliable|0x2000|DATA), completion cb 0x19. errno family 0x64/0x65/0x66. param_1 must==1 (channel selector, semantics inferred).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ddee8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
