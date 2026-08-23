# 0x005bdae0 register_objtype_0x1a_wrapper

| field | value |
|---|---|
| Original address | 0x005bdae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdae0 |
| Resolved name | register_objtype_0x1a_wrapper |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3790
**Callees:** FUN_005bdeb0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper that calls FUN_005bdeb0 (type-0x1a registration) and returns 0.

## Notes / uncertainty
Thin wrapper -> 005bdeb0, returns 0. Called from handler-registration driver 005b3790.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
