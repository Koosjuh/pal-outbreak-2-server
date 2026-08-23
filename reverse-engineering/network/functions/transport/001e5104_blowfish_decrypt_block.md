# 0x001e5104 blowfish_decrypt_block

| field | value |
|---|---|
| Original address | 0x001e5104 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5104 |
| Resolved name | blowfish_decrypt_block |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e5538, FUN_001ea8e8
**Callees:** FUN_001e4ec8
**Referenced globals:** ctx P-array
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blowfish 64-bit block decrypt: 16 Feistel rounds over P-array[17..2] then final whitening with P[1]/P[0].

## Notes / uncertainty
Inverse of e4fd8; reverse subkey order P[17..2] then P[1]/P[0] whitening; ctx word-addressed. Certain by structure.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5104.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
