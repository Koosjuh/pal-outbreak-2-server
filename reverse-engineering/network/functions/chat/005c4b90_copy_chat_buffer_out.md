# 0x005c4b90 copy_chat_buffer_out

| field | value |
|---|---|
| Original address | 0x005c4b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4b90 |
| Resolved name | copy_chat_buffer_out |
| Subsystem | chat |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b53f0
**Callees:** —
**Referenced globals:** 0x6fc05a chat-buf src
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-copies 296 bytes (0x94*2) from chat buffer 0x6fc05a into caller's dst (snapshot for render).

## Notes / uncertainty
Pure 296-byte (0x94*2) snapshot copy from chat buffer 0x6fc05a to caller dst; unrolled 2-byte loop, no branches. Internal chat-buffer record layout not mapped (not needed for the copy).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
