# 0x005ea120 markup_ctx_push

| field | value |
|---|---|
| Original address | 0x005ea120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea120 |
| Resolved name | markup_ctx_push |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** +0xe96c (ctx depth counter); +0xe96d (ctx stack array)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe96c

## Behavioral explanation
Pushes a zero entry onto the nested-tag context stack at +0xe96d indexed by counter +0xe96c, increments the counter, flushes layout.

## Notes / uncertainty
Nested-element open: push zero entry stack[+0xe96c] @+0xe96d, depth++, flush run. No bounds clamp visible (overflow risk); per-level byte meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
