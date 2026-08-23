# 0x006134b0 scenario_list_render

| field | value |
|---|---|
| Original address | 0x006134b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006134b0 |
| Resolved name | scenario_list_render |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_0060f880, FUN_006146e0
**Referenced globals:** 0x653f50 (per-lang scenario labels); ctx+0x1c (list cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x1c scenario cursor

## Behavioral explanation
Renders 3 scenario/area list rows: for i in 0..2 looks up label (FUN_0060f880, +0x1c cursor base) and draws at stepped y via FUN_006146e0(0x65,...).

## Notes / uncertainty
Draws 3-row scenario list window at cursor ctx+0x1c, labels via FUN_0060f880 (0x653f50), x=0x65. y-formula row*0x1c+0xc4 INFERRED (raw uses clobbered extraout_a1_lo) — pitch/base uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006134b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
