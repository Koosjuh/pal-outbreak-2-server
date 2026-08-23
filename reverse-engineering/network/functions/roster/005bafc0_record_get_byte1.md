# 0x005bafc0 record_get_byte1

| field | value |
|---|---|
| Original address | 0x005bafc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bafc0 |
| Resolved name | record_get_byte1 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad350, FUN_005ba5b0, FUN_0062c9f0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns byte at record+1 in table base(0); used by the room-header renderer as the password/flag bit.

## Notes / uncertainty
Reads byte+1; consumed by room-header renderer FUN_005ad350 as password/lock flag (inferred, not runtime-confirmed).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bafc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
