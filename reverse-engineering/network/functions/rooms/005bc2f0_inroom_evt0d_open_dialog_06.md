# 0x005bc2f0 inroom_evt0d_open_dialog_06

| field | value |
|---|---|
| Original address | 0x005bc2f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc2f0 |
| Resolved name | inroom_evt0d_open_dialog_06 |
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
Sub-event 0xd: when in-room, clears the 0x300 event buffer, sets message code 6 and dispatches screen/event 0xb; sibling of FUN_005bc2a0.

## Notes / uncertainty
Dispatcher case 0x0d, gated on 0x6ff2b1!=0: clears 0x6fc5e8, queues UI message class 6 (->id 9), fires event 0x0b. Same file's thunk_FUN_005c61b0 = dispatcher case 0x0e, sends reliable op-0x0f (4-byte body) on 0x6febac. Dialog class + op0f role unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc2f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
