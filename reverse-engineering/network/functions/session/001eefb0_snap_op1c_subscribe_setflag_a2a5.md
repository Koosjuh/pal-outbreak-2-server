# 0x001eefb0 snap_op1c_subscribe_setflag_a2a5

| field | value |
|---|---|
| Original address | 0x001eefb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eefb0 |
| Resolved name | snap_op1c_subscribe_setflag_a2a5 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001efe00
**Referenced globals:** 0x37a2a5 (mode flag:=1 on success)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a5

## Behavioral explanation
Calls FUN_001efe00(); on success sets mode flag 0x37a2a5=1, else returns -1.

## Notes / uncertainty
Renamed from snap_call_efe00_setflag_a2a5. Callee IS the op1c RPC stub (FUN_001efe00); sets a2a5=1 ONLY on success (confirmed-state, unlike other latches). op1c/op1d = enable/disable pair; subscribed resource unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eefb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
