# 0x005dae40 ui_spawn_widget_type1

| field | value |
|---|---|
| Original address | 0x005dae40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dae40 |
| Resolved name | ui_spawn_list_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0 (widget_node_alloc)
**Referenced globals:** iRam00701068+0x68e7f: list-widget state flag; LAB_005daee0: script label; FUN_005daf30: draw callback
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e7f

## Behavioral explanation
Widget factory sibling of `ui_spawn_background_widget`, for the selection-list/content layer. On enable (`param_1 == 1`) it allocates a node from pool/type 1 (`FUN_005dfde0(1,0)`), zero-inits geometry, installs script label `LAB_005daee0` (+0x14) and the draw callback `ui_draw_selection_overlay` (FUN_005daf30) at +0x18, sets the node lifecycle byte +6 = 1 (active), and records list-widget state flag 0x68e7f = 3. The callback then renders the 500-entry item list and the selection highlight each frame. Pure UI construction. Renamed to `ui_spawn_list_widget` (its callback iterates the item list, not a generic "type1").

## Input / output
- `param_1` (`long`): enable selector; only `1` acts.
- Returns: void.

## Side effects
- Allocates node (NULL-safe); installs FUN_005daf30 callback.
- `iRam00701068 + 0x68e7f = 3`.

## Important branches
- `if (param_1 == 1)` gate; `if (lVar2 != 0)` alloc-success gate.

## Constants & flags
- Pool id 1 (vs 0 for background, 2 for scrollbar) → `FUN_005dfde0(1,0)`.
- Node[0]=1 active, Node[1]=1 visible, Node[6]=1 (list type), Node[7]=0.
- Node+0x14 = &LAB_005daee0, Node+0x18 = FUN_005daf30.
- 0x68e7f = 3: list-widget-present/state flag.

## Corrected reconstruction
```c
void ui_spawn_list_widget(long enable /*p1*/)
{
    if (enable != 1) return;

    ui_widget_t *w = (ui_widget_t *)FUN_005dfde0(1, 0);   // alloc pool 1
    if (w == NULL) return;

    w->visible = 1;                    // +1
    w->active  = 1;                    // +0
    w->script  = &LAB_005daee0;        // +0x14
    w->draw    = ui_draw_selection_overlay; // +0x18 = FUN_005daf30
    w->x = w->y = 0;                   // +0x34/+0x38
    w->f4c = w->f50 = 0;               // +0x4c/+0x50
    w->step_x = w->step_y = 0;         // +0x40/+0x44
    w->lifecycle = 1;                  // +6  (active list)
    w->subtype   = 0;                  // +7
    w->s10 = w->s0c = w->s0e = w->s10b = 0; // +0xa..+0x10

    *((uint8_t *)iRam00701068 + 0x68e7f) = 3;   // list widget state
}
```

## Evidence
- Raw decompile: `sources/overlays/overlay-3dat-decompile/FUN_005dae40.c`.
- Identical init skeleton to FUN_005da8e0 with pool arg 1, callback FUN_005daf30, lifecycle byte 1, flag 0x68e7f=3.
- Callback FUN_005daf30 iterates the 500-ptr item list (iRam00701068+0x5ffc0) — basis for the "list" rename.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Meaning of state value 3 (vs 1/2 for the other widgets) and `LAB_005daee0` script contents not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dae40.c`  — untouched decompiler output.
