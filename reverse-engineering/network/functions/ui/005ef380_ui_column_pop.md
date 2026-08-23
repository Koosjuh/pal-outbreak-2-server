# 0x005ef380 ui_column_pop

| field | value |
|---|---|
| Original address | 0x005ef380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef380 |
| Resolved name | ui_column_pop |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8960, FUN_005e9d20
**Callees:** FUN_005ec100
**Referenced globals:** +0x124 column count; +0x17c active-row id; +0xd894 current node
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x124 column count

## Behavioral explanation
Decrements the layout column counter at ctx+0x124 (floored at 0) and refreshes the active row via FUN_005ec100.

## Notes / uncertainty
Inverse of ui_column_push: floored decrement of col count +0x124 with same depth-gated row-id, refresh_active_row.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
