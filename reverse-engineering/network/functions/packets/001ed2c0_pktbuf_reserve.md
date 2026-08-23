# 0x001ed2c0 pktbuf_reserve

| field | value |
|---|---|
| Original address | 0x001ed2c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed2c0 |
| Resolved name | pktbuf_reserve |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5288, FUN_001d63b8, FUN_001d6ee0, FUN_001d9b6c, FUN_001db7e8, FUN_001dbefc, FUN_001dc0b8, FUN_001dc310, FUN_001dc508, FUN_001dc804, FUN_001dc9fc, FUN_001dcbf4, FUN_001dcdfc, FUN_001dd33c, FUN_001dd5f8, FUN_001dd840, FUN_001dda88, FUN_001ddee8, FUN_001de0c0, FUN_001de298, FUN_001de470, FUN_001de648, FUN_001de840, FUN_001de9e8, FUN_001ded08, FUN_001df044, FUN_001df1d8, FUN_001df380, FUN_001df66c, FUN_001dfbf8, FUN_001dfda0, FUN_001dff7c, FUN_001e0188, FUN_001e05c8, FUN_001e0774, FUN_001e094c, FUN_001e0ed8, FUN_001ed74c, FUN_001ed864
**Callees:** FUN_001ebca8, FUN_001ebcd0, FUN_001ed21c, FUN_001ed360
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Returns current tail; if param_2 bytes fit (FUN_001ed360) advances used-length by param_2 (grow payload), else returns 0.

## Notes / uncertainty
Bump-allocator append: returns pre-advance tail or 0 on overflow; advances used_len by param_2 iff pktbuf_fits. ~40 encoder callers. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed2c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
