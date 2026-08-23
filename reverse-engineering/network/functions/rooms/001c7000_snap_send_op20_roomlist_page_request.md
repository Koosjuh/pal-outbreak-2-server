# 0x001c7000 snap_send_op20_roomlist_page_request

| field | value |
|---|---|
| Original address | 0x001c7000 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7000 |
| Resolved name | snap_send_op20_roomlist_page_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001ee590
**Referenced globals:** 0x365e18 got; 0x365e1a batch; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x20
**State vars:** conn+0xd next-state=0x07

## Behavioral explanation
Emits opcode 0x20 room-list page request: appends progress counters 0x365e18/0x365e1a; advances to state 0x07.

## Notes / uncertainty
Improved name (page request). op0x20: body u16 received(0x365e18)||u16 page-size(0x365e1a=8), next-state 0x07.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7000.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
