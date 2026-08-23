# 0x0017f0e8 dbcman_config

| field | value |
|---|---|
| Original address | 0x0017f0e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f0e8 |
| Resolved name | dbcman_config |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017ee60
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x304 (main channel 0x27af88): sends config token (flag-table 0x27e480 at init), returns IOP reply word. Reply-word meaning unconfirmed; name from init call site + fn ordering.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f0e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
