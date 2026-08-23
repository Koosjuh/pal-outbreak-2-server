# 0x001c42d0 snap_send_op18_request

| field | value |
|---|---|
| Original address | 0x001c42d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c42d0 |
| Resolved name | snap_send_op18_request |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** conn+0xd next-state; conn+0x1c socket
**Referenced strings:** —
**Referenced opcodes:** 0x18
**State vars:** conn+0xd next-state=0x03

## Behavioral explanation
Emits empty request opcode 0x18 and transmits; advances to state 0x03.

## Notes / uncertainty
Rewrote: body-less reliable opcode-0x18 sender, 8-byte header + net_sendto(len+8), success->state 0x03. Shared send idiom pinned via begin_tx/net_sendto. tx_commit(FUN_001c3840) is a stub; >-2 success convention inferred. App meaning of 0x18 unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c42d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
