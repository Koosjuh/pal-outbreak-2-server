# 0x005be120 free_task_slot

| field | value |
|---|---|
| Original address | 0x005be120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be120 |
| Resolved name | free_task_slot |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bdfe0
**Callees:** —
**Referenced globals:** 0x6ca980 slot state; 0x6ca97c/0x6ca97e slot ids; 0x6ca96c destroy-cb; 0x6cbc80/0x6cbc7c match keys
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc80/0x6cbc7c current-object ids

## Behavioral explanation
Frees a task slot: mode 1 matches by short IDs (0x6cbc80/0x6cbc7c) then clears state and fires the destroy callback; mode 2 frees by explicit index, also firing the callback.

## Notes / uncertainty
Frees a task slot: mode1 matches slot +0x16/+0x14 against 0x6cbc80/0x6cbc7c (set by reply cb) then fires destroy_cb; mode2 frees by index. Closes launch/reply/free loop with app_reply_cb_state2. mode2 callers not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
