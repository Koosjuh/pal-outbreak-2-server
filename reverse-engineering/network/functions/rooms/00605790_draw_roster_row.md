# 0x00605790 draw_roster_row

| field | value |
|---|---|
| Original address | 0x00605790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605790 |
| Resolved name | draw_roster_row |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005fe4b0, FUN_0062fdf0
**Referenced globals:** 0x6c7c2c (room-list table base, stride 0x3b0); 0x6c7d18/0x6c7d1a/0x6c7d1c (scenario fields); PTR_DAT_0068ae30 (scenario name ptrs); cRam006c5497; 0x64a078/0x64a080 (fmt)
**Referenced strings:** fmt @0x64a078; fmt @0x64a080
**Referenced opcodes:** —
**State vars:** cRam006c5497

## Behavioral explanation
Draw callback for one room-list row: if slot empty draws a placeholder, else renders room name (0x6c7c3c), player count and scenario/status text (pointer table PTR_DAT_0068ae30 / FUN_005fe4b0), highlighting the selected row.

## Notes / uncertainty
RENAMED from draw_room_list_entry: 0x6c7c2c is the Confirmed in-room roster_table (stride 0x3b0 x4), so this draws a player roster row (name + chosen character), not a room-browser line. Empty-slot placeholder = unpopulated roster symptom. char vs scenario id at +0xec inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
