# 0x005ac6f0 overlay_reset_warm

| field | value |
|---|---|
| Original address | 0x005ac6f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac6f0 |
| Resolved name | overlay_reset_warm |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006088b0
**Callees:** FUN_001b3720, FUN_005ac3b0, FUN_005ac7d0, FUN_005af300, FUN_005af340, FUN_005b2410, FUN_005b24d0, FUN_005be620, FUN_00606ea0, FUN_00606f10, FUN_00618ae0, FUN_00618b60, FUN_00634550
**Referenced globals:** 0x6c4b90(lobby state blk); 0x343560; 0x6c4fd7; 0x6c4faa; 0x6c4fab
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa; uRam006c4fab; uRam006c4fd7

## Behavioral explanation
Warm re-init variant of overlay_init_full: clears 874f30, re-zeros 0x6c4b90 block, re-runs init subset, resets top state faa=0/fab=0.

## Notes / uncertainty
Warm re-init: clear_menu_state_874f30 first, re-zero 0x6c4b90, subset of cold-init calls (omits 005af420/005af370/006277a0/001a7e20), then force top_screen=0/top_substate=0. Callee-diff vs cold documented; omission rationale inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac6f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
