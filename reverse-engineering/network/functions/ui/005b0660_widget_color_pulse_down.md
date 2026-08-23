# 0x005b0660 widget_color_pulse_down

| field | value |
|---|---|
| Original address | 0x005b0660 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0660 |
| Resolved name | widget_alpha_fade_out |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0550 (widget_cb_row_highlight)
**Callees:** —
**Referenced globals:** 0x6c5497 cRam006c5497 = selection index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+3 row index; +5 selected-flag; +6 pulse-active; +8 step counter; +0x2c color; +0x4c ramp step(f32); +0x50 alpha accum(f32)

## Behavioral explanation
Alpha fade-OUT pulse for a non-selected highlight row. When idle (`+6==0`) and this row is not the selected one (`+3 != cRam006c5497`), it arms a 16-step ramp starting at alpha 255. Each active frame it decrements the alpha accumulator `+0x50` by the step `+0x4c` (16.0) and writes it into the top (alpha) byte of the color `+0x2c` (RGB fixed white). After 16 steps it latches the color to `0x00ffffff` (fully transparent), sets `+5=1` (now unselected/idle) and clears the pulse-active flag. Net effect: the highlight bar on a row that just lost selection fades to invisible.

## Input / output
- `param_1` — widget pointer.
- returns void.

## Side effects
- Writes `+0x2c` (color alpha), `+0x50` (accum), and on completion `+5=1`, `+6=0`.
- Arms `+6=1`, `+0x50=255.0`, `+0x4c=16.0`, `+8=16` on trigger.

## Important branches
- `+6==1` (active): `--(+8) < 1` -> latch `0x00ffffff`, `+5=1`, `+6=0`; else ramp alpha down and write `((int)accum<<24)|0xffffff`.
- `+6==0 && +3 != cRam006c5497` (not selected) -> arm the fade-out.
- (`+6==0 && +3 == sel`) -> no-op (the selected row is handled by pulse_up).

## Constants & flags
- start alpha `+0x50 = 0x437f0000` = 255.0f; step `+0x4c = 0x41800000` = 16.0f; steps `+8 = 0x10` (16).
- final color `0x00ffffff` (alpha 0, white). Active color = `((int)accum << 24) | 0x00ffffff`.
- the `2.1474836e+09` (2^31) guard wraps a float that would overflow the int cast (defensive; not normally hit).

## Corrected reconstruction
```c
// fade a deselected row's highlight alpha 255 -> 0 over 16 frames
void widget_alpha_fade_out(Widget *w) {
    if (w->pulse_active /*+6*/ == 1) {
        if (--w->step /*+8*/ < 1) {
            w->color /*+0x2c*/ = 0x00ffffff;      // fully transparent
            w->sel_flag /*+5*/ = 1;
            w->pulse_active = 0;
        } else {
            float a = w->accum /*+0x50*/ - w->ramp /*+0x4c*/;
            w->accum = a;
            if (a >= 2147483648.0f) a -= 2147483648.0f;   // int-cast guard
            w->color = ((int)a << 24) | 0x00ffffff;
        }
    } else if (w->pulse_active == 0 && w->row /*+3*/ != g_selection /*cRam006c5497*/) {
        w->pulse_active = 1;
        w->accum = 255.0f;                         // 0x437f0000
        w->ramp  = 16.0f;                          // 0x41800000
        w->step  = 0x10;
    }
}
```

## Evidence
- FUN_005b0660.c: active branch decrementing `+8`, latch `0xffffff`/`+5=1`/`+6=0`, else `+0x50 - +0x4c` then `(int)fVar2<<0x18|0xffffff` (lines 12-27); arm condition `+6==0 && +3 != cRam006c5497` with `+0x50=0x437f0000`, `+0x4c=0x41800000`, `+8=0x10` (lines 29-34).
- Mirror of widget_alpha_fade_in (0x5b0750); both dispatched by widget_cb_row_highlight per the `+5` flag.
- Runtime-unvalidated.

## Remaining uncertainty
Color channel order (alpha-in-top-byte, RGB white) inferred from `<<24 | 0xffffff`. Name generalized from "pulse_down" to "alpha_fade_out" to reflect the single-shot (not oscillating) ramp.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0660.c`  — untouched decompiler output.
