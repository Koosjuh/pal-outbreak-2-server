# 0x005b8b60 widget_cb_area_icon

| field | value |
|---|---|
| Original address | 0x005b8b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8b60 |
| Resolved name | widget_cb_area_icon |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20, FUN_0062fd90
**Referenced globals:** 0x006970f4 bRam=area/scenario count; 0x006970f6 icon descriptor table; 0x006c4fd3 cRam=pause/mode gate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd3; bRam006970f4

## Behavioral explanation
Display-object callback that draws an area/scenario-indexed icon: FUN_0062fd90(type)+ (+3)*0xc gives a descriptor, then set-palette/pos/draw; special branch indexes table 0x6970f6 stride 0x14a8 by (+3 - 2).

## Notes / uncertainty
Area/scenario icon row; low indices draw descriptor string, higher draw area-table 0x6970f6 stride 0x14a8 bounded by bRam006970f4. UI consumer of area data, not protocol; entry layout opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
