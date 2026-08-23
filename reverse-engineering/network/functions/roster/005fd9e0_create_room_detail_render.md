# 0x005fd9e0 create_room_detail_render

| field | value |
|---|---|
| Original address | 0x005fd9e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fd9e0 |
| Resolved name | create_room_detail_render |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005bac80, FUN_005fe4b0, FUN_00618c20, FUN_0062fea0
**Referenced globals:** 0x6970a0 member model; bRam006970f4 count; 0x6c7c2c char-grid (stride 0x1f0-ish); 0x6c7d18/0x6c7d1c char id; cRam006c5499 cursor; 0x6c4bac area id
**Referenced strings:** 0x649888; 0x649ae0; 0x649ae8
**Referenced opcodes:** —
**State vars:** cRam006c5499 selection; bRam006970f4 count

## Behavioral explanation
Renders the create-room/scenario detail panel: draws member rows (bRam006970f4) or the 4-slot char grid (0x6c7c2c), plus area/scenario/difficulty fields.

## Notes / uncertainty
Host/create peer of 005fcc70; ctx[+2] view mode 0/1/3 = member-list / 4-slot char grid (0x6c7c2c stride 0x3b0) / scenario description. View-mode enum inferred from layout, not a symbol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fd9e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
