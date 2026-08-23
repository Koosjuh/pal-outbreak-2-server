# 0x001c5ea0 snap_send_op2d_request

| field | value |
|---|---|
| Original address | 0x001c5ea0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5ea0 |
| Resolved name | snap_send_op2d_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2d
**State vars:** conn+0xd next-state=0x2a

## Behavioral explanation
Emits empty request opcode 0x2d and transmits; advances to state 0x2a.

## Notes / uncertainty
Bare payload-less 0x2d request (8-byte header only), next-state 0x2a -> transfer-setup reply. Unambiguous.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
