# 0x001c46a0 snap_send_op0f_request

| field | value |
|---|---|
| Original address | 0x001c46a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c46a0 |
| Resolved name | snap_send_op0f_request |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** conn+0xd next-state=0x1e

## Behavioral explanation
Emits empty request opcode 0x0f and transmits; advances to state 0x1e.

## Notes / uncertainty
Rewrote: body-less reliable opcode-0x0f sender, success->state 0x1e (list-download loop entry, corroborated by recv loop 0x1e/0x1f). Which list 0x0f requests unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c46a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
