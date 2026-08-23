# 0x001c3750 packet_decrypt_checksum

| field | value |
|---|---|
| Original address | 0x001c3750 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3750 |
| Resolved name | packet_decrypt_checksum |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c3b90
**Callees:** FUN_00106b60, FUN_0010a050, FUN_001c3490
**Referenced globals:** —
**Referenced strings:** TUlOQU1JT0g (crypto key)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
In-place XOR de-obfuscation of a received payload (same 'MINAMIOH' keystream) returning the recomputed 15-bit checksum for verification.

## Notes / uncertainty
In-place inverse of 0x1c3650; sums plaintext post-decrypt so checksums match; NULL->0xffffffff; caller (0x1c3b90) accept/reject behavior not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
