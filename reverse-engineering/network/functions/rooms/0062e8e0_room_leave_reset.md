# 0x0062e8e0 room_enter_arm_queries  (orig. "room_leave_reset")

| field | value |
|---|---|
| Original address | 0x0062e8e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e8e0 |
| Resolved name | room_enter_arm_queries |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062dc40 `create_room_flow` (step 4, on create-**success** `result==0`); FUN_0062de90 (room-enter flow)
**Callees:** FUN_005aec20 (apply lobby state block); FUN_005c0f60 (room-detail request, cb 0x62ef80); FUN_005c2820 (player-count request, cb 0x62eff0)
**Referenced globals:** lobby_state_block 0x6c4b9e (lobby_sm←3, in-room) / 0x6c4b9f (screen_major←0) / 0x6c4ba0 (screen_step←0) / 0x6c4ba1←0; 0x6c4600 selected-room id; 0x6c79ac room-detail/roster buffer (0xec0 bytes = 4×0x3b0); 0x6c4fe6 / 0x6c4fe8 player-data fields; 0x6c550d / 0x6c550f flags; 0x6c5510 / 0x6c5514(=0x3c) / 0x6c5518(=0x14) timers
**Referenced strings:** —
**Referenced opcodes:** room-detail + player-count queries via FUN_005c0f60 / FUN_005c2820 (reply cbs 0x62ef80 / 0x62eff0)
**State vars:** 0x6c4b9e/9f/ba0/ba1 lobby sub-states; 0x6c550d/550f flags

## Behavioral explanation
**NAME CORRECTION:** despite the `FUN_0062e8e0` grouping next to the leave handlers and the prior "room_leave_reset" label, the deep read shows this is the **room-ENTER commit**: it is called only on create-**success** (`create_room_flow` step 4, `result==0`) and from the enter flow (`FUN_0062de90`), and it drives the lobby state block *into* the room (`lobby_sm 0x6c4b9e = 3` = in-room), not out of it (`room_back_exit` 0x0062e800 sets it to `1`). It is the "I am now in the room, set up the in-room view" hook.

What it does, in order: reset the create/join sub-state (`screen_major 0x6c4b9f=0`, `screen_step 0x6c4ba0=0`, `0x6c4ba1=0`), set `lobby_sm 0x6c4b9e = 3` (in-room), and **commit the block** via `FUN_005aec20(0x6c4b90)` so the lobby dispatcher switches to the in-room screen. It then **clears the in-room room-detail / roster buffer** at `0x6c79ac` (0xec0 bytes = 4 roster rows × 0x3b0 — the same-sized region as the drawn roster table 0x6c7c2c), resets the in-room player-data fields (`0x6c4fe6=0`, `0x6c4fe8=0`) and the frame timers (`0x6c5510=0`, `0x6c5514=0x3c`, `0x6c5518=0x14`, `0x6c550f=0`, `0x6c550d=1`), and finally **fires the two in-room queries** against the just-entered room `0x6c4600`: `FUN_005c0f60(room, 0x62ef80)` (room detail) and `FUN_005c2820(room, 0x62eff0)` (player count). Clearing `0x6c79ac` before the queries is why the roster/count start blank until the replies land — the same "zero-then-refill" pattern as `roster_screen_enter` (0x0062bb20).

This is directly on the create-room-roster path: on a **successful create**, `create_room_flow` calls this to enter the host into the room view and request the detail + player count. If the server never actually inserted the host (the create-registration blocker), these queries return an empty/1-of-0 room, which matches the observed "1/0P, only CREATOR" symptom.

## Input / output
- No parameters (`void`). Operates entirely on globals; reads selected room `0x6c4600`.
- Returns `void`. Progress via the two reply cbs (0x62ef80 room detail, 0x62eff0 player count) that fill the in-room view.

## Side effects
- Lobby block: `0x6c4b9f=0`, `0x6c4ba0=0`, `0x6c4b9e=3` (in-room), `0x6c4ba1=0`; `FUN_005aec20(0x6c4b90)` apply.
- `0x6c4fe8=0`, `0x6c550d=1`, `0x6c4fe6=0`.
- `memset(0x6c79ac, 0, 0xec0)` — clear the room-detail / roster region (4×0x3b0).
- Timers/flags: `0x6c5510=0`, `0x6c5514=0x3c` (60), `0x6c5518=0x14` (20), `0x6c550f=0`.
- `FUN_005c0f60(0x6c4600, 0x62ef80)` — room-detail request (reply cb 0x62ef80).
- `FUN_005c2820(0x6c4600, 0x62eff0)` — player-count request (reply cb 0x62eff0).

## Important branches
None — straight-line. It is an unconditional in-room setup routine (the branching lives in its callers: `create_room_flow` only reaches it on `result==0`).

