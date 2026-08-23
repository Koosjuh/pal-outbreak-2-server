# 0x005df110 url_find_dotdot_segment

| field | value |
|---|---|
| Original address | 0x005df110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df110 |
| Resolved name | url_find_dotdot_segment |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df340
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans for a '/../' sequence in the range and returns it (or NULL).

## Notes / uncertainty
Rewrote to full reconstruction. First '/../' (parent) segment; RFC-3986 '/..' case, memmove tail -3, with the root-anchored policy split handled by url_canonicalize.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
