# 0x005ba7b0 set_ui_dirty_flag_c5538

| field | value |
|---|---|
| Original address | 0x005ba7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba7b0 |
| Resolved name | set_ui_dirty_flag_c5538 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b25c0, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b33f0, FUN_005b3510, FUN_005b3590, FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005b45f0, FUN_005f62e0, FUN_005f8340, FUN_005fba80, FUN_005fc850, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230, FUN_00604af0, FUN_00605430, FUN_00607f70, FUN_006178a0, FUN_00617bb0, FUN_006193e0, FUN_00628760, FUN_00629a40, FUN_0062b670, FUN_0062cd20
**Callees:** —
**Referenced globals:** 0x006c5538 uRam=UI flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c5538

## Behavioral explanation
One-line setter: uRam006c5538 = 1 (a UI/refresh flag).

## Notes / uncertainty
One-way store uRam006c5538=1 from 29 screen/widget-spawn sites; inferred UI-dirty/redraw latch. Consumer/clear site not located, so exact flag meaning unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba7b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
