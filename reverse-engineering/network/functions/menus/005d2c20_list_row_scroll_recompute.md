# 0x005d2c20 list_row_scroll_recompute

| field | value |
|---|---|
| Original address | 0x005d2c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d2c20 |
| Resolved name | member_group_row_pick_or_scroll |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d1e80 (lobby_list_activate_dispatch, open-group path)
**Callees:** FUN_005d5df0 (scroll group window w/ tag), FUN_0061e730 (confirm SFX)
**Referenced globals:** view@0x701070 (scroll +4/+8), cursor@0x701078 (+2/+4/+5/+6/+8/+0xa/+0xc/+0x10/+0x12/+0x1c/+0x20), ui@0x701068 (entities[] +0x5ffc0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cursor.group_count(+4), cursor.sub_index(+5), cursor.orientation(+6)

## Behavioral explanation
Handles a click **inside an already-expanded member group** (the group whose head is at index
`param_1`, i.e. `cursor.selected_idx`). Two jobs:
1. **Group mini-scrollbar**: when the group has >10 rows and the cursor is over the group's thumb
   column (right 16px of the head bbox), it hit-tests the thumb sub-regions and either nudges the group
   window via FUN_005d5df0 (tags 5/6) or pages `sub_index`(+5) by ±9, recomputing the thumb band
   (`row_band_top/bottom/height` at +8/+0xa/+0xc) and drag delta (+0x1c). These paths **return
   `param_1`** (group stays open).
2. **Row pick + commit**: otherwise it maps `cursor_y` to a member row `iVar6` within the visible
   window, plays the confirm SFX, writes the absolute picked index to `cursor+2`, **copies the picked
   member's name pointer (`+0x60`) and id (`+0x5f`) into the group-head entity** (so the collapsed head
   shows the chosen member), snaps the cursor onto the head, clears `group_count`, and **returns 0**
   (group collapses / selection committed).

The caller assigns the return to `selected_idx`, so 0 = collapse/commit, nonzero = keep scrolling.

## Input / output
- Input: `param_1` = group-head entity index (`cursor.selected_idx`).
- Output: `param_1` (kept open, scrolled) or `0` (collapsed after commit / miss).

## Side effects
- Scroll paths: FUN_005d5df0(0,±1,5|6) or `sub_index`±9 with band recompute (`+8/+0xa/+0xc/+0x1c`).
- Commit path: FUN_0061e730; `cursor+2` = picked absolute index; head->`+0x60` = member->`+0x60`;
  head->`+5` = member->`+0x5f`; `cursor.cursor_y` snapped; `cursor.group_count = 0`.

## Important branches
- `cursor_x ≤ head_left || head_right ≤ cursor_x` → `group_count=0`, return 0 (cursor left group).
- `group_count > 10 && head_right−16 < cursor_x < head_right` → thumb column: `orientation` selects
  downward vs upward geometry; sub-regions map to a small ±1 nudge (5df0 tag 5), a ±9 page (recompute
  band, tag context 5), a dead zone (return param_1), or an arrow (5df0 tag 6). All return `param_1`.
- Row pick: scan rows `0..group_count` (or the 10-row window when `group_count ≥ 10`) for the row whose
  band contains `cursor_y` (`head_top+20+row*18 ≤ cursor_y < +next`, inverted when `orientation`). Out
  of range → return 0. On hit → commit (above), return 0.
- Window-edge guards in the `group_count ≥ 10` case use `sub_index`/`cursor+2` to keep the picked row
  inside the scrolled window (`bVar−sub < 9` tests).

## Constants & flags
- Row height `0x12`(18); group body top `20.0`; window sweep `162.0`(9·18)/`180.0`(10·18); thumb hit
  inset `16.0`; row pitch `0x90`(144); full sweep `0x5a0`(1440); page step `9`; window size `10`.
- Band math: `row_band_top = (sub_index−1)*0x90/count + 0x12`; `row_band_bottom = 0x5a0/count +
  row_band_top`; `row_band_height = bottom − top`.
- FUN_005d5df0 tags: `5` = fine group nudge, `6` = group arrow scroll.

## Corrected reconstruction
```c
// returns param_1 (group stays open) or 0 (committed/collapsed)
int member_group_row_pick_or_scroll(int head_idx)   // FUN_005d2c20
{
    Entity *head = (Entity*)ui->entities[head_idx];
    float hl = head->world_x - (float)view->scroll_x;         // head left
    float hr = hl + head->w;                                  // head right
    float ht = head->world_y - (float)view->scroll_y;         // head top
    float cx = (float)cursor->cursor_x;

    if (cx <= hl || hr <= cx) { cursor->group_count = 0; return 0; }  // cursor left group

    uint8_t n = cursor->group_count;
    if (n > 10 && hr - 16.0f < cx && cx < hr) {               // ---- group mini-scrollbar ----
        // orientation-selected thumb hit-test; nudges window / pages sub_index by 9;
        // recomputes row_band_top/bottom/height (+8/+0xa/+0xc) and drag delta (+0x1c);
        // FUN_005d5df0(0, +/-1, 5|6). All these sub-paths:  return head_idx;
        return group_thumb_scroll(cursor, head, ht, cx);      // (helper; exact ladder in raw)
    }

    // ---- row pick within the visible window ----
    int row = pick_row_from_y(cursor, ht, n);                 // orientation-aware band scan
    if (row < 0) return 0;                                    // miss

    play_confirm();                                           // FUN_0061e730
    int abs_idx = row + head_idx + cursor->sub_index;         // picked member entity index
    Entity *m = (Entity*)ui->entities[abs_idx];
    cursor->b2   = (char)row + (char)head_idx + cursor->sub_index;  // committed sub-selection
    head->name   = m->name;      // +0x60 <- +0x60  (head shows chosen member)
    head->flag5  = m->member_id; // +5    <- +0x5f
    cursor->cursor_y = (short)(int)((ui->entities[cursor->selected_idx]->world_y
                                     - (float)view->scroll_y) + 10.0f);
    cursor->group_count = 0;                                  // collapse
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005d2c20.c` (size 3336).
- Called only by FUN_005d1e80 when `selected_idx != 0` and the open entity is a member group (kind 8);
  the `+0x60`/`+0x5f` copy is what makes the collapsed head render the picked member. Row/window
  constants (0x12/20/162/180/0x90/0x5a0) match FUN_005cf680/8e0 and the 1e80 member-sizing loop.

## Remaining uncertainty
- The two thumb-scroll ladders and the row-scan bounds are summarized into helpers (`group_thumb_scroll`,
  `pick_row_from_y`); the exact per-region 5df0 tags (5 vs 6) and page-clamp edge cases are transcribed
  in the raw. `member_id`/name copy semantics inferred from the field usage. Runtime-unvalidated.
