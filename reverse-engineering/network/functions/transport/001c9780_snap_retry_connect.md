# 0x001c9780 snap_retry_connect

| field | value |
|---|---|
| Original address | 0x001c9780 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c9780 |
| Resolved name | snap_retry_connect |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9850, FUN_001c9b00
**Callees:** FUN_001ee650, FUN_001ee680
**Referenced globals:** 0x35ccb2=retry counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xc=topstate; param_1+0xd=substate

## Behavioral explanation
Retry helper: increments a retry counter (max 3), tears down the socket and resets the conn state to 0 for another attempt; returns 0 when retries exhausted.

## Notes / uncertainty
Connect-retry: bumps global 0x35ccb2, caps attempts at 3, tears down socket + resets conn state bytes/timers to 0, returns 1(retry)/0(give up). Counter-reset-on-success not visible here; conn+0x10..0x16 typed as generic u16 timers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c9780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
