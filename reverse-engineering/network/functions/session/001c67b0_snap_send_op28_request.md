# 0x001c67b0 snap_send_op28_request

| field | value |
|---|---|
| Original address | 0x001c67b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c67b0 |
| Resolved name | snap_send_op28_request |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x28
**State vars:** conn+0xd next-state=0x24

## Behavioral explanation
Emits opcode 0x28 (the op28 selector reply) with no extra body and transmits; advances to state 0x24.

## Notes / uncertainty
Rewrote + renamed reply->request (builder emits client->server): body-less reliable opcode-0x28, success->state 0x24. op06-seq echo that drives op28 completion is stamped into header[5] upstream, not here. tx_commit convention inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c67b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
