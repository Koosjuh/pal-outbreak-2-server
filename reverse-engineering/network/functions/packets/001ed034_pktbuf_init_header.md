# 0x001ed034 pktbuf_init_header

| field | value |
|---|---|
| Original address | 0x001ed034 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed034 |
| Resolved name | pktbuf_init_header |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec9e0, FUN_001ed0bc
**Callees:** FUN_001ebc10, FUN_001ebcd0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x10..+0x28 header; buf used-length; buf+? =0xffff

## Behavioral explanation
Zeroes packet header fields +0x10..+0x28, sets used-length=0 (FUN_001ebcd0) and a 16-bit field to 0xffff (FUN_001ebc10) — initialize a fresh packet buffer.

## Notes / uncertainty
Reset allocated pktbuf node: zero header +0x10..+0x28, used-length(+0xc)=0, clear flags(+0xe) via &~0xffff. Payload base +0x2c (cross-checked w/ pktbuf_tail_ptr). Always returns 0.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed034.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
