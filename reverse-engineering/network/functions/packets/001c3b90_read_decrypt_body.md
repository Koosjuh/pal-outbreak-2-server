# 0x001c3b90 read_decrypt_body

| field | value |
|---|---|
| Original address | 0x001c3b90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3b90 |
| Resolved name | read_decrypt_body |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4960, FUN_001c4d40, FUN_001c5260, FUN_001c56f0, FUN_001c5a20, FUN_001c5c90, FUN_001c6130, FUN_001c65c0, FUN_001c6840, FUN_001c6c60, FUN_001c70b0, FUN_001c7a70, FUN_001c8790, FUN_001c8eb0, FUN_001c9030, FUN_001c91d0, FUN_001c92d0, FUN_001c95e0
**Callees:** FUN_001069a8, FUN_00106b60, FUN_001c3750, FUN_001c3ab0
**Referenced globals:** obj+0x34 rx-buf; obj+0x40 cursor; obj+0x30 hdr; obj+0x4c seed
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x40 cursor

## Behavioral explanation
Reads an encrypted framed body: be16 length + be16 expected-checksum, copies/zero-pads into caller buffer, decrypts via FUN_001c3750 and validates checksum (returns -1/-2/-3 on hdr/overflow/checksum error) advancing cursor on success.

## Notes / uncertainty
Per-segment decrypt+verify (18 reply-parser callers): be16 len(-2 checksum) + be16 expected-ck, memcpy from obj+0x34+cursor, zero-pad, FUN_001c3750 decrypt keyed by hdr[5]+seed obj+0x4c, compare checksum; ret len / -1 hdr / -2 overflow / -3 ck-fail; advances cursor on success. Cipher primitive 3750 not in set (likely keystream-XOR+checksum).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
