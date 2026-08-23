# 0x005ef220 ui_column_push

| field | value |
|---|---|
| Original address | 0x005ef220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef220 |
| Resolved name | ui_column_push |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e88c0, FUN_005e9c30, FUN_005e9d00, FUN_005ea420, FUN_005ea4a0
**Callees:** FUN_005ec100, FUN_005ec4f0, FUN_005ec800
**Referenced globals:** +0x124 column count (<=0xe); +0x128 col-value array; +0x168 col-attr array; +0x17c active-row id; +0x2c3/+0x2d3 converter sources; +0xd892/+0xd894 node stack
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x124 column count; +0xd892

## Behavioral explanation
Appends a layout column/tab entry: clamps count at ctx+0x124 to 14, fills stride arrays (+0x128/+0x168) optionally via converters, increments column count, refreshes active row.

## Notes / uncertainty
Append layout column/tab-stop: value (+0x128) from attr str +0x2c3 or inherit, attr byte (+0x169) from +0x2d3 or inherit; count +0x124 clamp 14. One-slot src/dest offset (+0x128->+0x12c) preserved; inherit-vs-two-array ambiguity noted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
