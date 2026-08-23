# 0x005f64b0 anim_pulse_alpha_cb

| field | value |
|---|---|
| Original address | 0x005f64b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f64b0 |
| Resolved name | anim_pulse_alpha_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** func_0x001886c0(sin)
**Referenced globals:** 0x649730 (x-coord table); 0x692ec0 (angle scale const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+4 (init flag); param+9 (reset flag); param+0x3a (anim angle)

## Behavioral explanation
Per-frame draw callback that pulses a sprite's alpha/color: advances angle field +0x3a by 0x400 (mask 0x7fff), takes sin (func_0x001886c0), scales to 255 and packs into the color word at +0x2c.

## Notes / uncertainty
Per-frame draw node cb; pulses alpha (top byte of RGBA @+0x2c) via sin(phase). RGBA byte-order and owner+0x10 layout inferred, not runtime-captured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f64b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
