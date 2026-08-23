# 0x005aca20 menu_state1_render_wrap

| field | value |
|---|---|
| Original address | 0x005aca20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aca20 |
| Resolved name | menu_state1_render_wrap |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_005acab0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Top-state 1 step: brackets the in-lobby screen dispatch (FUN_005acab0) with render begin/end thunks.

## Notes / uncertainty
Top-state 1: render-scope bracket (001ca720 begin / 001ca750 end) around in-lobby dispatcher FUN_005acab0. Thin wrapper; real work in acab0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aca20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
