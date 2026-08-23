# 0x005beba0 register_objtype_0xad

| field | value |
|---|---|
| Original address | 0x005beba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005beba0 |
| Resolved name | register_objtype_0xad |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005beb40
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 object registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers a type-0xad object into 0x7018d0 via the identity/no-op register stubs and returns its id.

## Notes / uncertainty
Register wrapper: begin(0xAD)->commit->end, returns 0xAD; caller FUN_005beb40 stores tag into dispatch table slot*0x20+0x6ca97e. Builder callees inert so net effect = mint constant 0xAD. Table population not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005beba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
