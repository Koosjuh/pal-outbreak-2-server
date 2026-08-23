# 0x005bee90 menu_build_label_0xb4

| field | value |
|---|---|
| Original address | 0x005bee90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bee90 |
| Resolved name | menu_build_label_0xb4 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea70, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbf99 label string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds menu entry #0xb4 into UI object 0x7018d0 from label string at 0x6cbf99.

## Notes / uncertainty
Static-label builder (id 0xb4, str 0x6cbf99). Same stub-callee caveat as 0xb2.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bee90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
