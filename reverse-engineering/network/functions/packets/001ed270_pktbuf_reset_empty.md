# 0x001ed270 pktbuf_reset_empty

| field | value |
|---|---|
| Original address | 0x001ed270 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed270 |
| Resolved name | pktbuf_reset_empty |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ebcd0, FUN_001ed21c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Sets used-length=0 and recomputes tail pointer — empties the payload without freeing the buffer.

## Notes / uncertainty
Sets used_len(+0x0c)=0 and recomputes tail (return discarded). Straight-line; header size 0x2c corroborated. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
