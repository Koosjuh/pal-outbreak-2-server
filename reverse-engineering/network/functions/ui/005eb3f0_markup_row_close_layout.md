# 0x005eb3f0 markup_row_close_layout

| field | value |
|---|---|
| Original address | 0x005eb3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb3f0 |
| Resolved name | markup_row_close_layout |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005f10a0
**Referenced globals:** +0xd892 (depth); +0xd894; +0x186 (mode); +0x24e0..+0x2512 (cell struct); +0x182 (page width)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x186

## Behavioral explanation
Type-2 element close (table mode only): closes via FUN_005f10a0(...,2), accumulates child height into parent (+0x2e/+0x24), recomputes min widths (+0x24fc/+0x1c) and max page width (+0x182), decrements table depth.

## Notes / uncertainty
Type-2/row close: folds height/width into parent obj (+0x2e/+0x24/+0x1c), raises page width in measure pass, decrements depth. Does NOT commit to doc flow. Parent field semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb3f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
