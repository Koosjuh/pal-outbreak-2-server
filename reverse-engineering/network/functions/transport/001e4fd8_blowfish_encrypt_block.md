# 0x001e4fd8 blowfish_encrypt_block

| field | value |
|---|---|
| Original address | 0x001e4fd8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e4fd8 |
| Resolved name | blowfish_encrypt_block |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e5234, FUN_001e56c8
**Callees:** FUN_001e4ec8
**Referenced globals:** ctx P-array (ctx+0..0x44)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blowfish 64-bit block encrypt: 16 Feistel rounds over P-array[0..15] then final whitening with P[16]/P[17] (ctx+0x40/0x44).

## Notes / uncertainty
Blowfish 64-bit block encrypt, 16 Feistel rounds + P16/P17 whitening; ctx P-array at +0x00, S-boxes at 0x48/0x448/0x848/0xc48; F-func FUN_001e4ec8=(S0[a]+S1[b])^S2[c]+S3[d]. Algorithm-identified, not runtime-traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e4fd8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
