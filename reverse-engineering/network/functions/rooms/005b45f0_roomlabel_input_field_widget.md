# 0x005b45f0 roomlabel_input_field_widget

| field | value |
|---|---|
| Original address | 0x005b45f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b45f0 |
| Resolved name | roomlabel_input_field_widget |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3ed0, FUN_005b41b0
**Callees:** FUN_005b4c80, FUN_005ba570, FUN_005ba7b0, FUN_005f5c10, FUN_00618b60, FUN_006345e0, FUN_00634ab0, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6c4610 uRam006c4610 / 0x6c4618 / 0x6c4620 key-repeat masks; 0x6c4674 room-meta table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+3 sub-state; widget+7 room idx; widget+0x18 timer

## Behavioral explanation
Sub-widget update for a room name/label input field: fades a panel in (0x5b4c80), runs the text field (0x634ab0 read against key masks), and commits it (0x5f5c10).

## Notes / uncertainty
4-phase text-input field widget for a room name/label; edits room-meta record at 0x6c4674+idx*0x14, commits 0x14(20)-byte field via FUN_005f5c10 (matches room_record.name char[20]). Caret x=76.0 (0x42980000). Shared by enter (5b3ed0) and create (5b41b0). Editor codes -1 cancel / 1 confirm.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b45f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
