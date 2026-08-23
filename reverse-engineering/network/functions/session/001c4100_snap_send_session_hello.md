# 0x001c4100 snap_send_session_hello

| field | value |
|---|---|
| Original address | 0x001c4100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4100 |
| Resolved name | snap_send_session_hello |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001bf2e0, FUN_001c3840, FUN_001c3ab0, FUN_001c3c90, FUN_001c3da0, FUN_001c4020, FUN_001ee590
**Referenced globals:** conn+0x4c session-key; conn+0xd next-state; 0x35ba80 client-flags; 0x343571 cap-flag
**Referenced strings:** 0x3c9580; 0x245e38
**Referenced opcodes:** 0x00
**State vars:** conn+0x4c session-key; conn+0xd next-state=0x36

## Behavioral explanation
Builds the session open/register handshake: derives+stores the session key at conn+0x4c (FUN_001c3ab0), emits selector(0,2) with two config strings and a capability/flags byte, transmits, advances to state 0x36.

## Notes / uncertainty
Rewrote: opcode-0 who=2 hello. Latches session key conn+0x4c from leading RX u16 (feeds every field checksum), packs identity(0x3c9580)+version(0x245e38)+flags, cap bit 0x4 from 0x343571, ->state 0x36. fill_local_identity field split inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
