# 0x005ca420 room_enter_menu_action

| field | value |
|---|---|
| Original address | 0x005ca420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca420 |
| Resolved name | room_enter_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (bound as a per-frame menu handler via dispatch pointer)
**Callees:** FUN_005ca6a0 (rebuild_room_softmenu), FUN_005cce30 (resolve_member_roster / back), FUN_005d0a40 (enter/select current room — probes slot via 0x005d73c0)
**Referenced globals:** `iRam00701070` menu-ctx → +0x2e phase
**Referenced strings:** —
**Referenced opcodes:** — (FUN_005d0a40 leads to the enter path; wire op 0x2b/0x26 downstream)
**State vars:** `*(iRam00701070+0x2e)`

## Behavioral explanation
Member (d) of the room-menu family. ACTION → FUN_005d0a40, which is the "act on the currently-selected room" path: FUN_005d0a40 calls `cur_room_slot_probe` (0x005d73c0) to test whether the current room has a free/occupiable slot, gating an enter attempt. SCAN falls through to the shared roster scan. Single-action variant like handler_b, but the action is room-enter rather than refresh.

## Input / output
- **Input:** none (void); implicit menu context + current-room cursor `uRam00701018`.
- **Output:** void; effect is an enter/select attempt on the current room.

## Side effects
- Soft-menu rebuild.
- FUN_005d0a40 enter/select effects (slot probe + possible enter request).
- Possible +0x2e rewrite on SCAN.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) | FUN_005d0a40 (enter/select current room) |
| `menu_ctx+0x2e == 0x08` (SCAN)   | FUN_005cce30 |
| otherwise | return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a`, `MENU_PHASE_SCAN = 0x08`.

## Corrected reconstruction
```c
void room_enter_menu_action(void)
{
    rebuild_room_softmenu();                 // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION)
        room_enter_selected();               // FUN_005d0a40 -> cur_room_slot_probe (005d73c0)
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN)
        resolve_member_roster();             // FUN_005cce30
}
```

## Evidence
- Raw decompile lines 9–16.
- Callee FUN_005d0a40 → cur_room_slot_probe (0x005d73c0) which tests slot occupancy (mode 1 then 2) — establishes the enter/slot-gate semantics.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether FUN_005d0a40 issues the enter wire op directly or only sets up the SM; the "full vs. free" branch inside cur_room_slot_probe is only partially understood.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca420.c`  — untouched decompiler output.
