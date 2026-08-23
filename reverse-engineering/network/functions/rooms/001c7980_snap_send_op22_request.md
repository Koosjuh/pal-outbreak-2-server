# 0x001c7980 snap_send_op22_request

| field | value |
|---|---|
| Original address | 0x001c7980 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7980 |
| Resolved name | snap_send_op22_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x365e18; 0x365e1a; 0x365e0c cursor; 0x365e20 records; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x22
**State vars:** conn+0xd next-state=0x0b

## Behavioral explanation
Emits opcode 0x22 room request: appends counters 0x365e18/0x365e1a and the current room record name (0x365e20 indexed by 0x365e0c); advances to state 0x0b.

## Notes / uncertainty
op0x22 (member/population page): u16 received||u16 page-size||room name, from state 0x0a -> 0x0b. Members-vs-attrs payload inferred from position.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
