# 0x00606de0 append_roomlist_entry

| field | value |
|---|---|
| Original address | 0x00606de0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606de0 |
| Resolved name | append_roomlist_entry |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6970
**Callees:** —
**Referenced globals:** 0x00874430 list-table; 0x00874410 staging-record; 0x0070cd70 count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0070cd70

## Behavioral explanation
Appends a 0x14-byte record from staging 0x874410 into the 0x874430[10] table and bumps count 0070cd70 (capped at 10).

## Notes / uncertainty
Bounds-guarded (count<10) memcpy of staged 0x14-byte record into display table + count++. Exact; internal record fields undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
