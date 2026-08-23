# 0x005b0750 widget_color_pulse_up

| field | value |
|---|---|
| Original address | 0x005b0750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0750 |
| Resolved name | widget_alpha_fade_in |
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
Alpha fade-IN pulse for the selected highlight row — the mirror of `widget_alpha_fade_out`. When idle (`+6==0`) and this row IS the selected one (`+3 == cRam006c5497`), it arms a 16-step ramp starting at alpha 0. Each active frame it increments the alpha accumulator `+0x50` by the step `+0x4c` (16.0) and writes it into the top (alpha) byte of the color `+0x2c` (RGB white). After 16 steps it latches to `0xffffffff` (opaque white), sets `+5=0` (selected/idle) and clears the pulse flag. Net effect: the highlight bar fades in on the newly-selected row.

## Input / output
- `param_1` — widget pointer.
- returns void.

## Side effects
- Writes `+0x2c` (color alpha), `+0x50` (accum), and on completion `+5=0`, `+6=0`.
- Arms `+6=1`, `+0x50=0.0`, `+0x4c=16.0`, `+8=16` on trigger.

## Important branches
- `+6==1` (active): `--(+8) < 1` -> latch `0xffffffff`, `+5=0`, `+6=0`; else ramp alpha up and write `((int)accum<<24)|0xffffff`.
- `+6==0 && +3 == cRam006c5497` (selected) -> arm the fade-in.
- (`+6==0 && +3 != sel`) -> no-op (non-selected rows are handled by fade_out).

## Constants & flags
- start alpha `+0x50 = 0` (0.0f); step `+0x4c = 0x41800000` = 16.0f; steps `+8 = 0x10` (16).
- final color `0xffffffff` (opaque white). Active color = `((int)accum << 24) | 0x00ffffff`.
- `2.1474836e+09` (2^31) overflow guard on the accumulator before the int cast.

## Corrected reconstruction
```c
// fade the selected row's highlight alpha 0 -> 255 over 16 frames
void widget_alpha_fade_in(Widget *w) {
    if (w->pulse_active /*+6*/ == 1) {
        if (--w->step /*+8*/ < 1) {
            w->color /*+0x2c*/ = 0xffffffff;      // opaque white
            w->sel_flag /*+5*/ = 0;
            w->pulse_active = 0;
        } else {
            float a = w->accum /*+0x50*/ + w->ramp /*+0x4c*/;
            w->accum = a;
            if (a >= 2147483648.0f) a -= 2147483648.0f;   // int-cast guard
            w->color = ((int)a << 24) | 0x00ffffff;
        }
    } else if (w->pulse_active == 0 && w->row /*+3*/ == g_selection /*cRam006c5497*/) {
        w->pulse_active = 1;
        w->accum = 0.0f;
        w->ramp  = 16.0f;                          // 0x41800000
        w->step  = 0x10;
    }
}
```

## Evidence
- FUN_005b0750.c: active branch decrementing `+8`, latch `0xffffffff`/`+5=0`/`+6=0`, else `+0x50 + +0x4c` then `(int)fVar2<<0x18|0xffffff` (lines 12-27); arm condition `+6==0 && +3 == cRam006c5497` with `+0x50=0`, `+0x4c=0x41800000`, `+8=0x10` (lines 29-34).
- Exact mirror of widget_alpha_fade_out (0x5b0660): `+`-ramp vs `-`-ramp, `== sel` vs `!= sel`, start 0 vs 255.
- Runtime-unvalidated.

## Remaining uncertainty
Same channel-order assumption as the fade-out sibling. Name generalized "pulse_up" -> "alpha_fade_in".

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0750.c`  — untouched decompiler output.
