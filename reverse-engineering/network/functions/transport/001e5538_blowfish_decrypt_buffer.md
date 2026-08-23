# 0x001e5538 blowfish_decrypt_buffer

| field | value |
|---|---|
| Original address | 0x001e5538 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5538 |
| Resolved name | blowfish_decrypt_buffer |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9678, FUN_001d9b6c
**Callees:** FUN_00105dd8, FUN_00105e30, FUN_001e2304, FUN_001e2394, FUN_001e5104, FUN_001e5234
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Decrypts a byte buffer in place: allocates a Blowfish ctx (0x1048), keys it (e5234), then for each 8-byte block byteswaps in, runs decrypt-block (e5104), byteswaps out.

## Notes / uncertainty
In-place Blowfish-ECB decrypt, per-call re-key (malloc 0x1048), ceil(len/8) blocks with bswap in/out (e2394/e2304). Sig (buf,key,len,keylen). Inbound body path.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5538.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
