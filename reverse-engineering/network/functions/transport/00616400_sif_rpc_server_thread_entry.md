# 0x00616400 sif_rpc_server_thread_entry

| field | value |
|---|---|
| Original address | 0x00616400 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616400 |
| Resolved name | sif_rpc_server_thread_entry |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x70f318 (rpc server data); 0x70f2d0 (rpc server handle); 0x70e2c0 (rpc recv buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
RPC service thread entry: sets up the RPC server queue and registers FUN_00616318 as the dispatch handler for the service.

## Notes / uncertainty
EE RPC-server thread entry: sceSifInitRpc + SetRpcQueue + RegisterRpc(sid=0x80001101, func=616318 dispatch, buf=0x70e2c0). Concluding sceSifRpcLoop inferred (decomp tail truncated by bad-instruction); SIF stub names by-signature.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
