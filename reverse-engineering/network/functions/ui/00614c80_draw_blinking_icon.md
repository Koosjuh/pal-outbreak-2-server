# 0x00614c80 draw_blinking_icon

| field | value |
|---|---|
| Original address | 0x00614c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614c80 |
| Resolved name | draw_icon_with_pulse |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612120, FUN_00612ae0, FUN_00613b10
**Callees:** FUN_00614e60 (build_sprite_quads), func_0x001a7b70 (renderer blend-mode set), func_0x001886c0 (sin)
**Referenced globals:** DAT_0064c2b0 (icon descriptor table, 4 bytes/entry); 0x64b9b0 (sprite-descriptor base, 0xc stride); DAT_00693928 (pulse/time scale); iRam0070d1c0+0x29 (audio/beat level byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x29

## Behavioral explanation
Draws one HUD icon selected by `param_1`. Each icon has a 4-byte descriptor in table `DAT_0064c2b0`:
`[0]`=base sprite index, `[1]`=base quad count, `[2]`=pulse-overlay sprite index, `[3]`=pulse-overlay
quad count (0 = no pulse). It always draws the base sprite at full opacity, then — if the descriptor
has a pulse overlay — temporarily switches the renderer to additive blend, computes a sine-driven alpha
from a global phase (`DAT_00693928`) scaled by the current audio/beat level (`ui+0x29`), draws the
overlay sprite tinted with that alpha in the high byte, and restores the default blend mode. Net effect:
an icon that softly pulses/glows in time with an audio or animation beat.

## Input / output
- `param_1` (`int`): icon id; indexes the descriptor table as `DAT_0064c2b0[param_1*4]`.
- `param_2`, `param_3` (`undefined8`): X and Y draw position (forwarded to `build_sprite_quads` as `dx,dy`).
- **returns** void.

## Side effects
- Emits sprite quads via `FUN_00614e60` (into the current draw list).
- Toggles renderer blend-mode register `0x5e` (`0x12` additive during the pulse draw, restored to `0x32`).

## Important branches
- `descriptor[3] == 0` (no pulse-overlay quads) → draw base sprite only, return.
- `descriptor[3] != 0` → additionally draw the pulse overlay with the computed alpha tint.
- `if (2.1474836e9 <= fVar3) fVar3 -= 2.1474836e9;` — unsigned-from-float correction (the `float→int`
  cast for the alpha byte handles values above INT_MAX), not domain logic.

## Constants & flags
- Descriptor stride `4` bytes: `[0]` base sprite idx, `[1]` base quad count, `[2]` pulse sprite idx,
  `[3]` pulse quad count.
- Sprite base `0x64b9b0`, stride `0xc` (12 bytes) → `sprite_addr = 0x64b9b0 + idx*0xc`.
- Blend-mode register `0x5e`: `0x12` = additive (pulse), `0x32` = default (restored).
- Alpha = `sin(DAT_00693928 * beat_level / 2 / 16) * 127 + 128` → range ~1..255, packed into bits 24-31
  of the color (`(alpha<<24) | 0xffffff` = white RGB, variable alpha).
- Base sprite color `0xffffffff` (opaque white).

## Corrected reconstruction
```c
struct icon_desc {            // DAT_0064c2b0[icon_id], 4 bytes
    uint8_t base_sprite;      // [0]
    uint8_t base_quads;       // [1]
    uint8_t pulse_sprite;     // [2]
    uint8_t pulse_quads;      // [3]  0 = no pulse overlay
};
#define SPRITE_BASE   0x64b9b0
#define SPRITE_STRIDE 0xc
#define BLEND_ADDITIVE 0x12
#define BLEND_DEFAULT  0x32

void draw_icon_with_pulse(int icon_id, short x, short y)
{
    struct overlay_ui_state *ui = (struct overlay_ui_state *)g_overlay_ui;
    struct icon_desc *d = &((struct icon_desc *)&DAT_0064c2b0)[icon_id];

    // base sprite, opaque white
    build_sprite_quads((short *)(SPRITE_BASE + d->base_sprite * SPRITE_STRIDE),
                       d->base_quads, x, y, 0xffffffff);          // FUN_00614e60

    if (d->pulse_quads != 0) {
        gs_set(0x5e, BLEND_ADDITIVE);                              // func_0x001a7b70
        float phase = (DAT_00693928 * (float)ui->beat_level) / 2.0f / 16.0f; // ui+0x29
        float a = sinf(phase) * 127.0f + 128.0f;                  // func_0x001886c0
        if (a >= 2147483648.0f) a -= 2147483648.0f;               // unsigned cast fixup
        uint32_t color = ((uint32_t)(int)a << 24) | 0xffffff;     // variable alpha, white RGB
        build_sprite_quads((short *)(SPRITE_BASE + d->pulse_sprite * SPRITE_STRIDE),
                           d->pulse_quads, x, y, color);
        gs_set(0x5e, BLEND_DEFAULT);                              // restore
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00614c80.c` (size 468, 3 callers, callee 00614e60).
- Descriptor stride `*4`, sub-fields `[0..3]`, sprite base `0x64b9b0` × `0xc`, alpha `sin*127+128`, the
  `0x5e=0x12`/`0x5e=0x32` blend bracket, and the `(int)a<<24 | 0xffffff` color pack are all exact.
- `func_0x001886c0` = sin and `func_0x001a7b70` = renderer-param set carried from fan-out classification;
  the blend bracket matches `overlay_gfx_init`'s default `0x5e=0x32`.

## Remaining uncertainty
`DAT_00693928` is inferred to be a global animation-phase/time value and `ui+0x29` an audio/beat level;
neither is runtime-validated. Which icons pulse (which descriptor entries carry a non-zero `[3]`) is
data-table dependent and not enumerated here. Pure UI effect; no protocol impact.
