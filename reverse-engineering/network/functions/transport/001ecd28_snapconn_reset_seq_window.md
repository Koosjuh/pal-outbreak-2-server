# 0x001ecd28 snapconn_reset_seq_window

| field | value |
|---|---|
| Original address | 0x001ecd28 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ecd28 |
| Resolved name | snapconn_reset_seq_window |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d4fa4, FUN_001ebed0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x3c..+0x58 counters; conn+0x5c/+0x62/+0x68 base seq; conn+0x60/+0x66/+0x6c cursor

## Behavioral explanation
Zeroes conn+0x3c..+0x58 and seeds +0x60=+0x5c, +0x66=+0x62, +0x6c=+0x68 (re-arm the three reorder/ack windows to their base seqs).

## Notes / uncertainty
Zeroes +0x3c..+0x58, seeds 3 channel cursors=bases (+0x60/66/6c from +0x5c/62/68); base/cursor naming inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ecd28.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
