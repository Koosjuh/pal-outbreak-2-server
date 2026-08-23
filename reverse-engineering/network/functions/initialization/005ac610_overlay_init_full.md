# 0x005ac610 overlay_init_full

| field | value |
|---|---|
| Original address | 0x005ac610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac610 |
| Resolved name | overlay_init_full |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4040, FUN_006233e0
**Callees:** FUN_001b3720, FUN_005ac7d0, FUN_005af300, FUN_005af340, FUN_005af370, FUN_005af420, FUN_005b2410, FUN_005b24d0, FUN_005be620, FUN_00606ea0, FUN_00606f10, FUN_00618ae0, FUN_00618b60, FUN_006277a0, FUN_00634550
**Referenced globals:** 0x6c4b90(lobby state blk,0x54dc); 0x343560; 0x6c4fd7; 0x34359d
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fd7

## Behavioral explanation
Full overlay init: memsets the 0x54dc-byte lobby state block at 0x6c4b90 and runs the whole subsystem init sequence (render/session/room managers).

## Notes / uncertainty
Cold init: memset lobby_state_block(0x6c4b90,0x54dc)=0, set overlay-ready 0x6c4fd7=1, run full ~18-call subsystem bring-up. Individual manager callee roles not deeply decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
