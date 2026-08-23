# 0x005bb610 broadcast_op11_to_room

| field | value |
|---|---|
| Original address | 0x005bb610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb610 |
| Resolved name | broadcast_op11_to_room |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb670
**Callees:** FUN_005c60d0
**Referenced globals:** 0x007006d4 handler table [4] (stride 8)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates 4 slots at 0x7006d4 (stride 8); for each non-null handler pointer calls FUN_005c60d0(handler, &param_2), broadcasting a single byte to all registered handlers.

## Notes / uncertainty
RENAMED/re-scoped rooms: broadcasts event byte via send_op11(005c60d0) to each non-null of 4 conn slots at 0x7006d4 (room max players). param_1 unused. Event meaning + caller trigger open; op11 wire semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
