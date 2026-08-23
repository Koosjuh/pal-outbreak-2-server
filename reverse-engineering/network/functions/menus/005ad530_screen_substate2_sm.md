# 0x005ad530 screen_substate2_sm

| field | value |
|---|---|
| Original address | 0x005ad530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad530 |
| Resolved name | screen_substate2_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ace00
**Callees:** FUN_005adc80, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bfbe0, FUN_005bfd80
**Referenced globals:** obj +0xf/+0x42b/+0x992/+0x16; 0x6c45fc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c45fc

## Behavioral explanation
Sub-screen 2 state machine (+0xf): pops up a message box (5bfbe0/5bfd80 callbacks), sets flag 0x6c45fc=1, advances/exits.

## Notes / uncertainty
Frame-driven SM (+0xf) for lobby sub-screen 2: two-stage message box (callbacks 0x5ada90/0x5adbe0), sets g_msgbox_request 0x6c45fc=1, wait/confirm loop. No wire. Box-style ids 5/7 and input mask 0x210 inferred, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
