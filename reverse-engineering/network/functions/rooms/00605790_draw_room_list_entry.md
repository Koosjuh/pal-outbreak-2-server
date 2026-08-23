# 0x00605790 draw_roster_row (was draw_room_list_entry)

| field | value |
|---|---|
| Original address | 0x00605790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605790 |
| Resolved name | draw_roster_row |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

> Name corrected: table `0x6c7c2c` (stride 0x3b0 ×4) is the **in-room roster table** (`roster_table`, Confirmed in `lobby_state_block.md`), not the room-browser list. This callback draws one player row (name + chosen character), not a room-list line.

**Callers:** — (item draw-callback, one instance per roster row)
**Callees:** ui_draw_set_size(005af2e0), ui_draw_set_color(005af2c0), ui_draw_text(005af1e0), lookup_id_to_index(005fe4b0), region_table_lookup_e(0062fdf0)
**Referenced globals:** 0x6c7c2c (roster_table base, stride 0x3b0); entry+0x00 occupied byte; entry+0x10 (`0x6c7c3c`) name; entry+0xec/0xee/0xf0 (`0x6c7d18/1a/1c`) character id/resolve-mode/name-idx; cRam006c5497 (selected row); PTR_DAT_0068ae30 (character/scenario name ptrs); fmt @0x64a078/@0x64a080
**Referenced strings:** printf templates @0x64a078, @0x64a080
**Referenced opcodes:** — (render)
**State vars:** param_1+2 row index (byte); param_1+3 row id; param_1+0x28 row Y

## Behavioral explanation
Draw-callback for a single roster row `i = *(param_1+2)`. It indexes the roster table as `base = 0x6c7c2c + i*0x3b0` (the decompiler expands the stride as `(i*0x3c - i)*0x10 = i*0x3b0`). If the row's occupied byte (`base+0`) is zero it draws an empty-slot placeholder from layout region 6. Otherwise it draws the player name at `base+0x10` (highlighting the row in colour `0xf` when it is the selected row `cRam006c5497 == *(param_1+3)`, else colour 0), then draws that player's chosen character/scenario label. The character label is resolved two ways: if `base+0xee == 0` it formats the raw id (`base+0xec`) plus `PTR_DAT_0068ae30[base+0xf0]`; otherwise it maps the id through `lookup_id_to_index` → `func_0x001b68b0` and prints the resolved name only if found.

## Input / output
- **param_1** (`int`) — UI item descriptor. `+2` row index, `+3` row id (compared to selection), `+0x28` base Y.
- **Return** `void`.

## Side effects
- Latches `param_1+4` (step) to 1 on first frame.
- Text output only; reads roster row fields. No protocol effects.

## Important branches
- `*(param_1+4)` step init (0→1; other non-1 → return).
- `base+0 == 0` (empty slot) → placeholder from `region_table_lookup_e(6)` and return.
- `cRam006c5497 == *(param_1+3)` → highlight colour `0xf`, else `0` (then colour `0x11` for the name field).
- `*(short*)(base+0xee) == 0` → raw-id format path; else resolve via `lookup_id_to_index(base+0xec)`, drawing only if index `>= 0` and `func_0x001b68b0(index) != 0`.

## Constants & flags
- Roster stride `0x3b0`, base `0x6c7c2c`; name at `+0x10`, character id at `+0xec`.
- `region_table_lookup_e(6)` — empty-slot placeholder layout.
- Colours: `0xf` selected-row, `0x11` name field, `0` normal.
- Name column X: `0x48` (name), `0x192` (character label).

## Corrected reconstruction
```c
// roster_table entry (partial): stride 0x3b0
typedef struct {
    uint8_t  occupied;      // +0x00
    char     name[...];     // +0x10
    // ...
    uint16_t char_id;       // +0xec
    uint16_t resolve_mode;  // +0xee  (0 => raw-id table, else index-lookup)
    uint16_t char_name_idx; // +0xf0
} roster_row;               // base 0x6c7c2c

void draw_roster_row(ui_item *item) {
    char buf[128];
    if (item->step != 1) {              // +4
        if (item->step != 0) return;
        item->step = 1;
    }
    int i = *(uint8_t*)(item + 2);
    roster_row *R = (roster_row*)(0x6c7c2c + i*0x3b0);
    int row_y = item->row_y + 6;        // +0x28

    if (R->occupied == 0) {             // empty slot placeholder
        layout_rec *L = region_table_lookup_e(6);
        ui_draw_set_size(L->size_25);
        ui_draw_set_color(L->color_26);
        ui_draw_text(L->x_28, row_y, L->style_27, L->str_2c);
        return;
    }

    // player name (highlight if selected)
    ui_draw_set_color(cRam006c5497 == *(uint8_t*)(item+3) ? 0x0f : 0x00);
    ui_draw_set_color(0x11);
    sprintf(buf, FMT_64a078, R->name);
    ui_draw_text(0x48, row_y, 0, buf);

    // chosen character / scenario label
    ui_draw_set_color(0);
    if (R->resolve_mode == 0) {
        const char *num = num_to_str(R->char_id);                 // 001b6950
        sprintf(buf, FMT_64a080, num, PTR_DAT_0068ae30[R->char_name_idx]);
        ui_draw_text(0x192, row_y, 0, buf);
    } else {
        int idx = lookup_id_to_index(R->char_id);                 // 005fe4b0
        const char *nm;
        if (idx >= 0 && (nm = scenario_name_by_index(idx)) != NULL) // 001b68b0
            ui_draw_text(0x192, row_y, 0, nm);
    }
}
```

## Evidence
- Raw: `FUN_00605790.c` (520 bytes). Stride `(i*0x3c - i)*0x10 == i*0x3b0` and base `0x6c7c2c` exact.
- `0x6c7c2c` = roster_table (Confirmed, `lobby_state_block.md`; readers include 0x00605790). Drives the name-resolution twin of `render_room_results_screen` (0x00602340).
- Empty-slot symptom: an unpopulated row (`occupied==0`) renders the placeholder, matching the "row missing / (null)" reports when the server never fills the roster.

## Remaining uncertainty
- Whether `+0xec` is a character id vs a scenario id is inferred from the shared `lookup_id_to_index`/`PTR_DAT_0068ae30` mechanism; roster rows carry the chosen character, so "character" is the leading reading. Field names positional. Format-string text not fetched. Not runtime-validated.
