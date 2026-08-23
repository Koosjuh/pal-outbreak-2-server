# 0x005f7690 goto_dialog_screen

| field | value |
|---|---|
| Original address | 0x005f7690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7690 |
| Resolved name | goto_dialog_screen |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005aec70, FUN_005f7c80
**Callees:** FUN_005aec20, FUN_005b9110
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xe (page); param+0xf/+0x10 (substate); param+0x45b

## Behavioral explanation
Sets a screen struct into a dialog state (+0xe=3, +0xf/+0x10 by param2), re-inits FUN_005aec20, tears down net FUN_005b9110(0x4c), marks +0x45b=2.

## Notes / uncertainty
Switches screen to dialog page (+0xe=3), variant sub-state from param2, tears down session via FUN_005b9110(0x4c), raises +0x45b=2. Error-page identity and 0x4c meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
