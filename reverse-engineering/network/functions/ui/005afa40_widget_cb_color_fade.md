# 0x005afa40 widget_cb_color_fade

| field | value |
|---|---|
| Original address | 0x005afa40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005afa40 |
| Resolved name | widget_cb_selection_marquee |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a widget callback by screen_build_score_list)
**Callees:** —
**Referenced globals:** 0x6c5497 cRam006c5497 = current selection index; 0x638910 const y-position table (10× i16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+4 anim-FSM; +8 blink-hold; +9 blink-count; +0xa slide-frames; +0x28 y; +0x2c ARGB color; +0x38 tracked-selection; +0x3a alpha-delta(i16); +0x4c slide-step(f32)

## Behavioral explanation
Per-frame callback for the selection marquee/highlight on the score-list screen. It does two things at once: (1) **tracks the selected row vertically** — whenever the global selection index `cRam006c5497` differs from the widget's cached `+0x38`, it starts an 8-frame slide of its y (`+0x28`) toward the target position from the const table at 0x638910; (2) **pulses its alpha** through a small FSM on `+4` that ramps the top (alpha) byte of the ARGB color `+0x2c` up and down using the signed delta `+0x3a`, producing a breathing highlight.

State machine on `+4` (only advanced while the selection is unchanged; a selection change forces a re-target back to state 1):
- **0 (init):** set sprite `+0x22=0x130`, blend flag `+0x24|=0x80`, color `+0x2c=0x4cffffff` (alpha 0x4c, white), snap `+0x28` to `table[sel]`, advance. Then run the re-target check.
- **1:** transient; immediately handled by the re-target check (begins a slide, sets alpha-delta path).
- **2:** alpha-pulse hold; decrement `+9`; on expiry advance and reload full color `0xffffffff`, `+8=0xe`, `+9=8`, `+0x3a=-22`; otherwise ramp alpha by `+0x3a`.
- **3:** decrement `+8`; when it underflows advance a phase.
- **4:** decrement `+9`; on expiry loop back to state 1 with color `0x4cffffff`; otherwise ramp alpha by `+0x3a`.
- **>=4/other:** skip to the slide tail.

Slide tail (`LAB_005afdd4`): if `+0xa` (slide frames) nonzero, decrement it and move `+0x28` by `-slide_step`; on the last frame snap `+0x28` exactly to `table[sel]`.

## Input / output
- `param_1` — widget pointer.
- returns void; all effects are on the widget and its color/position.

## Side effects
- Writes widget `+0x22/0x24/0x28/0x2c/+0x38/+0x3a/+0x4c` plus the FSM/counter bytes `+4/+8/+9/+0xa`.
- Reads global selection `cRam006c5497` and const table 0x638910 (copied to stack each call).

## Important branches
- `+0x38 != cRam006c5497` (in every non-init state that reaches the re-target check) -> start slide: `+0x4c = (y - table[sel]) / 8`, `+0x38 = sel`, `+0xa = 8`, advance FSM.
- state 2: `--(+9) < 1` -> reload full-white + reset alpha-pulse params (delta -22); else alpha += delta.
- state 4: `--(+9) < 1` -> back to state 1 (color 0x4cffffff); else alpha += delta.
- slide tail: `+0xa != 0` -> step y; reaching 0 snaps y to target.

## Constants & flags
- `+0x22 = 0x130` marquee sprite id.
- `+0x24 |= 0x80` blend/enable bit.
- `+0x2c` ARGB: `0x4cffffff` = dim white (alpha 0x4c), `0xffffffff` = full white; alpha byte = `(color>>24)`.
- `+0x3a` alpha delta: `0x16` (+22) and `0xffea` (-22) — pulse amplitude.
- slide over 8 frames (`/8.0`, `+0xa=8`); const y table = 0x638910 (10 shorts).

## Corrected reconstruction
```c
// selection-tracking marquee: slides to the selected row and breathes its alpha
void widget_cb_selection_marquee(Widget *w) {
    short ytab[10];                        // copied from 0x638910 each frame
    memcpy(ytab, &DAT_00638910, sizeof ytab);
    int sel = g_selection /*cRam006c5497*/;

    switch (w->anim /*+4*/) {
    case 4:
        if (w->tracked /*+0x38*/ == sel) {
            if (--w->blink_cnt /*+9*/ < 1) { w->anim = 1; w->color = 0x4cffffff; }
            else w->color = (((w->color>>24) + (u16)w->adelta) << 24) | 0xffffff;
        } else goto retarget;
        break;
    case 3:
        if (w->tracked == sel) { if (--w->blink_hold /*+8*/ < 0) w->anim++; }
        else goto retarget;
        break;
    case 2:
        if (w->tracked == sel) {
            if (--w->blink_cnt < 1) {
                w->anim++; w->color = 0xffffffff;
                w->blink_hold = 0xe; w->blink_cnt = 8; w->adelta /*+0x3a*/ = -22;
            } else w->color = (((w->color>>24) + (u16)w->adelta) << 24) | 0xffffff;
        } else goto retarget;
        break;
    default:                               // states 0, 1, and any other
        if (w->anim != 1) {
            if (w->anim != 0) { /* >=5 */ goto slide_tail; }
            // state 0 init
            w->sprite_id /*+0x22*/ = 0x130;
            w->blend /*+0x24*/ |= 0x80;
            w->color = 0x4cffffff;
            w->anim++;
            w->y /*+0x28*/ = ytab[sel];
        }
    retarget:
        if (w->tracked != sel) {
            w->slide_step /*+0x4c*/ = (float)(w->y - ytab[sel]) / 8.0f;
            w->tracked = sel;
            w->anim++;
            w->blink_cnt = 8;
            w->slide_frames /*+0xa*/ = 8;
            w->adelta = 0x16;              // +22
        }
    }

slide_tail:
    if (w->slide_frames != 0) {
        w->slide_frames--;
        w->y = (short)((float)w->y - w->slide_step);
        if (w->slide_frames == 0) w->y = ytab[sel];   // snap
    }
}
```
Note: the raw code is a linear if/else-if on `+4` (2,3,4,1/0), not a compiler `switch`; the exact fall-through into the shared re-target/slide-tail path is preserved above but re-expressed for readability. The state-0/1 branch merges into the re-target check as in the decompile.

## Evidence
- FUN_005afa40.c: table copy from `_DAT_00638910` (lines 18-22); FSM on `*(param_1+4)` values 4/3/2/1/0 (lines 24-115); re-target block computing `+0x4c = (y - table[sel])/8` and setting `+0x38`, `+0xa=8` (lines 39-45,105-113); alpha ramp `((color>>0x18)+delta)*0x1000000|0xffffff` (lines 33-35,78-80); slide tail `LAB_005afdd4` (lines 117-125).
- Sprite id 0x130 and blend 0x80 match the marquee layer allocated by screen_build_score_list.
- Runtime-unvalidated.

## Remaining uncertainty
The precise perceptual result of the 2/3/4 alpha-pulse cycle (blink cadence) is inferred from the counter math, not observed. ARGB channel order (alpha-in-top-byte) assumed from the `>>24 | 0xffffff` idiom. Original name generalized to "selection_marquee" (was "color_fade") since it also slides position.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005afa40.c`  — untouched decompiler output.
