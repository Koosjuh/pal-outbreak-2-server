# 0x001ef3e0 snap_ipc_lock

| field | value |
|---|---|
| Original address | 0x001ef3e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef3e0 |
| Resolved name | snap_ipc_lock |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ef4a0, FUN_001ef4f0, FUN_001ef540, FUN_001ef5c0, FUN_001ef610, FUN_001ef690, FUN_001ef710, FUN_001ef770, FUN_001ef7d0, FUN_001ef830, FUN_001ef8d0, FUN_001ef9a0, FUN_001efa70, FUN_001efb80, FUN_001efc90, FUN_001efcf0, FUN_001efda0, FUN_001efe00, FUN_001efe70, FUN_001efee0, FUN_001eff60, FUN_001f0070, FUN_001f0230, FUN_001f0290, FUN_001f02e0, FUN_001f0330, FUN_001f0450, FUN_001f04a0, FUN_001f0560, FUN_001f05c0, FUN_001f0650, FUN_001f06a0, FUN_001f06f0, FUN_001f0750, FUN_001f07a0, FUN_001f07f0, FUN_001f0840, FUN_001f0890, FUN_001f0920, FUN_001f0980, FUN_001f09f0, FUN_001f0a80, FUN_001f0ad0, FUN_001f0b40, FUN_001f0bf0, FUN_001f0c40, FUN_001f0cb0, FUN_001f0d10, FUN_001f0d90, FUN_001f0df0, FUN_001f0eb0, FUN_001f0f10
**Callees:** —
**Referenced globals:** 0x37aee0 (SNAP IPC semaphore id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
WaitSema(0x37aee0) — acquires the SN@P IPC mutex/semaphore.

## Notes / uncertainty
WaitSema(0x37aee0); lock half of the pair that serializes all SN@P RPC stubs over shared bufs 0x37cf00/0x37bf00. Binary-mutex assumed, not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
