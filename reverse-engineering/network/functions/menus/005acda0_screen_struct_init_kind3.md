# 0x005acda0 screen_struct_init_kind3

| field | value |
|---|---|
| Original address | 0x005acda0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acda0 |
| Resolved name | screen_obj_init_substate3 |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00601700
**Callees:** FUN_00637180, FUN_005af120
**Referenced globals:** 0x6c45f8 (selection/context index); 0x6c4b90 (lobby_state_block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c45f8

## Behavioral explanation
Constructor for a screen-object struct that starts in **substate-major 3**. Same kind tag (`[0]=1`)
as the substate-0 variant (0x005acd60), but sets `[0xe]=3`, clears `[0xf]` and `[0x10]`, and stores
the caller's `param_2` into the global selection/context index `0x6c45f8`. Because `[0xe]=3`, the
sub-screen dispatcher (`screen_substate_dispatch_A`, 0x005ace00) starts in branch 3 (`FUN_005ad680`).
The "kind3" name refers to that initial substate, not a different object type.

## Input / output
- **Input:** `undefined1 *param_1` (screen-object struct); `undefined1 param_2` (selection/context
  index to publish into 0x6c45f8).
- **Output:** none (`void`).

## Side effects
- `param_1[0]    = 1` (kind/active tag)
- `param_1[0xe]  = 3` (substate major -> dispatch branch 3 = FUN_005ad680)
- `param_1[0xf]  = 0`, `param_1[0x10] = 0`
- `uRam006c45f8  = param_2` (publish selection index)
- `FUN_00637180()` (input arm), `FUN_005af120(0x6c4b90, 0)` (render bind).

## Important branches
None — straight-line init.

## Constants & flags
| offset / addr | set to | meaning |
|---|---|---|
| +0x0 | 1 | object kind / active flag |
| +0xe | 3 | substate-major -> dispatch branch 3 (FUN_005ad680) |
| +0xf, +0x10 | 0 | substate-minor + aux cursors cleared |
| 0x6c45f8 | param_2 | selection/context index consumed by the branch-3 sub-screen |

## Corrected reconstruction
```c
// Init a screen object to start in substate-major 3 (dispatch branch 3), publishing a selection.
void screen_obj_init_substate3(screen_obj *obj /*param_1*/, uint8_t sel_index /*param_2*/)
{
    obj->kind           = 1;
    obj->substate_major = 3;    // -> dispatch branch 3 (FUN_005ad680)
    obj->substate_minor = 0;
    obj->substate_aux   = 0;    // +0x10
    g_sel_index_6c45f8  = sel_index;   // uRam006c45f8
    input_arm();                // FUN_00637180
    screen_render_bind((void *)0x6c4b90, 0);   // FUN_005af120
}
```

## Evidence
- Raw decompile `FUN_005acda0.c`: stores to [0]/[0xe]=3/[0xf]/[0x10], 0x6c45f8=param_2, then
  FUN_00637180 + FUN_005af120.
- +0xe branch mapping (3 -> FUN_005ad680) from the dispatcher `FUN_005ace00`.
- Structurally identical to `FUN_005acd60` except +0xe seed and the extra +0x10 clear + 0x6c45f8 store.

## Remaining uncertainty
Meaning of the selection index at 0x6c45f8 and what branch-3 sub-screen (`FUN_005ad680`) does are not
decoded here. Full screen-object layout beyond the touched offsets unconfirmed. Which UI action caller
0x601700 represents is unknown. Not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acda0.c`  — untouched decompiler output.
