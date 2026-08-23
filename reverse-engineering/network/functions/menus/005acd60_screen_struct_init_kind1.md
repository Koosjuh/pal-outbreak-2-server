# 0x005acd60 screen_struct_init_kind1

| field | value |
|---|---|
| Original address | 0x005acd60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acd60 |
| Resolved name | screen_obj_init_substate0 |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790, FUN_00600d10
**Callees:** FUN_00637180, FUN_005af120
**Referenced globals:** 0x6c4b90 (lobby_state_block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constructor for a screen-object struct. Sets the object's kind/active byte (`[0]`) to 1 and its
substate cursors (`[0xe]` major, `[0xf]` minor) to 0, then arms input handling (`FUN_00637180`) and
render (`FUN_005af120(0x6c4b90, 0)`). Because `[0xe]=0`, the object's sub-screen dispatcher
(`screen_substate_dispatch_A`, 0x005ace00) will start in branch 0 (`FUN_005acea0`). Pairs with the
`[0xe]=3` variant `screen_struct_init_kind3` (0x005acda0).

## Input / output
- **Input:** `undefined1 *param_1` — pointer to the screen-object struct to initialize.
- **Output:** none (`void`).

## Side effects
- `param_1[0]   = 1` (kind/active tag)
- `param_1[0xe] = 0` (substate major)
- `param_1[0xf] = 0` (substate minor)
- `FUN_00637180()` (input arm), `FUN_005af120(0x6c4b90, 0)` (render/link into lobby block).

## Important branches
None — straight-line init.

## Constants & flags
| offset | set to | meaning |
|---|---|---|
| +0x0 | 1 | object kind / active flag |
| +0xe | 0 | substate-major -> dispatch branch 0 (FUN_005acea0) in 0x005ace00 |
| +0xf | 0 | substate-minor cursor |

`FUN_005af120(0x6c4b90, 0)` binds the object to the lobby state block (0x6c4b90) for rendering.

## Corrected reconstruction
```c
// Init a screen object to start in substate-major 0 (dispatch branch 0). [inferred struct]
typedef struct {              // [inferred] screen object
    uint8_t  kind;            // +0x0  (1 = active)
    uint8_t  _pad[0xd];
    uint8_t  substate_major;  // +0xe  selects FUN_005ace00 branch
    uint8_t  substate_minor;  // +0xf
    uint8_t  substate_aux;    // +0x10 (used by kind3 variant)
} screen_obj;

void screen_obj_init_substate0(screen_obj *obj)   // param_1
{
    obj->kind           = 1;
    obj->substate_major = 0;   // -> dispatch branch 0
    obj->substate_minor = 0;
    input_arm();               // FUN_00637180
    screen_render_bind((void *)0x6c4b90, 0);  // FUN_005af120
}
```

## Evidence
- Raw decompile `FUN_005acd60.c`: stores to [0]/[0xe]/[0xf], then FUN_00637180 + FUN_005af120.
- +0xe as substate-major confirmed by the dispatcher `FUN_005ace00`/thunk which switches on
  `*(obj+0xe)` (0..3).
- Contrast with `FUN_005acda0` which sets +0xe=3 (kind3 variant).

## Remaining uncertainty
Full screen-object layout beyond +0/0xe/0xf/0x10 not decoded. Roles of `FUN_00637180`
(input arm, inferred) and `FUN_005af120` (render bind, inferred) not deeply traced. Which UI screens
callers 0x5b3790/0x600d10 construct is unconfirmed. Not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acd60.c`  — untouched decompiler output.
