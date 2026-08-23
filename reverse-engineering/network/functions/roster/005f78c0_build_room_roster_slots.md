# 0x005f78c0 build_room_roster_slots

| field | value |
|---|---|
| Original address | 0x005f78c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f78c0 |
| Resolved name | build_room_roster_slots |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7800
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bae80, FUN_005bf410, FUN_005bfbe0, FUN_005f8340, FUN_005fe1e0, FUN_00618b60
**Referenced globals:** 0x70b410 (slot->player table); 0x6c3030 (member table, stride 0x15c); 0x6c303e (member-present flag); 0x6c45f8 (local member id); param+0x4c4 (cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xf (step); param+0x16 (timer); 0x70b410

## Behavioral explanation
On room-detail entry, builds the 6-slot player assignment table 0x70b410 from the room member records (present-flags cRam006c303e in the 0x6c3030 table, stride 0x15c) and the member bitmask FUN_005bae80; then registers the display list via FUN_005f8340 and arms input FUN_005bfbe0(0,7,...).

## Notes / uncertainty
3-step SM building the 6-slot 0x70b410 map from member table 0x6c3030 present flags + FUN_005bae80 room bitmask; arms on_memberlist_reply (005f7b30). Empty member table -> all slots 0xff = 1/0p symptom. FUN_005bae80 bit->member mapping unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f78c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
