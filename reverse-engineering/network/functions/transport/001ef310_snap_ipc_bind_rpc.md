# 0x001ef310 snap_ipc_bind_rpc

| field | value |
|---|---|
| Original address | 0x001ef310 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef310 |
| Resolved name | snap_ipc_bind_rpc |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee110
**Callees:** FUN_00106b60, FUN_00115a98
**Referenced globals:** 0x37aee0 (SNAP IPC semaphore id); 0x37df10 (IPC message queue); 0x37df08 (queue counter); 0x37df00 (queue counter); 0x37df34 (ready flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37df34 (ready flag)

## Behavioral explanation
Initializes the SN@P IPC layer: lazily CreateSema()s semaphore 0x37aee0, zeroes queue counters, then spins receiving on message-queue 0x37df10 (FUN_00115a98) until ready (iRam0037df34!=0).

## Notes / uncertainty
EE->IOP SIF RPC bootstrap: lazily CreateSema mutex 0x37aee0(1/1), zero queue counters, sceSifBindRpc(client@0x37df10, server 0x1270110) retry-spin (0x10000) until bound (0x37df34!=0). Lib fn identities inferred from call shape.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
