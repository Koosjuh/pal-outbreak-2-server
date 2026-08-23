# 0x005bef00 menu_build_entry_0xb5_ret

| field | value |
|---|---|
| Original address | 0x005bef00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bef00 |
| Resolved name | menu_build_entry_0xb5_ret |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bebf0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 menu UI object
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Adds/queries menu entry #0xb5 on 0x7018d0 and returns the builder result (no label arg).

## Notes / uncertainty
Terminal no-label entry (id 0xb5); returns handle that caller FUN_005bebf0 stores in descriptor table 0x6ca97e[idx]. Whether 0xb5 is action/terminator unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bef00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
