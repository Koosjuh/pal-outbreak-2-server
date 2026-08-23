# 0x005ca290 roomlist_scroll_menu_action

| field | value |
|---|---|
| Original address | 0x005ca290 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca290 |
| Resolved name | roomlist_scroll_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as a per-frame menu handler via a dispatch pointer, no static caller)
**Callees:** FUN_005ca6a0 (rebuild_room_softmenu), FUN_005cce30 (resolve_member_roster / back), FUN_005d0960 (roomlist page-forward), FUN_005d09d0 (roomlist page-back)
**Referenced globals:** `iRam00701070` menu-context ptr → +0x2e menu-phase byte, +0x2c selection index
**Referenced strings:** —
**Referenced opcodes:** — (drives room-list nav; no direct wire op)
**State vars:** `*(iRam00701070+0x2e)`; `*(iRam00701070+0x2c)`

## Behavioral explanation
One of a six-member family of per-frame room-menu handlers (a–f, 0x005ca290–0x005ca4f0). Every member first calls `rebuild_room_softmenu` (0x005ca6a0) to re-lay-out the on-screen soft-menu buttons for the current context, then branches on the menu-phase byte at `menu_ctx+0x2e`:
- **phase 0x0a (ACTION/confirm)** — the user pressed confirm; run this handler's specific action.
- **phase 0x08 (SCAN)** — fall through to `resolve_member_roster` (0x005cce30), the shared list/roster scan that also handles the "back" transition.

This member is the **room-list scroll** handler: in ACTION phase it reads the selection sub-index at `menu_ctx+0x2c` and pages the room list — `+0x2c==2` → page forward (FUN_005d0960, which tests `roomlist_has_next_fwd` 0x005d71a0), `+0x2c==1` → page back (FUN_005d09d0, which tests `roomlist_has_prev` 0x005d72d0).

## Input / output
- **Input:** none (void). Implicit input = global menu context `*0x701070` (+0x2e phase, +0x2c selection).
- **Output:** void. Effect is a room-list page transition or a roster re-scan.

## Side effects
- Rebuilds soft-menu button set (via 0x005ca6a0 → FUN_005dff90/FUN_005e0320 label writes).
- On page nav: mutates the current-room cursor `uRam00701018` and room-view scroll state inside FUN_005d0960/FUN_005d09d0.
- On SCAN: may rewrite `menu_ctx+0x2e` (8↔10) inside 0x005cce30.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) & `+0x2c == 2` | page forward: FUN_005d0960 |
| `menu_ctx+0x2e == 0x0a` (ACTION) & `+0x2c == 1` | page back: FUN_005d09d0 |
| `menu_ctx+0x2e == 0x0a` & `+0x2c` other | no-op (no page change) |
| `menu_ctx+0x2e == 0x08` (SCAN) | FUN_005cce30 roster scan / back |
| otherwise | fall through, return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a` ('\n') — confirm pressed. Evidence: compared at line 10; written to `10` by 0x005cce30 lines 59/79.
- `MENU_PHASE_SCAN  = 0x08` ('\b') — list/roster scan phase. Evidence: compared at line 18; written to `8` by 0x005cce30 line 87.
- `+0x2c` selection: `2`=forward, `1`=back [inferred from paired has_next/has_prev callees].

## Corrected reconstruction
```c
// menu_ctx = *(void**)0x701070  (room-menu context object)
enum { MENU_PHASE_SCAN = 0x08, MENU_PHASE_ACTION = 0x0a };

void roomlist_scroll_menu_action(void)
{
    rebuild_room_softmenu();                       // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION) {
        if (menu_ctx->selection /*+0x2c*/ == 2)
            roomlist_page_forward();               // FUN_005d0960 -> has_next (005d71a0)
        else if (menu_ctx->selection == 1)
            roomlist_page_back();                  // FUN_005d09d0 -> has_prev (005d72d0)
    }
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN) {
        resolve_member_roster();                   // FUN_005cce30 (also handles "back")
    }
}
```

## Evidence
- Raw decompile lines 9–20 (dispatch on +0x2e, sub-dispatch on +0x2c to FUN_005d0960/FUN_005d09d0).
- Shared prologue FUN_005ca6a0 confirmed as soft-menu rebuild (callees FUN_005dff90 slot-select + FUN_005e0320 label-set, 12 callers across the a–f family).
- FUN_005d0960 → roomlist_has_next_fwd (0x005d71a0); FUN_005d09d0 → roomlist_has_prev (0x005d72d0) — establishes forward/back semantics.
- GLOBALS.md: 0x701070 = menu sub-struct ptr, +0x2e menu/kind.
- Runtime-unvalidated (no rig trace of the +0x2c selection values).

## Remaining uncertainty
- Exact numeric meaning of `+0x2c` (2=fwd/1=back is inferred from the callee pairing, not observed).
- Whether this handler is bound to browse-rooms specifically vs. another paged list (bound via a dispatch pointer, so no static caller pins the screen).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca290.c`  — untouched decompiler output.
