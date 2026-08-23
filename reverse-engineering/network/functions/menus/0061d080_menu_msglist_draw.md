# 0x0061d080 menu_msglist_draw

| field | value |
|---|---|
| Original address | 0x0061d080 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061d080 |
| Resolved name | menu_msglist_draw |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_0061cc80, FUN_0061cce0
**Referenced globals:** 0x665e50 group table; 0x665df0 per-lang string-ptr table; bRam0034359d language
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Draws a message/label group from table DAT_00665e50 (index<0xb7, stride 0xc): sets color/scale from the record and renders each string via text_draw_tokens.

## Notes / uncertainty
Mode-0 core of text_draw_with_name_subst without name-subst/redirect: draws message block id<0xb7 from 0x665e50 + per-lang lines 0x665df0, -1=center, y+=pitch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061d080.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
