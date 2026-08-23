# 0x00606e40 teardown_overlay_state

| field | value |
|---|---|
| Original address | 0x00606e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606e40 |
| Resolved name | teardown_overlay_state |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_00607370
**Callees:** FUN_001b3720, FUN_005af340, FUN_00605f80, FUN_00606ea0, FUN_00618b60
**Referenced globals:** 0x006c4b90 state-block(0x54dc); 0x006c4faa mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa

## Behavioral explanation
Overlay teardown: stops audio/render, memset 0x54dc state block at 0x6c4b90, re-inits scratch buffers, sets mode 6c4faa=0.

## Notes / uncertainty
Full overlay teardown: memset lobby_state_block 0x6c4b90/0x54dc, re-init 3 record buffers, top_screen=0, render stop/re-arm, ext teardown. First callee FUN_00605f80 is opaque veneer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
