# 0x00636890 kbd_render_main

| field | value |
|---|---|
| Original address | 0x00636890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00636890 |
| Resolved name | kbd_render_main |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dc2b0, FUN_0060f910, FUN_00618c90, FUN_00619800
**Callees:** FUN_005af2c0, FUN_00631a30, FUN_00632390, FUN_00633c10, FUN_006365d0, FUN_006366a0, FUN_006379e0, FUN_00637f40, FUN_00637f80, FUN_00637f90, FUN_006381e0
**Referenced globals:** 0x715da8 state struct; 0x690d70/74 glyph metrics; 0x691150.. glyph tables; 0x692410/0x692420 slot tables; 0x6946e8/0x6946f0 scale consts
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x26 confirm; 0x2f mode; 0x11 slot-count; 0x35 flags

## Behavioral explanation
Main soft-keyboard draw: renders the key grid, per-key glyph labels, cursor highlight, text field and 12-slot decoration; scales layout and iterates the layout table.

## Notes / uncertainty
Per-frame top-level soft-keyboard draw: bg/frame, key grid, animated cursor glow (cos of +0x06 anim), labels, 12 candidate glyphs, caret/underline. param_1=scale (0=full,else inset). Many low-level GS wrappers un-decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00636890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
