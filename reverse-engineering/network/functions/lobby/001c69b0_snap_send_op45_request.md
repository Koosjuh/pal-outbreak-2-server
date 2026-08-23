# 0x001c69b0 snap_send_op45_request

| field | value |
|---|---|
| Original address | 0x001c69b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c69b0 |
| Resolved name | snap_send_op45_request |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3da0, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x45
**State vars:** conn+0xd next-state=0x26

## Behavioral explanation
Emits opcode 0x45 with a single byte(1) selector; advances to state 0x26.

## Notes / uncertainty
Machine-F (single ≤256B buffer) setup request: 0x45 + sub-selector 0x01 → state 0x26. Sub-selector confirmed by reply handler; payload identity unconfirmed; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c69b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
