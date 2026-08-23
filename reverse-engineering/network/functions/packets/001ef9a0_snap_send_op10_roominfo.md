# 0x001ef9a0 snap_send_op10_roominfo

| field | value |
|---|---|
| Original address | 0x001ef9a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef9a0 |
| Resolved name | snap_send_op10_roominfo |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e332c
**Callees:** FUN_001069a8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37cf1e (len, 2B); 0x37cf20 (payload); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x10
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x10 (room-info) carrying a caller data buffer (clamped 0xc00), returns result.

## Notes / uncertainty
Sema-guarded transport RPC stub (op 0x10 send, room-info sub-selector). Publishes id/len/payload to TX scratch 0x37cf00, runs FUN_001ef400->FUN_00115c68 txn, returns 16-bit reply status word; no reply body copied (send half; reply fetched via op12/op13). Clamp 0xc00, header overhead 0x26. Uncertain: status word = byte-count vs ack.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef9a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
