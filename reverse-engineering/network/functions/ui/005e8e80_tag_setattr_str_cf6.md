# 0x005e8e80 tag_setattr_str_cf6

| field | value |
|---|---|
| Original address | 0x005e8e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8e80 |
| Resolved name | tag_setattr_str_cf6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0xcf6 (string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: extracts a 256-byte string arg into render-ctx field +0xcf6.

## Notes / uncertainty
Extract arg into str buffer +0xcf6 (per-run trio); no expansion. Attribute role unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8e80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
