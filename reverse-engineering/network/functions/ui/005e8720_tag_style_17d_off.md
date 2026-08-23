# 0x005e8720 tag_style_17d_off

| field | value |
|---|---|
| Original address | 0x005e8720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8720 |
| Resolved name | tag_style_17d_off |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** +0x17d (style flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x17d

## Behavioral explanation
Markup tag handler: clears render flag +0x17d=0.

## Notes / uncertainty
Inverse of 0x005e86f0; clears +0x17d.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
