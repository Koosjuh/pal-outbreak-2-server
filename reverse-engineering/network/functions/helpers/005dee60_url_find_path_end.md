# 0x005dee60 url_find_path_end

| field | value |
|---|---|
| Original address | 0x005dee60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dee60 |
| Resolved name | url_find_path_end |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df170, FUN_005df340, FUN_005df7b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans a URL string forward to the first NUL, '?' or '#', returning the pointer to the end of the path component.

## Notes / uncertainty
Already complete: returns first '\0','?' or '#' — exclusive end of the hierarchical part; the upper-bound used by every sibling scanner. Left untouched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dee60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
