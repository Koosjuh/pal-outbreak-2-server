# 0x001d53cc snap_now_ms

| field | value |
|---|---|
| Original address | 0x001d53cc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d53cc |
| Resolved name | snap_now_ms |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8, FUN_001db7e8
**Callees:** FUN_0010ea10, FUN_001e41fc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads the system clock and returns a millisecond timestamp (sec*1000 + ms).

## Notes / uncertainty
ms timestamp = sec*1000 + scale(sub_second,1000); returns 1 on clock-read failure. Used by retransmit/keepalive timers. Sub-second units (ns vs ticks) and wall vs monotonic unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d53cc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
