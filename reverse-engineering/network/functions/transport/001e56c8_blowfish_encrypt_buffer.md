# 0x001e56c8 blowfish_encrypt_buffer

| field | value |
|---|---|
| Original address | 0x001e56c8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e56c8 |
| Resolved name | blowfish_encrypt_buffer |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9b6c
**Callees:** FUN_00105dd8, FUN_00105e30, FUN_001e2304, FUN_001e2394, FUN_001e4fd8, FUN_001e5234
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Encrypts a byte buffer (param_2->param_1): keys a fresh Blowfish ctx (e5234) and processes each 8-byte block with encrypt-block (e4fd8) plus endian swaps; returns padded length.

## Notes / uncertainty
Blowfish-ECB encrypt src->dst, returns padded length (nblocks*8). Sig (dst,src,len,key,keylen). Outbound reliable body path; source may be read to 8B alignment.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e56c8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
