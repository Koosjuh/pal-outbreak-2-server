# 0x005bee40 menu_build_entry_0xb3_dynamic

| field | value |
|---|---|
| Original address | 0x005bee40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bee40 |
| Resolved name | menu_build_entry_0xb3_dynamic |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea20, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object; 0x6cbf98 dynamic value var
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds menu entry #0xb3 into 0x7018d0 using a dynamic value var uRam006cbf98 (via FUN_005bea20) rather than a fixed string.

## Notes / uncertainty
Dynamic-value menu-entry variant (id 0xb3) binding runtime var 0x6cbf98 via bea20. Callee stubs; value-binding inferred. UI-only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bee40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
