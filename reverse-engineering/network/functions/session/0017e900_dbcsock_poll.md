# 0x0017e900 dbcsock_poll

| field | value |
|---|---|
| Original address | 0x0017e900 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017e900 |
| Resolved name | dbcsock_poll |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0017eb20, FUN_0017eb98, FUN_0017ec58, FUN_0017ecc0, FUN_0017fc10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Poll endpoint: lazy-bind if unbound, then either dbcman_ctl_recv(fn0x31a) for fresh status or read cached status record (FUN_0017ec58); failure tail clears bound flag + FUN_0017eb20 reset. Helper fns ecc0/ec58/eb20 and 0x101800c selector + (ptr|4) length trick unresolved. Returns status byte.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017e900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
