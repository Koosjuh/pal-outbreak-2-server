# 0x005c19d0 on_reply_room_list

| field | value |
|---|---|
| Original address | 0x005c19d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c19d0 |
| Resolved name | on_reply_room_list |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x6fee6c raw room records (0x24); 0x6cfb58/0x6cfb5c/0x6cfb60/0x6cfb74/0x6cfb75/0x6cfb76 room-list table; 0x6ca898 room count; 0x6ce5c2 ready count; 0x6cba2d SM signal
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca898; 0x6cba2d; 0x6ce5c2

## Behavioral explanation
Room-list reply parser: for each reply entry NOT flagged 0x40000000, fills raw records 0x6fee6c (0x24) and room-list table 0x6cfb58 (0x144) — id, occupancy (max at +0x20 vs cur at +0x14 => status 4 full else 3), passworded bit ((flags>>1)&0x8000), name; caps at 30 (0x6ca898); sets 0x6ce5c2=0x1e.

## Notes / uncertainty
op49 reply parser: walks 0x28-stride room_record entries, skips 0x40000000 (in-game/hidden) rooms, fills raw table 0x6fee6c + UI table 0x6cfb58 (id/cur/max/handle/passworded), occupancy marker 4=full/3=joinable, caps 30, signals SM done/fail. Field offsets not yet pcap-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c19d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
