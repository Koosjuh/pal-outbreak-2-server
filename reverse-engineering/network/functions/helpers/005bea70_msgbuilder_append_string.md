# 0x005bea70 msgbuilder_append_string

| field | value |
|---|---|
| Original address | 0x005bea70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea70 |
| Resolved name | msgbuilder_append_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005bec80, FUN_005becf0, FUN_005bed60, FUN_005bedd0, FUN_005bee90
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns).

## Notes / uncertainty
Inert slot. Uniform callsite (0x7018d0, strptr, strlen(strptr)) in menu builders -> counted-string append. Role well-inferred from (ptr,len) pattern; body writes nothing.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
