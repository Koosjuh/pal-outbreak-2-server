# 0x005bdc70 apply_ui_dimensions

| field | value |
|---|---|
| Original address | 0x005bdc70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdc70 |
| Resolved name | apply_ui_dimensions |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bc990, FUN_005bcee0
**Callees:** —
**Referenced globals:** 0x6cb98c one-shot flag; 0x6cb96c UI callback ptr; 0x36848c/8e src dims; 0x7006ac/a8 clamped dims; 0x368490/92 & 0x6febe0 pos
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cb98c dirty/one-shot flag

## Behavioral explanation
One-shot (gated by cRam006cb98c): fires a UI callback then latches clamped width/height (<=0xfa) from 0x36848c/8e into UI globals 0x7006ac/a8.

## Notes / uncertainty
One-shot (flag 0x6cb98c) UI layout finalizer: measure callback 0x6cb96c, clamp width/height to 0xFA into 0x7006ac/a8, conditional position latch 0x6febde/e0. Pure UI; field labels inferred from 0xFA clamp.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdc70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
