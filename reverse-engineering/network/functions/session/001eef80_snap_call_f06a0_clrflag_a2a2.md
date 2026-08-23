# 0x001eef80 snap_call_f06a0_clrflag_a2a2

| field | value |
|---|---|
| Original address | 0x001eef80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eef80 |
| Resolved name | snap_call_f06a0_clrflag_a2a2 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001f06a0
**Referenced globals:** 0x37a2a2 (mode flag:=0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a2

## Behavioral explanation
Calls FUN_001f06a0() and clears mode flag 0x37a2a2=0.

## Notes / uncertainty
Clear-half of a2a2 pair; FUN_001f06a0() then a2a2=0 ungated. Set-half FUN_001eedc0. Callee f0650/f06a0 are 0x50-adjacent enable/disable.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eef80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
