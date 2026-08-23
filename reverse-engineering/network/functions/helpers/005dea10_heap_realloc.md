# 0x005dea10 heap_realloc

| field | value |
|---|---|
| Original address | 0x005dea10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dea10 |
| Resolved name | heap_realloc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005de880, FUN_005de8d0, FUN_005de9a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
malloc/free/realloc front-end: size==0 frees, ptr==0 allocs, else finds old block, allocs new (0x10-aligned), copies min(old,new) and frees old.

## Notes / uncertainty
UPGRADED from classified to full reconstruction. Latent bug found: entry alignment (always +16) makes the size==0/free branch DEAD CODE. Non-destructive on failure; alloc-new-before-free-old makes min(old,new) memcpy safe. func_0x00106a58 assumed memcpy.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dea10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
