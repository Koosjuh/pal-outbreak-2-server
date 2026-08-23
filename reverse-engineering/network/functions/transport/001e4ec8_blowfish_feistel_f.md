# 0x001e4ec8 blowfish_feistel_f

| field | value |
|---|---|
| Original address | 0x001e4ec8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e4ec8 |
| Resolved name | blowfish_feistel_f |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e4fd8, FUN_001e5104
**Callees:** —
**Referenced globals:** ctx+0x48.. Blowfish S-boxes
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blowfish F-function: four S-box lookups (offsets 0x48/0x448/0x848/0xc48) combined ((S0+S1)^S2)+S3 over the four input bytes.

## Notes / uncertainty
Canonical Blowfish F ((S0[a]+S1[b])^S2[c])+S3[d]; ctx = 18-word P-array +0x00 then 4x0x400 S-boxes. Encrypted payload scope/key-seed outside this leaf.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e4ec8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
