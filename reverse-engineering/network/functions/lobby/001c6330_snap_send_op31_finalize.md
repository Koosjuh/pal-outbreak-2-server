# 0x001c6330 snap_send_op31_finalize

| field | value |
|---|---|
| Original address | 0x001c6330 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6330 |
| Resolved name | snap_send_op31_finalize |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x31
**State vars:** conn+0xd next-state=0x40

## Behavioral explanation
Emits empty request opcode 0x31 and transmits; advances to state 0x40.

## Notes / uncertainty
Renamed request→finalize: body-less 0x31 download-complete op, chains FSM into 0x40 (op45/machine-F entry). Peer-side ack semantics inferred; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
