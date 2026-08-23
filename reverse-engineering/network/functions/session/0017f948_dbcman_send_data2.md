# 0x0017f948 dbcman_send_data2

| field | value |
|---|---|
| Original address | 0x0017f948 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f948 |
| Resolved name | dbcman_send_data2 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017fda8
**Callees:** FUN_00115c68, FUN_00115e60, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Async bulk send fn0x131b on dedicated channel 0x27afb0 (buffer 0x27b280/0x1090, max payload 0x1080); busy-check via sif_rpc_bind_ready -> 'SendData2 BUSY' string; sema-guarded fill. Header-word roles unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f948.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
