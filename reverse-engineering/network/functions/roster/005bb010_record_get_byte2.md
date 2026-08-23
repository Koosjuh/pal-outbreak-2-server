# 0x005bb010 record_get_byte2

| field | value |
|---|---|
| Original address | 0x005bb010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb010 |
| Resolved name | record_get_byte2 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad350, FUN_0062c9f0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns byte at record+2 in table base(0), stride 0x1e4.

## Notes / uncertainty
Reads byte+2; adjacent status flag to byte1, same room-header renderer callers. Semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
