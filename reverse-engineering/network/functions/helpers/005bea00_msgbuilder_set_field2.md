# 0x005bea00 msgbuilder_set_field2

| field | value |
|---|---|
| Original address | 0x005bea00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea00 |
| Resolved name | msgbuilder_set_field2 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00606780
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns).

## Notes / uncertainty
Inert slot. Called (0x7018d0,2) in the 0x1031 reply build. Meaning of scalar 2 (subtype/count/version) unresolvable from empty body.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
