# 0x00606610 lobby_conn_await_connect

| field | value |
|---|---|
| Original address | 0x00606610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606610 |
| Resolved name | lobby_conn_await_connect |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** —
**Referenced globals:** uRam0035a6f4 (socket); sRam0035a714 (poll status); sRam0070cdca/cdc8 (timer/state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam0070cdc8

## Behavioral explanation
State-2 step: polls socket connect completion (func_0x001ee430, status==4 => connected) and advances; on poll error or timeout closes the socket and backs the state down.

## Notes / uncertainty
Pipeline state-2: poll connect (func_0x001ee430, status@0x35a714==4=connected -> state++ ->3, attempt=0); poll-error or timeout -> state--, close+recreate socket. Status codes beyond 4 not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
