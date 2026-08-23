# 0x005fba80 build_roomlist_widgets

| field | value |
|---|---|
| Original address | 0x005fba80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fba80 |
| Resolved name | build_roomlist_widgets |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8ec0, FUN_005fa490, FUN_005fb860
**Callees:** FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x6c4fcd list flag; 0x6c4602 list count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the room/roster list widget set: allocates rows (FUN_00618ba0), assigns ids 0x42/0x47/0x48/0x49/0x63 and per-frame callbacks FUN_005fbbf0 / FUN_005fc000.

## Notes / uncertainty
Builds room-list panel: header(0x42)+5 rows x4 cells(0x49/0x47/0x48/0x63), row render cb=FUN_005fbbf0, binds count 0x6c4602. elem ids are UI ids not opcodes. Widget struct field names inferred; per-alloc null-guards abort.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fba80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
