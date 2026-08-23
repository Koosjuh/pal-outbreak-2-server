# 0x005af370 ui_snapshot_tables

| field | value |
|---|---|
| Original address | 0x005af370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af370 |
| Resolved name | ui_init_two_tables_from_template |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ac610
**Callees:** func_0x001069a8 (base-module memcpy)
**Referenced globals:** 0x6951f0 (table A, dst); 0x694700 (table B, dst); 0x3c8a90 (template, src)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Screen-entry table initializer. Bulk-copies a fixed 0xAF0-byte (2800) template from ROM/const data at 0x3c8a90 into two working tables at 0x6951f0 and 0x694700. Both destinations get the *same* source, so this seeds two identical parallel tables — typically a "current" and "shadow/previous" pair used for diffing or for a two-buffer menu list. Called once from the single screen builder FUN_005ac610 (which also calls `ui_snapshot_tables`-adjacent init `FUN_005af420` and sound setup), i.e. it is that screen's data reset.

## Input / output
- no parameters.
- returns void.

## Side effects
- Overwrites 0xAF0 bytes at global 0x6951f0 and 0xAF0 bytes at global 0x694700, both from 0x3c8a90.

## Important branches
- None (two straight-line memcpys).

## Constants & flags
- `0xAF0` = 2800-byte table size (per-table). Two tables → 5600 bytes total copied.
- `func_0x001069a8(dst, src, len)` = base-module `memcpy`.

## Corrected reconstruction
```c
extern void *memcpy_ee(void *dst, const void *src, size_t n); // func_0x001069a8

#define UI_TABLE_A   ((void*)0x006951f0)
#define UI_TABLE_B   ((void*)0x00694700)
#define UI_TEMPLATE  ((const void*)0x003c8a90)
#define UI_TABLE_SZ  0xAF0   // 2800 bytes

void ui_init_two_tables_from_template(void)
{
    memcpy_ee(UI_TABLE_A, UI_TEMPLATE, UI_TABLE_SZ);
    memcpy_ee(UI_TABLE_B, UI_TEMPLATE, UI_TABLE_SZ);
}
```

## Evidence
- Raw decompile (`FUN_005af370.c`): two `func_0x001069a8(dst,0x3c8a90,0xaf0)` calls with dsts 0x6951f0 / 0x694700. Single caller 0x5ac610. Runtime-unvalidated.

## Remaining uncertainty
- Purpose of the paired tables (current vs shadow, or two independent lists) is inferred from the identical-source copy, not proven. Element layout inside the 0xAF0 block unknown. "snapshot" in the old name is a guess — this is really a template-load/reset; resolved name updated accordingly.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af370.c`  — untouched decompiler output.
