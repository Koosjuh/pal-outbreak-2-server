# 0x005c0e30 room_enter_begin

| field | value |
|---|---|
| Original address | 0x005c0e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0e30 |
| Resolved name | room_enter_begin |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8060, FUN_00617a50, FUN_0062cb00, FUN_0062e720
**Callees:** FUN_005bf0e0
**Referenced globals:** 0x6cdbe6 roster table; 0x6ff2b1 room state (=3); 0x6cbb6c SM guard; 0x6cbb48 pump=FUN_005c1c80; 0x6cbb4c ctx; 0x6cbb68 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbb6c guard; 0x6ff2b1; 0x6cbb68 step

## Behavioral explanation
Begins the enter-room sequence (guard 0x6cbb6c): zeroes roster 0x6cdbe6, stores room slots 0/1/2 (bf0e0), sets room state 0x6ff2b1=3, and arms pump FUN_005c1c80 with completion ctx param_4.

## Notes / uncertainty
Arms the enter-room SM (guard 0x6cbb6c): clears roster 0x6cdbe6, seats slot regs 0/1/2, presets ownership lock 0x6ff2b1=3 (joiner skips host STAT 1->3 step), installs pump FUN_005c1c80. Meaning of slot regs 0/1 in enter path partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
