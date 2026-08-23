# 0x00604e70 draw_room_header_and_count

| field | value |
|---|---|
| Original address | 0x00604e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604e70 |
| Resolved name | draw_room_header_and_count |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00604810, FUN_0062fdf0, FUN_0062fea0
**Referenced globals:** 0x694700 (member pool); cRam006c5495/cRam006c5497; sRam006c54a4; &DAT_0064a010/0x64a020/0x64a030/0x64a040 (format strings)
**Referenced strings:** fmt @0x64a020; fmt @0x64a030; fmt @0x64a040
**Referenced opcodes:** —
**State vars:** cRam006c5495; cRam006c5497

## Behavioral explanation
Draw callback for a room panel: formats room/user labels from menu-string records (0x62fdf0/0x62fea0) and renders the occupied player count via FUN_00604810 over pool 0x694700.

## Notes / uncertainty
Header row draws occupancy via count_occupied_slots(0x694700,0x32) - the N/xP count the create-room goal tracks. Text vs scroll-box variant on +2. cRam006c5495 (count) vs sRam006c54a4 (secondary) split inferred from template arg order; format text not fetched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
