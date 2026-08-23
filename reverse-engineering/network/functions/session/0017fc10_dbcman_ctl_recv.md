# 0x0017fc10 dbcman_ctl_recv

| field | value |
|---|---|
| Original address | 0x0017fc10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017fc10 |
| Resolved name | dbcman_ctl_recv |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017e900, FUN_0017fd28
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x31a: 2 arg words + in/out length, IOP returns status at +0x20c and copies payload (0x27b00c) back to caller buffer. Used by dbcsock_poll. Arg-word roles (handle vs selector) unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017fc10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
