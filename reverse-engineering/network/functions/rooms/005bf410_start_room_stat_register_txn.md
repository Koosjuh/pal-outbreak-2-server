# 0x005bf410 start_room_stat_register_txn

| field | value |
|---|---|
| Original address | 0x005bf410 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf410 |
| Resolved name | start_room_stat_register_txn |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f78c0
**Callees:** —
**Referenced globals:** 0x6cbc34 busy flag; 0x6cbc24 room index; 0x6cbc10 tick cb ptr(=FUN_005bf470); 0x6cbc14 user cb; 0x6cbc30 SM state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc34 busy

## Behavioral explanation
Guarded launcher for the room STAT/USER registration: latches room index (param&0xffff)@0x6cbc24, arms state machine FUN_005bf470, stores user cb.

## Notes / uncertainty
Guarded launcher for room STAT/USER register: busy latch 0x6cbc34, room idx 0x6cbc24, arms tick SM FUN_005bf470 at 0x6cbc10, done-cb 0x6cbc14; returns 0/-1. Whether create path actually reaches it is the open blocker.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
