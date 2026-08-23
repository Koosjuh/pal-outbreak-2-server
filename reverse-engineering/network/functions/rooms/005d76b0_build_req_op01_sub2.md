# 0x005d76b0 build_req_op01_sub2

| field | value |
|---|---|
| Original address | 0x005d76b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d76b0 |
| Resolved name | build_req_op01_sub2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cccf0
**Callees:** FUN_005d6630, FUN_005d7310, FUN_005d7410, FUN_005df7b0
**Referenced globals:** 0x004f694 txn head; 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** 0x01
**State vars:** —

## Behavioral explanation
Builds an opcode 0x01 subtype 2 txn record for the current room, copies who-bytes; if FUN_005df7b0(room) reports not-ready sets state 6 with error class 0x124=2.

## Notes / uncertainty
op01/subtype2 per-room detail query (from roomlist_query_dispatch); no seq/pending-kind write; demotes record to error state 6 / err-class 2 when FUN_005df7b0 says room not ready. sub2 pump routing not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d76b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
