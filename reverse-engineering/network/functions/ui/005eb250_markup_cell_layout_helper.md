# 0x005eb250 markup_cell_layout_helper

| field | value |
|---|---|
| Original address | 0x005eb250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb250 |
| Resolved name | markup_cell_layout_helper |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb0f0, FUN_005eb1d0, FUN_005f0e10, FUN_005f10a0
**Callees:** FUN_005effc0, FUN_005f0070
**Referenced globals:** +0xd894 (cell idx); +0x186 (mode); +0x18d (dirty); +0x24e0/+0x252c/+0x24f4 (cell struct)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894; +0x186

## Behavioral explanation
Layout helper for the current cell (+0x24e0): clears dirty flags, in mode 0xf6 stores child pointer at +0x24f4, then runs FUN_005effc0/005f0070 to lay out the element; -1 if no cell.

## Notes / uncertainty
Cell layout helper: requires cell->obj, in measure pass (0xF6) records child ptr at +0x24f4, runs FUN_005effc0/005f0070. Complements 0x5eb0f0's readback.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
