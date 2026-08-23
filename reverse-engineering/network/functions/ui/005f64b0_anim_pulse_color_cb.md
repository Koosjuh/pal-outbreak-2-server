# 0x005f64b0 anim_pulse_color_cb

| field | value |
|---|---|
| Original address | 0x005f64b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f64b0 |
| Resolved name | anim_pulse_alpha_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as a display-list node draw callback; no static caller)
**Callees:** func_0x001886c0 (sinf)
**Referenced globals:** DAT_00649730 (int16 x-coordinate/column table); DAT_00692ec0 (float angle→radian scale const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+4 (init state 0/1); node+9 (phase-reset request); node+0x3a (u16 animation phase); node+0x24 (u16 flag word); node+0x28 (u16 x); node+0x2c (u32 RGBA color)

## Behavioral explanation
Per-frame draw/update callback for one display-list node (a blinking/pulsing sprite or text cell). On first
call it initializes the node (marks it active, seeds default palette/height fields, zeroes the phase). Every
frame it: (1) refreshes the node's X position from a column table indexed by the owning widget's column
field, (2) advances a 15-bit animation phase by a fixed step, (3) optionally snaps the phase to the sine peak
(0x4000 = quarter turn) when a reset was requested, and (4) computes `alpha = sin(phase) * 255` and writes it
into the top byte of the node's RGBA color word, leaving RGB untouched. Net effect: the node's opacity
oscillates sinusoidally — a highlight/attention pulse.

## Input / output
- `param_1` (`node*`): pointer to a display-list node / draw record (the `+0x24/+0x28/+0x2c/+0x3a` layout is the
  common overlay draw-node used across these `_cb` callbacks).
- Returns `void`. All output is in-place mutation of the node.

## Side effects
- node+4: 0→1 (activate) on first call.
- node+8 = 0x14, node+9 = 0, node+0x0a = 0xff  (default height/flags/max-alpha seeds, init only).
- node+0x24 |= 0x80  (sets a render flag bit; init only).
- node+0x28 = column X from `DAT_00649730[widget->col]` (every frame).
- node+0x3a = (node+0x3a + 0x400) & 0x7fff  (phase advance, wraps at 0x8000).
- node+0x2c: RGB (low 24 bits) preserved, alpha (bits 24-31) replaced with `sin(phase)*255`.

## Important branches
- `node+4 != 1`:
  - `node+4 != 0` (some other/paused state) → early `return`, no draw.
  - `node+4 == 0` (fresh) → run the init block (seed fields, set flag 0x80), then fall through to per-frame update.
- `node+9 != 0` (reset-phase request) → force phase = 0x4000 (sine == 1.0, full brightness) and clear the request.
- `fVar2 < 2.1474836e9` branch: this is the decompiler's float→unsigned-int conversion guard (values ≥ 2^31
  are handled by subtracting 2^31). Since `sin()*255 ∈ [-255,255]`, the `>= 2^31` path is never taken at
  runtime; both arms load the same masked color. Behaviorally a no-op guard.

## Constants & flags
- `0x400` — phase step per frame (1/32 of the 0x8000 phase range).
- `0x7fff` — phase mask (15-bit wrap).
- `0x4000` — sine-peak phase (quarter period → sin == 1.0), used as the reset/full-brightness value.
- `0x80` (node+0x24) — render/visibility flag bit set at init.
- `0xff` (node+0x0a) — max alpha seed.
- `0x28` shift on node+0x2c — alpha occupies the top byte (RGBA, alpha = bits 24..31).

## Corrected reconstruction
```c
// Display-list draw node (subset; shared across overlay _cb callbacks)
typedef struct draw_node {
    /* 0x04 */ u8   state;        // 0=uninit, 1=active, other=paused (skip)
    /* 0x08 */ u8   height;       // seeded 0x14
    /* 0x09 */ u8   reset_phase;  // request: snap phase to peak
    /* 0x0a */ u8   max_alpha;    // seeded 0xff
    /* 0x10 */ widget *owner;     // owning widget (has u16 col @ +0x0c)
    /* 0x24 */ u16  flags;        // |0x80 = visible/render
    /* 0x28 */ u16  x;            // screen X (from column table)
    /* 0x2c */ u32  rgba;         // 0xAARRGGBB-style; this cb pulses A
    /* 0x3a */ u16  phase;        // 15-bit sine phase
} draw_node;

void anim_pulse_alpha_cb(draw_node *n)
{
    if (n->state != 1) {
        if (n->state != 0) return;          // paused/other → skip frame
        n->state       = 1;                 // activate
        n->height      = 0x14;
        n->reset_phase = 0;
        n->max_alpha   = 0xff;
        n->phase       = 0;
        n->flags      |= 0x80;              // mark visible
    }

    n->x = ((s16*)DAT_00649730)[ n->owner->col ];   // refresh X from column table

    n->phase = (n->phase + 0x400) & 0x7fff;         // advance phase, wrap

    if (n->reset_phase) {                           // snap to full brightness
        n->phase       = 0x4000;                    // sin(0x4000) == 1.0
        n->reset_phase = 0;
    }

    float s = sinf(DAT_00692ec0 * (float)n->phase / 65536.0f);  // [-1,1]
    u8 alpha = (u8)(s * 255.0f);                     // pulsing alpha
    n->rgba = (n->rgba & 0x00FFFFFF) | ((u32)alpha << 24);       // keep RGB, set A
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005f64b0.c` (size 344, 0 callers/callees recorded).
- `func_0x001886c0` fed `scale * phase/65536` then `*255` = classic `sinf` opacity envelope.
- `DAT_00649730` indexed by `*(int*)(node+0x10) + 0xc` = the sibling column-X table also used by
  `draw_footer_row_cb` (0x649740). Both are `_cb` draw nodes sharing the `+0x24/+0x28/+0x2c/+0x3a` layout.
- Confidence **High** (structure + math unambiguous). Runtime validation pending.

## Remaining uncertainty
- Exact RGBA byte order (whether the top byte is alpha vs. a fixed intensity) is inferred from the shift, not
  from a runtime frame capture.
- `node+0x10` owner layout (`col` @ +0x0c) is inferred from the shared column-table indexing pattern.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f64b0.c`  — untouched decompiler output.
