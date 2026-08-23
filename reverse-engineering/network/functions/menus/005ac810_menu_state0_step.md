# 0x005ac810 menu_state0_step

| field | value |
|---|---|
| Original address | 0x005ac810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac810 |
| Resolved name | menu_state0_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_00608670
**Referenced globals:** 0x6c4fab; 0x6c4faa; 0x6c50e8(timer); 0x6c50ec; 0x701e10
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fab; uRam006c4faa

## Behavioral explanation
Top-state 0 step: initial substate arms libgfx, next substate sets a 0xe10 timer and calls FUN_00608670 then clears 0x701e10.

## Notes / uncertainty
Top-state 0 (entry): substate0 arms gfx; substate1 -> top_screen=1, arm 0xe10(3600) timeout at 0x6c50e8, FUN_00608670(0x6c50ec), clear flag 0x701e10. Purpose of 608670/0x6c50ec and flag 0x701e10 not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
