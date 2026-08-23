# 0x005bdeb0 register_objtype_0x1a

| field | value |
|---|---|
| Original address | 0x005bdeb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdeb0 |
| Resolved name | register_objtype_0x1a |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bdae0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 object registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers an object/handler of type code 0x1a into dispatch object 0x7018d0 via the vtable-register stubs.

## Notes / uncertainty
Registers type 0x1a into 0x7018d0, NO set-handler step (handler-less/marker type). Builder leaves stubbed. Runtime role unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdeb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
