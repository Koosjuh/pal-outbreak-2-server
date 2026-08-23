# 0x00606520 lobby_conn_connect_retry

| field | value |
|---|---|
| Original address | 0x00606520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606520 |
| Resolved name | lobby_conn_connect_retry |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** FUN_005c4690, FUN_00605d30
**Referenced globals:** sRam0070cdca/cdcc (retry/timer); sRam0070cdc8 (state); uRam0035a6f4 (socket); uRam0035b723 (error code)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam0070cdc8; uRam0035a6f4

## Behavioral explanation
State-1 connect step: fetches host/port (FUN_005c4690), opens socket (FUN_00605d30), advances on success, retries up to 4 times (300-tick backoff), else fails to error state 99 (code 5).

## Notes / uncertainty
Pipeline state-1: on backoff-timer(0x70cdca) expiry, up to 4 attempts open socket FUN_00605d30->fd@0x35a6f4; success state++ (->2), fail 300-tick retry, exhausted -> state=99 err code 5. 3rd arg of FUN_00605d30 meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
