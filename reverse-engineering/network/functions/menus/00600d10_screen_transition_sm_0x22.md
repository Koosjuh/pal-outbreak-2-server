# 0x00600d10 screen_transition_sm_0x22

| field | value |
|---|---|
| Original address | 0x00600d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600d10 |
| Resolved name | screen_transition_sm_0x22 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff9f0
**Callees:** FUN_005acd60, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005c22a0
**Referenced globals:** 0x6c4b90 menu context
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xf step; param_1+0x16 timer; param_1+0x42b screen-id=0x22

## Behavioral explanation
4-state screen transition: sets screen-id 0x22, registers render cb 0x601700, kicks timed action FUN_005b9060, and on timeout resets menu context via FUN_005acd60.

## Notes / uncertainty
4-state launch/wait/commit SM: kicks async action 0x14 w/ +0x5ec ctx, 0x4c-frame timeout -> FUN_005acd60 commit, installs tag-0x22 handler 0x601700. Which network op 0x14 drives is not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
