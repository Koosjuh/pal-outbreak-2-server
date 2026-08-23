# 0x005df640 url_scheme_is_javascript

| field | value |
|---|---|
| Original address | 0x005df640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df640 |
| Resolved name | url_scheme_is_javascript |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df340
**Callees:** FUN_005dedc0, FUN_005df600
**Referenced globals:** iRam00701068+0x4d05c (scratch); PTR_s_javascript__006465a0 (scheme table)
**Referenced strings:** javascript:
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Lowercases a copy of the URL and prefix-matches it against a scheme table headed by 'javascript:', returning the matched index or -1 (used to block/route by scheme).

## Notes / uncertainty
Copies URL to scratch+0x4d05c, lowercases, prefix-matches NULL-term table PTR_s_javascript__006465a0; returns match index or -1. strlen/strncmp (func_0x0010a050/0010a338) identities inferred. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
