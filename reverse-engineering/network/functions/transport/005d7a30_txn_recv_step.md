# 0x005d7a30 txn_recv_step

| field | value |
|---|---|
| Original address | 0x005d7a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7a30 |
| Resolved name | txn_recv_step |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8340
**Callees:** FUN_005d6b40, FUN_005d6ce0, FUN_005d7310, FUN_005df7b0, FUN_0060d4f0, FUN_0060dea0
**Referenced globals:** 0x004f47c roster pool head; 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** record+0x104 state; record+0x114 recv-len

## Behavioral explanation
Drives the receive side of a txn record: per mode char (FUN_005df7b0) calls FUN_0060dea0/FUN_0060d4f0 to read a datagram into +0x118/+0x11a; on -3/-2 (fatal) sets state 6, on success stores length at +0x114, and drops stale roster nodes whose id collides.

## Notes / uncertainty
Txn-record recv step: mode 3=recv_connected(60dea0), 2=recvfrom(60d4f0), 4-byte hdr into +0x118/+0x11a. -3/-2 fatal->state6; >=0 data->len@+0x114 return 0; -1 no-data->prune stale roster-pool(0x4f47c) nodes on seq collision (node+0x108). Field 0x118/0x11a semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
