# 0x005bed60 menu_build_label_0xb1

| field | value |
|---|---|
| Original address | 0x005bed60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bed60 |
| Resolved name | menu_build_label_0xb1 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea70, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbe96 label string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds menu entry #0xb1 into UI object 0x7018d0 from label string at 0x6cbe96.

## Notes / uncertainty
Same shape; tag 0xB1, label string 0x6cbe96. Third member; the three label ptrs form a packed string block.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bed60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
