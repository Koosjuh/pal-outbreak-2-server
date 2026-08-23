# 0x0062ba70 menu_dispatch_695d28

| field | value |
|---|---|
| Original address | 0x0062ba70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ba70 |
| Resolved name | menu_dispatch_695d28 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40, FUN_005ff950, FUN_00628710, FUN_00629370
**Callees:** FUN_0062bb20, FUN_0062bbc0, FUN_0062bda0, FUN_0062c1d0, FUN_0062c350
**Referenced globals:** 0x695d28 screen selector
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00695d28

## Behavioral explanation
Screen dispatcher: switch on cRam00695d28 (0..4) into roster/enter submachines.

## Notes / uncertainty
Pure fan-out dispatcher on global cRam00695d28 (0..4) -> bb20/bbc0/bda0/c1d0/c350; default returns 0. Second-level menu router for roster/detail/enter screens. Sub-screen labels inferred from callees, not runtime-captured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ba70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
