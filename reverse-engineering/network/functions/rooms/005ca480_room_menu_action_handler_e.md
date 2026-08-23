# 0x005ca480 room_popup_menu_action_result1

| field | value |
|---|---|
| Original address | 0x005ca480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca480 |
| Resolved name | room_popup_menu_action_result1 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (bound as a per-frame menu handler via dispatch pointer)
**Callees:** FUN_005ca6a0 (rebuild_room_softmenu), FUN_005cce30 (resolve_member_roster / back), FUN_005d5b60 (dismiss popup / resume)
**Referenced globals:** `uRam00701e18` popup-result selector; `iRam00701070` menu-ctx → +0x2e phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** `*(iRam00701070+0x2e)`; `uRam00701e18`

## Behavioral explanation
Member (e) of the room-menu family, and the first of a twin pair (e/f) that resolve a two-choice room popup/confirm dialog. ACTION → record the chosen result by writing `uRam00701e18 = 1`, then dismiss the popup and resume via `FUN_005d5b60(0)`. The downstream consumer of `0x701e18` reads that selector to pick the follow-up action (result 1 here, result 2 in handler_f 0x005ca4f0). SCAN falls through to the shared roster scan.

## Input / output
- **Input:** none (void); implicit menu context.
- **Output:** void; sets `0x701e18 = 1` and closes the popup.

## Side effects
- `uRam00701e18 = 1` (popup-result selector).
- FUN_005d5b60(0) — popup dismiss / resume-parent.
- Soft-menu rebuild; possible +0x2e rewrite on SCAN.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) | `0x701e18 = 1`; FUN_005d5b60(0) |
| `menu_ctx+0x2e == 0x08` (SCAN)   | FUN_005cce30 |
| otherwise | return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a`, `MENU_PHASE_SCAN = 0x08`.
- `POPUP_RESULT = 1` at `0x701e18` (vs. `2` in the twin handler_f). Evidence: line 11; contrasted with 0x005ca4f0 line 11.

## Corrected reconstruction
```c
void room_popup_menu_action_result1(void)
{
    rebuild_room_softmenu();                 // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION) {
        g_popup_result /*0x701e18*/ = 1;
        popup_dismiss(0);                    // FUN_005d5b60
    }
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN) {
        resolve_member_roster();             // FUN_005cce30
    }
}
```

## Evidence
- Raw decompile lines 9–16; identical shape to 0x005ca4f0 except `0x701e18 = 1` vs `2`.
- Runtime-unvalidated.

## Remaining uncertainty
- What the two `0x701e18` values map to semantically (e.g. Yes/No, Enter/Cancel) — the consumer of `0x701e18` is not decompiled in this batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca480.c`  — untouched decompiler output.
