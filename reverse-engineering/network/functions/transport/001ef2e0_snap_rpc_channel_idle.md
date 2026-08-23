# 0x001ef2e0 snap_rpc_channel_idle

| field | value |
|---|---|
| Original address | 0x001ef2e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef2e0 |
| Resolved name | snap_rpc_channel_idle |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee160
**Callees:** FUN_00115e60
**Referenced globals:** 0x37df10 (SNAP IPC message queue)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Predicate: returns true iff FUN_00115e60(0x37df10) (message-queue/state probe) yields 0 — queue-empty / no-pending test.

## Notes / uncertainty
renamed from msgq_is_empty: probes SIF-RPC client-data 0x37df10 (same handle ef400 dispatches through) ==0 => idle. CheckStatRpc identity/polarity inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef2e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
