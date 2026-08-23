# 0x005b24e0 lobby_menu_state_dispatch

| field | value |
|---|---|
| Original address | 0x005b24e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b24e0 |
| Resolved name | lobby_menu_state_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0 (top-screen id 0)
**Callees:** FUN_005b25c0 (0 init), FUN_005b29b0 (1), FUN_005b2bc0 (2 entry), FUN_005b3070 (3), FUN_005b33f0 (4), FUN_005b3510 (5), FUN_005b3590 (6), FUN_005b3790 (7), FUN_005b2e40 (8), FUN_005b4a50 (9)
**Referenced globals:** — (dispatch is on the passed context block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0xe menu sub-state selector

## Behavioral explanation
Second-level state router for the lobby/room menu (top-screen 0). Reached once per frame from
`lobby_overlay_frame_dispatch`. It switches on the menu sub-state byte at `ctx+0xe` (0..9) and calls the
matching sub-screen handler. Each sub-handler owns its own finer state at `ctx+0xf` (e.g. the entry
handler FUN_005b2bc0 is an 8-step machine on `ctx+0xf`). This is the backbone that walks the client from
lobby init → server/area list → room list → entering a room.

The `ctx` is the same `0x6c4b90` screen-context block the outer dispatcher operates on; `+0xe` is the
menu page and `+0xf` the per-page step.

## Input / output
- **param_1** = `screen_ctx *ctx` (= `0x6c4b90`). Void return.

## Side effects
- None directly; delegates entirely. Sub-handlers mutate `ctx` and drive network sends.

## Important branches
- `switch (ctx->menu_state /*+0xe*/)`: 0→005b25c0, 1→005b29b0, 2→005b2bc0, 3→005b3070, 4→005b33f0,
  5→005b3510, 6→005b3590, 7→005b3790, 8→005b2e40, 9→005b4a50; out-of-range → no-op.

## Constants & flags
- Menu-state ids (inferred from handler behaviour): 0 init/handler-install, 1 connect/handshake,
  2 lobby-entry (password/join), 3 room-list, 4 wait/refresh, 5 transfer, 6 state-6, 7 char/scenario,
  8 connect-2, 9 table-load. (Names inferred; only the id→handler mapping is certain.)

## Corrected reconstruction
```c
enum lobby_menu_state {   // ctx+0xe  (names [inferred])
    LMS_INIT       = 0,   // FUN_005b25c0 — installs id-keyed cmd handlers
    LMS_CONNECT    = 1,   // FUN_005b29b0
    LMS_ENTRY      = 2,   // FUN_005b2bc0 — lobby/room entry (password, join)
    LMS_ROOMLIST   = 3,   // FUN_005b3070
    LMS_WAIT       = 4,   // FUN_005b33f0
    LMS_XFER       = 5,   // FUN_005b3510
    LMS_STATE6     = 6,   // FUN_005b3590
    LMS_CHARSEL    = 7,   // FUN_005b3790
    LMS_CONNECT2   = 8,   // FUN_005b2e40
    LMS_TABLELOAD  = 9,   // FUN_005b4a50
};

void lobby_menu_state_dispatch(screen_ctx *ctx)
{
    switch (ctx->menu_state) {          // *(u8*)(ctx + 0xe)
        case LMS_INIT:      FUN_005b25c0(); break;
        case LMS_CONNECT:   FUN_005b29b0(); break;
        case LMS_ENTRY:     FUN_005b2bc0(); break;   // reconstructed: screen_lobby_entry
        case LMS_ROOMLIST:  FUN_005b3070(); break;
        case LMS_WAIT:      FUN_005b33f0(); break;
        case LMS_XFER:      FUN_005b3510(); break;
        case LMS_STATE6:    FUN_005b3590(); break;
        case LMS_CHARSEL:   FUN_005b3790(); break;
        case LMS_CONNECT2:  FUN_005b2e40(); break;
        case LMS_TABLELOAD: FUN_005b4a50(); break;
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005b24e0.c`.
- Case 2 confirmed = FUN_005b2bc0 (reconstructed lobby-entry SM keyed on ctx+0xf); case 0 installs the
  id-keyed command handlers (FUN_005b25c0 → registers e.g. area-refresh handler FUN_005b53b0).
- Confidence **High** (explicit switch); runtime **unvalidated** — the state names beyond the mapping
  are inferred.

## Remaining uncertainty
- The precise semantic name of each menu state (only 0/2 are strongly grounded via their handlers).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b24e0.c` — untouched decompiler output.
