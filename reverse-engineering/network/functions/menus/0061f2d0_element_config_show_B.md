# 0x0061f2d0 element_config_show_B

| field | value |
|---|---|
| Original address | 0x0061f2d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f2d0 |
| Resolved name | element_config_show_B |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061fd70, FUN_00620250, FUN_00620d60, FUN_00623be0, FUN_00625ea0
**Callees:** —
**Referenced globals:** 0x715316/0x715317 (element params); 0x71530a/0x71530b (counters); 0x71530c (redraw mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715316; 0x715317; 0x71530c

## Behavioral explanation
Stores two params to uRam00715316/17, resets 0x71530a/b, requests draw (0x71530c|=0x380000) — configure+show a second two-value UI element.

## Notes / uncertainty
Already reconstructed twin of f270 (0x715316/17, |=0x380000). Widget identity unresolved. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f2d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
