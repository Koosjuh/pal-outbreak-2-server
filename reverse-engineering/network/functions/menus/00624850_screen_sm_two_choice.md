# 0x00624850 screen_sm_two_choice

| field | value |
|---|---|
| Original address | 0x00624850 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00624850 |
| Resolved name | screen_sm_two_choice |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f180, FUN_0061f1a0, FUN_0061f1b0, FUN_0061f1f0, FUN_0061f250, FUN_0061f270, FUN_0061f470, FUN_0061f4b0, FUN_0061f680
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e8 cursor; 0x86f810/0x86f820 selection buffers; 0x3c9580 link
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152e8

## Behavioral explanation
Screen state machine for a 2-option selection menu: draws element 0x35, moves a left/right cursor (e750/e720) and confirms via e7f0/e800; returns selected index+1 / -1.

## Notes / uncertainty
Two-option chooser (phases 0-3) + exit-confirm sub-flow (phases 4-7); option buffers 0x86f810/0x86f820, link source 0x3c9580. Returns sel+1 / -1. Human meaning of the two choices and confirm-vs-cancel button polarity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00624850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
