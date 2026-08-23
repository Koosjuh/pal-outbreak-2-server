# 0x005c27d0 register_ui_obj_0xda

| field | value |
|---|---|
| Original address | 0x005c27d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c27d0 |
| Resolved name | menu_build_entry_0xda_ret (register_ui_obj_0xda) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2390, FUN_005c2460
**Callees:** FUN_005be9e0 (begin-entry, returns handle), FUN_005bea10 (commit-entry), FUN_005bea80 (advance)
**Referenced globals:** 0x7018d0 (menu/UI object registry)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Same shape as the terminal menu builder `menu_build_entry_0xb5_ret` (0x5bef00): appends a plain
(no-label) entry **id 0xda** to the build object 0x7018d0 and returns the entry handle from
`FUN_005be9e0`. It is the entry-append primitive used by the two dialog assemblers `FUN_005c2390`
and `FUN_005c2460` (siblings of the 0xec builder `FUN_005c4460`). No value/label step → an action or
terminator row.

## Input / output
- **Params:** none.
- **Returns:** `u16` — entry handle from `FUN_005be9e0(obj, 0xda)` (identity → 0xda in this
  decompile).

## Side effects
- Adds the 0xda entry to 0x7018d0 and advances the builder cursor. No wire/no lobby state.

## Important branches
- None — straight-line.

## Constants & flags
- `0xda` — menu entry id (widget/string-resource slot).
- `0x7018d0` — menu object registry base.

## Corrected reconstruction
```c
// Appends the (no-label) menu entry 0xda and returns its handle. Used by dialog builders 0x5c2390/0x5c2460.
u16 menu_build_entry_0xda_ret(void)
{
    menu_obj *obj = (menu_obj *)0x7018d0;
    u16 handle = menu_entry_begin(obj, /*entry_id*/ 0xda);  // FUN_005be9e0
    menu_entry_commit(obj);                                 // FUN_005bea10
    menu_entry_advance(obj);                                // FUN_005bea80
    return handle;
}
```

## Evidence
- Raw decompile: 3-step (begin/commit/advance), `return uVar1`, id 0xda — identical to 0x5bef00 with
  a different id.
- Same builder-primitive family (0x5be9e0/bea10/bea80), which decompile as thin/identity stubs, so
  widget semantics are inferred from the call pattern (consistent with the 0xb2..0xb5 builders).

## Remaining uncertainty
- Whether 0xda is an action button vs terminator not provable from code; builder primitives are
  stubs. Original name "register_ui_obj" retained as alias; the function is more precisely a
  menu-entry builder. UI-only, runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c27d0.c`  — untouched decompiler output.
