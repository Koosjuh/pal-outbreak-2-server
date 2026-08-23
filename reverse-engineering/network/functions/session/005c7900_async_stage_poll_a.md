# 0x005c7900 async_stage_poll_a

| field | value |
|---|---|
| Original address | 0x005c7900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7900 |
| Resolved name | async_stage_poll_a |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0
**Callees:** —
**Referenced globals:** 0x700fd8 (stage flag); 0x86f838 (frame countdown); 0x86f800/0x86f7f8; 0x365e04 (timeout const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fd8

## Behavioral explanation
Polls a system async op (func_0x001c33xx) with a frame-countdown gate; returns pending/done/error for the room-list menu driver.

## Notes / uncertainty
Non-blocking stage-A driver on flag 0x700fd8: idle->start (func_0x001c3300, countdown=0x365e04), running->poll (func_0x001c3380: status3=done/1, status4=err/-1). Which net op + full status enum inferred, runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
