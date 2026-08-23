# 0x001eed90 snap_call_f02e0_clrflag_a2a1

| field | value |
|---|---|
| Original address | 0x001eed90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eed90 |
| Resolved name | snap_call_f02e0_clrflag_a2a1 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001f02e0
**Referenced globals:** 0x37a2a1 (mode flag:=0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a1

## Behavioral explanation
Calls FUN_001f02e0() and clears mode flag 0x37a2a1=0.

## Notes / uncertainty
Clear-half of a2a1 mode-latch pair; FUN_001f02e0() then a2a1=0 ungated (records intent). Set-half FUN_001ee8d0. Subsystem identity unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eed90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
