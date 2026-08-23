# 0x005bedd0 menu_build_label_0xb2

| field | value |
|---|---|
| Original address | 0x005bedd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bedd0 |
| Resolved name | menu_build_label_0xb2 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea70, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbf17 label string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds menu entry #0xb2 into UI object 0x7018d0 from label string at 0x6cbf17.

## Notes / uncertainty
Static-label menu-entry builder (id 0xb2, str 0x6cbf17) into obj 0x7018d0. Builder-primitive callees (be9e0 identity, bea10/70/80 void) decompile as stubs, so widget semantics inferred from call pattern. UI-only, not protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bedd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
