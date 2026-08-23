# 0x005c2340 clear_status_and_notify

| field | value |
|---|---|
| Original address | 0x005c2340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2340 |
| Resolved name | clear_status_and_notify |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ffb20
**Callees:** FUN_005bf230
**Referenced globals:** 0x6cbc84 UI status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc84

## Behavioral explanation
Clears UI status 0x6cbc84=0 and calls FUN_005bf230 (UI notify/refresh).

## Notes / uncertainty
Clears txn latch 0x6cbc84=0 then calls invoke_callback_status -> forces 0x00 success path. Callback ptr passed to bf230 is implicit/register-carried, recipient context-dependent.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
