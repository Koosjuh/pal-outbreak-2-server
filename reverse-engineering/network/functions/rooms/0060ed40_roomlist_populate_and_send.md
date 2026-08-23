# 0x0060ed40 roomlist_populate_and_send

| field | value |
|---|---|
| Original address | 0x0060ed40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060ed40 |
| Resolved name | roomlist_populate_and_send |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006101d0
**Callees:** FUN_0060eaa0, FUN_0060eba0, FUN_0060ec60, FUN_006157e0, FUN_006159c0, FUN_006166f0
**Referenced globals:** ctx+0x19ad0 (entry count); ctx+0x19af4/0x19ae0/0x19ae8 (transport conn/args); ctx+0x9d80 (room-record array base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x19ad0 count

## Behavioral explanation
Zeroes the room-list region (+0x9d80,0xc080B), then for each of *(+0x19ad0) entries inits a 0x1340-byte record (FUN_006166f0) and issues a transport send/poll (FUN_006159c0 then spin FUN_006157e0).

## Notes / uncertainty
Per-room fill loop: clears record array (+0x9d80,0xc080), 3 ctx builders, then for each of +0x19ad0 entries reset record + net_request_issue_t2 (retry<0) + net_request_poll (until 0). Record stride 0x1340, src stride 0x240. build_ctx helpers + func_0x00112b20 undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060ed40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
