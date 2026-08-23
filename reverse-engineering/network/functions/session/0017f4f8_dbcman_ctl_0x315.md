# 0x0017f4f8 dbcman_ctl_0x315

| field | value |
|---|---|
| Original address | 0x0017f4f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f4f8 |
| Resolved name | dbcman_ctl_0x315 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x315, one arg word in / reply word out; structurally like close/config but NOT init-gated. No caller in batch; exact op (status/abort/option) unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f4f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
