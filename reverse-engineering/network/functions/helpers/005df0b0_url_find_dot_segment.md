# 0x005df0b0 url_find_dot_segment

| field | value |
|---|---|
| Original address | 0x005df0b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df0b0 |
| Resolved name | url_find_dot_segment |
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
Scans for a '/./' sequence in the range and returns it (or NULL).

## Notes / uncertainty
Rewrote to full reconstruction. First '/./' (current-dir) segment; RFC-3986 remove_dot_segments '/.' case, memmove tail -2.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df0b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
