# 0x005c1770 pump_room_list_query

| field | value |
|---|---|
| Original address | 0x005c1770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1770 |
| Resolved name | pump_room_list_query |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c3e50
**Referenced globals:** 0x6cfb58/0x6cfb60/0x6cfb76 room-list table (30*0x144); 0x6fee6c raw room records; 0x6ff2b0 host flag (=0); 0x6ca898 parse count; 0x6cba2c/0x6cba28 SM guard/step
**Referenced strings:** LOID; STAT
**Referenced opcodes:** —
**State vars:** 0x6cba2c guard; 0x6cba28 step; 0x6ff2b0

## Behavioral explanation
Async pump (guard 0x6cba2c): initializes the 30-entry room-list table 0x6cfb58 (0x144), clears raw records 0x6fee6c and host flag 0x6ff2b0=0, then sends a 'LOID'+'STAT' query for 0x1e=30 rooms and registers reply handler FUN_005c19d0.

## Notes / uncertainty
Room-list enumeration SM: step0 resets state (incl. clearing stale host flag 0x6ff2b0=0), presets 30 UI rows, sends reliable op49 with LOID+STAT descriptors for 30 rooms, arms reply 0x5c19d0. 0x3c-byte request descriptor layout only partially mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
