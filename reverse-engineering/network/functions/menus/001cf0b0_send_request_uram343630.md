# 0x001cf0b0 send_request_uram343630

| field | value |
|---|---|
| Original address | 0x001cf0b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf0b0 |
| Resolved name | load_localized_archive_into_a (uRam343630) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cf2b0 (build_localized_asset_path), FUN_001cb360 (archive_load)
**Referenced globals:** uRam00343630 (published destination-buffer pointer)
**Referenced strings:** 0x24cab0 (fixed base filename)
**Referenced opcodes:** —
**State vars:** uRam00343630

## Behavioral explanation
Thin wrapper that loads one fixed, language-localized archive into a caller-supplied destination buffer and publishes that buffer's address to the global 0x343630 so later consumers can find the loaded data. It localizes the base name 0x24cab0 via `build_localized_asset_path`, then calls `archive_load(name, dst=param_1, mode=1, 0)` (mode 1 = local/disc source). No return value / no success check here — the caller inspects the buffer.

## Input / output
- **Params:** `param_1` = destination buffer address for the decoded archive (also cached to 0x343630).
- **Returns:** void.

## Side effects
- `uRam00343630 = (u32)param_1` — publishes the dest pointer (consumer-visible handle to this dataset).
- Fills `param_1` with the loaded archive (header + records; see `archive_load` layout in 0x1cf150).

## Important branches
None — straight-line; no success gate on the load result.

## Constants & flags
- `0x24cab0` = the fixed base filename this loader always fetches (localized per region).
- `archive_load` mode `1` = `ARCHIVE_LOCAL` (disc/local source; contrast mode `0x10001` remote used in 0x1cf150/0x1d1110).

## Corrected reconstruction
```c
// archive_load: loads named indexed archive into dst; mode 1 = local. See 0x1cf150 for header layout.
extern long archive_load(const char *name, void *dst, uint32_t mode, int flags); // FUN_001cb360
static void *g_dataset_a;   // uRam00343630

void load_localized_archive_into_a(void *dst)
{
    g_dataset_a = dst;                                    // publish for later consumers
    char *path = build_localized_asset_path(BASE_NAME_A); // localize 0x24cab0
    archive_load(path, dst, ARCHIVE_LOCAL /*1*/, 0);
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001cf0b0.c` — `uRam00343630 = param_1; uVar1 = FUN_001cf2b0(0x24cab0); FUN_001cb360(uVar1, param_1, 1, 0)`.
- Sibling `0x1cf100` is byte-identical modulo base name 0x24cae0 and global 0x343634 → confirms the "publish dest ptr + load localized archive" pattern.

## Remaining uncertainty
- What dataset 0x24cab0 names (area list / news / ranking / config) — the string is not dumped here.
- Whether 0x343630 is later read as "the A dataset" vs just scratch — inferred from the paired-global pattern (343630/343634/343628/34362c form a dest-pointer cluster).
- Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf0b0.c`  — untouched decompiler output.
