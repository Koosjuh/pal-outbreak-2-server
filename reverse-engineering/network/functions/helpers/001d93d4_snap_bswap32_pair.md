# 0x001d93d4 snap_bswap32_pair

| field | value |
|---|---|
| Original address | 0x001d93d4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d93d4 |
| Resolved name | snap_bswap32_pair |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps two consecutive u32 words in place (ntohl/htonl on an 8-byte header field).

## Notes / uncertainty
In-place bswap32 of two consecutive words (htonl/ntohl on an 8-byte header field); host LE <-> big-endian SN@P wire. Called by header fix-up FUN_001d9f78. Which field unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d93d4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
