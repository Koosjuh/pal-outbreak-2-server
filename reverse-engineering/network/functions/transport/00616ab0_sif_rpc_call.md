# 0x00616ab0 sif_rpc_call

| field | value |
|---|---|
| Original address | 0x00616ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616ab0 |
| Resolved name | sif_rpc_call |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006158c8, FUN_00615930, FUN_006159c0, FUN_00615e20, FUN_00615ea8, FUN_00615f48, FUN_00615fc8, FUN_00616048, FUN_006160a0, FUN_006160f8, FUN_00616150, FUN_006161d8, FUN_00616210, FUN_00616250, FUN_00616288
**Callees:** FUN_00616a00
**Referenced globals:** 0x70d200 (SifRpcClientData); 0x70d240 (send/recv buf)
**Referenced strings:** 0x693db8 (error/log fmt when channel down)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Core SIF-RPC dispatch: ensures the guard sema exists then issues sceSifCallRpc(clientData=0x70d200, fno=param_3, sync, sendbuf/recvbuf=0x70d240 x0x1000, callback=0x6169d8); logs error if channel unavailable.

## Notes / uncertainty
Single choke-point for 15 RPC wrappers: guard-init then sceSifCallRpc(client,fno,mode=1,buf,0x1000 send/recv aliased,endcb=0x6169d8); logs 0x693db8 on channel-down; mode=1 semantics + buffer aliasing uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
