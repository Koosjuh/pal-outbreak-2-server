# 0x0062a5e0 overlay_menu_dispatch_695d10

| field | value |
|---|---|
| Original address | 0x0062a5e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062a5e0 |
| Resolved name | overlay_menu_dispatch_695d10 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00629330, FUN_006293b0
**Callees:** FUN_0062a680, FUN_0062a6d0, FUN_0062a8c0, FUN_0062adb0, FUN_0062aeb0, FUN_0062b020
**Referenced globals:** 0x695d10 screen-selector
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00695d10

## Behavioral explanation
Top-level screen state dispatcher: switch on uRam00695d10 (0..5) into sub-screen handlers.

## Notes / uncertainty
Phase dispatcher: switch uRam00695d10 (0..5) to 6 handlers, default returns 0. Handlers 1-5 not yet reconstructed; ABI pass-through of (ctx,0) inferred from callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062a5e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
