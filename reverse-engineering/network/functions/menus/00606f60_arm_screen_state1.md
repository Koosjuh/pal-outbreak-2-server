# 0x00606f60 arm_screen_state1

| field | value |
|---|---|
| Original address | 0x00606f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606f60 |
| Resolved name | arm_screen_state1_mode7 |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_005ac400, FUN_00607370
**Callees:** func_0x00106b60 (memset)
**Referenced globals:** 0x70cdb8 (screen-state block, 0xc bytes; state word); 0x6c4faa (top_screen mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070cdb8; uRam006c4faa

## Behavioral explanation
Sibling of `reset_screen_state_mode7` (0x00606f10): also selects top_screen mode 7 and clears
the 0xc-byte screen-state block, but arms the state word to **1** instead of 0 — i.e. it enters
the room-query screen machine one step in (a re-entry / retry path that skips the state-0
initial step). Unlike 606f10 it does **not** touch the render callback (the caller is already
inside the render loop).

## Input / output
- No parameters, void return.

## Side effects
- `memset(0x70cdb8, 0, 0xc)` then `0x70cdb8 = 1` (state word = 1).
- `0x6c4faa = 7` (top_screen mode).

## Important branches
- Straight-line; no conditionals.

## Constants & flags
- state word **1** (vs 0 in 606f10) — advance-past-init entry.
- `top_screen` mode **7**; block 0x70cdb8 size 0xc.

## Corrected reconstruction
```c
void arm_screen_state1_mode7(void) {
    memset((void*)0x70cdb8, 0, 0xc);
    *(u32*)0x70cdb8 = 1;          // enter screen SM at state 1
    g_lobby.top_screen = 7;       // 0x6c4faa
}
```

## Evidence
- Raw decompile: FUN_00606f60.c (64 bytes) — memset then state=1, mode=7 confirmed.
- Contrast with FUN_00606f10 (state 0 + render re-arm) establishes the retry-vs-fresh split.
- Runtime-unvalidated.

## Remaining uncertainty
- Which callers use the state-1 entry vs state-0 (retry semantics not traced to a concrete flow).
