# 0x005e8d60 tag_paragraph_reset_attrs

| field | value |
|---|---|
| Original address | 0x005e8d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d60 |
| Resolved name | tag_paragraph_reset_attrs |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ee590, FUN_005eef70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: consumes arg then runs FUN_005ee590 (layout helper).

## Notes / uncertainty
eef70 flush + ee590 attr-reset, no re-emit (8d30 minus ee610). Suggest rename tag_paragraph_reset_attrs.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
