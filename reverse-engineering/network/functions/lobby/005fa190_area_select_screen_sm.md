# 0x005fa190 area_select_screen_sm

| field | value |
|---|---|
| Original address | 0x005fa190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa190 |
| Resolved name | area_select_screen_sm |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005c0960, FUN_005c0a00, FUN_005c0d30, FUN_005c0f20, FUN_005fe300
**Referenced globals:** 0x6970a0 list model; 0x6c0778/0x6c076f/0x6c0774 room-slot record (stride 0x15c); 0x006970f4 count; +0x42b overlay id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state; bRam006970f4 count

## Behavioral explanation
Area/scenario-select screen state machine: builds the area list (FUN_005fe300), memsets 0x6970a0 model, loads per-area records and sends the area query.

## Notes / uncertainty
6-substate area/scenario-select SM: loads current area record (0x15c stride), requests list (0x5fc520), unpacks nested entries into model 0x6970a0 (0x14a8/0x41 strides), confirms (0x5fc5c0), seeds 4 roster slots (0x3b0). Reply-buffer source column offsets approximate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
