# 0x005acab0 lobby_overlay_frame_dispatch

| field | value |
|---|---|
| Original address | 0x005acab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acab0 |
| Resolved name | lobby_overlay_frame_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aca20
**Callees:** screen handlers FUN_005b24e0 (menu/room SM, case 0), thunk_FUN_005ace00 (1), FUN_005f76f0 (2), FUN_005f8d40 (3), FUN_005fe620 (4), FUN_00616c40 (5), FUN_005f6aa0 (6), FUN_005ade20 (7 session), FUN_006177d0 (8), FUN_00617a50 (0xb), FUN_005ff950 (0xc), FUN_0062d5e0 (0xe), FUN_005af4d0 (0xf); gates FUN_005aedc0/FUN_005ae770/FUN_005ae3e0/FUN_005aec70; enter FUN_005aefb0/FUN_005af090; post FUN_005b1d20/FUN_005b1a00/FUN_005b1d10/FUN_00618c30; misc FUN_005be330/FUN_00627a20
**Referenced globals:** 0x6c4b90 top-screen id + ctx blk ; 0x6c4fbc paused ; 0x6c4fc4 fade ctr ; 0x6c50e8 timer ; 0x6c5522/0x6c5524 ; 0x6c555f/0x6c5560 ; 0x6c4fb0 frame ctr ; 0x35a6f4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 top-screen id ; cRam006c4fbc paused ; cRam006c4fc4 fade

## Behavioral explanation
Top-level per-frame driver for the whole online/lobby overlay. Once per frame it: (1) polls
`FUN_005be330` and arms a `0xe10` (3600-frame ≈ 60 s) timeout counter if it returns non-zero; (2) runs
an overlay-ready gate (`FUN_005aedc0(0x6c4b90)`) — only if the overlay context is live does the body
run; (3) enters/updates the context (`FUN_005aefb0`/`FUN_005af090`), decrements assorted fade/timeout
counters; (4) if not in a modal/paused sub-mode (`cRam006c4fbc == 0`) **switches on the top-screen id
`cRam006c4b90` (0..0xf)** to the matching screen handler, then runs the standard post-pass
(`FUN_00618c30` + `FUN_005b1d20`). When paused, a restricted set of screen ids (5,0xe,0xc,4,3,2) get an
alternate modal path; all others get the plain `FUN_005b1a00` overlay draw. Finally it advances the
frame counter `0x6c4fb0` and ticks the `0x6c5560/0x6c555f` message-flash pair.

`cRam006c4b90` is the **top-level online screen selector** (title/net menus, lobby, room, session,
etc.); screen 0 dispatches into the lobby/room state machine `FUN_005b24e0` whose sub-state lives at
`ctx+0xe`.

## Input / output
- No params (operates on fixed globals). Void.
- `0x6c4b90` doubles as the screen id (byte) and the base of the screen context block passed to
  handlers.

## Side effects
- Runs exactly one screen handler per frame; mutates the screen context and many UI globals.
- Arms/decrements timers `0x6c50e8`, `0x6c4fc4`, `0x6c5560`; clears `0x6c5522/0x6c5524/0x6c555f`.
- Increments frame counter `0x6c4fb0`.

## Important branches
- `FUN_005be330(0x35a6f4) != 0` → set `timer 0x6c50e8 = 0xe10`.
- `FUN_005aedc0(ctx) != 0` → overlay not ready → return (skip the whole frame body).
- `FUN_005ae770(ctx) != 0` or `FUN_005ae3e0(ctx) != 0` → early-out to just `FUN_00618c30()` (busy /
  transition in progress).
- `cRam006c4fbc == 0` (not modal) → **screen switch** on `cRam006c4b90`; else modal path:
  - id ∈ {5,0xe,0xc,4,3,2} → `FUN_005aec70(ctx)` chooses `FUN_005b1a00` vs `FUN_005b1d10`.
  - otherwise → `FUN_005b1a00(ctx)`.
