# 0x001c3650 packet_encrypt_checksum

| field | value |
|---|---|
| Original address | 0x001c3650 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3650 |
| Resolved name | packet_encrypt_checksum |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c3f40
**Callees:** FUN_00106b60, FUN_0010a050, FUN_001c3490
**Referenced globals:** —
**Referenced strings:** TUlOQU1JT0g (base64 crypto key -> 'MINAMIOH')
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
XOR-obfuscates a payload with a keystream (base64-decoded key 'MINAMIOH' XOR seq/seed bytes) while accumulating a 15-bit checksum returned to the caller.

## Notes / uncertainty
Outbound XOR obfuscation: dst=src^key[i&7]^(seed+seq+i), key='MINAMIOH' (b64 TUlOQU1JT0g), checksum=(sum_plaintext+seq*0x101)&0x7fff; NULL->0xffffffff; unvalidated on live wire.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
