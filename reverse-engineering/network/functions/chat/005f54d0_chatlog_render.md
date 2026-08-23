# 0x005f54d0 chatlog_render

| field | value |
|---|---|
| Original address | 0x005f54d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f54d0 |
| Resolved name | chatlog_render_window |
| Subsystem | chat |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f84c0, FUN_005fec30, FUN_00601d50, FUN_00602340
**Callees:** FUN_005af2e0 (set font/palette base), FUN_005af1e0 (draw text), FUN_005af2c0 (set color), FUN_005f4ed0 (scroll-up input count), FUN_005f4fd0 (scroll-down input count), FUN_005f5300 (set line color), func_0x001ae3e0 (strlen)
**Referenced globals:** iRam003435d4 (+0xc9358 head / +0xc935c view / +0xc9360 tail); chatBase +0xc8000; 0x6c54d0 (per-row attr cache, byte[]); 0x6c54e0 (per-row x cache, short[]); 0x649718 (name/message separator glyph); DAT_00692ec8 (font advance); cRam006c50fb (log-mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** view +0xc935c; cRam006c50fb

## Behavioral explanation
Draws the visible chat-log window. Given a window mode (`param_1` = 0/1/2) it selects a row count
and a base Y, computes the top-of-window slot (`view`), then draws up to N rows: for each slot with
a non-empty name it draws the name, a separator glyph, and the message text, coloring each field via
`chatlog_set_line_color` (0x5f5300). It also populates two per-row caches (`0x6c54d0` visible/attr,
`0x6c54e0` message-x) later consumed by the per-line display-node callback (0x5f5970).

Scroll model:
- **Live mode** (`cRam006c50fb == 0`): auto-follow. `view` is recomputed each call as `head - rowCount`
  (mod 50), clamped so it never precedes `tail` (if fewer than a full window of messages exist, start at `tail`).
- **History mode** (`!= 0`): manual scroll. `FUN_005f4ed0()` = scroll-up steps, `FUN_005f4fd0()` = scroll-down
  steps. Up moves `view` toward `tail` (bounded); down moves `view` toward `head` while the gap exceeds rowCount.

Window presets:
| mode (param_1) | rows | baseY | notes |
|---|---|---|---|
| 2 | 11 | 100.0 | tallest window |
| 1 | 5  | 96.0  | compact |
| 0 | 10 | 84.0  | default lobby |

## Input / output
- `param_1` (int) — window mode 0/1/2 (row count + geometry). Values outside 0..2 leave rows/baseY
  uninitialized (decompiler `unaff` regs) — caller is expected to pass 0/1/2 only.
- returns `void`.

## Side effects
- Draw calls: `FUN_005af2e0(0x12)` (base font), `FUN_005af1e0(x,y,0,str)` (text), `FUN_005af2c0(idx)` (color).
- Writes `view` (+0xc935c) with the computed scroll anchor.
- Writes per-row caches `0x6c54d0[row]` (attr D / visibility seed) and `0x6c54e0[row]` (message start x).

## Important branches
- Mode select `param_1 == 2/1/0` -> (rows, baseY) = (11,100)/(5,96)/(10,84).
- `cRam006c50fb == 0` (live): `gap = (head - tail) mod 50`; `gap < rows ? view = tail : view = (head - rows) mod 50`.
- else (history): `up = FUN_005f4ed0()`. `up == 0` -> down path: `n = FUN_005f4fd0()`; loop n times: if
  `(head - view) mod 50 > rows` then `view = (view + 1) mod 50`. `up != 0` -> loop up times: if `view != tail`
  then `view = (view - 1) mod 50`.
- Per row: `if (name[view] != '\0')` -> draw name + separator, seed `0x6c54d0[row]=attrD`, `0x6c54e0[row]=x`.
  Empty name row -> skip name, message drawn at default x=64.
- Message: always attempts to draw slot C (the `iVar5 != 0` guard is address-truthy, effectively always taken).

## Constants & flags
- Row counts `11 / 5 / 10`, base Y `100 / 96 / 84`, per-row Y step `20.0`.
- Name x = `0x40` (64). Separator drawn from `0x649718`; message x advances by `DAT_00692ec8`-derived
  `fVar10 = 18.0 - DAT_00692ec8` per half-char, +`fVar10*2` past the separator.
- `0x12` — base font/palette id passed to `FUN_005af2e0`.
- `0x6c54d0` = `u8[rows]` visibility/attr cache; `0x6c54e0` = `s16[rows]` message-start-x cache.
- `cRam006c50fb` — live(0) vs history(≠0) scroll mode.

## Corrected reconstruction
```c
void chatlog_render_window(int mode /*param_1*/)
{
    int base = iRam003435d4;
    u8 *chat = (u8 *)(base + 0xc8000);
    FUN_005af2e0(0x12);                          // base font
    float halfAdv = 18.0f - DAT_00692ec8;

    int   rows;  float baseY;
    if      (mode == 2) { rows = 11; baseY = 100.0f; }
    else if (mode == 1) { rows = 5;  baseY = 96.0f;  }
    else /* mode == 0*/ { rows = 10; baseY = 84.0f;  }

    int *head = (int*)(base+0xc9358), *view = (int*)(base+0xc935c), *tail = (int*)(base+0xc9360);
    int slot;
    if (cRam006c50fb == 0) {                      // live auto-follow
        int gap = *head - *tail; if (gap < 0) gap += 0x32;
        if (gap < rows) *view = *tail;
        else { int v = *head - rows; if (v < 0) v += 0x32; *view = v; }
        slot = *view;
    } else {                                      // history scroll
        short up = FUN_005f4ed0();
        if (up == 0) {
            short dn = FUN_005f4fd0();
            for (int k = 0; k < dn; k++) {
                int gap = *head - *view; if (gap < 0) gap += 0x32;
                if (gap > rows && (++*view == 0x32)) *view = 0;
            }
        } else {
            for (int k = 0; k < up; k++)
                if (*view != *tail) { int v = *view - 1; if (v < 0) v += 0x31; *view = v; }
        }
        slot = *view;
    }

    for (int row = 0; row < rows; row++) {
        float x = 64.0f;
        ((u8*)0x6c54d0)[row] = 0;
        float rowY = baseY + row * 20.0f;
        char *name = (char*)(chat + slot*0x11 + 800);
        if (*name != '\0') {
            chatlog_set_line_color(slot, 1);
            FUN_005af1e0(0x40, (int)rowY, 0, name);          // draw name @x=64
            int w = strlen(name);
            x = (w / 2.0f) * halfAdv + 64.0f;
            ((s16*)0x6c54e0)[row] = (s16)x;
            FUN_005af2c0(0);
            FUN_005af1e0((int)x, (int)rowY, 0, (void*)0x649718); // separator glyph
            x += halfAdv * 2.0f;
            ((u8*)0x6c54d0)[row] = chat[slot + 0x1364];          // attr D
        }
        char *msg = (char*)(chat + slot*0x42 + 0x672);
        chat[slot*0x42 + 0x6b3] = 0;                              // clear a byte in the C region
        chatlog_set_line_color(slot, 2);
        FUN_005af1e0((int)x, (int)rowY, 0, msg);                  // draw message
        if (++slot > 0x31) slot = 0;                              // next ring slot
    }
}
```

## Evidence
- Raw: `FUN_005f54d0.c` — mode->(`unaff_s5_lo`, `in_f23`) = (0xb,100)/(5,96)/(10,84); live scroll math
  `head-tail`/`head-rows`; history path `FUN_005f4ed0`/`FUN_005f4fd0` step loops; per-row draw of name
  (`+800`), separator (`0x649718`), message (`+0x672`); caches `0x6c54d0`/`0x6c54e0`; color via `FUN_005f5300`.
- Field offsets consistent with `chatlog_push_msg` (0x5f50d0) and `chatlog_set_text_color` (0x5f5300).
- Caches `0x6c54d0`/`0x6c54e0` are read back by `chatlog_line_obj_cb` (0x5f5970), confirming their roles.

## Remaining uncertainty
- Exact FP geometry (`fVar10`/`fVar11` pixel math) is approximate — Ghidra float regs (`in_f23`,
  `unaff_s5_lo`) are inferred, and `DAT_00692ec8` value not dumped. The `*(iVar4+0x6b3)=0` write is
  a scratch byte inside the C array whose purpose is unconfirmed. Control flow is faithful; no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f54d0.c`  — untouched decompiler output.
