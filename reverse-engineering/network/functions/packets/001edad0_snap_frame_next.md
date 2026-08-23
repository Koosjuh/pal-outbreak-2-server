# 0x001edad0 snap_frame_next

| field | value |
|---|---|
| Original address | 0x001edad0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001edad0 |
| Resolved name | snap_frame_next |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_001069a8, FUN_001ebca8, FUN_001ed6bc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Given a frame at param_2, reads its 0x10-byte header, and returns pointer to the next frame (param_2 + len&0x3ff) if >=0x10 payload remains, else 0.

## Notes / uncertainty
Frame iterator: header copy (opt out-param), step by len&0x3ff, return 0 when <0x10 bytes remain (end of chain).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001edad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
