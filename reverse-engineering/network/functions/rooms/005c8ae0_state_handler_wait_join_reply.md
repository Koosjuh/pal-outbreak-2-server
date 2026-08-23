# 0x005c8ae0 state_handler_wait_join_reply

| field | value |
|---|---|
| Original address | 0x005c8ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8ae0 |
| Resolved name | state_handler_wait_join_reply |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d8340
**Referenced globals:** 0x701068+0x60dcc (join/ack counter); 0x701070+1/+2 (state); 0x700fe0 (result); 0x700fe8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1

## Behavioral explanation
State handler: dequeues a session message (FUN_005d8340), and on type +5==9 bumps the join/ack counter (0x60dcc); at 2 advances to state 2, else resets to idle.

## Notes / uncertainty
Transport room-op SM state: polls reply queue (+0x4f97c); ok+subtype9 = paired ack, counter 0x60dcc==2 -> major-state 2, else reset/wait; other/err -> major-state 2. subtype-9 = GOOD here (polarity flips in 8d10). Which transport op (0x2b/0x2d) open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
