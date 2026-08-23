# 0x005ee010 layout_table_cell

| field | value |
|---|---|
| Original address | 0x005ee010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee010 |
| Resolved name | layout_table_cell |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9e20
**Callees:** FUN_005d9350, FUN_005eced0, FUN_005ed460, FUN_005f2b10
**Referenced globals:** iRam007012a0; +0xd8bc/+0xd8c0/+0xd8c4 (cursor/col); +0x10 (width); +0x186 (pass); +0xd8cc (flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892

## Behavioral explanation
Lays out a table-cell/column: computes x (wrapping via layout_newline if it won't fit), advances the column cursor +0xd8c0, and draws a cell separator via FUN_005d9350 on the draw pass.

## Notes / uncertainty
Cell placement w/ wrap (FUN_005ed460), advance col_x by maxcol*8+0x18, draw separator FUN_005d9350; table-mode delegates FUN_005f2b10. Open-vs-close cell semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
