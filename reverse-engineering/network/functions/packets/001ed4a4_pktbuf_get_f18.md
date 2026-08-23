# 0x001ed4a4 pktbuf_get_f18

| field | value |
|---|---|
| Original address | 0x001ed4a4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed4a4 |
| Resolved name | pktbuf_get_f18 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001e19c4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x18

## Behavioral explanation
Getter: returns header field at buf+0x18.

## Notes / uncertainty
Getter +0x18; used as send-time base in retransmit due-time (FUN_001d5460) and RTO estimator (FUN_001e19c4) -> [inferred] last-send timestamp. Clock units unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed4a4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
