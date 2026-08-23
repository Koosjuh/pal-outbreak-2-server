# 0x001c5480 snap_send_op3d_request

| field | value |
|---|---|
| Original address | 0x001c5480 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5480 |
| Resolved name | snap_send_op3d_request |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x3d
**State vars:** conn+0xd next-state=0x3c

## Behavioral explanation
Emits empty request opcode 0x3d and transmits; advances to state 0x3c — starts download machine C.

## Notes / uncertainty
Machine-C opener: bodyless op3d, substate->0x3c; reached from 0x3b (after machine B).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5480.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
