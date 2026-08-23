# 0x001ef000 snap_op1d_unsubscribe_clrflag_a2a5

| field | value |
|---|---|
| Original address | 0x001ef000 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef000 |
| Resolved name | snap_op1d_unsubscribe_clrflag_a2a5 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001efe70
**Referenced globals:** 0x37a2a5 (mode flag:=0 on success)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a5

## Behavioral explanation
Calls FUN_001efe70(); on success clears mode flag 0x37a2a5=0, else -1.

## Notes / uncertainty
Renamed from snap_call_efe70_clrflag_a2a5. Callee IS op1d RPC stub (FUN_001efe70); clears a2a5=0 only on success. OFF-twin of op1c/a2a5 set-half.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef000.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
