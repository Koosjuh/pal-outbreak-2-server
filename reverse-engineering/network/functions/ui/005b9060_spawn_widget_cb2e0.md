# 0x005b9060 spawn_widget_cb2e0

| field | value |
|---|---|
| Original address | 0x005b9060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b9060 |
| Resolved name | spawn_count_label_widget |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** 21 sites (FUN_005ad530, FUN_005ae510, FUN_005b20c0, FUN_005f6a20, FUN_0062ab50, FUN_0062c870 …)
**Callees:** FUN_00618ba0 (display_node_alloc)
**Referenced globals:** uRam006c4fcd (msg channel id), uRam006c4fce, uRam006c4fcf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcd; uRam006c4fce; uRam006c4fcf

## Behavioral explanation
Spawns a **positioned count/label widget** rendered by `count_widget_cb` (`FUN_005ba2e0`). Resets the message-channel state, allocates a node (null-checked), stores the low byte of `param_1` as the type `+2`, the data pointer `param_2` at `+0x10`, and chooses subtype `+3` / icon `+0x22` from `param_1` bit `0x8000`: clear → subtype 0, icon `0x8d`; set → subtype 1, icon `0x143`. (The `0x8000` here is a **local widget-mode flag**, not the SN@P transport who-byte reliable bit.)

## Input / output
- `param_1` (`ulong`): low byte = widget type; bit `0x8000` = mode select. `param_2` (`undefined4`): data ptr → `+0x10`. No return.

## Side effects
- Globals `uRam006c4fcd=0xff`, `uRam006c4fce=1`, `uRam006c4fcf=0`.
- On alloc: `+0=1`, `+2=(u8)param_1`, `+0x34=-26`, `+0x10=param_2`, `+0xc=count_widget_cb`, `+3` and `+0x22` per mode. (Note: unlike the message spawners this one does **not** clear `+0x30`.)

## Important branches
- alloc == 0 → return.
- `param_1 & 0x8000 == 0` → `+3=0`, `+0x22=0x8d`.
- `param_1 & 0x8000 != 0` → `+3=1`, `+0x22=0x143`.

## Constants & flags
- Mode flag `0x8000` (widget-local; distinct from transport 0x8000 reliable bit).
- Icons `0x8d` (normal) / `0x143` (mode-1 alt frame).
- `z=-26`; callback `FUN_005ba2e0`.

## Corrected reconstruction
```c
void spawn_count_label_widget(u32 param, void *data) // FUN_005b9060
{
    uRam006c4fcf = 0; uRam006c4fcd = 0xff; uRam006c4fce = 1;

    struct widget *w = display_node_alloc();
    if (w == 0) return;

    w->alloc = 1;
    w->type  = (char)param;              // +2
    w->z     = -26;                      // +0x34
    w->data  = data;                     // +0x10
    w->cb    = count_widget_cb;          // +0xc = FUN_005ba2e0
    if ((param & 0x8000) == 0) { w->index = 0; w->icon = 0x8d; }
    else                       { w->index = 1; w->icon = 0x143; }
}
```

## Evidence
- Raw: `FUN_005b9060.c` (164 bytes; callee alloc; installs `FUN_005ba2e0`). 21 callers.
- Name upgraded `spawn_widget_cb2e0 → spawn_count_label_widget`: its callback `count_widget_cb` (0x005ba2e0) draws a positioned count/label; subtype-1 path there sets `uRam006ca04d`. Runtime-unvalidated.

## Remaining uncertainty
- `0x143` alt-icon meaning not resolved; `param_2` payload shape defined by `count_widget_cb`.
```
