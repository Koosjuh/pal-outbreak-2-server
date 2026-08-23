# 0x001ef070 snap_call_f0840_clrflag_a2a6

| field | value |
|---|---|
| Original address | 0x001ef070 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef070 |
| Resolved name | snap_call_f0840_clrflag_a2a6 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0, FUN_001c2770
**Callees:** FUN_001f0840
**Referenced globals:** 0x37a2a6 (mode flag:=0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a6

## Behavioral explanation
Calls FUN_001f0840() and clears mode flag 0x37a2a6=0.

## Notes / uncertainty
Clear-half of a2a6 pair; FUN_001f0840() then a2a6=0, returns fixed 0 (callee result DISCARDED, unlike sibling clear-halves). Best-effort disable.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
