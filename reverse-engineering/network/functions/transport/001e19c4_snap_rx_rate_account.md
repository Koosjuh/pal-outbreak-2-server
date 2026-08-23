# 0x001e19c4 snap_rx_rate_account

| field | value |
|---|---|
| Original address | 0x001e19c4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e19c4 |
| Resolved name | snap_rx_rate_account |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e1ac8
**Callees:** FUN_001eb088, FUN_001ebca8, FUN_001ed4a4, FUN_001ed4fc, FUN_001ed584
**Referenced globals:** conn+0x510 window; conn+0x4fc stat ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x510 rate-window

## Behavioral explanation
Rate/throughput accounting on a received packet: computes a delta from packet timestamps and per-conn window (conn+0x510/+0x4fc) and feeds FUN_001eb088 (congestion/RTT bookkeeping).

## Notes / uncertainty
Rate/congestion estimator sample from pkt counters into conn+0x510/+0x4fc; packet counter fields (A/count/C) not mapped to named headers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e19c4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
