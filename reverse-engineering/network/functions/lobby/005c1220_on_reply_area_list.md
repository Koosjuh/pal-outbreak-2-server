# 0x005c1220 on_reply_area_list

| field | value |
|---|---|
| Original address | 0x005c1220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1220 |
| Resolved name | on_reply_area_list |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c2ab0, FUN_005c7d00
**Referenced globals:** 0x6fec08 area records (0x24 stride); 0x6ce5dc area table (0x144); 0x6ce5be ready count; 0x6cb9dd SM signal
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cb9dd; 0x6ce5be

## Behavioral explanation
Reply handler for the area/channel 'NAME' query: parses each reply entry, matches its 2-digit id, and fills area records 0x6fec08 and the 10-entry table 0x6ce5dc (name, 5 u32 fields, status via 2ab0); sets ready count 0x6ce5be=10.

## Notes / uncertainty
Reply cb for NAME query; tag '\0'=data / '\''=terminator. Parses 2-digit area id, bounds 1..10, fills 0x6fec08 (0x24) + population 0x6ce5de; confirms +0x20=LOID (0x6fec28) feeding STAT query. id-digit column is a decompiler-quirk index (semantics firm).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
