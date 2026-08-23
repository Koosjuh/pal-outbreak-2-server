# 0x001f1fe0 iopdev_rpc_init

| field | value |
|---|---|
| Original address | 0x001f1fe0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f1fe0 |
| Resolved name | iopdev_rpc_init |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d4250
**Callees:** FUN_001133e8, FUN_00114ac8, FUN_00115300, FUN_00115a98, FUN_001f22a0, FUN_001f27c8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Init of a SEPARATE SIF-RPC client (client 0x37e9e0, server 0x80000211): sceSifInitRpc/BindRpc, enumerate (fno1), alloc+init <128 x 0x38B device blocks @0x37eb10, install VBLANK_END INTC handler 0x1f2f40. Structure firm; device identity is a Hypothesis (no string ties it to sockets/PHY/etc).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f1fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
