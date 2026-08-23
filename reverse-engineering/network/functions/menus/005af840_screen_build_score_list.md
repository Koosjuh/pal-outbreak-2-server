# 0x005af840 screen_build_score_list

| field | value |
|---|---|
| Original address | 0x005af840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af840 |
| Resolved name | screen_build_score_list |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030
**Callees:** FUN_005ba7c0, FUN_00618ba0
**Referenced globals:** 0x6c45fa uRam006c45fa entry count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds a session-title/score results screen: allocates a set of widgets via widget_alloc and wires per-frame callbacks (cursor highlight FUN_005b0210, list rows FUN_005b0550, title/score rows FUN_005affb0, header FUN_005b08f0), iterating uRam006c45fa entries.

## Notes / uncertainty
One-shot builder allocating 7+2*rowcount widgets with per-frame callbacks; row sprite split 0x131/0x132 at index 5; FUN_005ba7c0 = screen-commit (by convention). Inline LAB deco callbacks not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
