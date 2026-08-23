# 0x001d5460 snap_retransmit_scan

| field | value |
|---|---|
| Original address | 0x001d5460 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5460 |
| Resolved name | snap_retransmit_scan |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001eb2d4, FUN_001eb3b8, FUN_001eb4dc, FUN_001ebbd0, FUN_001ebc10, FUN_001ebd54, FUN_001ebd7c, FUN_001ed44c, FUN_001ed4a4, FUN_001ed4fc, FUN_001ed524, FUN_001ed5dc, FUN_001ed634
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x50c err (200/300); conn+0x518 max-retries

## Behavioral explanation
Walks the in-flight/unacked queue (conn+0x58), and for packets whose cumulative size fits the window it checks the resend counter against conn+0x518, bumps retry timers, and requeues onto the send list; overflow sets error 300/200 at conn+0x50c.

## Notes / uncertainty
Retransmit engine: param_2=now; moves timed-out in-flight nodes (conn+0x58) back to send pool (conn+0x60), re-arming flags 0x400/0x1000, timer+200, seq cleared. Errors 300 (retry cap conn+0x518) / 200 (queue) in conn+0x50c. The three ed4a4/44c/4fc accessors interpreted as timer components (vs size) from the now-comparison — not individually traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
