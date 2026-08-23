# 0x005becf0 menu_build_label_0xb0

| field | value |
|---|---|
| Original address | 0x005becf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005becf0 |
| Resolved name | menu_build_label_0xb0 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea70, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbe8b label string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds menu entry #0xb0 into UI object 0x7018d0 from label string at 0x6cbe8b.

## Notes / uncertainty
Same shape as 0xaf; tag 0xB0, label string 0x6cbe8b. Second member of the bec80-bef00 menu-builder family.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005becf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
