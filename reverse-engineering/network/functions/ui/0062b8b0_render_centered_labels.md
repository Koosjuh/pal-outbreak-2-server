# 0x0062b8b0 render_centered_labels

| field | value |
|---|---|
| Original address | 0x0062b8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b8b0 |
| Resolved name | render_centered_labels |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fea0
**Referenced globals:** +0x26/+0x28 draw coords
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Measures two localized strings (ids 0x61/0x62), computes widths and draws them centered around x=0x140 (FUN_005af1e0).

## Notes / uncertainty
Per-frame node draw callback: renders two localized labels (ids 0x61/0x62) centered on x=0x140 with 9px/char advance; init sets coords/Z on first run. Pure presentation, unrelated to net. No caller in slice; which labels/screen unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b8b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
