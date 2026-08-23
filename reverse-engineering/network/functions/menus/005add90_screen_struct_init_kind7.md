# 0x005add90 screen_struct_init_kind7

| field | value |
|---|---|
| Original address | 0x005add90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005add90 |
| Resolved name | screen_obj_init_kind7 |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7f30
**Callees:** —
**Referenced globals:** — (writes only through the passed pointer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
A constructor/initializer for a small **screen widget header**: it stamps the object's kind/type byte to `7` and zeroes the leading substate cursors. This is the "kind 7" variant of a family of `screen_obj_init_kindN` initializers (compare `*param_1 = 7` here vs. the kind bytes 0/2/3/4/5/6/0xc/0xe seen in the dispatchers). Called once, by `FUN_005f7f30`, when that screen constructs its widget. The first byte (`*param_1`) is the **type selector** that the overlay dispatchers (`FUN_005ae3e0`, `FUN_005ae770`, `FUN_005aec70`) branch on; kind 7 is one of the values those dispatchers explicitly *exclude* from overlay handling.

## Input / output
- `param_1` : `screen_obj*` (`undefined1*`) — the widget header to initialize.
- returns `void`.

## Side effects
- `param_1[0] = 7` — kind/type byte.
- `param_1[1] = 0` — secondary state/substate.
- `param_1[0xe] = param_1[0xf] = param_1[0x10] = param_1[0x11] = 0` — clears four cursor/step bytes (the same `+0xe`/`+0xf` confirm-latch/step pair used by `screen_substate2_sm`).

## Important branches
- None — straight-line stores.

## Constants & flags
- `7` = widget **kind** value (type selector byte at offset 0). Kinds observed across this overlay: `0,2,3,4,5,6,7,0xc,0xe`. `[inferred]`

## Corrected reconstruction
```c
// Initialize a "kind 7" screen widget header.
void screen_obj_init_kind7(screen_obj *obj) {
    obj->kind   /*+0x00*/ = 7;
    obj->sub    /*+0x01*/ = 0;
    obj->latch  /*+0x0e*/ = 0;   // confirm latch (see screen_substate2_sm +0xe)
    obj->step   /*+0x0f*/ = 0;   // SM step cursor (+0xf)
    obj->f10    /*+0x10*/ = 0;
    obj->f11    /*+0x11*/ = 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005add90.c` (32 bytes, six stores, single caller `FUN_005f7f30`).
- Offset `0`=kind and `+0xf`=step corroborated by the dispatchers/SMs in this same overlay batch (`FUN_005ae3e0` switches on `*param`, `screen_substate2_sm` steps `+0xf`).

## Remaining uncertainty
- Meaning of the `+0x10`/`+0x11` bytes (further cursors vs. flags) not individually confirmed.
- Whether kind 7 corresponds to a specific screen (e.g. a particular list/menu) — not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005add90.c`  — untouched decompiler output.
