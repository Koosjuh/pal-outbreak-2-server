# 0x005df060 url_find_double_slash

| field | value |
|---|---|
| Original address | 0x005df060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df060 |
| Resolved name | url_find_double_slash |
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
Scans for the first '//' occurrence in the range and returns it (or NULL).

## Notes / uncertainty
Rewrote to full reconstruction. First '//' in [start,end-1); feeds the empty-segment collapse loop in url_canonicalize.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
