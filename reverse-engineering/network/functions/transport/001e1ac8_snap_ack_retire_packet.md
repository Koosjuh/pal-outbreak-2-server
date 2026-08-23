# 0x001e1ac8 snap_ack_retire_packet

| field | value |
|---|---|
| Original address | 0x001e1ac8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1ac8 |
| Resolved name | snap_ack_retire_packet |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d6988
**Callees:** FUN_001e19c4, FUN_001eb4dc, FUN_001eb784, FUN_001ebbd0, FUN_001ec9e0
**Referenced globals:** conn+0x60 TX pool; conn+0x520 pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node flag 0x800

## Behavioral explanation
Pops an acked/received node from the socket queue (struct+8, falling back to conn+0x60), tags it 0x800, updates rate accounting (e19c4), and returns it to the pool.

## Notes / uncertainty
Renamed from snap_ack_dequeue_process: retires the in-flight packet matching acked seq param_3 (search primary list via comparator 0x1edfd0, fallback conn+0x60), marks 0x800, unlinks, RTT-accounts (e19c4), frees conn+0x520. param_2 list identity and param_4 sample units inferred from single caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1ac8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
