# 0x005b1e80 draw_namelist

| field | value |
|---|---|
| Original address | 0x005b1e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1e80 |
| Resolved name | draw_namelist |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1b10
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b1e30, FUN_0062fe20
**Referenced globals:** 0x6c4fbf cRam006c4fbf selected index; 0x638c50 DAT_00638c50 per-entry X/Y coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbf

## Behavioral explanation
Renders the name list: loops the table from 0x5b1e30 drawing each entry with per-entry color (highlighting the selected one 0x6c4fbf), plus two extra labels at fixed coords.

## Notes / uncertainty
Draws name list: font0x12, per-row highlight color 0xf when i==cRam006c4fbf else 0, string@ (0x68,DAT_00638c50[i]); footer color0x15 two detail lines (loc e*2 / e*2+1) at Y0x150/0x166 for current entry. Color id space + string-group arg not fully decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1e80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
