# 0x005d19a0 cursor_hittest_hover_select

| field | value |
|---|---|
| Original address | 0x005d19a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d19a0 |
| Resolved name | cursor_hittest_hover_select |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x701068+0x5ffc0 entity array; 0x701078+0x10/0x12 cursor; 0x701070+0x4/0x8 scroll; 0x701070+0x18 flags; 0x701068+0x68e78 hover idx; 0x701068+0x68e82
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x18; 0x701068+0x68e82

## Behavioral explanation
Hit-tests the cursor against the entity list (bbox at +0x34/+0x38/+0x40/+0x44) and sets the hover index for selectable kinds (0x06/0x07/0x0d/0x11/0x12/0x02).

## Notes / uncertainty
Point hit-test picking selectable entity under cursor -> ui.hover_index(+0x68e78); excludes scrollbar chrome (flags&2/&4 bands); accepts kinds 0x06/0x07, 0x0d(gated), 0x02/0x11/0x12(name nonempty). Sets over_chrome(+0x68e82) on miss.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d19a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
