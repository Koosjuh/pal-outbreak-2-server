# 0x005e0050 texture_table_teardown

| field | value |
|---|---|
| Original address | 0x005e0050 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0050 |
| Resolved name | texture_table_teardown |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd650
**Callees:** —
**Referenced globals:** iRam00701068+0x607c0 (texture handle table); iRam00701068+0x609c0 (texture count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x609c0

## Behavioral explanation
Frees every loaded texture handle in the table (@+0x607c0, count @+0x609c0) via external free func_0x001cbbb0 and clears the count.

## Notes / uncertainty
Frees all live texture handles (table@+0x607c0, byte count@+0x609c0) via func_0x001cbbb0, NULLs slots, count=0. Called from scene-reset FUN_005cd650. Free-target identity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0050.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
