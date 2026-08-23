# 0x005be9e0 msgbuilder_begin_record

| field | value |
|---|---|
| Original address | 0x005be9e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be9e0 |
| Resolved name | msgbuilder_begin_record |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bda80, FUN_005bdeb0, FUN_005bdef0, FUN_005beba0, FUN_005bec80, FUN_005becf0, FUN_005bed60, FUN_005bedd0, FUN_005bee40, FUN_005bee90, FUN_005bef00, FUN_005c08b0, FUN_005c0dc0, FUN_005c1e70, FUN_005c1f30, FUN_005c1ff0, FUN_005c2080, FUN_005c2250, FUN_005c27d0, FUN_005c4460, FUN_005c6fb0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registration stub that returns its second arg (the type selector); used by the object-type register wrappers to seed a type code.

## Notes / uncertainty
Identity: returns arg2 (record/type tag). Opens a 0x7018d0 builder record; 21 callers all pass 0x7018d0 as arg1. In FUN_005beba0 the returned tag is stored into the 0x6ca97e dispatch table. No store present in this build.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be9e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
