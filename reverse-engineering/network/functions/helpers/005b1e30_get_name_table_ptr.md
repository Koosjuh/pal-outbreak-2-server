# 0x005b1e30 get_name_table_ptr

| field | value |
|---|---|
| Original address | 0x005b1e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1e30 |
| Resolved name | get_name_table_ptr |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1b10, FUN_005b1d20, FUN_005b1e80
**Callees:** —
**Referenced globals:** 0x8744f8 bRam008744f8 region/version flag; 0x6c4b90 cRam006c4b90 scenario/area index; 0x638b40 name table A; 0x638a50 name table B
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x8744f8; 0x6c4b90

## Behavioral explanation
Returns pointer to the active name/label string table, selected by region flag 0x8744f8 and the scenario/index char 0x6c4b90 (stride 15 or 16).

## Notes / uncertainty
Region-variant name-table selector: g_regionMode(0x8744f8)<2 -> table 0x638b40 stride 15, else 0x638a50 stride 16, indexed by g_labelIndex(0x6c4b90). Region semantics (NTSC/PAL/lang) inferred; record layout not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
