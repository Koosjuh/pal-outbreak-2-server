# 0x005e9ea0 markup_meta_match_keyword

| field | value |
|---|---|
| Original address | 0x005e9ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ea0 |
| Resolved name | markup_meta_match_keyword |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec320
**Referenced globals:** iRam007012a0 (overlay UI state base); +0x1120 (meta-tag matched flag)
**Referenced strings:** 0x648528 (7-char keyword literal)
**Referenced opcodes:** —
**State vars:** +0x1120

## Behavioral explanation
Markup handler: copies a tag field and memcmps it against a 7-char keyword (0x648528); on match sets UI flag +0x1120.

## Notes / uncertainty
Case-fold attr read (FUN_005ec320) + memcmp vs 7-char keyword @0x648528; sets gate +0x1120. Keyword string not dereferenced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
