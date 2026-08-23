# 0x001c7580 snap_send_op1e_detail_request

| field | value |
|---|---|
| Original address | 0x001c7580 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7580 |
| Resolved name | snap_send_op1e_detail_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3ea0, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x365e0c cursor; 0x365e20 records; 0x365f7c room-token; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x1e
**State vars:** conn+0xd next-state=0x09

## Behavioral explanation
Emits opcode 0x1e room-detail request: appends the current room's stored id (0x365f7c) and name (record at 0x365e20 indexed by 0x365e0c*0x260); advances to state 0x09.

## Notes / uncertainty
Per-room detail (op0x1e): body u32 token(record+0x15c)||name(record+0x00), index=cursor*0x260, next 0x09. Token 0 until detail reply fills it.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
