# 0x00606ac0 login_state_reset

| field | value |
|---|---|
| Original address | 0x00606ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606ac0 |
| Resolved name | login_state_reset (alt: lobby_screen_sm_reset) |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006075e0, FUN_00608300, FUN_006088b0
**Callees:** FUN_00606a50
**Referenced globals:** uRam006c4b9e (lobby_sm); uRam006c4b9f (screen_major); uRam006c4ba0 (screen_step); uRam006c4ba1; uRam006c4faa (top_screen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b9e / 0x6c4b9f / 0x6c4ba0 / 0x6c4ba1 / 0x6c4faa

## Behavioral explanation
Re-initializes the lobby/room screen state machine held in `lobby_state_block` (base 0x6c4b90) and
clears the async-op slot. It zeroes the SM tuple `lobby_sm` (0x6c4b9e), `screen_major` (0x6c4b9f),
`screen_step` (0x6c4ba0) and the adjacent byte 0x6c4ba1, and forces `top_screen` (0x6c4faa) to `8`
— i.e. it parks the top-menu dispatcher at state 8 while the sub-SM restarts from zero. It then
calls `async_op_state_reset` (FUN_00606a50) so no stale request is pending. This is the "return the
lobby screen to a known idle" routine invoked on entry to / exit from the enter-confirm and
create/enter flows (callers FUN_006075e0 enter-confirm, FUN_00608300, FUN_006088b0).

## Input / output
- **Params:** none.
- **Returns:** void.
- **Meaning:** SM reset.

## Side effects (all writes to `lobby_state_block`)
- `0x6c4b9e (lobby_sm) = 0`
- `0x6c4b9f (screen_major) = 0`
- `0x6c4faa (top_screen) = 8`
- `0x6c4ba0 (screen_step) = 0`
- `0x6c4ba1 = 0`
- `FUN_00606a50()` — clears the async request slot (0x70cd90/0x70cd88).

## Important branches
None. Straight-line reset.

## Constants & flags
- `top_screen = 8` — target top-menu dispatcher state after reset (specific screen; see menu_top_dispatch).
- `0` — idle for the SM tuple bytes.

## Corrected reconstruction
```c
// lobby_state_block @ 0x6c4b90 (see structure-layouts/lobby_state_block.md)
extern struct lobby_state_block g_lobby;   // 0x006c4b90

extern void async_op_state_reset(void);    // FUN_00606a50

// Reset the lobby/room screen SM to idle and park the top menu at state 8.
void login_state_reset(void)               // aka lobby_screen_sm_reset
{
    g_lobby.lobby_sm      = 0;   // 0x6c4b9e
    g_lobby.screen_major  = 0;   // 0x6c4b9f
    g_lobby.top_screen    = 8;   // 0x6c4faa
    g_lobby.screen_step   = 0;   // 0x6c4ba0
    *(uint8_t*)0x006c4ba1 = 0;   // adjacent SM byte [inferred: screen_substep]
    async_op_state_reset();
}
```

## Evidence
- Raw writes map 1:1 onto documented `lobby_state_block` offsets (0x6c4b9e/9f/a0, 0x6c4faa) —
  structure-layouts/lobby_state_block.md.
- Callee FUN_00606a50 is the async-slot reset — this pairs the SM reset with a request-slot clear.
- Confidence **High** on which fields/values; the "login" label predates the struct mapping, so
  `lobby_screen_sm_reset` is the more accurate name. Runtime unvalidated.

## Remaining uncertainty
Meaning of 0x6c4ba1 (labeled here screen_substep, [inferred]) and the exact semantics of top_screen
state `8` are not independently confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606ac0.c`  — untouched decompiler output.
