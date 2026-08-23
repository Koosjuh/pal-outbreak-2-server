# 0x005e4840 draw_focus_highlight

| field | value |
|---|---|
| Original address | 0x005e4840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e4840 |
| Resolved name | draw_focus_highlight |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dcb90
**Callees:** FUN_005e07c0, FUN_005e1aa0, FUN_005e2060
**Referenced globals:** iRam00701068+0x5ffc0 (element list), +0x68e78 (focused-element index); iRam00701070+4/+8 (scroll), +0x1c margin, +0x5c3 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x68e78 (focus index)

## Behavioral explanation
Draws the selection/focus decoration around the currently-focused element (index @+0x68e78 into the element list), choosing frame style by the element type and +0x5d nibble.

## Notes / uncertainty
Draws focus decoration on element at +0x68e78: frame-sprite style (from +0x5d nibble) only for type 0x0d w/ flag bit2 clear (+ header redraw via FUN_005e2060), else grey box outline. Exclusion chain reduces to type 0x0d.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e4840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
