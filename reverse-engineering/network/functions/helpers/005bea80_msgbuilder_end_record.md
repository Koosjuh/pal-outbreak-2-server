# 0x005bea80 msgbuilder_end_record

| field | value |
|---|---|
| Original address | 0x005bea80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea80 |
| Resolved name | msgbuilder_end_record |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005bda80, FUN_005bdeb0, FUN_005bdef0, FUN_005beba0, FUN_005bec80, FUN_005becf0, FUN_005bed60, FUN_005bedd0, FUN_005bee40, FUN_005bee90, FUN_005bef00, FUN_005c08b0, FUN_005c0dc0, FUN_005c1e70, FUN_005c1f30, FUN_005c1ff0, FUN_005c2080, FUN_005c2250, FUN_005c27d0, FUN_005c4460, FUN_005c6fb0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns); the trailing no-op in every object-type register wrapper.

## Notes / uncertainty
Inert 8-byte slot, 21 callers. Terminal (end-record/finalize) call in every builder wrapper after commit bea10. Role inferred from position.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
