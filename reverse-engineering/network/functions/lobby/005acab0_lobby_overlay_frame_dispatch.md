# 0x005acab0 lobby_overlay_frame_dispatch

| field | value |
|---|---|
| Original address | 0x005acab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acab0 |
| Resolved name | lobby_overlay_frame_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aca20
**Callees:** FUN_005acda0, FUN_005ade20, FUN_005ae3e0, FUN_005ae770, FUN_005aec70, FUN_005aedc0, FUN_005aefb0, FUN_005af090, FUN_005af4d0, FUN_005b1a00, FUN_005b1d10, FUN_005b1d20, FUN_005b24e0, FUN_005be330, FUN_005f6aa0, FUN_005f76f0, FUN_005f8d40, FUN_005fe620, FUN_005ff950, FUN_00616c40, FUN_006177d0, FUN_00617a50, FUN_00618c30, FUN_00627a20, FUN_0062d5e0
**Referenced globals:** 0x6c4b90(screen id + state blk); 0x6c4fbc(paused flag); 0x6c50e8(timer); 0x6c5560/0x6c555f; 0x6c5522/0x6c5524; 0x6c4fb0(frame ctr); 0x6c4fc4; 0x35a6f4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4fbc; cRam006c4fc4

## Behavioral explanation
In-lobby per-frame dispatcher: switches on screen id cRam006c4b90 (0..0xf) to each lobby/room screen handler, with a paused/overlay-active alternate path; ticks frame counter.

## Notes / uncertainty
Renamed from lobby_screen_dispatch. Top-level per-frame online-overlay router: switch on top-screen id 0x6c4b90 (0-0xf) to screen handlers, with overlay-ready/busy gates + modal path; arms 0xe10 timeout, ticks frame ctr. Case 0→lobby menu SM (005b24e0), 7→session. Screen-id→handler mapping inferred not observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
