# 0x005e8d90 tag_setattr_str_af6

| field | value |
|---|---|
| Original address | 0x005e8d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d90 |
| Resolved name | tag_setattr_str_af6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0xaf6 (string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: extracts a 256-byte string arg into render-ctx field +0xaf6.

## Notes / uncertainty
Extract markup ="value" via FUN_005ec1b0 into str buffer +0xaf6 (256B, per-run trio cleared by ee590). Attribute role of +0xaf6 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
