# 0x005b6c90 ui_widget_alloc_type_5b6d50

| field | value |
|---|---|
| Original address | 0x005b6c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6c90 |
| Resolved name | ui_widget_alloc_type_5b6d50 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3cb0, FUN_005b3ed0, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230
**Callees:** FUN_00618ba0
**Referenced globals:** LAB_005b6d50 (widget tick handler)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocate a UI display object (FUN_00618ba0), set its handler pointer to LAB_005b6d50 and stash params (byte, byte, u32) into the object.

## Notes / uncertainty
UI display-node factory installing handler LAB_005b6d50; UiNode field labels (+0x38 group,+0x10 callback) inferred; handler body not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
