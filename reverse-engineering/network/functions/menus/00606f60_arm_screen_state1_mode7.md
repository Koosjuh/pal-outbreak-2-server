# 0x00606f60 arm_screen_state1_mode7

| field | value |
|---|---|
| Original address | 0x00606f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606f60 |
| Resolved name | arm_screen_state1_mode7 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac400, FUN_00606fc0, FUN_00607370
**Callees:** —
**Referenced globals:** 0x0070cdb8 screen-state; 0x006c4faa mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070cdb8; uRam006c4faa

## Behavioral explanation
memset 0x70cdb8, sets screen-state=1 and mode 6c4faa=7.

## Notes / uncertainty
Sibling of 606f10 but arms screen state word=1 (retry/skip-init), top_screen=7, no render re-arm. Which callers use state-1 vs state-0 not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
