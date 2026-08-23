# 0x0062e440 room_join_sequence

| field | value |
|---|---|
| Original address | 0x0062e440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e440 |
| Resolved name | room_join_sequence |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062e3c0
**Callees:** FUN_005af120, FUN_005b68e0, FUN_005b6900, FUN_005bffa0, FUN_005c0a00, FUN_005c44a0
**Referenced globals:** 0x6c4600 selected-room; 0x34356c config
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 join-step; struct+0x42b screen(=0x17); struct+0x97e retry-flag; struct+0x98c timeout

## Behavioral explanation
Room-join sequence (struct+0x10 switch): sends join steps for selected room 0x6c4600 via FUN_005c0a00(...,0x62f1e0) and FUN_005bffa0(...,0x62f2b0), sets screen +0x42b=0x17, arms retry timer +0x98c, restarts frame via FUN_005af120.

## Notes / uncertainty
Already fully reconstructed. Join-selected-room 3-stage send SM against 0x6c4600; case0 falls through to case1 wait (faithful). Open: which opcode each of FUN_005c0a00/005bffa0/005c44a0 emits; retry-flag +0x97e semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
