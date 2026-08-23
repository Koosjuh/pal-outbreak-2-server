# 0x00604860 table_find_by_id

| field | value |
|---|---|
| Original address | 0x00604860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604860 |
| Resolved name | table_find_by_id |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5520, FUN_00603f30, FUN_006049b0, FUN_00604a80, FUN_00619430, FUN_006278e0, FUN_006293f0, FUN_006296a0, FUN_0062d430
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Linear search of a 0x38-stride table for an entry whose 0x10-byte key at +0x10 matches the argument; returns index or -1.

## Notes / uncertainty
Shared linear id lookup (0x38 stride, 16-byte id at +0x10, occupied gate) -> index or -1. 9 callers; structurally clean.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
