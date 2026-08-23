# 0x005de660 localized_string_cat2

| field | value |
|---|---|
| Original address | 0x005de660 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de660 |
| Resolved name | localized_string_cat2 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8340
**Callees:** —
**Referenced globals:** cRam0035ba80 (language); PTR_PTR tables per language
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0035ba80

## Behavioral explanation
For category id 2, returns a localized string-table pointer selected by language (cRam0035ba80).

## Notes / uncertainty
Already reconstructed; category==2 single-group per-language lookup verified. Semantic of category 2 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de660.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
