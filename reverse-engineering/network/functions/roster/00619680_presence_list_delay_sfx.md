# 0x00619680 presence_list_delay_sfx

| field | value |
|---|---|
| Original address | 0x00619680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619680 |
| Resolved name | presence_list_delay_sfx |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619330
**Callees:** FUN_005b8cf0, FUN_005b9110
**Referenced globals:** ctx[1] substate; ctx+0x18 frame counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx[1]

## Behavioral explanation
Step 3: a 4-substate delay/settle handler that plays UI sounds (FUN_005b8cf0(0x7a), FUN_005b9110(0x4c)) and counts down 0x3c frames before advancing.

## Notes / uncertainty
Phase 3: 4-substate delay with SFX 0x7a then 0x4c around a 0x3c-frame countdown, then advance. SFX ids unmapped; countdown runs 61 frames (post-dec compare).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
