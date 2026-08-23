# 0x001cf2b0 build_region_template_string

| field | value |
|---|---|
| Original address | 0x001cf2b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf2b0 |
| Resolved name | build_localized_asset_path |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cf0b0, FUN_001cf100, FUN_001cf150, FUN_001d1050, FUN_001d1110, FUN_001d1410, FUN_001d1530, FUN_001d33d0, FUN_001d3500, FUN_001d3fd0
**Callees:** FUN_0010a6b0 (strchr/memchr), FUN_001069a8 (memcpy), FUN_00106b60 (memset), FUN_00109728 (sprintf)
**Referenced globals:** 0x36c2d0 (output path scratch, 0x40B); 0x36c250 stem scratch is local (`auStack_40`); 0x24c830 (`PTR_DAT_0024c830[]` region/language string table); bRam0034359d (region/language index)
**Referenced strings:** 0x24cb68 (printf format, ~"%s%s%s")
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Takes a base filename (e.g. `"list.bin"`) and rewrites it into a **language/region-localized** filename by splicing a locale token in front of the extension. It splits the input at the first `.` (0x2e) into a *stem* and an *extension* (the `.`-onward tail), then `sprintf`s `stem + locale_string + extension` into the shared scratch buffer at 0x36c2d0 using format 0x24cb68. The locale string is chosen from the region table `PTR_DAT_0024c830[bRam0034359d]` (per the active PAL language index). Returns the address of the completed scratch string (0x36c2d0). This is the single shared path-localizer used by every list/asset loader in this cluster.

## Input / output
- **Params:** `param_1` = pointer to a NUL/`.`-terminated base filename.
- **Returns:** `0x36c2d0` — pointer to the localized path string (valid until the next call; single shared buffer).

## Side effects
- Overwrites the 0x40-byte scratch at 0x36c2d0 (the returned string). **Not reentrant** — callers must consume the result before the next invocation.
- Reads global language index `bRam0034359d` to index the region table.

## Important branches
None (straight-line). Implicit: `FUN_0010a6b0(param_1, '.')` locates the extension; the stem length is `('.'-ptr) - param_1`.

## Constants & flags
- `0x2e` = `'.'` — extension delimiter searched by `FUN_0010a6b0`.
- `0x40` = size of both the stem scratch (`auStack_40`) and the output scratch (0x36c2d0) — filenames are ≤ 63 chars.
- `PTR_DAT_0024c830[]` = region/language string table indexed by `bRam0034359d` (GLOBALS: "0x24c830 region pointer table"; 0x34359d "language index").

## Corrected reconstruction
```c
extern char *FUN_0010a6b0(const char *s, int ch);   // strchr (returns ptr to first `ch`)
extern char *g_region_str_tbl[];                     // 0x24c830
extern uint8_t g_lang_index;                         // 0x34359d
static char g_localized_path[0x40];                  // 0x36c2d0  (shared, non-reentrant)

// e.g. "menu.bin" + region "e" -> "menu" + "e" + ".bin"  (exact glue per fmt 0x24cb68)
char *build_localized_asset_path(const char *base_name)
{
    char stem[0x40];
    memset(stem, 0, sizeof(stem));
    const char *dot = FUN_0010a6b0(base_name, '.');          // extension start
    memcpy(stem, base_name, (int)dot - (int)base_name);      // copy stem (pre-'.')

    memset(g_localized_path, 0, sizeof(g_localized_path));
    sprintf(g_localized_path, /*fmt 0x24cb68 ~"%s%s%s"*/
            FMT_LOCALIZED_PATH, stem, g_region_str_tbl[g_lang_index], dot);
    return g_localized_path;   // 0x36c2d0
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001cf2b0.c` — `FUN_0010a6b0(param_1,0x2e)` (strchr '.'), stem memcpy of `uVar1-param_1`, `sprintf(0x36c2d0, 0x24cb68, stem, PTR_0024c830[bRam0034359d], uVar1)`, `return 0x36c2d0`.
- Called by 10 sibling loaders, always immediately before `FUN_001cb360` (archive load) — confirms it produces a filename/path.
- GLOBALS.md: 0x24c830 region table; 0x34359d language index.

## Remaining uncertainty
- Exact glue text of format 0x24cb68 (assumed `"%s%s%s"`; could insert a separator) — not dumped here.
- Whether the 4th `sprintf` arg is the extension tail (`dot`, most likely) or a length is inferred from arg order.
- Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf2b0.c`  — untouched decompiler output.
