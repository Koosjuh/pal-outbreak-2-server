# 0x0017eb98 dbcsock_bind

| field | value |
|---|---|
| Original address | 0x0017eb98 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017eb98 |
| Resolved name | dbcsock_bind |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017e900
**Callees:** FUN_0017f2b8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
dbcman_bind(fn0x303) then store bind handle(+0x14) + set bound flag(+0x0c). Error semantics delegated to 0x0017f2b8 (0xfffffff4 when endpoint flag!=1).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017eb98.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
