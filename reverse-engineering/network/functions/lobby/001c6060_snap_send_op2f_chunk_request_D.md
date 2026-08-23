# 0x001c6060 snap_send_op2f_chunk_request_D

| field | value |
|---|---|
| Original address | 0x001c6060 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6060 |
| Resolved name | snap_send_op2f_chunk_request_D |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** 0x365d74 ids; 0x365db4 idx; 0x365db8 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2f
**State vars:** conn+0xd next-state=0x2c

## Behavioral explanation
Emits opcode 0x2f chunk-fetch: appends current slot-id (0x365d74[idx]), offset (0x365db8), window 0x2d2; advances to state 0x2c.

## Notes / uncertainty
Sender of machine-D 0x2f chunk request (slot_id,offset,window=0x2d2 → state 0x2c). Framing primitives (hdr_begin/put_u32_be/put_u16_be/transmit) read directly and grounded. Lobby payload identity unconfirmed; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
