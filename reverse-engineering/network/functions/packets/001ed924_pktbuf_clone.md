# 0x001ed924 pktbuf_clone

| field | value |
|---|---|
| Original address | 0x001ed924 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed924 |
| Resolved name | pktbuf_clone |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** FUN_001069a8, FUN_001ebbd0, FUN_001ebc10, FUN_001ebca8, FUN_001ebcd0, FUN_001ebd04
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length; buf+0x10 header

## Behavioral explanation
Duplicates a packet: copies header+payload (from +0x10, used+0x1c bytes) into dest, then sets dest length, 0xffff field, and copies the FUN_001ebbd0 field.

## Notes / uncertainty
Deep-copies header(0x10..0x2c,=0x1c)+payload, sets len, resets+copies flags; bounds error 0xffffe0c2. Establishes the header block that contains f24/f28. Metadata below +0x10 not cloned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed924.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
