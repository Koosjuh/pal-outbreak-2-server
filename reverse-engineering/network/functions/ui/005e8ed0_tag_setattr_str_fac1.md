# 0x005e8ed0 tag_setattr_str_fac1

| field | value |
|---|---|
| Original address | 0x005e8ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8ed0 |
| Resolved name | tag_setattr_str_fac1 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0xfac1 (string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: extracts a 256-byte string arg into render-ctx field +0xfac1.

## Notes / uncertainty
Extract arg into +0xfac1 (256B, NOT in ee590 per-run clear set -> inferred persistent/page-scoped, e.g. title/resource). Role unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
