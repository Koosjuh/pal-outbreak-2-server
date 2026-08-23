# 0x005adcd0 get_selected_room_field

| field | value |
|---|---|
| Original address | 0x005adcd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005adcd0 |
| Resolved name | get_selected_room_field |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4480
**Callees:** FUN_005fa820
**Referenced globals:** 0x6c4b98/0x6c4b99/0x6c4b9c(cur room id fields)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b99

## Behavioral explanation
Accessor: given selector 0/1/2 returns room id/index fields from cRam006c4b98/sRam006c4b9c/cRam006c4b99 (mapping raw id via FUN_005fa820, 999->0).

## Notes / uncertainty
Renamed get_room_field->get_selected_room_field. Selector 0/1/2 accessor over selected-room tuple 0x6c4b98/99(mode)/9c; sel0 maps via FUN_005fa820 with 999->0. Uncertainty: exact field semantics (index->room-number map is hypothesis).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005adcd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
