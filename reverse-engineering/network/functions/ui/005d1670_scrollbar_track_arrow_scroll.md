# 0x005d1670 scrollbar_track_arrow_scroll

| field | value |
|---|---|
| Original address | 0x005d1670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d1670 |
| Resolved name | scrollbar_track_arrow_scroll |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5df0
**Referenced globals:** 0x701078+0x10/0x12 cursor; 0x701070+0x4/0x8 scroll; 0x701070+0x1a..0x28 margins/thumb; 0x701068+0x68e80/0x68e81 scroll dir
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e80; 0x701068+0x68e81

## Behavioral explanation
When cursor sits in edge bands, triggers directional auto-scroll (5df0) and records the scroll direction.

## Notes / uncertainty
RENAMED from cursor_edge_autoscroll: this is scrollbar arrow-button/track-gutter scroll (not cursor edge; that's 0af0). Arrow ids 3/4 into ui+0x68e80/81; page +/-0x167 vert, +/-0x200 horiz; thumb recompute scroll*0x15c/0x228.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d1670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
