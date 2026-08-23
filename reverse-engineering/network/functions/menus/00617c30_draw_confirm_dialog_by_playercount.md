# 0x00617c30 draw_confirm_dialog_by_playercount

| field | value |
|---|---|
| Original address | 0x00617c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617c30 |
| Resolved name | draw_player_result_row_by_count |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (table-driven / tail-called; not statically recovered)
**Callees:** FUN_00618c20 (finish/close), FUN_005af2e0 (set font size), FUN_005af2c0 (set color), FUN_005fe4b0 (id->handle lookup), FUN_0062fea0 (localized string), FUN_00617fa0 (draw text scaled+centered)
**Referenced globals:** bRam006c5520 (player count 1..4); layout tables 0x6542b0/0x6542d0/0x654300/0x654340 (per-count) + 0x654270 (coord seed); result records at 0x6c6d7c/0x6c6d94/0x6c6e58/0x6c6e5a/0x6c6e5c (stride 0x3b0); 0x68ae30 (string-ptr table)
**Referenced strings:** 0x654390, 0x654398, 0x6543a0, 0x6543a8 (sprintf format strings)
**Referenced opcodes:** —
**State vars:** obj+3 slot index (player); obj+4 minor-state (0/1/2); obj+1 done flag; obj+0x26 draw-x; obj+0x28 draw-y

## Behavioral explanation
Draws one player's **result-summary row** in the end-of-room / confirm panel. `bRam006c5520` (1..4) is the active player count and selects which per-count layout table supplies text coordinates; `obj+3` is the slot/player index being drawn. The object is a tiny 3-state widget:

- **State 0 (init):** advance to state 1. If the slot index is out of range for the current count (`slot >= count`) mark done (`obj+1 = 0`) and close via `FUN_00618c20`. Otherwise seed the widget's base draw coords `+0x26`/`+0x28` from table `0x654270` (indexed by `slot` and `count-1`), scaling x by 1.25.
- **State 1 (fall-through, and re-entry):** pick the per-count layout table and a per-slot "centered" flag, then render four text lines for this player from the player's result record (stride `0x3b0`): a name/character line at font size `0x1c`, then three detail lines at font `0x10` (a stored string, a localized label `FUN_0062fea0(0x6a)` formatted with a value, and a numeric field). Each line is positioned with the table's (x,y) pair and drawn through `FUN_00617fa0`.
- **State 2:** just calls `FUN_00618c20` (finish/close) and returns.

The record slot's field `+0x6c6e5a` selects the name formatting: when 0, format an entry id via `func_0x001b6950` + a string-ptr from table `0x68ae30`; otherwise resolve a handle via `FUN_005fe4b0` and format its name, falling back to a placeholder string (`0x654398`) when the lookup fails.

## Input / output
- **param_1** (object pointer): the result-row widget. Reads `+3` (slot), `+4` (state); writes `+1`, `+4`, `+0x26`, `+0x28`.
- **returns** `void`.

## Side effects
- `obj+4` state transitions 0->1; state 2 terminal.
- `obj+0x26`/`obj+0x28` seeded with scaled coords (state 0).
- Emits up to four `FUN_00617fa0` text draws; sets font size via `FUN_005af2e0(0x1c)` then `FUN_005af2e0(0x10)`, color via `FUN_005af2c0(0)`.
- `FUN_00618c20` invoked on out-of-range / unknown-count / state-2 (finish path).

## Important branches
- `if (obj[4]==2) { FUN_00618c20(); return; }` — terminal state.
- `if (obj[4]==0)`: set state 1; `if (count <= slot) { obj[1]=0; FUN_00618c20(); return; }` else seed coords.
- Count dispatch selects layout table + centered flag:
  - `count==4` -> table 0x654340, `centered = ((slot & 1) != 0) ^ 1` (centered on even slots).
  - `count==3` -> table 0x654300, `centered = (slot == 2)`.
  - `count==2` -> table 0x6542d0, `centered = (slot == 0)`.
  - `count==1` -> table 0x6542b0, `centered = 0`.
  - else -> `FUN_00618c20(param_1)` (unknown count: close).
- Name-format branch: `if (record.f6e5a == 0)` -> id/format path; `else` -> handle-lookup path with `<0`/`0` -> placeholder `0x654398`.

## Constants & flags
- `bRam006c5520` = player count, valid `1..4`.
- Layout table stride: `slot*0x14` (20 bytes = 10 shorts per slot): `[0,1]` = name-line xy, `[4,5]/[6,7]/[8,9]` = the three detail-line xy pairs (`[2,3]` unused here).
- Result record stride `0x3b0` (944) — same stride as the drawn roster rows (`0x6c7c2c` in lobby_state_block); this table lives at `0x6c6d7c..0x6c6e5c`.
- Font sizes: `0x1c` (name line), `0x10` (detail lines). Localized string id `0x6a` via `FUN_0062fea0`.
- `func_0x00109728` = sprintf; `func_0x001b6950`/`func_0x001b68b0` = id/handle -> string helpers.

