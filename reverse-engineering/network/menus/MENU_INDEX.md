# MENU_INDEX — network screens & their handlers

_Auto-generated. Screens = switch targets of the two overlay dispatchers: menu_top_dispatch (state 0x6c4faa) and lobby_screen_dispatch (state 0x6c4b90). Each handler is one screen/step._

| Group | State var | Handler | Subsystem | Opcodes | Behavior |
|---|---|---|---|---|---|
| top-menu | 0x6c4faa (top screen) | 0x005ac400 menu_state3_step | menus | — | Top-state 3 step machine; drives substate fab through init/poll (FUN_00605fa0) with net-gl |
| top-menu | 0x6c4faa (top screen) | 0x005ac4c0 menu_confirm_dialog_step | menus | — | Top-state 0x17 step: countdown via fab/timer then reads pad bitmask (0x10,0x200) to branch |
| top-menu | 0x6c4faa (top screen) | 0x005ac810 menu_state0_step | menus | — | Top-state 0 step: initial substate arms libgfx, next substate sets a 0xe10 timer and calls |
| top-menu | 0x6c4faa (top screen) | 0x005aca20 menu_state1_render_wrap | menus | — | Top-state 1 step: brackets the in-lobby screen dispatch (FUN_005acab0) with render begin/e |
| top-menu | 0x6c4faa (top screen) | 0x005aca50 menu_state4_enter | menus | — | Top-state 4 handler: tears down then transitions to state 5 (fab=0, faa=5), clears 874f7c. |
| top-menu | 0x6c4faa (top screen) | 0x006063c0 lobby_conn_state_dispatch | session | — | Top-level lobby-connection dispatcher: switches on sRam0070cdc8 (0..6, 99) to the correspo |
| top-menu | 0x6c4faa (top screen) | 0x00606af0 session_login_state_machine | session | — | 6-case session/login driver (cRam006c4b9e): issues reliable requests via FUN_005b8cf0 (off |
| top-menu | 0x6c4faa (top screen) | 0x00606cb0 dispatch_by_conn_mode | menus | — | Branches to FUN_005f4550 or FUN_006082e0 depending on connection-mode flag 3c8a80. |
| top-menu | 0x6c4faa (top screen) | 0x00606cf0 roomlist_screen_tick | rooms | — | Per-frame state-machine dispatcher: switch(0070cdb8) states 0-5 into the room-query/select |
| top-menu | 0x6c4faa (top screen) | 0x00608300 login_connect_state_machine | session | — | Multi-phase connect/login state machine on cRam0070cda8 (0,1,2,'c',3,4,5,6): sprintf reque |
| top-menu | 0x6c4faa (top screen) | 0x006088b0 reconnect_state_machine | session | — | Connect/reconnect state machine on cRam0070cd98 (0-4): sprintf request into 0x701e20, conn |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005acda0 screen_obj_init_substate3 | menus | — | Initializes a screen-object struct: tag=1, [0xe]=3, [0xf]/[0x10]=0, stores param into 0x6c |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005ade20 screen7_session_sm | session | — | Lobby screen-7 state machine (+0xe): runs the session/connect sequence, snapshots a 0x1d0- |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005aec70 menu_item_action_dispatch | menus | — | Per-widget action dispatcher: gated by enable byte +0x45a, routes on pending-action (+0x99 |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005aedc0 menu_transition_timeout | menus | — | Per-frame menu transition/timeout driver: decrements timers (+0x558/+0x55c/+0x560), on inp |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005af4d0 screen_build_title_menu | menus | — | Builds a title/session menu screen: FSM on +0xe allocates widgets via widget_alloc (0x618b |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005b1a00 run_menu_task_if_active | menus | — | Thin guard: if the task-active flag at +0x438 is set, run the dialog/task dispatcher 0x5b1 |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005b1d10 clear_task_busy_flag | menus | — | One-liner: clears the modal-task busy flag at struct+0x42c. |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005b1d20 spawn_namelist_widget | roster | — | Allocates two UI elements and installs 0x5b1b10 as their callback to spawn the name-select |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005b24e0 lobby_menu_state_dispatch | lobby | — | Top-level lobby/menu screen state machine: switches on screen id +0xe (0-9) to the per-scr |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005be330 overlay_frame_driver | session | — | Master per-frame overlay tick: guarded by iRam006ca950, drives session poll (FUN_005c7d40/ |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005f6aa0 connect_flow_router | session | — | Top-level router: dispatches on the mode byte *(param+0x10) — modes 0-2 to FUN_005f6b00, m |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005f76f0 lobby_screen_dispatch | lobby | — | Per-frame dispatcher (gated by busy-check FUN_005aec70) routing on screen-id *(param+1): 0 |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005f8d40 roomlist_screen_dispatch | rooms | — | Per-frame dispatcher for the room-list screen (busy-gated FUN_005aec70): routes on *(param |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005fe620 lobby_menu_router | lobby | — | Top-level lobby menu router: guarded by FUN_005aec70, dispatches on current menu id (+1) t |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x005ff950 lobby_page_dispatcher | menus | — | Top-level lobby/room page dispatcher: gated on busy (FUN_005aec70), routes by phase byte + |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x00616c40 room_scene_state_dispatch | rooms | — | Per-tick dispatcher for the room scene: on major-state byte +0xe routes to phase handlers  |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x006177d0 modeB_scene_state_dispatch | menus | — | Per-tick dispatcher for a type-0x0b scene object: routes major-state +0xe (0..5) to six su |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x00617a50 list_menu_state_machine_618130 | menus | — | Per-tick state machine (minor +0xf 0..4) for a scene driven by table 0x618130: opens a UI  |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x00627a20 roster_display_tick_timers | roster | — | Per-frame tick: decrements the per-slot countdown at 0x715512 for every in-use roster disp |
| lobby | 0x6c4b90 (lobby sub-screen) | 0x0062d5e0 lobby_tick_gate | lobby | — | Per-frame tick entry: if FUN_005aec70()==0 and struct+1==0 run the major dispatcher FUN_00 |
