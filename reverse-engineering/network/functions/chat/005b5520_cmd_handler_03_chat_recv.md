# 0x005b5520 cmd_handler_03_chat_recv

| field | value |
|---|---|
| Original address | 0x005b5520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5520 |
| Resolved name | chat_cmd03_recv_line_to_scrollback |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as command-selector 3 via FUN_005bdf70(3, 0x5b5520) from FUN_005b25c0)
**Callees:** FUN_005c3e80 (parse chat record → sender/name/text), FUN_00604860 (name filter/dedup lookup)
**Referenced globals:** 0x6c555e(log count); 0x6c555f/0x6c5560/0x6c5561(log redraw/header flags); 0x6c5562(scrollback ring, 8×0xa5); 0x870880(name filter table, 0x1e slots)
**Referenced strings:** —
**Referenced opcodes:** — (command-selector 3, not a wire opcode)

## Behavioral explanation
The **command-selector-3 handler**: inserts a received chat line into the 8-row on-screen chat
scrollback. It (1) zero-inits a 0xa4 scratch, (2) parses the pending message into three fields —
sender id (0x10), display name (0x14), and text (0x80) — via `FUN_005c3e80`, (3) runs the name
through a filter/dedup table (`FUN_00604860(table=0x870880, count=0x1e, name)`) and **only proceeds
when it returns -1** (name allowed / not filtered), (4) scrolls the ring down by one row (rows 0..6 →
1..7, freeing row 0), (5) writes the new line into row 0, and (6) bumps the visible-line count (cap 8),
sets the redraw/header flags, and plays notify SFX 3 (`FUN_001b0140(3)`). Each row is a
`chat_line` record of stride 0xa5: `{ valid(1), sender[0x10], name[0x10], gap[4], text[0x80] }`.

## Input / output
- No parameters (reads the module's pending-message state via `FUN_005c3e80`).
- Returns void. Effect is entirely on the scrollback globals.

## Side effects
- Shifts the 8-entry ring `chat_scrollback[0..6]` down into `[1..7]` (0xa5 bytes each).
- Writes row 0: valid=1 (0x6c5562), sender (0x6c5563), name (0x6c5573), text (0x6c5587).
- `chat_log_count (0x6c555e)++`, clamped to 8.
- Sets header/redraw flags: `0x6c5560 = 0xe0`, `0x6c5561 = 1`, `0x6c555f = 1`.
- Plays notify SFX id 3 (`FUN_001b0140(3)`).

## Important branches
- `FUN_00604860(0x870880, 0x1e, name) != -1` (name found/filtered) → **do nothing**, return. Only a
  -1 (name not in the filter table) allows the insert. (Mute / ignore-list gate.)
- `chat_log_count + 1 > 8` → clamp to 8.

## Constants & flags
- `0xa5` (165) — chat_line stride = 1 + 0x10 + 0x10 + 4 + 0x80.
- `8` — ring capacity / max visible lines.
- `0x1e` (30) — filter table slot count at 0x870880.
- `0xe0` / `1` — header redraw flags at 0x6c5560 / 0x6c5561 / 0x6c555f.
- `3` — notify SFX id passed to FUN_001b0140.

## Corrected reconstruction
```c
// chat_line: 0xa5-byte scrollback row.
typedef struct { u8 valid; char sender[0x10]; char name[0x10]; u8 gap[4]; char text[0x80]; } chat_line; // 0xa5
static chat_line chat_scrollback[8];   // @0x6c5562
static u8  chat_log_count;             // @0x6c555e
// header/redraw flags @0x6c555f,0x6c5560,0x6c5561

void chat_cmd03_recv_line_to_scrollback(void) {
    u8 sender[0x10], name[0x14], text[0x8c];
    memset(sender, 0, 0xa4);
    parse_chat_record(sender, name, text);              // FUN_005c3e80

    if (name_filter_lookup(0x870880, 0x1e, name) != -1) // FUN_00604860: in ignore list?
        return;                                          // filtered → drop

    for (int d = 7; d > 0; d--)                          // scroll ring down, free row 0
        memcpy(&chat_scrollback[d], &chat_scrollback[d-1], 0xa5);

    chat_scrollback[0].valid = 1;                        // 0x6c5562
    memcpy(chat_scrollback[0].sender, sender, 0x10);     // 0x6c5563
    memcpy(chat_scrollback[0].name,   name,   0x10);     // 0x6c5573
    memcpy(chat_scrollback[0].text,   text,   0x80);     // 0x6c5587

    *(u8*)0x6c5560 = 0xe0; *(u8*)0x6c5561 = 1; *(u8*)0x6c555f = 1; // redraw flags
    if (++chat_log_count > 8) chat_log_count = 8;
    play_notify_sfx(3);                                  // FUN_001b0140(3)
}
```

## Evidence
- Raw: nested copy loop `puVar4 = iVar6*0xa5 + 0x6c5562; puVar3 = iVar5*0xa5 + 0x6c5562;` with iVar5:7→1, iVar6:6→0 ⇒ shift-down.
- Row writes: `0010a4f0(0x6c5563, sender,0x10); (0x6c5573, name,0x10); (0x6c5587, text,0x80)` at offsets +1/+0x11/+0x25 of the 0xa5 row.
- `FUN_00604860(0x870880,0x1e, name)` guarded by `== -1` ⇒ allow-list/mute filter.
- Installed as selector 3 (memory note: FUN_005bdf70(3, 0x5b5520)).
- Runtime-unvalidated.

## Remaining uncertainty
- Exact field widths inside `FUN_005c3e80`'s output (sender 0x10 vs name 0x14) and whether 0x870880 is a *mute* list vs a *seen* dedup cache. The 4-byte gap in the row (between name and text) is unlabeled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5520.c`  — untouched decompiler output.
