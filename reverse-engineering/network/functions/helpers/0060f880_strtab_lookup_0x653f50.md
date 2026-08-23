# 0x0060f880 strtab_lookup_0x653f50

| field | value |
|---|---|
| Original address | 0x0060f880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f880 |
| Resolved name | strtab_lookup_0x653f50 (scenario/menu label by lang) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006134b0, FUN_006140d0
**Callees:** —
**Referenced globals:** 0x653f50 (per-lang string table base), bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Same two-level lookup as `FUN_0060f830` but with the base table **hard-wired to `0x653f50`**: selects `((u32**)0x653f50)[lang]` then returns the 32-bit word at `[idx]`. `0x653f50` is the per-language table of scenario/area menu label pointers. `FUN_006134b0` (scenario_list_render) uses it with `idx = ctx+0x1c cursor + row` to fetch the label for each visible scenario row; `FUN_006140d0` uses it similarly.

Because it wraps a fixed base, it is effectively `strtab_lookup_word_by_lang(0x653f50, idx)`.

## Input / output
- `param_1` — `int idx`: 32-bit-word index into the language's `0x653f50` sub-table.
- Returns `undefined4` — the string pointer `((u32**)0x653f50)[lang][idx]`.

## Side effects
None (pure read). Reads `bRam0034359d` and global table `0x653f50`.

## Important branches
None. No bounds check on `idx`.

## Constants & flags
- `0x653f50` — base of the per-language scenario/menu label pointer table (`DAT_00653f50`).
- `bRam0034359d` — language index.

## Corrected reconstruction
```c
/* 0x0060f880 — scenario/menu label lookup: g_labelTable[lang][idx]. */
extern unsigned char g_language;                 /* bRam0034359d */
extern const char *g_labelTable_0x653f50[/*NUM_LANG*/][/*N*/];

const char *strtab_lookup_0x653f50(int idx)
{
    const char **subtable = (const char **)g_labelTable_0x653f50[g_language];
    return subtable[idx];
}
```

## Evidence
- Raw decompile: `return *(undefined4 *)(*(int *)(&DAT_00653f50 + (uint)bRam0034359d * 4) + param_1 * 4);`
- Caller FUN_006134b0 uses `idx = *(char*)(ctx+0x1c) + row` (scenario cursor + 0..2).
- Confidence **High**. Not runtime validated.

## Remaining uncertainty
Whether entries are C-string pointers or OSD glyph-run pointers (both draw the same via FUN_006146e0); table length not bounded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f880.c`  — untouched decompiler output.
