# 0x005ca320 room_refresh_menu_action

| field | value |
|---|---|
| Original address | 0x005ca320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca320 |
| Resolved name | room_refresh_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (bound as a per-frame menu handler via dispatch pointer)
**Callees:** FUN_005ca6a0 (rebuild_room_softmenu), FUN_005cce30 (resolve_member_roster / back), FUN_005d59f0 (room refresh/send action)
**Referenced globals:** `iRam00701070` menu-context ptr → +0x2e menu-phase byte
**Referenced strings:** —
**Referenced opcodes:** — (FUN_005d59f0 is a room refresh/list-request path)
**State vars:** `*(iRam00701070+0x2e)`

## Behavioral explanation
Member (b) of the six-handler room-menu family (see 0x005ca290 for the shared shape). Rebuilds the soft-menu, then on menu-phase `+0x2e`:
- **ACTION (0x0a):** invokes FUN_005d59f0 — a single-shot room refresh/send action (no selection sub-index, unlike handler_a).
- **SCAN (0x08):** falls through to the shared roster scan / back (FUN_005cce30).

This is the simplest ACTION variant: one confirm → one action call, no `+0x2c` sub-branch.

## Input / output
- **Input:** none (void); implicit global menu context.
- **Output:** void; effect is FUN_005d59f0's room-refresh side effects.

## Side effects
- Soft-menu rebuild (0x005ca6a0).
- FUN_005d59f0's effects on ACTION (room list/refresh request).
- Possible `+0x2e` 8↔10 rewrite in 0x005cce30 on SCAN.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) | FUN_005d59f0 (room refresh) |
| `menu_ctx+0x2e == 0x08` (SCAN)   | FUN_005cce30 (roster scan / back) |
| otherwise | return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a`, `MENU_PHASE_SCAN = 0x08` — same enum as the family (evidence in 0x005cce30 which writes both).

## Corrected reconstruction
```c
void room_refresh_menu_action(void)
{
    rebuild_room_softmenu();                 // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION)
        room_refresh_send();                 // FUN_005d59f0
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN)
        resolve_member_roster();             // FUN_005cce30
}
```

## Evidence
- Raw decompile lines 9–16.
- Family/enum evidence shared with 0x005ca290 (soft-menu + phase dispatch).
- Runtime-unvalidated; the precise behavior of FUN_005d59f0 (refresh vs. re-request) not traced.

## Remaining uncertainty
- Whether FUN_005d59f0 issues a wire request (op49 room-list re-query) or only a local view refresh — not decompiled here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca320.c`  — untouched decompiler output.
