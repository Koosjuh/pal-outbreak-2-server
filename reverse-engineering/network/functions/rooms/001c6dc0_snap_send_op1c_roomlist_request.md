# 0x001c6dc0 snap_send_op1c_roomlist_request

| field | value |
|---|---|
| Original address | 0x001c6dc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6dc0 |
| Resolved name | snap_send_op1c_roomlist_request |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** 0x365e00 cursor; 0x365e10 counter; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x1c
**State vars:** 0x365e00 cursor; conn+0xd next-state=0x05

## Behavioral explanation
Emits opcode 0x1c room-list request: resets counters (0x365e10; 0x365e00 when fsm-state 1) and appends resume-cursor 0x365e00; advances to state 0x05.

## Notes / uncertainty
Room-list loop entry (op0x1c): resets batch ctr 0x365e10, resets resume cursor 0x365e00 when op_mode==1, appends cursor, next-state 0x05. Cursor is a server continuation token.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
