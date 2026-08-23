# 0x001ea8e8 blowfish_ecb_hashed_key

| field | value |
|---|---|
| Original address | 0x001ea8e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ea8e8 |
| Resolved name | blowfish_ecb_hashed_key |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9b6c
**Callees:** FUN_00105dd8, FUN_00105e30, FUN_001e2304, FUN_001e2394, FUN_001e5104, FUN_001e5234, FUN_001e5854, FUN_001ea784, FUN_001ea804
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Derives a key by SHA-1-hashing two input pairs (param_3/4, param_5/6), then encrypts param_1 in 8-byte blocks via a keyed block-cipher round (FUN_001e5104) with endian transforms around each block.

## Notes / uncertainty
Blowfish-ECB (0x1048 key schedule = P[18]+S[4][256]) keyed by SHA-1(span_a||span_b) 20B digest; 8-byte block loop with bswap pre/post. Algorithm ID inferential from ctx size; encrypt/decrypt direction lives in FUN_001e5104 (not in set). Known-answer test would confirm.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ea8e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
