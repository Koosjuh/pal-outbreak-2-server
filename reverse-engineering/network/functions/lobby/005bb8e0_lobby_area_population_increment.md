# 0x005bb8e0 lobby_area_population_increment

| field | value |
|---|---|
| Original address | 0x005bb8e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb8e0 |
| Resolved name | lobby_area_population_increment |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005c7d00
**Referenced globals:** 0x6ce5de (per-area lobby population, stride 0x144); 0x6d2158/0x6d215a (current area idx + count for UI); 0x6cbc7e/0x6cbc84 (UI status fields)
**Referenced strings:** —
**Referenced opcodes:** 0x03
**State vars:** —

## Behavioral explanation
Increments the per-area lobby population counter (0x6ce5de, stride 0x144, saturating at -1==unset) for the current area and pushes a UI refresh (FUN_005bdfe0(0xf)).

## Notes / uncertainty
Command-id-3 push handler (installed by 005bc860): increment per-area population u16 at 0x6ce5de[idx] (stride 0x144, 0xffff sentinel = unset), mirror to UI 0x6d2158/0x6d215a, push redraw event 0xf. Ties to rig-validated area-data feature. Full area_record layout beyond +0 unknown; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb8e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
