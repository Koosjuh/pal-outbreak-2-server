# 0x005e9c70 menu_row_append_item

| field | value |
|---|---|
| Original address | 0x005e9c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9c70 |
| Resolved name | menu_row_append_item |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ef200 (prologue — opaque), FUN_005eef70 (menu_append_item)
**Referenced globals:** — (directly); FUN_005eef70 touches cfg+0x188, cfg+0x1540, cfg+0xd8bc…, cfg+0x4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (via callee)

## Behavioral explanation
Appends a parsed item to the current menu row's item list. Runs the opaque row prologue FUN_005ef200,
then FUN_005eef70(param_2), which — when not in the alternate-render mode (`cfg+0xd892 == 0`) —
appends `param_2` into the item table at `cfg+0x1540` indexed by the item count `cfg+0x188`
(FUN_005eea60 fill, FUN_005eeca0 finalize), snapshots the measure output `cfg+0xd8c0/0xd8c2` back into
`cfg+0xd8bc/0xd8be`, re-measures via FUN_005ec170, resets `cfg+4 = 0`, and clears `*param_2`. In
alternate-render mode it defers to FUN_005f3ac0. So this handler wires one selectable item/choice into
the menu being built.

## Input / output
- `param_1`: unused.
- `param_2` (`char *item`): the item text/record passed to FUN_005eef70 (and zeroed by it on success).
- Returns `0`.

## Side effects (via FUN_005eef70)
- Writes an entry into the item table `cfg+0x1540[cfg+0x188]`.
- Updates `cfg+0xd8bc/0xd8be` from `cfg+0xd8c0/0xd8c2`; resets `cfg+4 = 0`; clears `*param_2`.
- Alternate path (`cfg+0xd892 != 0`): FUN_005f3ac0 instead.

## Important branches
- None locally. The `cfg+0xd892` mode split and item indexing are inside FUN_005eef70.

## Constants & flags
- `cfg+0xd892` — alternate-render/mode flag (selects FUN_005f3ac0 vs. normal append).
- `cfg+0x188` — current item count / append index.
- `cfg+0x1540` — item table base (stride 4 in the observed index math).

## Corrected reconstruction
```c
// append a selectable item to the current menu row
uint64_t menu_row_append_item(void *unused, char *item)
{
    menu_row_prologue();          // FUN_005ef200 (opaque)
    menu_append_item(item);       // FUN_005eef70
    return 0;
}
```

## Evidence
- Raw decompile: FUN_005ef200(); FUN_005eef70(param_2).
- FUN_005eef70 read directly: `cfg+0xd892` mode split, `cfg+0x1540 + cfg[0x188]*4` indexing, snapshot
  of `cfg+0xd8bc/be` from `cfg+0xd8c0/c2`, `cfg+4=0`, `*param_1=0`.
- FUN_005ef200 opaque (halt_baddata).
- Runtime-unvalidated.

## Remaining uncertainty
- Exact record layout stored at `cfg+0x1540` (stride/field types) and FUN_005eea60/FUN_005eeca0 detail.
- FUN_005ef200 behavior (opaque).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9c70.c`  — untouched decompiler output.
