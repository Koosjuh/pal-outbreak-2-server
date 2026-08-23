# 0x00616518 sif_rpc_server_teardown

| field | value |
|---|---|
| Original address | 0x00616518 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616518 |
| Resolved name | sif_rpc_server_teardown |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006156b0, FUN_00615778
**Callees:** —
**Referenced globals:** 0x70f2d0/0x70f318 (rpc server data)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Tears down the RPC service: stops the server data (0x70f2d0/0x70f318) and deletes the service thread param_1.

## Notes / uncertainty
sceSifRemoveRpc(server 0x70f2d0, queue 0x70f318) + RemoveRpcQueue + DeleteThread(param_1); IOP-RPC call names inferred from arg arity+region; halt_baddata is decompiler artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616518.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
