# 0x001ef4a0 snap_ipc_rpc_type5

| field | value |
|---|---|
| Original address | 0x001ef4a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef4a0 |
| Resolved name | snap_ipc_rpc_type5 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee3b0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37bf18 (IPC reply slot in buffer B); 0x37cf00 (IPC buffer A); 0x37bf00 (IPC buffer B)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Synchronous IPC RPC: locks (ef3e0), sends message type 5 with 0x20-byte buffers via ef400, reads reply word from 0x37bf18, unlocks (ef3f0), returns it.

## Notes / uncertainty
Serialised RPC-5 round trip: lock(ef3e0)/call(5,0x20,0x20)/read u16 reply @0x37bf18/unlock(ef3f0). RPC-5 = status/poll query; its IOP-side meaning is external to this binary.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef4a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
