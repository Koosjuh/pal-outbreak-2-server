# 0x005bc2a0 inroom_evt09_open_dialog_0c

| field | value |
|---|---|
| Original address | 0x005bc2a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc2a0 |
| Resolved name | inroom_evt09_open_dialog_0c |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdf90, FUN_005c7e30
**Referenced globals:** 0x6fc5e8 (0x300 event/message buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1

## Behavioral explanation
Sub-event 9: when in-room, clears the 0x300 event buffer (0x6fc5e8), sets message code 0xc (FUN_005c7e30) and dispatches screen/event 7 (FUN_005bdf90).

## Notes / uncertainty
Dispatcher case 9, gated on unlock_gate 0x6ff2b1==1: clears 0x300 dialog buffer 0x6fc5e8, queues UI message class 0xc (FUN_005c7e30 maps 0xc->id 4), fires event-table handler 7 (FUN_005bdf90, table 0x6ca8a0). Dialog/event user-meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc2a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
