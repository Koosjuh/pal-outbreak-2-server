# 0x00618b60 ui_reset_view_flags

| field | value |
|---|---|
| Original address | 0x00618b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618b60 |
| Resolved name | ui_reset_view_flags |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ac400, FUN_005ac610, FUN_005ac6f0, FUN_005aca50, FUN_005acea0, FUN_005ade20, FUN_005ae210, FUN_005af4d0, FUN_005b1a30, FUN_005b25c0, FUN_005b3070, FUN_005b33f0, FUN_005b3510, FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005b45f0, FUN_005b4a50, FUN_005f62e0, FUN_005f6b00, FUN_005f6d20, FUN_005f78c0, FUN_005f9280, FUN_005f9540, FUN_005fba80, FUN_005fc850, FUN_005fe800, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230, FUN_00603d90, FUN_00603e40, FUN_00603f30, FUN_00605430, FUN_006069b0, FUN_00606af0, FUN_00606e40, FUN_00606fc0, FUN_00607260, FUN_006075e0, FUN_00607ac0, FUN_00608300, FUN_006088b0, FUN_00617030, FUN_00617270, FUN_006176a0, FUN_006178a0, FUN_00617980, FUN_006193e0, FUN_00627ea0, FUN_00629a40, FUN_0062a680, FUN_0062aeb0, FUN_0062b670, FUN_0062bb20, FUN_0062c1d0, FUN_0062cd20, FUN_0062d140
**Callees:** —
**Referenced globals:** uRam006c5538; uRam006c4fce; uRam006c4fd7; uRam006c4fcd
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fd7; uRam006c5538 view flags

## Behavioral explanation
Resets a small block of UI/view state flags; extremely widely called (63 callers) as a per-screen reset primitive.

## Notes / uncertainty
Per-screen compositor flag reset (63 callers). Clears partlist-pass gate (0x6c5538=0), enables pair-pass gate (0x6c4fd7=1) — both cross-confirmed as the gates read by sprite_compositor_render. Ghidra truncated epilogue (halt_baddata); 2 of 4 flags' meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