## Constants & flags
- `0x6c4b9e (lobby_sm) = 3` = **in-room** (contrast `room_back_exit` sets `1` = room-list). See `lobby_state_block`.
- Roster/detail buffer `0x6c79ac`, cleared length `0xec0` = `4 × 0x3b0` — matches the 4-row roster table stride (`roster_table` 0x6c7c2c, 4×0x3b0). Same zero-then-refill idiom as `roster_screen_enter` clearing `+0x10b8`/`+0x12c2`.
- Timers: `0x6c5514 = 0x3c` (60 frames ≈ 1 s), `0x6c5518 = 0x14` (20 frames). `0x6c5510/550f/550d` = in-room refresh flags/counters.
- Player-data fields `0x6c4fe6`/`0x6c4fe8` (paged selection fields per GLOBALS 0x6c4fe6/fe8).
- Reply cbs: `0x62ef80` = room-detail handler (`FUN_0062ef80`), `0x62eff0` = player-count handler (`FUN_0062eff0`).
- `FUN_005aec20(0x6c4b90)` = apply/commit lobby state block (shared with `room_back_exit`). `FUN_005c0f60`/`FUN_005c2820` = the in-room detail/count request primitives.

## Corrected reconstruction
```c
// Called on room ENTER (create-success or join-enter). Sets the in-room view up.
void room_enter_arm_queries(void)   // FUN_0062e8e0  (misnamed "room_leave_reset")
{
    // --- drive the lobby state block INTO the room ---
    g_lobby.screen_major /*0x6c4b9f*/ = 0;
    g_lobby.screen_step  /*0x6c4ba0*/ = 0;
    g_lobby.lobby_sm     /*0x6c4b9e*/ = 3;   // in-room
    g_lobby.f4ba1        /*0x6c4ba1*/ = 0;
    lobby_block_apply(&g_lobby /*0x6c4b90*/);   // FUN_005aec20

    // --- reset in-room view state ---
    g_inroom.f4fe8 /*0x6c4fe8*/ = 0;
    g_inroom.f550d /*0x6c550d*/ = 1;
    g_inroom.f4fe6 /*0x6c4fe6*/ = 0;
    memset((void*)0x6c79ac, 0, 0xec0);       // clear roster/detail (4 x 0x3b0)

    unsigned char room = (unsigned char)g_selected_room; /*0x6c4600*/
    g_inroom.t5510 /*0x6c5510*/ = 0;
    g_inroom.t5514 /*0x6c5514*/ = 0x3c;      // 60
    g_inroom.t5518 /*0x6c5518*/ = 0x14;      // 20
    g_inroom.f550f /*0x6c550f*/ = 0;

    // --- arm the two in-room queries against the entered room ---
    request_room_detail(g_selected_room, &cb_detail /*0x62ef80*/);  // FUN_005c0f60
    request_player_count(room,           &cb_count  /*0x62eff0*/);  // FUN_005c2820
}
```
Straight-line; note the raw snapshots `0x6c4600` into a local (`uVar1`) before the second call — reproduced as `room`.

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062e8e0.c` (204 bytes). Callers FUN_0062dc40 (create step 4, `result==0` = success) and FUN_0062de90 (enter) — **both are entering, never leaving** → the "leave_reset" name is a misnomer; renamed `room_enter_arm_queries`.
- `0x6c4b9e = 3` (in-room) vs `room_back_exit`'s `0x6c4b9e = 1` (room-list) is the decisive tell for enter-vs-exit; both use the same `FUN_005aec20` block-apply. See `lobby_state_block`.
- `memset(0x6c79ac, 0, 0xec0)` where `0xec0 = 4×0x3b0` = the roster-table size (`roster_table` 0x6c7c2c) → this clears the in-room roster/detail region before refill.
- Selected room `0x6c4600` is the global latched by `roomlist_select_scan` (0x0062dae0) and consumed by `room_join_sequence` (0x0062e440).
- Directly relevant to the create-room-roster blocker: on create-success this arms the detail/count queries; an empty result here is the "1/0P only CREATOR" surface symptom when the host was never inserted server-side.
- Runtime-unvalidated but High (clean straight-line code, all globals corroborated).

## Remaining uncertainty
- Which app opcodes `FUN_005c0f60` (room detail) and `FUN_005c2820` (player count) put on the wire — inferred from the cbs' downstream use (0x62ef80 fills detail, 0x62eff0 fills count) and the `0x6970f4`/`0x6970a0` detail globals, but not proven here.
- Exact roles of `0x6c550d/550f/5510` and player-data `0x6c4fe6/fe8` within the in-room refresh loop.
- Whether the reply cbs feed the op0a/op28 member-list or a separate room-detail (op1e/op22) channel.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e8e0.c`  — untouched decompiler output.
