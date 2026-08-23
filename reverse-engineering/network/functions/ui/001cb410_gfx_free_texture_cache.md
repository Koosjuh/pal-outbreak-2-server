# 0x001cb410 gfx_free_texture_cache

| field | value |
|---|---|
| Original address | 0x001cb410 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb410 |
| Resolved name | gfx_free_texture_cache |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001cb490
**Referenced globals:** 0x36c570=texture cache table; 0x24c7f8=cache tag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates the 0xff-entry texture-cache table at 0x36c570 (0x10-byte slots), freeing each live entry (FUN_001cb490) and zeroing it.

## Notes / uncertainty
Frees live slots 1..255 (slot 0 skipped) via FUN_001cb490 then zeroes; tag=-1. FUN_001cb490 arg passed via register (dropped by decompiler).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
