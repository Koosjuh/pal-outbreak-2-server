# 0x00636190 kbd_render_fill_icon_ptrs

| field | value |
|---|---|
| Original address | 0x00636190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00636190 |
| Resolved name | kbd_render_fill_icon_ptrs |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x692224/0x692228 sprite-ptr tables; 0x69222c color/attr table; 0x6921c0..0x6921f4 icon descriptors
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34 page-index

## Behavioral explanation
Render setup: populates sprite/label pointer + color tables (PTR_DAT_00692224/DAT_0069222c...) for two button slots from the page descriptor (ptr 0x10,+0x20/+0x28/+0x24/+0x2c).

## Notes / uncertainty
Render-prep: fills 2 function-button draw slots (sprite/label/color) from page descriptor +0x10 (+0x20/+0x28/+0x24/+0x2c), per-tab color when mode==2. Pure UI.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00636190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
