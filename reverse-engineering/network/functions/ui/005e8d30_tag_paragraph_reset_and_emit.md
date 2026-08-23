# 0x005e8d30 tag_paragraph_reset_and_emit

| field | value |
|---|---|
| Original address | 0x005e8d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d30 |
| Resolved name | tag_paragraph_reset_and_emit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ee590, FUN_005ee610, FUN_005eef70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: consumes arg then runs FUN_005ee590 + FUN_005ee610 (layout finalize/commit helpers).

## Notes / uncertainty
eef70 flush + ee590 attr-reset (df6/df8=0x1e, clear str bufs) + ee610 emit/advance. Suggest rename tag_paragraph_reset_and_emit.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
