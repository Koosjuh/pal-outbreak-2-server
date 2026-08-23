# 0x005d8340 txn_complete_dispatch

| field | value |
|---|---|
| Original address | 0x005d8340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8340 |
| Resolved name | txn_complete_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8ae0, FUN_005c8bc0, FUN_005c8d10, FUN_005c8e70, FUN_005ca560, FUN_005ca640, FUN_005cc980, FUN_005cce30
**Callees:** FUN_005d6710, FUN_005d6920, FUN_005d6c90, FUN_005d6ce0, FUN_005d7a30, FUN_005d81b0, FUN_005de660, FUN_005dedc0
**Referenced globals:** 0x004f694 txn head; 0x004f588 roomlist head; 0x00701004 result ptr; 0x00700ff8 result flag; 0x00701008/09/0a/0c reply status bytes
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00700ff8; iRam00701004; uRam00701008; node+0x104 state

## Behavioral explanation
Scans the txn queue for a record matching a key; on state 6 (finished) routes the result by subtype and status: commits into the room list (FUN_005d6920), sets global result flags/pointer (0x701004/0700ff8) and builds an HTML page for status 0..9, freeing session nodes; on state 5 (partial) copies who/handle back and republishes.

## Notes / uncertainty
Inbound reply router: key-match scan, state-6/state-5 handling by subtype 0x01/0x02 & status byte 0x124; commits into roomlist 0x4f588, publishes 0x701004/0700ff8/701008.. and builds result page 0x4d15c. status codes beyond 4/8/9 grouped; who/handle widths inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
