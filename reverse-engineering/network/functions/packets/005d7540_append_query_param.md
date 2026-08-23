# 0x005d7540 append_query_param

| field | value |
|---|---|
| Original address | 0x005d7540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7540 |
| Resolved name | append_query_param |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d3930, FUN_005d47f0, FUN_005d5640, FUN_005d5900
**Callees:** FUN_005dfa90
**Referenced globals:** 0x004bf5c request query buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Appends an HTTP-style '&key=value' pair into the request buffer at base+0x4bf5c: leading 0x26 '&', 0x3d '=' separator, value URL-encoded via FUN_005dfa90, with 0x1000/0x100 length guards.

## Notes / uncertainty
Fully reconstructed real code: appends '&key=value' to query buffer at overlay_base(0x701068)+0x4bf5c; '&' only when non-empty, key raw, value FULLY percent-encoded (%XX per byte via FUN_005dfa90). Guards: total <0x1000, per-field <0x100; returns new length or -1. Confirms app layer = HTTP/Bioserver query-string.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
