# 0x005e8690 tag_style_17e_on

| field | value |
|---|---|
| Original address | 0x005e8690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8690 |
| Resolved name | tag_style_17e_on |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** +0x17e (style flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x17e

## Behavioral explanation
Markup tag handler: consumes arg and sets render flag +0x17e=1 (a style/attribute toggle).

## Notes / uncertainty
Flush-to-origin then set style flag +0x17e=1. Visual meaning of 0x17e (bold/color/etc) unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
