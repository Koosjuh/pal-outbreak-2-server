# 0x001ef040 snap_call_f07f0_setflag_a2a6

| field | value |
|---|---|
| Original address | 0x001ef040 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef040 |
| Resolved name | snap_call_f07f0_setflag_a2a6 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001f07f0
**Referenced globals:** 0x37a2a6 (mode flag:=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a6

## Behavioral explanation
Calls FUN_001f07f0() and sets mode flag 0x37a2a6=1.

## Notes / uncertainty
Set-half of a2a6 pair; FUN_001f07f0() then a2a6=1 ungated. Clear-half FUN_001ef070. Callee not in set.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef040.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
