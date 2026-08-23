# 0x005c9690 room_enter_state_handler

| field | value |
|---|---|
| Original address | 0x005c9690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9690 |
| Resolved name | room_enter_state_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cc980, FUN_005d5b10, FUN_005d5b60, FUN_005d5ba0, FUN_005d5c20, FUN_005d5cc0, FUN_005d6460, FUN_005d7410
**Referenced globals:** 0x701070+0x2e screen sub-state; 0x701070+2 step ctr; 0x701070+0x18 pad bits; 0x701068+0x4f8a4 button bits; 0x701068+0x60dcb busy flag; 0x701068+0x68e85 lobby phase
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** 0x701070+0x2e; 0x701070+2; 0x701068+0x68e85; 0x701068+0x60dcb; 0x701070+0x34

## Behavioral explanation
Per-frame handler for a room/lobby screen state: processes the queued net result via FUN_005cc980 and, on the right pad+flag combo, sends op06 (member enter/join) or advances/ tears down the screen.

## Notes / uncertainty
Per-frame op06 enter handshake; dispatches FUN_005cc980 status -2..+2 (send op06 on confirm, commit on -1, error dialog on -2). Status-code meanings and 0x642bc8 reserved string inferred from branch consequences, not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
