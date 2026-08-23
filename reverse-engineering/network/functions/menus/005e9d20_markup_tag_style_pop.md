# 0x005e9d20 markup_tag_style_pop

| field | value |
|---|---|
| Original address | 0x005e9d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d20 |
| Resolved name | markup_tag_style_pop |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70, FUN_005ef380
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Applies arg via FUN_005eef70 then triggers FUN_005ef380 (refresh).

## Notes / uncertainty
Flush run (FUN_005eef70) then style-stack pop (FUN_005ef380, depth-- floor 0). param_1 unused (tag descriptor).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
