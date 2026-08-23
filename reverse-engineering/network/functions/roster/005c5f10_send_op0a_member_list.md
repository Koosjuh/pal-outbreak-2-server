# 0x005c5f10 send_op0a_member_list

| field | value |
|---|---|
| Original address | 0x005c5f10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5f10 |
| Resolved name | send_op0a_member_list |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c0f60
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x0a member-list request to the target.

## Notes / uncertainty
op10-relay of inner op 0x0a (member-list request), body-less, to a single peer; caller FUN_005c0f60 trigger not fully traced. Reply drives roster_add_member/roster_member_list_fill.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5f10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
