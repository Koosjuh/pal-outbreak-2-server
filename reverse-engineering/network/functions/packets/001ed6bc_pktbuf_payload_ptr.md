# 0x001ed6bc pktbuf_payload_ptr

| field | value |
|---|---|
| Original address | 0x001ed6bc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed6bc |
| Resolved name | pktbuf_payload_ptr |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001d6468, FUN_001d6988, FUN_001ed7e0, FUN_001ed864, FUN_001edad0, FUN_001edbb8, FUN_001edd9c, FUN_001ee060
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns payload base = buf+0x2c.

## Notes / uncertainty
Returns b+0x2c payload base. Anchors whole layout; 0x2c header size locked across the family.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed6bc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
