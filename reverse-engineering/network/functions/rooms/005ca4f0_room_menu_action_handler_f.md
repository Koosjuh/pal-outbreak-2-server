# 0x005ca4f0 room_popup_menu_action_result2

| field | value |
|---|---|
| Original address | 0x005ca4f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca4f0 |
| Resolved name | room_popup_menu_action_result2 |
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
Twin of handler_e (0x005ca480); the only difference is the popup-result value. ACTION → `uRam00701e18 = 2`, then dismiss/resume via `FUN_005d5b60(0)`. SCAN falls through to the shared roster scan. Bound to the second choice of the same two-choice room popup.

## Input / output
- **Input:** none (void); implicit menu context.
- **Output:** void; sets `0x701e18 = 2` and closes the popup.

## Side effects
- `uRam00701e18 = 2` (popup-result selector).
- FUN_005d5b60(0) — popup dismiss / resume-parent.
- Soft-menu rebuild; possible +0x2e rewrite on SCAN.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) | `0x701e18 = 2`; FUN_005d5b60(0) |
| `menu_ctx+0x2e == 0x08` (SCAN)   | FUN_005cce30 |
| otherwise | return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a`, `MENU_PHASE_SCAN = 0x08`.
- `POPUP_RESULT = 2` at `0x701e18` (vs. `1` in twin handler_e). Evidence: line 11.

## Corrected reconstruction
```c
void room_popup_menu_action_result2(void)
{
    rebuild_room_softmenu();                 // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION) {
        g_popup_result /*0x701e18*/ = 2;
        popup_dismiss(0);                    // FUN_005d5b60
    }
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN) {
        resolve_member_roster();             // FUN_005cce30
    }
}
```

## Evidence
- Raw decompile lines 9–16; byte-identical to 0x005ca480 apart from the stored value.
- Runtime-unvalidated.

## Remaining uncertainty
- Same as handler_e: the semantic meaning of result 1 vs 2 depends on the (undecoded) `0x701e18` consumer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca4f0.c`  — untouched decompiler output.