## Corrected reconstruction
```c
// Per-player result record (stride 0x3b0), fields referenced here:
typedef struct result_rec {
    /* +0x00 (0x6c6d7c) */ char  name_str[?];   // drawn detail line 1
    /* +0x18 (0x6c6d94) */ int   value;         // formatted with fmt 0x6543a8
    /* +0xDC (0x6c6e58) */ short entry_id;
    /* +0xDE (0x6c6e5a) */ short use_handle;     // 0 = id path, !=0 = handle lookup
    /* +0xE0 (0x6c6e5c) */ short str_index;      // -> 0x68ae30[str_index]
} result_rec; // base 0x6c6d7c, indexed by slot*0x3b0

void draw_player_result_row_by_count(result_row_widget *w)
{
    char line[64];
    int  slot  = w->slot;              // w+3
    int  count = bRam006c5520;         // 1..4

    if (w->state /* w+4 */ == 2) { panel_finish(); return; } // FUN_00618c20

    if (w->state == 0) {
        w->state = 1;
        if (count <= slot) { w->done = 0; panel_finish(); return; } // w+1
        w->draw_x = coord_seed_x(slot, count);   // 0x654270 table, *1.25
        w->draw_y = coord_seed_y(slot, count);   // 0x654272
    }

    const short *lt; int centered;            // per-count layout table + center flag
    switch (count) {
    case 4: lt = TBL_654340; centered = ((slot & 1) != 0) ^ 1; break;
    case 3: lt = TBL_654300; centered = (slot == 2);           break;
    case 2: lt = TBL_6542D0; centered = (slot == 0);           break;
    case 1: lt = TBL_6542B0; centered = 0;                     break;
    default: panel_finish(); return;          // FUN_00618c20
    }

    const short *xy = &lt[slot * 10];         // stride 0x14
    result_rec *r   = &RESULT_RECS[slot];     // stride 0x3b0

    set_font_size(0x1c);                        // FUN_005af2e0
    set_color(0);                               // FUN_005af2c0
    if (r->use_handle == 0) {                   // r+0x6e5a
        sprintf(line, FMT_654390, fmt_id(r->entry_id), STRTAB_68ae30[r->str_index]);
    } else {
        long h = id_to_handle(r->entry_id);     // FUN_005fe4b0
        if (h < 0)                 sprintf(line, FMT_654398 /*placeholder*/);
        else { long s = handle_name(h);          // func_0x001b68b0
               if (s == 0) sprintf(line, FMT_654398);
               else        sprintf(line, FMT_6543A0, s); }
    }
    draw_text_scaled_centered(line, xy[0], xy[1], centered, 0x1c); // name line

    set_font_size(0x10);
    draw_text_scaled_centered(&r->name_str, xy[4], xy[5], centered, 0x10); // detail 1
    sprintf(line, FMT_6543A0, localized(0x6a));                             // FUN_0062fea0
    draw_text_scaled_centered(line, xy[6], xy[7], centered, 0x10);          // detail 2 (label)
    sprintf(line, FMT_6543A8, r->value);                                    // r+0x6c6d94
    draw_text_scaled_centered(line, xy[8], xy[9], centered, 0x10);          // detail 3 (value)
}
```

## Evidence
- Raw decompile: exact count dispatch with the four layout-table immediates and centered-flag expressions; the `slot*0x14` layout stride and `slot*0x3b0` record stride are algebraically exact from the pointer math (`(cVar1*4+iVar3)*4` and `((cVar1*0x10-iVar3)*4-iVar3)*0x10`).
- Font-size calls `FUN_005af2e0(0x1c)`/`(0x10)` and four `FUN_00617fa0` draws recovered verbatim; format strings 0x654390/398/3a0/3a8 referenced as immediates.
- `0x3b0` record stride matches the roster row stride documented in `structure-layouts/lobby_state_block.md` (0x6c7c2c 4×0x3b0), corroborating "one row per player".
- Confidence **Medium**: control flow fully recovered but no static callers, and several string/format helper identities (`func_0x001b6950/68b0`, `FUN_005fe4b0`, `FUN_0062fea0`) are inferred from usage, not confirmed.

## Remaining uncertainty
- Precise field offsets/types inside the 0x3b0 result record beyond those touched here; the exact meaning of the localized id `0x6a` and format strings' content (name/score/time layout) is inferred.
- No recovered caller — invocation context (which panel/state drives it) is assumed to be the end-of-room / confirm summary.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617c30.c`  — untouched decompiler output.
