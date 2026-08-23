# 0x005edc40 layout_form_control

| field | value |
|---|---|
| Original address | 0x005edc40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005edc40 |
| Resolved name | layout_form_control |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9680
**Callees:** FUN_005d9dd0, FUN_005ed6e0, FUN_005f2940
**Referenced globals:** iRam007012a0; +0x4e4 (type); +0x4e6 (fixed width); +0x6ec/+0x6ee; +0x182 (max width)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4e4; +0x186; +0xd892

## Behavioral explanation
Computes a form control's cell width from its type (+0x4e4) and value length, then lays it out via draw_form_control; updates max content width on the measure pass.

## Notes / uncertainty
Sizes control (cells) by type + multibyte glyph-count of value, routes to draw_form_control or table path FUN_005f2940. Min-width accumulate on pass 0xf6. +0xd8c0/+0xd8c4 operands in maxwidth math ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005edc40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
