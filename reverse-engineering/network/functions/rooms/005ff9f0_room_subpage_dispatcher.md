# 0x005ff9f0 room_subpage_dispatcher

| field | value |
|---|---|
| Original address | 0x005ff9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff9f0 |
| Resolved name | room_subpage_dispatcher |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff950
**Callees:** FUN_005ffa90, FUN_005ffb20, FUN_005ffbe0, FUN_00600200, FUN_00600d10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xe room-subpage

## Behavioral explanation
Room sub-page dispatcher: routes byte +0xe (0..4) to the create/list/detail/stats sub-screens (FUN_005ffa90/005ffb20/005ffbe0/00600200/00600d10).

## Notes / uncertainty
Pure fan-out on ctx+0xe (0..4) to room sub-screens; page 3 = detail SM variant2 (00600200). Decompiler dropped the param forward (handlers re-read globals). Page 0/1/2/4 semantic names not individually confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
