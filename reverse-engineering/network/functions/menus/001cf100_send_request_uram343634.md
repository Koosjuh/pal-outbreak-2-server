# 0x001cf100 send_request_uram343634

| field | value |
|---|---|
| Original address | 0x001cf100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf100 |
| Resolved name | load_localized_archive_into_b (uRam343634) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cf2b0 (build_localized_asset_path), FUN_001cb360 (archive_load)
**Referenced globals:** uRam00343634 (published destination-buffer pointer)
**Referenced strings:** 0x24cae0 (fixed base filename)
**Referenced opcodes:** —
**State vars:** uRam00343634

## Behavioral explanation
Exact sibling of `load_localized_archive_into_a` (0x1cf0b0): loads a second fixed, language-localized archive (base name 0x24cae0) into a caller-supplied destination buffer and publishes that buffer's address to the global 0x343634. Localizes via `build_localized_asset_path`, then `archive_load(name, dst=param_1, mode=1, 0)` (local source). The only differences from 0x1cf0b0 are the base name and the destination-pointer global.

## Input / output
- **Params:** `param_1` = destination buffer for the decoded archive (also cached to 0x343634).
- **Returns:** void.

## Side effects
- `uRam00343634 = (u32)param_1` — publishes the dest pointer for dataset B.
- Fills `param_1` with the loaded archive.

## Important branches
None — straight-line; no success gate.

## Constants & flags
- `0x24cae0` = fixed base filename for dataset B (localized per region).
- `archive_load` mode `1` = `ARCHIVE_LOCAL`.

## Corrected reconstruction
```c
static void *g_dataset_b;   // uRam00343634

void load_localized_archive_into_b(void *dst)
{
    g_dataset_b = dst;                                    // publish for later consumers
    char *path = build_localized_asset_path(BASE_NAME_B); // localize 0x24cae0
    archive_load(path, dst, ARCHIVE_LOCAL /*1*/, 0);
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001cf100.c` — identical shape to 0x1cf0b0 with 0x24cae0 / uRam00343634.

## Remaining uncertainty
- Identity of dataset 0x24cae0; whether A/B are two halves of one menu dataset. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf100.c`  — untouched decompiler output.
