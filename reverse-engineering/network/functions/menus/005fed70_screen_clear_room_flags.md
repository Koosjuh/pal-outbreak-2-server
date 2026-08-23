# 0x005fed70 screen_clear_room_flags

| field | value |
|---|---|
| Original address | 0x005fed70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fed70 |
| Resolved name | screen_clear_room_flags |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b6900
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x10 sub-step; param_1+0x9cc/0x9cb/0x9ab/0x9aa room-state flags

## Behavioral explanation
On sub-step 1 advances step and clears room/roster status flags (0x9cc/0x9cb/0x9ab/0x9aa); on sub-step 0 pops the screen.

## Notes / uncertainty
On sub-step 1 advances step and clears four room/roster status flags (+0x9cc/9cb/9ab/9aa); sub-step 0 idles via FUN_005b6900. Individual flag meanings not separately confirmed; 0->1 driver external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fed70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
