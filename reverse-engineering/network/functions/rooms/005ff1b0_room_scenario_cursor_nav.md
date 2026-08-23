# 0x005ff1b0 room_scenario_cursor_nav

| field | value |
|---|---|
| Original address | 0x005ff1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff1b0 |
| Resolved name | room_setup_cursor_nav |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0
**Callees:** FUN_005adc80 (get player count/index), FUN_005b09b0 (sub-list cursor helper), FUN_005b14b0 (read pad mask), FUN_005f5ea0 (submit/confirm scenario), func_0x001b0140 (play SFX)
**Referenced globals:** lobby_state_block @0x6c4b90 — +0x907 cursor, +0x908 roster sub-index, +0x909 confirmed-sel, +0x910/+0x11 focus toggle, +0x16 dirty, +0x443/+0x44c/+0x454/+0x456 flags, +0x97e variant, +0x992 redraw latch, +0x309c roster_table (=0x6c7c2c, stride 0x3b0); per-room capacity 0x6c076a (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** lb->cursor(+0x907), lb->focus_toggle(+0x11), lb->variant(+0x97e)

## Behavioral explanation
D-pad cursor / selection state machine for the **room-setup screen** (choose scenario/difficulty, toggle character panel, and start). Two layouts are selected by the variant byte `+0x97e` (0 = 4-item layout, cursor range effectively {0,1,gap@2,3}; nonzero = 5-item, {0,1,2,gap@3,4}). When the character sub-panel has focus (`+0x11 != 0`) cursor movement is delegated to FUN_005b09b0; otherwise this function moves the cursor with wrap/clamp across the two menu regions. After movement it reads the confirm (mask 0x10) / secondary (mask 0x200) buttons and acts on the current cursor slot: submit the scenario (FUN_005f5ea0), toggle the character panel focus, increment a sub-value, or — on the "start" slot — **gate on player count vs. room capacity** (`+0x456` compared to per-room capacity 0x6c076a) before advancing to the next screen. That capacity gate is the roster-count-sensitive path.

## Input / output
- `param_1` : `lobby_state_block*` (0x6c4b90).
- returns `void`. All effect via lobby_state_block + SFX.
- FUN_005b14b0(mask) → nonzero when that input is active; FUN_005adc80(...) → current player count/index (1-based).

## Side effects
- Moves `cursor` (+0x907), sets `confirmed_sel` (+0x909), flips `focus_toggle` (+0x11 ^= 1), sets dirty (+0x16=1) and clears redraw latch (+0x992=0) on transitions.
- On character-slot confirm, clears +0x44c only if the corresponding roster row (`roster_table[+0x908]`, stride 0x3b0) is empty.
- On start-slot confirm (variant path), sets +0x10=4, +0x443=1, +0x454=0 to advance screens — but only if capacity satisfied.
- Plays SFX 0/1/2/5.

## Important branches
- `+0x97e == 0` → 4-item layout (regions size iVar2=2, top iVar5=3); else 5-item (iVar2=3, iVar5=4).
- `+0x11 == 0` (menu focus): clamp/wrap cursor across two regions using pad masks 0x40004 / 0x80008 (coarse axis) and 0x10001 / 0x20002 (fine axis); SFX on each move.
- `+0x11 != 0` (char-panel focus): `FUN_005b09b0(&cursor, iVar2, 3)` handles movement.
- Action block, `variant==0`:
  - confirm(0x10) not held & secondary(0x200) held & cursor!=1 → SFX2, cursor=1.
  - confirm(0x10) held → cursor==3: confirmed_sel=3, `FUN_005f5ea0()` (submit), SFX1. cursor==2: focus_toggle^=1, confirmed_sel=cursor, empty-roster-row check → maybe clear +0x44c, SFX1. cursor==1: increment +0x10, +0x454=0, SFX, dirty=1. cursor==0: SFX5.
- Action block, `variant!=0`:
  - confirm not held & secondary held & cursor!=2 → cursor=2.
  - confirm held → cursor==4: confirmed_sel=4, `FUN_005f5ea0()`. cursor==3: focus toggle + empty-roster check. cursor==1: return (no-op / locked). cursor==2: increment +0x10, +0x454=0. cursor==0: **capacity gate** — if `+0x456 < room_capacity[player-1]` (0x6c076a) → SFX5, return (blocked); else advance (+0x10=4, +0x443=1).

## Constants & flags
- Pad masks (this game's input layer, [inferred] identities): `0x40004` coarse-prev (Up), `0x80008` coarse-next (Down), `0x10001` fine-prev (Left), `0x20002` fine-next (Right), `0x10` confirm, `0x200` secondary/back.
- SFX ids via func_0x001b0140: 0 move-tick, 1 confirm, 2 reposition, 5 error/blocked.
- roster row stride `0x3b0` (0x3c*x - x = 0x3b*x, ×0x10) — matches roster_table 4×0x3b0.
- capacity source 0x6c076a = per-room record capacity field (stride 0x15c), same table read by roomlist_row_render_cb.

## Corrected reconstruction
```c
// param_1 = &lobby_state_block (0x6c4b90)
void room_setup_cursor_nav(lobby_state_block *lb)
{
    int top, gap;
    if (lb->variant == 0) { top = 3; gap = 2; }   // +0x97e
    else                  { top = 4; gap = 3; }

    // ---- cursor movement ----
    if (lb->focus_toggle == 0) {                    // +0x11 : 0 = menu, 1 = char panel
        int c = lb->cursor;                          // +0x907
        if (c < 0 || gap <= c) {
            if (c < gap+1 || top < c) {              // in the top region / out of range
                if      (pad(0x40004)) { lb->cursor--; sfx(0); }        // coarse-prev
                else if (pad(0x80008)) { lb->cursor = gap; }           // coarse-next -> gap edge
                else if (pad(0x10001)) { lb->cursor++; sfx(0); }        // fine-prev
                else if (pad(0x20002)) { lb->cursor = gap; }            // fine-next -> gap edge
            } else {                                  // in gap..top band
                if      (pad(0x10001)) { lb->cursor--; sfx(0); }
                else if (pad(0x20002)) { if (lb->cursor < top) { lb->cursor++; sfx(0); }
                                          else lb->cursor = top; }
            }
        } else {                                      // 0..gap-1 region
            if      (pad(0x40004)) { if (lb->cursor < 1) lb->cursor = 0;
                                      else { lb->cursor--; sfx(0); } }
            else if (pad(0x80008)) { lb->cursor++; sfx(0); }
        }
    } else {
        sublist_cursor(&lb->cursor, gap, 3);          // FUN_005b09b0 (char panel)
    }

    // ---- action / confirm ----
    if (lb->variant == 0) {
        if (!pad(0x10)) {
            if (pad(0x200) && lb->cursor != 1) { sfx(2); lb->cursor = 1; lb->redraw_latch = 0; }
        } else switch (lb->cursor) {
            case 3: lb->confirmed_sel = 3; submit_scenario(lb); sfx(1); break;   // FUN_005f5ea0
            case 2: lb->field_10 = 0; lb->focus_toggle ^= 1; lb->confirmed_sel = lb->cursor;
                    if (roster_table[lb->roster_idx].occupied == 0) lb->field_44c = 0;
                    sfx(1); break;
            case 1: lb->field_10++; lb->field_454 = 0; sfx(?); lb->dirty = 1; lb->redraw_latch = 0; break;
            case 0: sfx(5); break;
        }
    } else {
        if (!pad(0x10)) {
            if (pad(0x200) && lb->cursor != 2) { sfx(); lb->cursor = 2; lb->redraw_latch = 0; }
        } else {
            switch (lb->cursor) {
            case 4: lb->confirmed_sel = 4; submit_scenario(lb); break;
            case 3: lb->field_10 = 0; lb->focus_toggle ^= 1; lb->confirmed_sel = lb->cursor;
                    lb->redraw_latch = 0;
                    if (roster_table[lb->roster_idx].occupied == 0) lb->field_44c = 0; break;
            case 1: return;                                   // locked slot
            case 2: lb->field_10++; lb->field_454 = 0; lb->redraw_latch = 0; break;
            case 0: {                                         // START — capacity gate
                int players = get_player_count();             // FUN_005adc80
                if (lb->field_456 < room_capacity[players-1]) { sfx(5); return; } // 0x6c076a: not enough
                lb->field_10 = 4; lb->redraw_latch = 0; lb->field_454 = 0; lb->field_443 = 1;
                break;
            }}
            sfx(1); lb->dirty = 1;                            // +0x16 = 1
        }
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ff1b0.c`.
- roster stride 0x3b0 and base +0x309c (=0x6c7c2c roster_table) match member_record.md / lobby_state_block.md.
- capacity read `*(u16*)((players-1)*0x15c + 0x6c076a)` shares the 0x15c room-slot table with roomlist_row_render_cb. FUN_005f5ea0 is the submit target (name from role, not a string). Runtime-unvalidated; pad-mask identities [inferred].

## Remaining uncertainty
- Exact pad-mask → physical-button mapping (0x10/0x200/0x40004/…) inferred from movement roles, not from an input table dump.
- Meaning of +0x454/+0x456/+0x44c precise semantics; +0x456 is the "selected/available count" compared to capacity but its writer isn't in this function.
- SFX ids in a couple of branches ambiguous (func_0x001b0140 called with 0 vs no-arg in decompile).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff1b0.c`  — untouched decompiler output.
