# 0x00632390 kbd_render_input_line

| field | value |
|---|---|
| Original address | 0x00632390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632390 |
| Resolved name | kbd_render_input_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636890
**Callees:** FUN_005af2c0, FUN_00632c00, FUN_00634010, FUN_006340d0, FUN_00634160, FUN_006341d0, FUN_00637e90, FUN_00637ed0
**Referenced globals:** 0x715da8 (kbd state: +0x4c text buf, +0x3c scroll, +0x2a len, +0x260 predictive, +0x1d kbd-type); 0x715bb0 (draw scratch); 0x68b6c8/0x68b6d0 (glyph/tables)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f; 0x715da8+0x1d (kbd type); 0x715da8+0x260 (predictive active)

## Behavioral explanation
Renders the name-entry text line: draws committed text (buf+0x4c), scroll window (+0x3c), cursor, and predictive candidate strings (+0x260/+0x46c/+0x47c) with font placement calls.

## Notes / uncertainty
Renders name-entry line: scroll window, password mask (+0x1d 5/0xa), 3-segment IME composition, underline cursor. Font-API float math and per-segment layout summarized not fully re-derived.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
