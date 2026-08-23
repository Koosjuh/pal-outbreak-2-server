# 0x005d74a0 build_req_op03

| field | value |
|---|---|
| Original address | 0x005d74a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d74a0 |
| Resolved name | build_req_op03 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca380, FUN_005d3930, FUN_005d47f0, FUN_005d5640, FUN_005d5900
**Callees:** FUN_005d6630, FUN_005d6a10, FUN_005d7410
**Referenced globals:** 0x004f694 txn head; 0x00701010 seq; 0x00701000 pending kind
**Referenced strings:** —
**Referenced opcodes:** 0x03
**State vars:** cRam00701010; uRam00701000

## Behavioral explanation
Builds a txn record opcode 0x03 subtype 1 for the current room payload, stamps seq, then FUN_005d6a10(record+0x108,1,1) to register a slot; sets pending kind=2.

## Notes / uncertainty
op03/sub1 builder (widest caller set, 5), kind2, plus slot-register bit via FUN_005d6a10. Slot-table target and op03 server semantics not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d74a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
