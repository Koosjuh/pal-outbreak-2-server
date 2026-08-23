# 0x00628860 render_room_member_panel

| field | value |
|---|---|
| Original address | 0x00628860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628860 |
| Resolved name | render_room_member_panel |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005ba4c0, FUN_005ba520, FUN_0062fdc0, FUN_0062fea0, FUN_0062ff00
**Referenced globals:** 0x694710 member-name; 0x694720 member-score; 0x715511 member-status; 0x66a9c0 fmt-strings
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Render callback drawing the in-room member panel: for up to the room's player count it draws each member's name (0x694710), slot number, score (0x694720, capped 9999) and ready/status icon (0x715511).

## Notes / uncertainty
In-room roster draw cb: header count from ctx+8, up to 7 rows name/slot/score/status from client tables 0x694710/0x694720/0x715511. Directly the create-room roster/count surface. hdl+0x44/+0x50 header args unpinned; not confirmed this vs FUN_00629d60 is shown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
