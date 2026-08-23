# 0x00606c80 reset_overlay_flags

| field | value |
|---|---|
| Original address | 0x00606c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606c80 |
| Resolved name | reset_lobby_sm_flags |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606af0, FUN_006088b0
**Callees:** —
**Referenced globals:** 0x6c4b9e (lobby_sm); 0x6c4b9f (screen_major); 0x6c4ba0 (screen_step); 0x6c4ba1; 0x6c4faa (top_screen mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa

## Behavioral explanation
Clears the lobby/create state-machine cursor and forces the top-menu dispatcher into mode 9.
Zeroes the four SM bytes in the lobby_state_block (`lobby_sm`, `screen_major`, `screen_step`,
and the byte after it) and sets `top_screen = 9`. Used when (re)entering the connect/room-query
screen so the create/join SM restarts from its initial step. Called from two overlay entry
paths (FUN_00606af0, FUN_006088b0).

## Input / output
- No parameters, void return.

## Side effects
- `0x6c4b9e = 0` (lobby_sm), `0x6c4b9f = 0` (screen_major / create-join major substate),
  `0x6c4ba0 = 0` (screen_step), `0x6c4ba1 = 0`.
- `0x6c4faa = 9` (top_screen dispatcher mode).

## Important branches
- None — straight-line stores.

## Constants & flags
- `top_screen` value **9** — the connect/room-query dispatch mode (menu_top_dispatch switch arm).
- All SM bytes cleared to 0 (initial step of the create/join machine).

## Corrected reconstruction
```c
void reset_lobby_sm_flags(void) {
    g_lobby.lobby_sm     = 0;   // 0x6c4b9e
    g_lobby.screen_major = 0;   // 0x6c4b9f
    g_lobby.screen_step  = 0;   // 0x6c4ba0
    g_lobby.screen_step2 = 0;   // 0x6c4ba1
    g_lobby.top_screen   = 9;   // 0x6c4faa
}
```

## Evidence
- Raw decompile: FUN_00606c80.c (48 bytes) — five literal stores confirmed.
- Field roles from lobby_state_block.md (0x6c4b9e lobby_sm, 0x6c4b9f screen_major,
  0x6c4ba0 screen_step, 0x6c4faa top_screen) and GLOBALS.md.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact switch arm reached by `top_screen == 9` (which concrete screen the dispatcher renders).
