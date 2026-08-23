# 0x0017faa8 dbcman_send_data3

| field | value |
|---|---|
| Original address | 0x0017faa8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017faa8 |
| Resolved name | dbcman_send_data3 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00115c68, FUN_00115e60, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Async bulk send fn0x131c on channel 0x27afd8 (buffer 0x27c380/0x2090, max payload 0x2080), forwards a completion callback (param_5). Larger twin of SendData2. Header-word roles unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017faa8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
