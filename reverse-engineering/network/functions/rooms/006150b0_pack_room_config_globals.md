# 0x006150b0 pack_room_config_globals

| field | value |
|---|---|
| Original address | 0x006150b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006150b0 |
| Resolved name | pack_room_config_globals |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610580, FUN_00610830
**Callees:** —
**Referenced globals:** 0x35ba80-0x35bfe0 (room cfg block); 0x701be0/0x701d00 (name flags); 0x654168/0x654178 (fmt)
**Referenced strings:** fmt @0x654168; fmt @0x654178
**Referenced opcodes:** —
**State vars:** room offs 0x1310 mode,0x1320/0x1325 flags,0x200/0x300-0x700,0x600/0x700

## Behavioral explanation
Packs the selected room struct (title/password/scenario/host fields, flags 0x1320/0x1325, mode 0x1310) into the 0x35ba80-0x35bfe0 global config block used to launch/host the room.

## Notes / uncertainty
Marshals selected room into connect/host config block 0x35ba80-0x35bfe0 (addr-mode enum bec8 0/1/2, octets, name pair, mode map baa8, defaults) + builds display strings 0x701d00/bf0 w/ present-flags 0x701be0. Note baa8 mode map differs from 0x006140d0 at case 3 (0 vs 2).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006150b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
