# 0x0060f8b0 ctxtab_lookup_0x653f70

| field | value |
|---|---|
| Original address | 0x0060f8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f8b0 |
| Resolved name | ctxtab_lookup_0x653f70 (per-language object handle) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006130a0, FUN_006139c0, FUN_006140d0
**Callees:** —
**Referenced globals:** 0x653f70 (per-lang handle table), bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Single-level accessor: returns `((u32*)0x653f70)[lang]` — the current language's entry from the table at `0x653f70`. Unlike the 830/860/880 helpers there is **no second index**; it yields one per-language pointer/handle. Callers treat the result as an object base and dereference fields off it (observed `+0x28 / +0x2c`), so `0x653f70[lang]` is a pointer to a per-language "context" object (e.g. default-name / roster-label context) rather than a plain string.

## Input / output
- (no parameters)
- Returns `undefined4` — `((u32*)0x653f70)[lang]`, a per-language object pointer/handle.

## Side effects
None (pure read). Reads `bRam0034359d` and global table `0x653f70`.

## Important branches
None.

## Constants & flags
- `0x653f70` — base of the per-language handle table (`DAT_00653f70`).
- `bRam0034359d` — language index.

## Corrected reconstruction
```c
/* 0x0060f8b0 — return the current language's context-object handle. */
extern unsigned char g_language;              /* bRam0034359d */
extern void *g_ctxTable_0x653f70[/*NUM_LANG*/];

void *ctxtab_lookup_0x653f70(void)
{
    return g_ctxTable_0x653f70[g_language];    /* 0x653f70 + lang*4 */
}
```

## Evidence
- Raw decompile: `return *(undefined4 *)(&DAT_00653f70 + (uint)bRam0034359d * 4);`
- Callers dereference the return at `+0x28/+0x2c` for default-name strings (roster renderers FUN_006130a0/FUN_006139c0/FUN_006140d0).
- Confidence **High**. Not runtime validated.

## Remaining uncertainty
Exact layout of the returned object beyond the `+0x28/+0x2c` fields the callers read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f8b0.c`  — untouched decompiler output.
