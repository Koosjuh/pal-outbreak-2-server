# 0x001cb3b0 gfx_reset_texture_cache_and_heap_window

| field | value |
|---|---|
| Original address | 0x001cb3b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb3b0 |
| Resolved name | gfx_reset_texture_cache_and_heap_window |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60
**Referenced globals:** 0x36c560=texture cache; 0x24c7f8=cache tag; 0x3435bc=heap base; 0x36b9c0/b8=heap window
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes a 0x1000-byte texture-cache table at 0x36c560 and initializes its heap window pointers from 0x3435bc.

## Notes / uncertainty
memset(0x36c560,0,0x1000) 256-slot cache + tag=-1 + heap window [base,base+0x10000). Per-slot field layout beyond +0=handle inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
