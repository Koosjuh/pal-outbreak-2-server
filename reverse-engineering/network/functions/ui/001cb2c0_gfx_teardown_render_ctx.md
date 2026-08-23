# 0x001cb2c0 gfx_teardown_render_ctx

| field | value |
|---|---|
| Original address | 0x001cb2c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb2c0 |
| Resolved name | gfx_teardown_render_ctx |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001cbae0
**Referenced globals:** 0x36b900=render ctx; 0x36b920=ctx struct; 0x343575=mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x343575=mode flag

## Behavioral explanation
Tears down the 0x36b920 render context (frees GS allocation via FUN_001cbae0, zeroes the 0x98-byte struct), or defers to an external routine when the mode flag is set.

## Notes / uncertainty
Frees GS/VRAM (FUN_001cbae0(0xFF0,1)) and memsets the 0x98-byte ctx when initialized+allocated, or delegates to external 0x3ACCE0 when mode flag 0x343575 set. Mirror of init; non-protocol.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb2c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
