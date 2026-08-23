# 0x00614720 set_draw_color

| field | value |
|---|---|
| Original address | 0x00614720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614720 |
| Resolved name | set_draw_color |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060f910, FUN_00612ca0, FUN_006130a0, FUN_00613380, FUN_00613530, FUN_006139c0
**Callees:** func_0x001af0b0, func_0x001af0c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the current draw color/attribute for subsequent `draw_text_element` calls. It selects attribute channel 0 then loads the supplied 32-bit ARGB color. In `region_select_render` (0x613530) it is called with the packed constants `0x80808080` (bright/enabled) and `0x80404040` (dim/disabled) immediately before each label draw, which pins the arg as an ARGB color word.

## Input / output
- `param_1` (u32 ARGB `color`, sign-extended in decomp): packed color, A=0x80 in observed uses.
- Returns: void.

## Side effects
- Programs the overlay draw pipeline's active color register (no context/global writes).

## Important branches
- None.

## Constants & flags
- `0x80808080` — bright / available label color (mid-grey, alpha 0x80). Evidence: 0x613530 "avail bit set" path.
- `0x80404040` — dim / unavailable label color. Evidence: 0x613530 "avail bit clear" path.

## Corrected reconstruction
```c
// Load the active text color. func_0x001af0b0(0) selects attribute slot 0;
// func_0x001af0c0 writes the ARGB word.  [inferred primitive names]
void set_draw_color(u32 argb)
{
    gfx_select_attr(0);       // func_0x001af0b0
    gfx_set_color(argb);      // func_0x001af0c0
}

enum ui_label_color {
    UI_COLOR_ENABLED  = 0x80808080,  // bright
    UI_COLOR_DISABLED = 0x80404040,  // dim
};
```

## Evidence
- Raw: `FUN_00614720.c` — `func_0x001af0b0(0)` then `func_0x001af0c0(param_1)`.
- Caller 0x613530 passes ARGB constants gated on the availability bitmask; other callers (0x612ca0, 0x6130a0, 0x613380, 0x6139c0) likewise call it just before text draws.
- Confidence **Medium**: color semantics inferred from constants, not runtime-confirmed; the `select(0)` arg meaning is a guess.

## Remaining uncertainty
Exact meaning of the constant `0` to `func_0x001af0b0` (attribute slot vs. blend mode). Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614720.c`  — untouched decompiler output.
