# 0x005ed1f0 layout_marker_box

| field | value |
|---|---|
| Original address | 0x005ed1f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed1f0 |
| Resolved name | layout_marker_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9a90, FUN_005e9b20
**Callees:** FUN_005d93f0, FUN_005ec170, FUN_005ed160, FUN_005f2450
**Referenced globals:** iRam007012a0; +0x8f4 (marker width); +0xd8be (y cursor); +0x186 (pass); +0xd892 (depth)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892

## Behavioral explanation
Lays out a list-item/bullet marker: sizes the marker box (+0x8f4), advances the y cursor (+0xd8be) and, on the draw pass, renders the bullet via FUN_005d93f0.

## Notes / uncertainty
Lays out/draws a filled list/block marker box (w+0x8f4,h+0x8f2) with 10px gaps; nested->FUN_005f2450. Originally 'list_item_bullet' but generic marker. param_1=center flag inferred; box-draw arg order inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed1f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
