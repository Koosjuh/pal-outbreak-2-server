# 0x001ed584 pktbuf_get_f20

| field | value |
|---|---|
| Original address | 0x001ed584 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed584 |
| Resolved name | pktbuf_get_f20 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e19c4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x20

## Behavioral explanation
Getter: returns field buf+0x20 (a counter incremented by FUN_001ed5dc).

## Notes / uncertainty
Getter +0x20 = retransmit attempt counter; RTO estimator FUN_001e19c4 gates on >0 and uses as attempt multiplier. Estimator math (conn+0x510) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed584.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
