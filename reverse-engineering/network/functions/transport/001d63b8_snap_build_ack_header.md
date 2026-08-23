# 0x001d63b8 snap_build_ack_header

| field | value |
|---|---|
| Original address | 0x001d63b8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d63b8 |
| Resolved name | snap_build_ack_header |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_001ed2c0, FUN_001ed60c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x44 peer id

## Behavioral explanation
Builds a standalone ack packet header 0x6010 (0x6000|0x10), stamps its seq from the source packet and the peer id from conn+0x44.

## Notes / uncertainty
Builds bare 16-byte unreliable ACK (header word 0x6010 = 0x6000|0x10): ack_base from conn+0x44 at +0x04, packet seq at +0x0c, rest zero. No-op if ed2c0 reserve fails. Matches op0x60 ack anchor.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d63b8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
