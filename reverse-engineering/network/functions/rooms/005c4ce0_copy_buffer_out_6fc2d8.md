# 0x005c4ce0 copy_buffer_out_6fc2d8

| field | value |
|---|---|
| Original address | 0x005c4ce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4ce0 |
| Resolved name | copy_buffer_out_6fc2d8 |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b5fb0
**Callees:** —
**Referenced globals:** 0x6fc2d8 list-buf src
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-copies 784 bytes (0x188*2) from table 0x6fc2d8 into caller's dst (snapshot of a room/list buffer).

## Notes / uncertainty
Fixed 784-byte memcpy from 0x6fc2d8 to caller dst (unrolled halfword copy). Renamed away from 'roomlist' claim: buffer identity (room-list page vs display scratch) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4ce0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
