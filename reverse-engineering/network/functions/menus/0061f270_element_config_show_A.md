# 0x0061f270 element_config_show_A

| field | value |
|---|---|
| Original address | 0x0061f270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f270 |
| Resolved name | element_config_show_A |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_00624850, FUN_00625190
**Callees:** —
**Referenced globals:** 0x715314/0x715315 (element params); 0x71530a/0x71530b (scroll/anim counters); 0x71530c (redraw mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715314; 0x715315; 0x71530c

## Behavioral explanation
Stores two params to uRam00715314/15, resets scroll counters 0x71530a/b, requests draw (0x71530c|=0x380) — configure+show a two-value UI element.

## Notes / uncertainty
Already reconstructed: stores 2 param bytes 0x715314/15, zeroes scroll ctrs, |=0x380. Param byte semantics unresolved. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
