# 0x001c48c0 snap_send_op12_named_request

| field | value |
|---|---|
| Original address | 0x001c48c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c48c0 |
| Resolved name | snap_send_op12_named_request |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x36842c name-buf; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x12
**State vars:** conn+0xd next-state=0x11

## Behavioral explanation
Emits request opcode 0x12 carrying a name string (from buffer 0x36842c); advances to state 0x11 — starts a named-resource download.

## Notes / uncertainty
Machine-A opener: header op12 + string TLV name@0x36842c, BE len fill, encrypt+enqueue, substate->0x11. Domain identity of named resource unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c48c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
