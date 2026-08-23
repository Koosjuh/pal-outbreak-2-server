# 0x005d73c0 cur_room_slot_probe

| field | value |
|---|---|
| Original address | 0x005d73c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d73c0 |
| Resolved name | cur_room_slot_probe |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d0a40
**Callees:** FUN_005d6a50, FUN_005d7310
**Referenced globals:** 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Tests current room slot occupancy via FUN_005d6a50(id,1); if empty, retries with mode 2 and returns whether slot 1 was empty.

## Notes / uncertainty
Gets current room id (005d7310), tests 005d6a50(id,1); if 0 runs fallback 005d6a50(id,2) for effect; returns (mode1==0). mode1/mode2 slot-class semantics inferred, not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d73c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
