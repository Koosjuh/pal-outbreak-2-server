# 0x005fc000 list_arrow_widget_cb

| field | value |
|---|---|
| Original address | 0x005fc000 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc000 |
| Resolved name | roomlist_row_marker_widget_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as a widget update callback at +0xc; invoked by the widget pump)
**Callees:** FUN_00618c20 (free/destroy widget)
**Referenced globals:** 0x649890 {x,y} coord table (stride 4); 0x6c076f room-slot record base (stride 0x15c); cRam006c4fd8 list scroll base index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget +4 lifecycle state (0/1/2); +3 row index

## Behavioral explanation
Per-frame update callback for a room-list **row marker sprite** (occupancy indicator / arrow). On its first update it latches its screen position from a coord table indexed by its row index (+3). Every subsequent frame it shows/hides itself based on whether the corresponding room-list slot record is occupied (`(scroll_base + row) * 0x15c + 0x6c076f`). On teardown (state 2) it frees itself.

## Input / output
- **param_1** (`int`, widget*): the widget object; +3 = row index (byte), +4 = lifecycle state, +1 = visible flag, +0x26/+0x28 = x/y.
- **returns** `void`.

## Side effects
- +4: 0→1 (init→active).
- +0x26/+0x28 set from coord table on init.
- +1 (visible) set each frame from slot occupancy.
- state 2: `FUN_00618c20()` frees the widget.

## Important branches
- **state 2:** `FUN_00618c20()` — destroy/free; return.
- **state 0 (init):** +4=1; +0x26 = `*(u16*)(0x649890 + idx*4)`; +0x28 = `*(u16*)(0x649892 + idx*4)`. Falls through to the visibility check.
- **state 1 (and fall-through from 0):** compute slot = `(cRam006c4fd8 + idx) * 0x15c + 0x6c076f`; if that byte == 0 → +1 = 0 (hidden); else +1 = 1 (visible).
- **any other state:** no-op (returns).

## Constants & flags
- `0x649890` / `0x649892` = x/y halves of a `{u16 x, u16 y}` coord table, stride 4, indexed by row.
- `0x15c` = stride of a room-list slot record (the byte at +0x6c076f within each record is the occupancy/valid flag).
- `cRam006c4fd8` = current list scroll base (top-of-window row index) [inferred].

## Corrected reconstruction
```c
// Update cb for a room-list row occupancy marker sprite.
// state (+4): 0 init, 1 active, 2 destroy.
void roomlist_row_marker_widget_cb(widget *w)   // param_1
{
    int idx = (char)w->row_index;               // +3
    switch (w->state) {                         // +4
    case 2:
        widget_free(w);                         // FUN_00618c20
        return;
    case 0:
        w->state = 1;
        w->x = coord_tbl[idx].x;                // 0x649890 + idx*4
        w->y = coord_tbl[idx].y;                // 0x649892 + idx*4
        /* fall through */
    case 1: {
        int slot = (int)cRam006c4fd8 + idx;     // scroll base + row
        u8 occupied = *(u8*)(slot * 0x15c + 0x6c076f);
        w->visible = occupied ? 1 : 0;          // +1
        break;
    }
    default:
        return;
    }
}
```

## Evidence
- Raw decompile `FUN_005fc000.c` (state dispatch and slot-flag math exact).
- `0x6c076f` stride 0x15c is the room-list slot-record array (occupancy flag) — cross-ref room-list build path.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether the marker is a scroll arrow vs. per-row occupancy dot is not visually confirmed; name generalized to "row marker".
- `cRam006c4fd8` confirmed as an index base by the multiply, but its exact update site (scroll handler) is not traced here.
```
