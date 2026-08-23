# 0x006178a0 modeB_state1_tick

| field | value |
|---|---|
| Original address | 0x006178a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006178a0 |
| Resolved name | modeB_state1_tick |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006177d0
**Callees:** FUN_005af2f0, FUN_005b8cf0, FUN_005b9060, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe major-state; +0x11 branch flag; +0x16 timer=10

## Behavioral explanation
type-0x0b scene state-1: advances state, plays a UI/sound branch depending on flag +0x11, arms a 10-tick timer.

## Notes / uncertainty
TICK: build panels, branch on obj+0x11 content_variant (0=sfx cue 0x4a, else render alt path from obj+0x5ec), arm timer=10. Variant field corroborated by 0x6179e0 constructor.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006178a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
