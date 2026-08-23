# 0x001ec9e0 subpool_free

| field | value |
|---|---|
| Original address | 0x001ec9e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ec9e0 |
| Resolved name | subpool_free |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5138, FUN_001d5288, FUN_001d5ae4, FUN_001d6468, FUN_001d6988, FUN_001d6dfc, FUN_001d72a8, FUN_001d9b6c, FUN_001db7e8, FUN_001dbefc, FUN_001dc0b8, FUN_001dc310, FUN_001dc508, FUN_001dc804, FUN_001dc9fc, FUN_001dcbf4, FUN_001dcdfc, FUN_001dd33c, FUN_001dd5f8, FUN_001dd840, FUN_001dda88, FUN_001ddee8, FUN_001de0c0, FUN_001de298, FUN_001de470, FUN_001de648, FUN_001de840, FUN_001de9e8, FUN_001ded08, FUN_001df044, FUN_001df1d8, FUN_001df66c, FUN_001dfbf8, FUN_001dfda0, FUN_001e0188, FUN_001e05c8, FUN_001e0774, FUN_001e094c, FUN_001e0ed8, FUN_001e14e8, FUN_001e1608, FUN_001e1ac8, FUN_001e2654, FUN_001e366c, FUN_001e3880, FUN_001e3a3c
**Callees:** FUN_001eb2d4, FUN_001eb2fc, FUN_001eb37c, FUN_001eb3b8, FUN_001ebc74, FUN_001ebd04, FUN_001ed034
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x40/0x48/0x50 free counters; +0x70/0x72/0x74 watermarks

## Behavioral explanation
Returns a buffer to its tier: validates it (FUN_001ed034), matches its capacity to one of the three tier MTUs (0xec/0x22c/0x3ac), tags the tier id, re-inserts it, bumps the free counter, and clears the high-water latch once the tier refills above threshold.

## Notes / uncertainty
Returns buf to tier by capacity==MTU match; bumps free counter; clears watermark latch (eb37c) when depth rises strictly above high-water (hysteresis vs alloc). Un-latch side that resumes op49; unfreed conn+0x520 buf keeps tier2 drained. cap tests are sequential not if/else.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ec9e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
