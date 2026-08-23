# 0x005b6cf0 ui_widget_alloc_type_5b6d80

| field | value |
|---|---|
| Original address | 0x005b6cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6cf0 |
| Resolved name | ui_widget_alloc_type_5b6d80 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f8340
**Callees:** FUN_00618ba0
**Referenced globals:** LAB_005b6d80 (widget tick handler)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocate a UI display object (FUN_00618ba0), set handler LAB_005b6d80 and stash three params.

## Notes / uncertainty
Byte-identical sibling of 6c90 with handler LAB_005b6d80; single caller FUN_005f8340; functional difference of the two handlers unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
