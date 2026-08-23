# 0x001d0510 decode_member_grid_8row

| field | value |
|---|---|
| Original address | 0x001d0510 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0510 |
| Resolved name | decode_member_grid_8row |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d09e0
**Callees:** FUN_00188a30, FUN_00188ad0
**Referenced globals:** iRam003435bc work base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Decodes a packed member record set (param_4 = count/offset pairs) into an 8-row display grid at param_2, interning name ids via thunk_FUN_00198d30/FUN_00188a30 and freeing old ids with FUN_00188ad0.

## Notes / uncertainty
Render-side unpack (not wire parser): {count,index_off} descriptors -> 8-row grid, interning glyph handles (FUN_00188a30/ad0) with -1 sentinel for empty/already-interned. Whether records are member names vs generic text not proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
