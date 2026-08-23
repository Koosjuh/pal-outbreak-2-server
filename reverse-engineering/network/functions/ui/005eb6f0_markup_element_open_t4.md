# 0x005eb6f0 markup_element_open_t4

| field | value |
|---|---|
| Original address | 0x005eb6f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb6f0 |
| Resolved name | markup_element_open_t4 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef5e0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4 (out len)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Type-4 element open: FUN_005f0e10(...,4), reset out buffer, layout FUN_005ef5e0 + commit FUN_005ef850(4); returns -1 on failure.

## Notes / uncertainty
Simplest opener: begin/prep/commit kind-4, return -(commit<0). Likely leaf/void element; inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb6f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
