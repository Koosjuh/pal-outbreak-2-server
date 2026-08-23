# 0x00606f10 reset_screen_state_mode7

| field | value |
|---|---|
| Original address | 0x00606f10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606f10 |
| Resolved name | reset_screen_state_mode7 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_005f6b00, FUN_005f6d20, FUN_006069b0, FUN_00608300
**Callees:** —
**Referenced globals:** 0x0070cdb8 screen-state; 0x006c4faa mode; 0x00618c90 render-cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa; uRam0070cdb8

## Behavioral explanation
memset the 0xc-byte screen-state at 0x70cdb8, sets mode 6c4faa=7 and re-arms the render callback.

## Notes / uncertainty
Enters room-query screen SM at state 0: memset 0x70cdb8/0xc, top_screen=7, render re-arm. 0x70cdb8 block layout beyond leading state word unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606f10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
