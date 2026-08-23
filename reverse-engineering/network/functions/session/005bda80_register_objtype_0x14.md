# 0x005bda80 register_objtype_0x14

| field | value |
|---|---|
| Original address | 0x005bda80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bda80 |
| Resolved name | register_objtype_0x14 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bda60
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea20, FUN_005bea80
**Referenced globals:** 0x7018d0 object/dispatch registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers an object/handler of type code 0x14 into dispatch object 0x7018d0 via the vtable-register stubs.

## Notes / uncertainty
Builder-idiom registration of type 0x14 (with handler param_1) into registry 0x7018d0; builder leaves (005be9e0/bea20/bea10/bea80) are identity/no-op stubs in this build so observable writes are nil. Runtime wiring unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bda80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
