# 0x001d6988 snap_recv_accept_reorder_gate

| field | value |
|---|---|
| Original address | 0x001d6988 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d6988 |
| Resolved name | snap_recv_accept_reorder_gate |
| Subsystem | transport |
| Relevance | unknown |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Confirmed |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001069a8, FUN_001e16b4, FUN_001e1ac8, FUN_001eb3b8, FUN_001ebcd0, FUN_001ec1f8, FUN_001ec9e0, FUN_001ed21c, FUN_001ed634, FUN_001ed68c, FUN_001ed6bc, FUN_001ed74c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
(pending)

## Notes / uncertainty
Core RX accept: 0x4000 ack-consume, reorder gate (expected_seq <= seq), 0x800 aggregate unpack (<=56 subsegs, err 0x1771-0x1774). Gate runtime-confirmed on rig; aggregate path decompile-only (not seen in PAL create traffic).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d6988.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Confirmed**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
