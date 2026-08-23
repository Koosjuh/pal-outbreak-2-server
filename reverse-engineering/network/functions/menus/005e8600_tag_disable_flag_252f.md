# 0x005e8600 tag_disable_flag_252f

| field | value |
|---|---|
| Original address | 0x005e8600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8600 |
| Resolved name | tag_disable_selectable |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005eef70 (flush-run + CR to origin), FUN_005ec100 (load palette)
**Referenced globals:** ctx+0xd892 (entry_mode); +0xd894 (entry_index); per-entry +0x24fb (entry type); +0x17c (global flag); +0x252f/entry (per-entry flag)
**Referenced strings:** —
**Referenced opcodes:** — (menu UI, not SN@P)
**State vars:** ctx+0xd892; +0xd894; per-entry +0x24fb; +0x17c; per-entry +0x252f

## Behavioral explanation
Inverse of `tag_enable_selectable` (`0x005e8580`): ends a selectable region and switches back
to the "disabled/normal" palette. It flushes the current run and carriage-returns the pen via
`FUN_005eef70`, then clears the selectable flag — global `ctx+0x17c = 0` in the normal stream
(`ctx+0xd892 == 0`), or the per-entry flag `ctx[entry_index*0x5c + 0x252f] = 0` in per-cell
mode. In per-cell mode there is an early-out **guard**: if the entry's type byte
`ctx[entry_index*0x5c + 0x24fb] == 3`, the function returns immediately WITHOUT clearing the
flag or reloading the palette — type-3 entries keep their enabled state (a locked/always-active
menu-entry class). Otherwise `FUN_005ec100(0)` reloads the disabled color row.

## Input / output
- `param_1` (undefined8): markup cursor — unused.
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0 (including the guarded early-out).

## Side effects
- `FUN_005eef70(param_2)`: flush run, carriage-return pen, reset run length, empty accumulator (always runs, even on the type-3 early-out — the flush precedes the guard).
- Global path: `ctx+0x17c = 0`, then `FUN_005ec100(0)`.
- Per-cell path (type != 3): `ctx[idx*0x5c + 0x252f] = 0`, then `FUN_005ec100(0)`.
- Per-cell path (type == 3): **no flag change, no palette reload** — returns after the flush.

## Important branches
- `ctx+0xd892 == 0` → clear global `+0x17c`, load palette row 0.
- else compute `base = ctx + idx*0x5c`:
  - `base[0x24fb] == 3` → `return 0` (guard: type-3 entry stays enabled).
  - else → `base[0x252f] = 0`, load palette row 0.

## Constants & flags
- `ctx+0xd892` — `entry_mode` (0 global / non-0 per-cell).
- Per-entry stride `0x5c`.
- `+0x24fb` — per-entry **type**; value `3` = locked/always-selectable class (skips disable).
- `+0x252f` — per-entry selectable flag; `+0x17c` global counterpart.
- `FUN_005ec100(0)` — color-state 0 = disabled/normal palette row.

## Corrected reconstruction
```c
#define ENTRY_STRIDE 0x5c
enum { ENTRY_TYPE_LOCKED = 3 };   // [inferred] entries that ignore the disable tag

undefined8 tag_disable_selectable(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);                 // FUN_005eef70
    if (g_txtctx->entry_mode == 0) {
        g_txtctx->selectable = 0;                       // +0x17c
    } else {
        uint8_t *base = (uint8_t*)g_txtctx + g_txtctx->entry_index * ENTRY_STRIDE;
        if (base[0x24fb] == ENTRY_TYPE_LOCKED)
            return 0;                                   // locked entry: leave enabled
        base[0x252f] = 0;
    }
    palette_load(0);                                    // FUN_005ec100 — disabled color row
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8600.c`.
- Structurally the mirror of `FUN_005e8580` with an added `+0x24fb == 3` early return and `FUN_005ec100(0)`.
- Shared callees `FUN_005eef70` / `FUN_005ec100` documented under `tag_enable_selectable`.
- Menu UI; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Semantics of entry type `3` (guessed "locked/always-active"); other type values untouched here.
