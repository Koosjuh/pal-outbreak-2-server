# 0x005add80 get_selected_room_u16_6c4b96

| field | value |
|---|---|
| Original address | 0x005add80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005add80 |
| Resolved name | get_selected_room_u16_6c4b96 |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4480
**Callees:** —
**Referenced globals:** 0x6c4b96(u16 field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Trivial accessor returning the 16-bit value at 0x6c4b96 (a current room/selection field).

## Notes / uncertainty
Trivial leaf getter returning u16 at 0x6c4b96 (selected-room tuple, paired with adcd0 in caller 0x5f4480). Fully reconstructed; field meaning (count/flags/attr) not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005add80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
