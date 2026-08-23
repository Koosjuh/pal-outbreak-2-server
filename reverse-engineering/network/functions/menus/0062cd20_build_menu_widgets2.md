# 0x0062cd20 build_menu_widgets2

| field | value |
|---|---|
| Original address | 0x0062cd20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cd20 |
| Resolved name | build_menu_widgets2 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062bb20, FUN_0062c1d0
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x66af50 widget table; 0x66af40 coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Widget-list builder from table PTR_DAT_0066af50[sel] (sentinel<0), allocs 0x12-type UI nodes and fills id/coords from 0x66af40; twin of FUN_0062b670.

## Notes / uncertainty
Structural twin of b670 with constants swapped: table 0x66af50, node type 0x12, coord tables 0x66af40/2. Reached from roster/detail submachines (bb20/c1d0) via menu_dispatch_695d28. Same inference caveats as b670.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cd20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
