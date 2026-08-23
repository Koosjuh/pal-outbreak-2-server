# 0x005ca380 room_name_request_menu_action

| field | value |
|---|---|
| Original address | 0x005ca380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca380 |
| Resolved name | room_name_request_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (bound as a per-frame menu handler via dispatch pointer)
**Callees:** FUN_005ca6a0 (rebuild_room_softmenu), FUN_005cce30 (resolve_member_roster / back), FUN_005dedf0 (string copy), FUN_005d74a0 (build room request from name), FUN_005d5a40 (submit/advance)
**Referenced globals:** `iRam00701068` session arena base; `arena+0x4f97c` room-name work buffer; `iRam00701070` menu-ctx → +0x3b room-name field, +0x2e phase; `uRam00700fe8` request-armed flag
**Referenced strings:** —
**Referenced opcodes:** — (feeds a room enter/create request path)
**State vars:** `*(iRam00701070+0x2e)`; `uRam00700fe8`

## Behavioral explanation
Member (c) of the room-menu family. The ACTION branch is the "commit selected room by name" path: it copies the room-name string from the menu context (`menu_ctx+0x3b`) into the session work buffer (`arena+0x4f97c`) with FUN_005dedf0 (a string-copy/format helper), builds a room request keyed on that name via FUN_005d74a0, arms the request flag `uRam00700fe8 = 1`, and advances/submits via FUN_005d5a40. SCAN falls through to the shared roster scan.

`arena+0x4f97c` sits in the session pool region (0x4f370/0x4f588 family per GLOBALS.md), i.e. the room-list/request pool — consistent with staging a room-keyed request record.

## Input / output
- **Input:** none (void); implicit menu context + arena.
- **Output:** void; stages a room request (name copied, flag armed, submit called).

## Side effects
- Writes `arena+0x4f97c` = copy of `menu_ctx+0x3b` (room name). (FUN_005dedf0)
- Builds request record via FUN_005d74a0 over that buffer.
- Sets `uRam00700fe8 = 1` (request-armed flag; shared with other room submit paths 0x005ca560/0x005ca640 per GLOBALS.md).
- Calls FUN_005d5a40 (submit / SM advance).
- Soft-menu rebuild; possible +0x2e rewrite on SCAN.

## Important branches
| condition | consequence |
|---|---|
| `menu_ctx+0x2e == 0x0a` (ACTION) | copy name → build request → set flag 0x700fe8 → submit |
| `menu_ctx+0x2e == 0x08` (SCAN)   | FUN_005cce30 |
| otherwise | return |

## Constants & flags
- `MENU_PHASE_ACTION = 0x0a`, `MENU_PHASE_SCAN = 0x08`.
- `uRam00700fe8 = 1` — room-request-armed flag [inferred: co-used by sibling submit handlers].

## Corrected reconstruction
```c
// arena = *(char**)0x701068 ; room-name work buffer = arena + 0x4f97c
void room_name_request_menu_action(void)
{
    rebuild_room_softmenu();                          // FUN_005ca6a0

    if (menu_ctx->menu_phase /*+0x2e*/ == MENU_PHASE_ACTION) {
        strcopy(&arena[0x4f97c], &menu_ctx->room_name /*+0x3b*/); // FUN_005dedf0
        build_room_request(&arena[0x4f97c]);          // FUN_005d74a0
        g_room_request_armed /*0x700fe8*/ = 1;
        room_request_submit();                        // FUN_005d5a40
    }
    else if (menu_ctx->menu_phase == MENU_PHASE_SCAN) {
        resolve_member_roster();                      // FUN_005cce30
    }
}
```

## Evidence
- Raw decompile lines 9–19 (name copy from +0x3b, build 0x4f97c, flag 0x700fe8=1, submit).
- GLOBALS.md: 0x700fe8 flag shared with 0x005ca380/0x005ca560/0x005ca640 (submit family); 0x4f588/0x4f370 pool region.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether FUN_005d74a0 populates an op-level request or a purely local list node; and which wire op FUN_005d5a40 ultimately emits (enter 0x2b vs. list 0x49) — not decompiled here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca380.c`  — untouched decompiler output.