- Screen switch cases: 0→005b24e0, 1→thunk_005ace00, 2→005f76f0, 3→005f8d40, 4→005fe620, 5→00616c40,
  6→005f6aa0, 7→005ade20, 8→006177d0, 0xb→00617a50, 0xc→005ff950, 0xe→0062d5e0, 0xf→005af4d0
  (ids 9,0xa,0xd have no case → no-op draw).

## Constants & flags
- `0xe10` = 3600 (≈60 s @60 Hz) overlay timeout preload.
- `cRam006c4fbc` — modal/pause flag (non-zero ⇒ suspend normal screen SM).
- Screen ids per switch above; `case 7 = 005ade20` is the in-session screen.

## Corrected reconstruction
```c
extern u8  g_top_screen;   // 0x6c4b90 (also base of screen ctx block)
extern u8  g_modal;        // 0x6c4fbc
extern u8  g_fade;         // 0x6c4fc4
extern u16 g_ovl_timeout;  // 0x6c50e8
extern int g_frame;        // 0x6c4fb0

void lobby_overlay_frame_dispatch(void)
{
    if (FUN_005be330(g_35a6f4)) g_ovl_timeout = 0xe10;       // arm 60s timeout

    if (overlay_gate(&g_top_screen) != 0) return;            // FUN_005aedc0: not ready

    overlay_enter(&g_top_screen);                            // FUN_005aefb0
    overlay_tick (&g_top_screen);                            // FUN_005af090
    FUN_00627a20();
    if (g_fade) g_fade--;
    g_6c5524 = 0;

    if (busy_a(&g_top_screen) || busy_b(&g_top_screen)) {    // FUN_005ae770 / FUN_005ae3e0
        FUN_00618c30();
    } else {
        g_6c5522 = 0;
        if (g_modal == 0) {
            switch (g_top_screen) {
                case 0x00: menu_room_sm(&g_top_screen); break;   // FUN_005b24e0
                case 0x01: thunk_FUN_005ace00(&g_top_screen); break;
                case 0x02: FUN_005f76f0(&g_top_screen); break;
                case 0x03: FUN_005f8d40(&g_top_screen); break;
                case 0x04: FUN_005fe620(&g_top_screen); break;
                case 0x05: FUN_00616c40(&g_top_screen); break;
                case 0x06: FUN_005f6aa0(&g_top_screen); break;
                case 0x07: FUN_005ade20(&g_top_screen); break;   // in-session
                case 0x08: FUN_006177d0(&g_top_screen); break;
                case 0x0b: FUN_00617a50(&g_top_screen); break;
                case 0x0c: FUN_005ff950(&g_top_screen); break;
                case 0x0e: FUN_0062d5e0(&g_top_screen); break;
                case 0x0f: FUN_005af4d0(&g_top_screen); break;
            }
            FUN_00618c30();
            FUN_005b1d20(&g_top_screen);
        } else if (g_top_screen==5||g_top_screen==0xe||g_top_screen==0xc||
                   g_top_screen==4 ||g_top_screen==3 ||g_top_screen==2) {
            if (FUN_005aec70(&g_top_screen)==0) FUN_005b1a00(&g_top_screen);
            else                                FUN_005b1d10(&g_top_screen);
            FUN_00618c30();
        } else {
            FUN_005b1a00(&g_top_screen);
            FUN_00618c30();
        }
    }

    if (g_6c5560 && --g_6c5560 == 0) g_6c555f = 0;           // message-flash timer
    g_frame++;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005acab0.c`.
- Case 0 → FUN_005b24e0 (reconstructed lobby SM) confirms this is the online-screen router.
- Confidence **High** (explicit switch/globals); runtime **unvalidated** (screen-id→handler mapping
  inferred from targets, not observed live).

## Remaining uncertainty
- Exact roles of the busy gates (005ae770/005ae3e0) and post-pass helpers (005b1a00/005b1d10/005b1d20);
  the non-cased ids (9,0xa,0xd) may be dead or handled elsewhere.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acab0.c` — untouched decompiler output.
