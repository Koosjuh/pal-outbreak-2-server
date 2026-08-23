# 0x005bb980 lobby_area_population_decrement

| field | value |
|---|---|
| Original address | 0x005bb980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb980 |
| Resolved name | lobby_area_population_decrement |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005c7d00
**Referenced globals:** 0x6ce5de (per-area lobby population, stride 0x144); 0x6d2158/0x6d215a (area idx + count for UI); 0x6cbc7e/0x6cbc84 (UI status fields)
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** —

## Behavioral explanation
Decrements the per-area lobby population counter (0x6ce5de) for the current area (floored at 0) and pushes a UI refresh (FUN_005bdfe0(0xf)).

## Notes / uncertainty
op0x07 (LEAVE) local handler; floored decrement of area_table[cur].population (0x144 stride, +0x6ce5de), refreshes UI popup + sets room_mode 0x10. LEAVE association inferred from mirror-pair FUN_005bb8e0 and the FUN_005bc860 dispatch table (not re-read).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
