# 0x005fb710 lobby_screen_dispatch

| field | value |
|---|---|
| Original address | 0x005fb710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb710 |
| Resolved name | lobby_screen_dispatch |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8e20
**Callees:** FUN_005f8060, FUN_005fb790, FUN_005fb860, FUN_005fb9b0
**Referenced globals:** +0xf page id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf page

## Behavioral explanation
Screen dispatcher on page id (+0xf): routes to sub-screens FUN_005f8060 / fb9b0 / fb860 / fb790.

## Notes / uncertainty
Already fully reconstructed. Sibling page router (pages 0-3) sharing caller FUN_005f8e20 and +0xf field with menu_page_dispatch; concrete screen identities unestablished.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
