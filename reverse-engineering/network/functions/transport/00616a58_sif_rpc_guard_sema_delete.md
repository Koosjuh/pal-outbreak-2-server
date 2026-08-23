# 0x00616a58 sif_rpc_guard_sema_delete

| field | value |
|---|---|
| Original address | 0x00616a58 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616a58 |
| Resolved name | sif_rpc_guard_sema_delete |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616b40
**Callees:** —
**Referenced globals:** 0x654208 (rpc guard sema handle, reset -1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654208 sema

## Behavioral explanation
Deletes the RPC guard semaphore (0x654208), resetting the handle to -1 and tearing down its wait object.

## Notes / uncertainty
Snapshot-clear-to-(-1) then free wait-record + DeleteSema; identity of wait-record thunks 0x0011b8e0/0x0011b938 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616a58.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
