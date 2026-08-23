# 0x005eb250 markup_element_layout_helper

| field | value |
|---|---|
| Original address | 0x005eb250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb250 |
| Resolved name | markup_cell_layout_helper |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb0f0, FUN_005eb1d0, FUN_005f0e10, FUN_005f10a0
**Callees:** FUN_005effc0, FUN_005f0070 (layout passes)
**Referenced globals:** g_mkp+0xd894 (current cell idx); +0x186 (pass mode); +0x18d (dirty flag); per-cell +0x24e0 (obj), +0x252c (flag), +0x24f4 (child ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** g_mkp+0xd894, +0x186

## Behavioral explanation
Shared cell-layout helper invoked when a type-2 element opens. It resolves the current cell record
(`MKP_CELL(+0xd894)`), requires its render object `cell->obj` (`+0x24e0`) to be non-null, clears two
"dirty/new" flags (`g_mkp+0x18d` and `cell+0x252c`), and — ONLY in measure pass (`+0x186 == 0xF6`) —
records the just-opened element pointer as the cell's child (`cell+0x24f4 = *param_1`). It then runs the
two-stage layout `FUN_005effc0` + `FUN_005f0070` over the cell (`cell+0x24e0`). The measure-pass child
record here is what the render pass reads back in `markup_element_open_t2` (0x5eb0f0). UI markup only.

## Input / output
- `param_1` — `u32 *element_ref`: pointer to the active element handle (its `*param_1` is the child).
- Return `u32`: `0` success; `0xFFFFFFFF` when the cell has no render object.

## Side effects
- `g_mkp+0x18d = 0`, `cell+0x252c = 0` (clear flags).
- Measure pass only: `cell+0x24f4 = *param_1` (link child).
- `FUN_005effc0(cell+0x24e0, obj)` and `FUN_005f0070(cell+0x24e0, obj)` run layout.

## Important branches
- `cell->obj (+0x24e0) == 0` -> return -1 (no layout target).
- `+0x186 == 0xF6` (measure) -> store child pointer; else skip.

## Constants & flags
- `PASS_MEASURE 0xF6` gate.
- Cell stride 92 (`idx*0x18 - idx`)*4, base `+0x24e0`; child slot `+0x24f4`.

## Corrected reconstruction
```c
u32 markup_cell_layout_helper(u32 *element_ref) {
    MkpCell *c = MKP_CELL(g_mkp->cur_cell);       // base +0x24e0, stride 92
    void *obj = c->obj;                           // +0x24e0
    if (obj == 0) return (u32)-1;

    g_mkp->flag_18d = 0;                           // +0x18d
    c->flag_252c    = 0;                           // +0x252c
    if (g_mkp->pass_mode == (s8)0xF6)              // measure pass records child
        c->child = *(void**)element_ref;           // +0x24f4
    FUN_005effc0(&c->obj, obj);                    // layout stage 1
    FUN_005f0070(&c->obj, obj);                    // layout stage 2
    return 0;
}
```

## Evidence
- Raw: cell = base + `(idx*0x18-idx)*4`; `obj=*(cell+0x24e0)`; `if(obj==0)return -1`; clear
  `+0x18d`/`+0x252c`; `if(+0x186==-10) *(cell+0x24f4)=*param_1`; call `FUN_005effc0`/`FUN_005f0070`.
- Complements 0x5eb0f0 (render pass reads `+0x24f4`).
- Runtime-unvalidated.

## Remaining uncertainty
Roles of `FUN_005effc0` vs `FUN_005f0070` (e.g. measure vs place) and the `+0x18d`/`+0x252c` flag
semantics are inferred, not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb250.c`  — untouched decompiler output.
