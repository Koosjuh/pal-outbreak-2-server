# 0x005c8ed0 session_arena_stream_reset

| field | value |
|---|---|
| Original address | 0x005c8ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8ed0 |
| Resolved name | session_arena_stream_reset |
| Subsystem | initialization |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005c9130, FUN_005c92d0, FUN_005d8b00, FUN_005dd920
**Referenced globals:** 0x701068 (arena); 0x701068+0x60dd0 (out-stream buf, 0x8000); 0x701068+0x68dd4 (write ptr); 0x701070 (state struct defaults)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Full reset of the session arena: zeroes sub-buffers, frees+reallocs the 500-slot message pool (92d0/9130), seeds a fresh out-stream, defaults, and registers handler/timer entries via FUN_005dd920.

## Notes / uncertainty
Already fully reconstructed (name refined from full_reset -> stream_reset). Resets out-stream substate only; cfg ids 0x5e-0x63 are config slots not wire opcodes; no direct callers in xref table.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
