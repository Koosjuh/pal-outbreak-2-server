# 0x005cccf0 roomlist_query_dispatch

| field | value |
|---|---|
| Original address | 0x005cccf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cccf0 |
| Resolved name | roomlist_query_dispatch |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9c50
**Callees:** FUN_005d76b0, FUN_005dedf0
**Referenced globals:** 0x701068+0x5ffc0 display-list; 0x701070+0x2d request ctr; 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2d; 0x701070+0x2e

## Behavioral explanation
Scans the display list for room ('\r') rows and, for populated ones, issues a per-row query (FUN_005dedf0 builds key -> FUN_005d76b0 sends), marking row state and bumping the 0x2d request counter; sets next sub-state 8 or 10.

## Notes / uncertainty
Fans out per-room detail queries (op01/sub2 via FUN_005d76b0), throttled to 20/pass via sm+0x2d, sets row[5] state and next screen kind 8/10. op01/sub2 <-> wire op48 name-loop is a hypothesis, not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cccf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
