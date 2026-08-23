# 0x001d3500 load_asset_e8_scratch

| field | value |
|---|---|
| Original address | 0x001d3500 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3500 |
| Resolved name | load_asset_e8_dual_dest |
| Subsystem | asset-loader |
| Relevance | unrelated (non-network) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (path format), FUN_001cf2b0 (path resolve/transform), FUN_001cb360 (disc read), FUN_001a0df0 (HDD read)
**Referenced globals:** 0x343577 (media source flag); 0x3435e8 (puRam003435e8, default dest); 0x3435dc (iRam003435dc, alt-dest base; alt = +0x10000); 0x34357a (stage id); 0x24d288 / 0x24d298 / 0x24d2a8 path fmts
**Referenced strings:** path fmts @0x24d288, @0x24d298, @0x24d2a8
**Referenced opcodes:** — (not a network function)
**State vars:** cRam00343577

## Behavioral explanation
Source-gated loader with a caller-selected destination. `param_1` chooses where the file lands:
`0` -> the default buffer `puRam003435e8`; non-zero -> the alternate staging buffer
`iRam003435dc + 0x10000`. The path is always formatted (disc template `0x24d288`+literal `0x24d298`,
or HDD template `0x24d2a8`, with the stage id) and then run through `FUN_001cf2b0` (path
resolve/transform) before the read. On failure the destination's first word is zeroed.

## Input / output
- `param_1` (long): destination selector — `0` = default buffer, non-zero = alt buffer (+0x10000).
- Returns: void.

## Side effects
- Fills the selected destination; on failure sets `*dest = 0` (invalid sentinel).

## Important branches
- `param_1 != 0` -> `dest = iRam003435dc + 0x10000` (alternate staging region).
- `param_1 == 0` -> `dest = puRam003435e8` (default).
- `cRam00343577 == 0` (disc): format `0x24d288`/`0x24d298`, transform, `FUN_001cb360(path,dest,1,0)`.
- `cRam00343577 != 0` (HDD): format `0x24d2a8`, transform, `FUN_001a0df0(path,dest)`.
- `bytes < 1` -> `*dest = 0`.

## Constants & flags
- `cRam00343577`: media source — `0` disc, non-zero HDD.
- `0x10000` (64 KiB): offset from `iRam003435dc` to the alternate destination buffer.
- `*dest == 0`: invalid/unloaded sentinel.

## Corrected reconstruction
```c
void load_asset_e8_dual_dest(long use_alt_dest /*param_1*/) {
    uint32_t *dest = use_alt_dest
        ? (uint32_t*)(g_alt_dest_base + 0x10000)   // iRam003435dc + 0x10000
        : g_e8_dest;                               // puRam003435e8

    char path[128];
    const char *resolved;
    long bytes;

    if (g_media_src == SRC_DISC) {
        format_path(path, PATHFMT_0x24d288, LIT_0x24d298, g_stage_id);
        resolved = resolve_path(path);             // FUN_001cf2b0
        bytes = disc_read(resolved, dest, 1, 0);   // FUN_001cb360
    } else {
        format_path(path, PATHFMT_0x24d2a8, g_stage_id);
        resolved = resolve_path(path);
        bytes = hdd_read(resolved, dest);          // FUN_001a0df0
    }

    if (bytes < 1) *dest = 0;                       // mark invalid
}
```

## Evidence
- Raw decompile `FUN_001d3500.c`: `puVar1 = puRam003435e8; if (param_1 != 0) puVar1 = iRam003435dc +
  0x10000;` dest select; media split; unconditional `uVar2 = FUN_001cf2b0(buf)` transform; reads
  `FUN_001cb360(uVar2,dest,1,0)` / `FUN_001a0df0(uVar2,dest)`; `lVar3 < 1 -> *puVar1 = 0`.
- Confidence **High** on structure; runtime-unvalidated. Not a network function. (Renamed `_scratch`
  -> `_dual_dest` to reflect the `param_1` destination selector.)

## Remaining uncertainty
- Meaning of the two destination regions (double-buffer vs. two distinct asset slots) and what
  `FUN_001cf2b0` resolves.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3500.c`  — untouched decompiler output.
