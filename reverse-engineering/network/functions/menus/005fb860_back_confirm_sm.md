# 0x005fb860 back_confirm_sm

| field | value |
|---|---|
| Original address | 0x005fb860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb860 |
| Resolved name | back_nav_dispatch_sm |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710 (per-frame screen dispatcher)
**Callees:** FUN_005b14b0 (poll input button-mask), FUN_005b9060 (load list), FUN_005b8cf0 (alt setup/build), FUN_005fba80 (rebuild room-list widgets), FUN_005b9110 (SFX cue)
**Referenced globals:** ctx +0x10 sub-state; +0x15 entry-mode; +0xe/+0xf/+0x10/+0x11 target page major/minor; +0x97c result/return-target code; +0x448/+0x449/+0x440 nav flags; +0x5ec list buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state (0..1); +0x97c result code

## Behavioral explanation
Back/return navigation dispatcher for a menu page. On the first frame it initializes and loads content (either a 20-entry list or an alternate build). On subsequent frames it waits for a confirm button (`FUN_005b14b0(0x210)`); once pressed it reads a **result/return-target code** at +0x97c and rewrites the page-selection fields (+0xe/+0xf/+0x10/+0x11) to route the UI to the correct destination page, clears nav flags, and plays a click SFX. Purely local navigation; no network opcodes.

## Input / output
- **param_1** (`int`, screen_ctx*): active page context.
- **returns** `void`. Navigation target expressed by rewriting +0xe/+0xf/+0x10/+0x11 (major/minor page selectors) that the outer dispatcher consumes next frame.

## Side effects
- +0x10 0→1 (init→wait).
- On confirm: +0xe/+0xf/+0x10/+0x11 set per result code; +0x440=0; SFX `FUN_005b9110(0x4c)`.
- result==4 path additionally clears +0x448/+0x449, sets +0x97c=1, and calls `FUN_005fba80()` to rebuild the room-list widget set (return-to-room-list).
- +0x5ec list buffer filled on init when entry-mode +0x15 == 0x14.

## Important branches
- **sub-state 0 (init):** set +0x10=1; if +0x15 == 0x14 → `FUN_005b9060(0x14, +0x5ec)` (load 20-entry list); else `FUN_005b8cf0()` (alternate content build).
- **sub-state 1 (wait for confirm):** poll `FUN_005b14b0(0x210)`; only act if a widget/button object is returned (≠0):
  - **result +0x97c == 4:** full reset (+0xe=+0xf=+0x10=+0x11=0, +0x448=+0x449=0), +0x97c=1, `FUN_005fba80()` → go back to the room-list page.
  - **result == 3:** target page (+0xe=2, +0xf=1, +0x10=0, +0x11=0).
  - **result == 2 / 1 / 0:** target page (+0xe=1, +0xf=0, +0x10=0, +0x11=0) — three codes collapse to the same destination.
  - **all confirm paths:** +0x440=0; `FUN_005b9110(0x4c)` click SFX.

## Constants & flags
- `0x210` = confirm/OK button-mask arg to `FUN_005b14b0` [inferred: OK/Circle poll].
- `0x14` = entry-mode selector at +0x15 and list length (20).
- `0x97c` result codes: 4 = return to room list; 3 = page(2,1); 0/1/2 = page(1,0). Evidence: literal dispatch.
- `0x4c` = SFX id (`FUN_005b9110`).

## Corrected reconstruction
```c
// Back/return dispatcher: confirm -> route to destination page by result code.
void back_nav_dispatch_sm(screen_ctx *s)   // param_1
{
    if (s->substate == 1) {                          // +0x10 : wait-for-confirm
        widget *w = input_poll(0x210);               // FUN_005b14b0(OK mask)
        if (w != 0) {
            switch (s->result_code) {                // +0x97c
            case 4:                                   // -> room list
                s->page_e = 0; s->page_f = 0;         // +0xe/+0xf
                s->substate = 0; s->page_11 = 0;      // +0x10/+0x11
                s->flag_448 = 0; s->flag_449 = 0;
                s->result_code = 1;
                roomlist_widgets_rebuild();           // FUN_005fba80
                break;
            case 3:
                s->page_e = 2; s->page_f = 1;
                s->substate = 0; s->page_11 = 0;
                break;
            case 2: case 1: case 0:
                s->page_e = 1; s->page_f = 0;
                s->substate = 0; s->page_11 = 0;
                break;
            }
            s->flag_440 = 0;                          // +0x440
            sfx_play(0x4c);                           // FUN_005b9110
        }
    }
    else if (s->substate == 0) {                      // init
        s->substate = 1;
        if (s->entry_mode == 0x14)                    // +0x15
            list_load(0x14, s->list_buf);             // FUN_005b9060
        else
            alt_content_build();                      // FUN_005b8cf0
    }
}
```

## Evidence
- Raw decompile `FUN_005fb860.c` (all result-code branches exact).
- `FUN_005fba80` is the room-list widget rebuilder (cross-ref: called on return in this SM and referenced by the room-list screen path).
- Page-selector fields +0xe/+0xf/+0x10/+0x11 are the menu-dispatch selectors used across the FUN_005fb710 family.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact meaning of the four page-selector bytes (+0xe/+0xf/+0x10/+0x11) as a coordinate into the page table is not fully mapped; only their reset values are known.
- `0x210` decoded as the OK/confirm mask by convention; not confirmed against the input table.
- `FUN_005b8cf0` content (the non-0x14 entry mode) not traced.
```
