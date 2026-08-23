# 0x001d33d0 load_asset_compressed_opt

| field | value |
|---|---|
| Original address | 0x001d33d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d33d0 |
| Resolved name | load_asset_pathxform_opt |
| Subsystem | asset-loader |
| Relevance | unrelated (non-network) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (path format), FUN_001cf2b0 (path transform/resolve), FUN_00109eb8 (string re-init), FUN_001cb360 (disc read), FUN_001a0df0 (HDD read)
**Referenced globals:** 0x343577 (media source flag); 0x34359d (cRam0034359d, path-transform enable flag); 0x3435ec (puRam003435ec, dest ptr; first word = validity); 0x34357a (stage id); 0x24d248 / 0x24d260 / 0x24d278 path fmts
**Referenced strings:** path fmts @0x24d248, @0x24d260, @0x24d278
**Referenced opcodes:** — (not a network function)
**State vars:** cRam00343577, cRam0034359d

## Behavioral explanation
Source-gated loader into the buffer pointed to by `puRam003435ec`, with an optional path-transform
pass. It first formats the base path (disc template `0x24d248`+literal `0x24d260`, or HDD template
`0x24d278`, each with the stage id). When the transform flag `cRam0034359d` is set, the formatted
path is passed through `FUN_001cf2b0` (a path resolver/redirect — e.g. to an alternate/override or
region-specific variant) and the buffer is re-initialised with the result before the read. On a
failed read it zeroes the destination's first word as an invalid marker.

## Input / output
- Inputs: none directly (globals: media flag, transform flag, stage id, dest ptr).
- Returns: void.

## Side effects
- Fills `*puRam003435ec`; on failure sets `*puVar1 = 0` (invalid sentinel).

## Important branches
- `cRam00343577 == 0` (disc):
  - format base path; if `cRam0034359d != 0` apply `FUN_001cf2b0` transform + re-init buffer;
  - `bytes = FUN_001cb360(path, dest, 1, 0)`; `bytes < 1` -> `*dest = 0`.
- `cRam00343577 != 0` (HDD):
  - format base path; if `cRam0034359d != 0` apply transform + re-init;
  - `bytes = FUN_001a0df0(path, dest)`; `bytes < 1` -> `*dest = 0`.
- The `cRam0034359d == 0` sub-branches use the base path unchanged; the two branches are otherwise
  identical except for the read API.

## Constants & flags
- `cRam00343577`: media source — `0` disc, non-zero HDD.
- `cRam0034359d`: path-transform enable — `0` = use base path, non-zero = resolve via `FUN_001cf2b0`.
- `*dest == 0`: invalid/unloaded sentinel.

## Corrected reconstruction
```c
void load_asset_pathxform_opt(void) {
    uint32_t *dest = g_asset_dest_ptr;   // puRam003435ec
    char path[128];
    long bytes;

    if (g_media_src == SRC_DISC) {
        format_path(path, PATHFMT_0x24d248, LIT_0x24d260, g_stage_id);
        if (g_path_xform) {                      // cRam0034359d
            const char *r = resolve_path(path);  // FUN_001cf2b0
            str_init(path, r);                   // FUN_00109eb8
        }
        bytes = disc_read(path, dest, 1, 0);     // FUN_001cb360
    } else {
        format_path(path, PATHFMT_0x24d278, g_stage_id);
        if (g_path_xform) {
            const char *r = resolve_path(path);
            str_init(path, r);
        }
        bytes = hdd_read(path, dest);            // FUN_001a0df0
    }

    if (bytes < 1) *dest = 0;                    // mark invalid
}
```

## Evidence
- Raw decompile `FUN_001d33d0.c`: nested split on `cRam00343577` then `cRam0034359d`; transform via
  `uVar2 = FUN_001cf2b0(buf); FUN_00109eb8(buf, uVar2);`; reads `FUN_001cb360(...,1,0)` /
  `FUN_001a0df0(...)`; both fail-paths `*puVar1 = 0`.
- Note: HDD fail predicate here is `< 1` (decompiler), not `== 0` as in some siblings.
- Confidence **High** on structure. Renamed from `_compressed_opt` to `_pathxform_opt` — the optional
  pass is a **path resolve/redirect** (`FUN_001cf2b0`), not evidenced as decompression. Not a network function.

## Remaining uncertainty
- Exact semantics of `FUN_001cf2b0` (path override table vs. localized-variant resolver vs. archive
  member lookup). The name change reflects "transform present" without proving it is compression.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d33d0.c`  — untouched decompiler output.
