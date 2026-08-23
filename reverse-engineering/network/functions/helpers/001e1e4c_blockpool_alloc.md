# 0x001e1e4c blockpool_alloc

| field | value |
|---|---|
| Original address | 0x001e1e4c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1e4c |
| Resolved name | blockpool_alloc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec, FUN_001d51e0, FUN_001e1468, FUN_001e1590, FUN_001eb1b0, FUN_001eba40, FUN_001ebed0
**Callees:** FUN_00102648
**Referenced globals:** 0x36d758 arena; 0x36d75c block-size hdr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** block magic 0xfafafafa/0xfbfbfbfb

## Behavioral explanation
First-fit allocator over the 52000-byte arena: rounds size to 0x20, walks blocks by magic (free 0xfafafafa->0xfbfbfbfb allocated), splits the block and returns a payload pointer.

## Notes / uncertainty
First-fit allocator over 52000-byte arena @0x36d758; 8-byte header [magic,size], FREE=0xfafafafa/ALLOC=0xfbfbfbfb, 0x20 round-up, splits remainder. No coalescing. Which pool it backs unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1e4c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
