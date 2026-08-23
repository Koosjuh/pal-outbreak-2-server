# 0x005ea190 markup_ctx_open_align

| field | value |
|---|---|
| Original address | 0x005ea190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea190 |
| Resolved name | markup_ctx_open_align |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec920, FUN_005ef780
**Referenced globals:** +0xe96c (ctx depth); +0xd892 (table mode); +0xd894; +0x14 (align nibble); +0x2531 (per-cell align)
**Referenced strings:** 0x648320 (align keyword table, len 0x20)
**Referenced opcodes:** —
**State vars:** +0xe96c; +0xd892; +0x14

## Behavioral explanation
Opens a nested tag: matches an alignment keyword (table 0x648320) into the ctx stack; if value==2 bumps the align nibble in +0x14 (global) or per-cell +0x2531 (table mode) capped at 0xf0.

## Notes / uncertainty
Opens nested align tag: keyword-lookup (tbl 0x648320) -> tag_stack; code==2 bumps global align nibble +0x14 or per-cell +0x2531 (cap 0xF0), reflow in table mode. Depth++ presumably in a matching close handler (not in-frame). Keyword table contents unread; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
