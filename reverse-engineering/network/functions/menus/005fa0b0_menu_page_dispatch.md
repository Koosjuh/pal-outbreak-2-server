# 0x005fa0b0 menu_page_dispatch

| field | value |
|---|---|
| Original address | 0x005fa0b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa0b0 |
| Resolved name | menu_page_dispatch |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8e20
**Callees:** FUN_005f8d00, FUN_005fa190, FUN_005fa490, FUN_005faa60, FUN_005fada0, FUN_005fb010, FUN_005fb060
**Referenced globals:** +0xf page id; +0x97c result code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf page id

## Behavioral explanation
Top page dispatcher: switch on screen id (+0xf) into the area/select/create/enter sub-screens; cases 4/7/8 raise error dialogs.

## Notes / uncertainty
Already fully reconstructed. Page router on screen+0xf; pages 4/7/8 are error terminals (dialog codes 0x89/0xb8/0xb9, strings unmapped).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa0b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
