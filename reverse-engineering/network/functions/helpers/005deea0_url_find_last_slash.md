# 0x005deea0 url_find_last_slash

| field | value |
|---|---|
| Original address | 0x005deea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005deea0 |
| Resolved name | url_find_last_slash |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df170, FUN_005df340
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans backward from end toward start for the last '/', returning it or NULL.

## Notes / uncertainty
Already complete: reverse scan for last '/' in [start,end), NULL if none; end exclusive (pre-decrement). Caller must ensure end>start. Left untouched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005deea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
