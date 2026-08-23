# 0x0017e700 dbcsock_close

| field | value |
|---|---|
| Original address | 0x0017e700 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017e700 |
| Resolved name | dbcsock_close |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0017f230
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
dbcman_close(fn0x302) then clears slot in_use(+0x08)/bound(+0x0c)/handle(+0x14). Handle source at call site not shown (decompiler omits arg).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017e700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
