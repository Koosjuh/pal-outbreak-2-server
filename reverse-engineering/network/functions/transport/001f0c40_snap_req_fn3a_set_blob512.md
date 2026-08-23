# 0x001f0c40 snap_req_fn3a_set_blob512

| field | value |
|---|---|
| Original address | 0x001f0c40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0c40 |
| Resolved name | snap_req_fn3a_set_blob512 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee7c0
**Callees:** FUN_0010a4f0, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
SN@P IOP-lib RPC stub fno 0x3a: uploads a 512-byte blob (tx+0x1c, NUL@tx+0x21b), send 0x220. Mechanism High via confirmed snap_ipc_call_rpc; which SN@P attribute the blob sets is inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0c40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
