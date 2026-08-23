# 0x00606da0 clear_roomlist_table

| field | value |
|---|---|
| Original address | 0x00606da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606da0 |
| Resolved name | clear_roomlist_table |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3510, FUN_005f6970
**Callees:** —
**Referenced globals:** 0x00874430 list-table[10]; 0x0070cd70 count; 0x00874f36 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0070cd70

## Behavioral explanation
memset the 10-entry x0x14 list table at 0x874430 (200 bytes) and zeroes its count 0070cd70 and 874f36.

## Notes / uncertainty
memset of 10x0x14 room-list DISPLAY table @0x874430 + zero count/flag. Exact. Per-entry field layout not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
