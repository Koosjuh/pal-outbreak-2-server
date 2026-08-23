# 0x00606000 lobby_resolve_and_connect

| field | value |
|---|---|
| Original address | 0x00606000 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606000 |
| Resolved name | lobby_resolve_and_connect |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00605fa0
**Callees:** FUN_00605d30
**Referenced globals:** sRam0070cdd0 (stage); sRam0070cdd2/cdd4 (timers); uRam0035a6f4 (socket handle); sRam0035a714 (poll status); 0x70bfb0 (host str); uRam0070bfa0 (port); 0x8716e3/0x87130f/0x874410 (host table)
**Referenced strings:** host:port buffer @0x70bfb0
**Referenced opcodes:** —
**State vars:** sRam0070cdd0; uRam0035a6f4

## Behavioral explanation
Three-stage state machine (sRam0070cdd0=0/1/2) that parses a 'host:port' string (':' 0x3a delimiter, decimal port), resolves the host against table 0x8716e3/0x87130f, kicks off DNS + socket connect (FUN_00605d30), and polls connect completion with retry/timeout (0x3c ticks x up to 0x15).

## Notes / uncertainty
3-stage non-blocking TCP bring-up: parse host:port from built-in server table, DNS resolve, socket connect w/ 60-tick x21 retry; returns 0/-1/-2. DNS+connect-poll externs inferred from -1/0/1 and status==4 conventions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606000.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
