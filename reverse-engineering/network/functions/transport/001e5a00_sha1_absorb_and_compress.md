# 0x001e5a00 sha1_absorb_and_compress

| field | value |
|---|---|
| Original address | 0x001e5a00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5a00 |
| Resolved name | sha1_absorb_and_compress |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ea784, FUN_001ea804
**Callees:** FUN_001069a8, FUN_001e5934
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
SHA-1 compression: buffers input into a 64-byte block, expands the 80-word schedule and runs the 4-round mix (constants 0x5a827999/0x6ed9eba1/0x8f1bbcdc/0xca62c1d6), updating the 5-word state.

## Notes / uncertainty
Renamed from sha1_transform_block: buffering+compression core. Args (ctx, &cursor, &remaining, finalize); returns true when finalize needs a 2nd (length-only) block. 80 rounds unrolled in raw; reconstructed as canonical loop (behaviorally equivalent, raw is ground truth for byte-exact reimpl).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
