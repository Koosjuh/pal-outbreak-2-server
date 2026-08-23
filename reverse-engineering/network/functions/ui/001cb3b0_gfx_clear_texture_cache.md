# 0x001cb3b0 gfx_clear_texture_cache

| field | value |
|---|---|
| Original address | 0x001cb3b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb3b0 |
| Resolved name | gfx_reset_texture_cache_and_heap_window |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60 (memset)
**Referenced globals:** 0x36c560 (texture-cache table, 256 x 0x10 = 0x1000B); 0x24c7f8 (current cache tag / stage id); 0x3435bc (work-heap base); 0x36b9c0 / 0x36b9b8 (heap allocation-window lo/hi pointers)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** DAT_0024c7f8, iRam0036b9c0, iRam0036b9b8

## Behavioral explanation
Hard-resets the graphics/texture resource cache. It zero-fills the entire 0x1000-byte cache descriptor table at 0x36c560 (256 slots x 0x10 bytes), invalidates the "currently loaded stage/tag" marker (0x24c7f8 := -1), and re-arms the transient allocation window used by the asset loader to a fresh 0x10000-byte span at the top of the work heap (`base` .. `base+0x10000`). This is a bookkeeping-only reset — it does **not** free the underlying GS/VRAM handles (that is `gfx_free_texture_cache`, 0x1cb410); it simply forgets them, so it is used at a scene boundary where the heap window is about to be reused.

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- `memset(0x36c560, 0, 0x1000)` — clears all 256 cache descriptors.
- `DAT_0024c7f8 = 0xFFFFFFFF` — marks "no stage/tag loaded".
- `iRam0036b9c0 = iRam003435bc` — window-low pointer := work-heap base.
- `iRam0036b9b8 = iRam003435bc + 0x10000` — window-high pointer := base + 64 KiB.

## Important branches
None — straight-line.

## Constants & flags
- `0x1000` = table size = 256 slots x 0x10 bytes (matches GLOBALS "0x36c560 texture cache 256x0x10").
- `0xFFFFFFFF` = invalid/none sentinel for the tag word 0x24c7f8 (same sentinel used across this asset block, e.g. 0x1cb410).
- `0x10000` = size of the loader's scratch allocation window.

## Corrected reconstruction
```c
// Descriptor for one cached texture/resource slot (0x10 bytes). [inferred layout]
typedef struct { void *handle; /* +0x0: 0 = empty */ uint32_t _rest[3]; } gfx_cache_slot; // 0x10

static gfx_cache_slot g_tex_cache[256];   // 0x36c560
static int32_t        g_cache_tag;        // 0x24c7f8  (current stage/tag, -1 = none)
static uint8_t       *g_heap_base;        // 0x3435bc  (work-heap base)
static uint8_t       *g_alloc_win_lo;     // 0x36b9c0
static uint8_t       *g_alloc_win_hi;     // 0x36b9b8

void gfx_reset_texture_cache_and_heap_window(void)
{
    memset(g_tex_cache, 0, sizeof(g_tex_cache));   // 0x1000 bytes, forget all slots
    g_cache_tag   = -1;                            // no stage loaded
    g_alloc_win_lo = g_heap_base;                  // reset scratch window to top of heap
    g_alloc_win_hi = g_heap_base + 0x10000;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001cb3b0.c` (5 statements, no branches).
- GLOBALS.md: 0x36c560 tagged "texture cache … 256x0x10"; 0x24c7f8 "current stage/area id"; 0x3435bc "heap base"; 0x36b9c0/b8 "heap window".
- Counterpart teardown `FUN_001cb410` shares the 0x36c5xx table and the -1 tag sentinel.

## Remaining uncertainty
- Exact per-slot field layout beyond `+0x0 = handle` is inferred; not needed for the reset semantics.
- Runtime-unvalidated (static only).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb3b0.c`  — untouched decompiler output.
