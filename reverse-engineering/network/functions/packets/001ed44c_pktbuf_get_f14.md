# 0x001ed44c pktbuf_get_f14

| field | value |
|---|---|
| Original address | 0x001ed44c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed44c |
| Resolved name | pktbuf_get_f14 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x14

## Behavioral explanation
Getter: returns header field at buf+0x14.

## Notes / uncertainty
Getter +0x14; due-time term f18+f14+f1c in retransmit engine FUN_001d5460 -> [inferred] base RTO/delay. Timing role inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed44c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
