# 0x005bda60 register_objtype_0x14_wrapper

| field | value |
|---|---|
| Original address | 0x005bda60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bda60 |
| Resolved name | register_objtype_0x14_wrapper |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b2bc0
**Callees:** FUN_005bda80
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper that calls FUN_005bda80 and returns 0.

## Notes / uncertainty
Thin wrapper -> 005bda80, returns 0. Declared param unused.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bda60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
