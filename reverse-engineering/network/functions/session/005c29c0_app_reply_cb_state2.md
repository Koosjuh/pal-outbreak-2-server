# 0x005c29c0 app_reply_cb_state2

| field | value |
|---|---|
| Original address | 0x005c29c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c29c0 |
| Resolved name | app_reply_cb_state2 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005c08b0, FUN_005c7d00
**Referenced globals:** 0x6cbc84 (error/status flag); 0x6cbc80 (payload word); 0x6cbc7e (state=2); 0x6cbc7c (key)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cbc84; uRam006cbc7e

## Behavioral explanation
App-reply callback: on status byte 0x00 clears / 0x27('\'') sets the 0x6cbc84 error flag, latches a payload word, sets state=2, and kicks the UI via bdfe0(0).

## Notes / uncertainty
STAT-channel reply cb. status 0x00 OK->0x6cbc84=0, 0x27 NG->0xff; publishes echoed handle reply[+0xc]->0x6cbc80, key->0x6cbc7c, state=2, then FUN_005bdfe0->free_task_slot(match). Upgraded Medium->High (closes launch/reply/free loop). reply[+0xc] layout assumed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c29c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
