# 0x005c5460 roster_ui_refresh_events

| field | value |
|---|---|
| Original address | 0x005c5460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5460 |
| Resolved name | roster_ui_refresh_events |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c54e0, FUN_005c5610
**Callees:** FUN_005bdf90
**Referenced globals:** 0x6cbc84 cursor; 0x6cbc7e mode=0x10; 0x6d2158 selected-idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cbc7e list-mode; uRam006d2158 sel

## Behavioral explanation
Resets roster UI cursor state and fires a batch of UI/state events (0x18,0x19,0x1a,0x29,0x1d,0x1e) to redraw the member list.

## Notes / uncertainty
Roster REDRAW entry: sets room_mode 0x6cbc7e=0x10, cursor/sel, fires 6 UI events (0x18/19/1a/29/1d/1e). Individual event-id target widgets inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
