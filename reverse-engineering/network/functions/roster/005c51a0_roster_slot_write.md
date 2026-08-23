# 0x005c51a0 roster_slot_write

| field | value |
|---|---|
| Original address | 0x005c51a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c51a0 |
| Resolved name | roster_slot_write |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c54e0
**Callees:** —
**Referenced globals:** 0x6fee6c roster-tokens(0x24); 0x6fee7c..0x6fee8c roster-fields; 0x6cfb58 room-member-tbl(0x144); 0x6cfb74 member-state; 0x6cfb75 reliable-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Populates a member roster slot: copies connID token + fields (0x10/0x14/0x18/0x1c/0x20) into parallel tables 0x6fee6c and 0x6cfb58, sets state 3 or 4 and reliable/host bit.

## Notes / uncertainty
Writes the two parallel per-member tables (id-slot 0x6fee6c stride 0x24; display 0x6cfb58 stride 0x144) from a source record. State 4 when src+0x10==src+0x1c (self/host) else 3; reliable bit from (src+0x18>>1)&0x8000. Offsets exact; field meanings (id10/id1c ordinals, the >>1 packed flags) inferred, runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c51a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
