# 0x005d7420 build_req_op01

| field | value |
|---|---|
| Original address | 0x005d7420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7420 |
| Resolved name | build_req_op01 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d6630, FUN_005d7410
**Referenced globals:** 0x004f694 txn head; 0x00701010 seq; 0x00701000 pending kind
**Referenced strings:** —
**Referenced opcodes:** 0x01
**State vars:** cRam00701010; uRam00701000

## Behavioral explanation
Builds a txn record with opcode 0x01 subtype 1 for the current room payload, stamps seq byte, who-byte 0; sets pending kind=1.

## Notes / uncertainty
op01/sub1 builder, kind1, seq stamped, who-hi=0. Zero direct callers (reached indirectly); op01 exact wire role loosely defined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
