# 0x005cd3e0 lobby_screen_state_reset

| field | value |
|---|---|
| Original address | 0x005cd3e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd3e0 |
| Resolved name | lobby_screen_state_reset |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e2060
**Referenced globals:** 0x701068+0x68e7e..0x68e86 phase/state block; 0x701070+0x36 flag; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e85; 0x701068+0x68e84; 0x701068+0x68e83; 0x701070+2

## Behavioral explanation
Resets the block of lobby/room phase vars (0x68e7e..0x68e86 to defaults) and, if not a sub-screen, runs FUN_005e2060; sets step to 1.

## Notes / uncertainty
Step-0: seeds phase block ov+0x68e7e..0x68e86 (4,5,5,5,5,2,3,0xC,3), gated FUN_005e2060 on scr+0x36==0 (top vs sub screen), scr+2=1. Individual phase-counter meanings inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
