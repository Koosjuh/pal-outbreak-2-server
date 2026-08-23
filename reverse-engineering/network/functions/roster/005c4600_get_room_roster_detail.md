# 0x005c4600 get_room_roster_detail

| field | value |
|---|---|
| Original address | 0x005c4600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4600 |
| Resolved name | get_room_roster_detail |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** FUN_005bf1e0, FUN_005c3b10
**Referenced globals:** 0x6fee8c (room handle, stride 0x24); 0x86f840 (selected room handle); 0x6fb758/0x6fb76b (roster display block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Produces the room roster/detail buffer for the caller: loads the room handle (0x6fee8c) into 0x86f840, builds the roster display via FUN_005c3b10 into 0x6fb76b, then copies 0x195 words (0x6fb758) out to param_1.

## Notes / uncertainty
Latches selected room handle (0x6fee8c table, stride 0x24) into 0x86f840, builds roster block via FUN_005c3b10, copies 0x654 bytes to caller. Only FUN_005bf1e0(2) 1-based selector semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
