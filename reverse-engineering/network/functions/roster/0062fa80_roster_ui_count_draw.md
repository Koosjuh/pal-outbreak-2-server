# 0x0062fa80 roster_ui_count_draw

| field | value |
|---|---|
| Original address | 0x0062fa80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fa80 |
| Resolved name | roster_ui_count_draw |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20, FUN_0062fc20, FUN_0062fc40
**Referenced globals:** 0x6c4fe6 player count; 0x6c50ca layout index; 0x66af80/8e layout tables; 0x6c4fd5 teardown
**Referenced strings:** 0x66afa0 count fmt
**Referenced opcodes:** —
**State vars:** 0x6c4fe6 player count; 0x6c4fd5 teardown

## Behavioral explanation
Player-count UI task: while cRam006c4fd5==0, draws the room player count/list using uRam006c4fe6 (count, <4 test) and sRam006c50ca, formatting via FUN_005af1e0 and layout tables 0x66af80/8e.

## Notes / uncertainty
Per-frame player-count indicator task. mode(+3)==0 = sprite badge (tile encodes count from table 0x66af80, hidden when count>=4 room-full, pulsing alpha); mode!=0 = textual count (sprintf count via fmt 0x66afa0 + ui_draw_text). Both read player-count global 0x6c4fe6 -- the exact UI consumer behind the create-room '1/0p' symptom (renders faithfully; wrong count means 0x6c4fe6 never populated upstream). Teardown clears build guard 0x6c5c45 and frees via 618c20. Static-only; field names inferred; no bounds clamp on count/layout index visible.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fa80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
