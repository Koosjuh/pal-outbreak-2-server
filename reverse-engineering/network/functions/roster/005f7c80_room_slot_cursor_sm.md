# 0x005f7c80 room_slot_cursor_sm

| field | value |
|---|---|
| Original address | 0x005f7c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7c80 |
| Resolved name | room_slot_cursor_sm |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7800
**Callees:** FUN_005b14b0, FUN_005f4b80, FUN_005f4be0, FUN_005f7690
**Referenced globals:** 0x6c45fe (member count); 0x70b410 (slot table); param+0x907 (cursor slot); param+0x992 (busy)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x907 (selected slot)

## Behavioral explanation
Handles D-pad navigation of the player-slot cursor +0x907 over the room roster (member count uRam006c45fe capped 6), reading direction edges via FUN_005b14b0 masks; cancel routes to FUN_005f7690.

## Notes / uncertainty
Room slot-grid cursor SM: gate on FUN_005f4be0, confirm(0x10) validates vs occupancy 0x70b410 (accept sfx5 / reject sfx1+state2), cancel(0x200)->FUN_005f7690. Confirm/cancel structure solid; nested movement deltas + count+1..count+3 band faithful but should be trace-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
