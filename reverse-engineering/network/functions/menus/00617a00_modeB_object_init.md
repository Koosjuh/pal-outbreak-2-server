# 0x00617a00 modeB_object_init

| field | value |
|---|---|
| Original address | 0x00617a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617a00 |
| Resolved name | modeB_object_init |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aeae0, FUN_005b1a30, FUN_006177d0, FUN_0062cb00, FUN_0062d8b0, FUN_0062e2a0, FUN_0062e720
**Callees:** FUN_005aec20, FUN_00637180
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0(type)=0x0b

## Behavioral explanation
Constructor stamping a scene object with type byte=0x0b and clearing its 8-byte state header; calls FUN_00637180 + FUN_005aec20.

## Notes / uncertainty
Constructor for type-0x0b scene; primes via FUN_00637180, clears 8-byte header incl. variant=0, registers. Body identical to the two thunks. FUN_00637180 role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
