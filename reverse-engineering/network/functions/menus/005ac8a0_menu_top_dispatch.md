# 0x005ac8a0 menu_top_dispatch

| field | value |
|---|---|
| Original address | 0x005ac8a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac8a0 |
| Resolved name | menu_top_dispatch |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006233e0
**Callees:** FUN_005ac400, FUN_005ac4c0, FUN_005ac810, FUN_005aca20, FUN_005aca50, FUN_005b2460, FUN_006063c0, FUN_00606af0, FUN_00606cb0, FUN_00606cf0, FUN_00608300, FUN_006088b0
**Referenced globals:** 0x6c4faa(top screen state); 0x6c4fde(busy); 0x6c4618/0x6c4610/0x6c4620(pad snapshot); 0x3434a0/0x3434a8/0x3434b8(pad in)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4faa; uRam006c4fde

## Behavioral explanation
Top-level overlay tick: snapshots pad input then switches on faa (0,1,3,4,5,6,7,8,9,10,0x17) to the per-screen step handlers.

## Notes / uncertainty
Already fully reconstructed; verified byte-for-byte against raw switch on cRam006c4faa. Per-screen semantics live in handlers; only state 5 propagates a return value.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac8a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
