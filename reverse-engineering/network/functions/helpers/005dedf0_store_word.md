# 0x005dedf0 store_word

| field | value |
|---|---|
| Original address | 0x005dedf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dedf0 |
| Resolved name | store_word |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca380, FUN_005cccf0, FUN_005cce30, FUN_005cd1d0, FUN_005d3930, FUN_005d5cc0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Trivial setter: *param_1 = param_2.

## Notes / uncertainty
Already complete: trivial *param_1 = param_2 32-bit store-through-pointer. Domain meaning is per-caller. Left untouched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dedf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
