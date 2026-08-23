# 0x005c8d10 state_handler_store_reply_advance

| field | value |
|---|---|
| Original address | 0x005c8d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8d10 |
| Resolved name | state_handler_store_reply_advance |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5e90, FUN_005d8340
**Referenced globals:** 0x701068+0x68dd0 (stored reply value); 0x701070+2 (sub-state); 0x700fe8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2

## Behavioral explanation
State handler: on dequeued reply, if subtype +5==9 aborts via FUN_005d5e90(-1); otherwise stores payload word to 0x68dd0 and advances sub-state.

## Notes / uncertainty
Transport SM capture state: err or subtype9 -> abort FUN_005d5e90(-1); else store msg word0 -> session+0x68dd0 (handle/id) + sub-state++. subtype-9 = FAILURE here (opposite of 8ae0). Captured-word type uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
