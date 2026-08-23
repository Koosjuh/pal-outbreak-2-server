# 0x00607fe0 build_position_table_unused

| field | value |
|---|---|
| Original address | 0x00607fe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607fe0 |
| Resolved name | draw_cb_pick_position_by_sel |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (no callers in corpus; likely a draw callback referenced only by data/indirect ptr)
**Callees:** — (inlined table copy + memset-less; no external calls)
**Referenced globals:** DAT_0064a0d0 (static position/color table, ~0x28 bytes); cRam006c5497 (selected index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5497

## Behavioral explanation
A node draw callback that, on first call, latches init and sets an attribute bit, then each
call selects one value from a static table indexed by the current selection cursor
`0x6c5497` (clamped to 0..10) and writes it into `node+0x2c` (the node's color/position word).
The function copies the static table from `0x64a0d0` onto the stack first (a compiler-materialised
local copy of ~0x28 bytes / 11 words) and indexes that. Effect: the widget's colour/position
tracks the currently-highlighted menu row. No callers appear in the corpus, so it is either dead
or wired only through an indirect/data callback pointer.

## Input / output
- **param_1** `int node` — the `draw_node` this callback drives.
- **returns** void.

## Side effects
- On first call: `node+0x04 = 1` (init latch), `node+0x01 = 1` (enabled), `node+0x24 |= 0x80`.
- Every call: `node+0x2c = position_table[min(sel, 10)]`.

## Important branches
- `node+0x04 == 1` -> skip init, go to selection.
- `node+0x04 != 0 && != 1` -> return (not drawable).
- `node+0x04 == 0` -> latch init block.
- `cRam006c5497 > 10` -> clamp index to 10.

## Constants & flags
- attr bit **0x80** (set into node+0x24) — same "positioned" attribute used by 00607fe0's peers.
- table **0x64a0d0**, copied as 11 u32 words to stack; index clamp max **10**.

## Corrected reconstruction
```c
// No corpus caller; treated as a draw callback (signature matches the cluster).
void draw_cb_pick_position_by_sel(draw_node *n) {
    u32 pos_tbl[11];
    memcpy(pos_tbl, (const void*)&DAT_0064a0d0, sizeof pos_tbl);  // materialised local copy

    if (n->init_done != 1) {
        if (n->init_done != 0) return;
        n->init_done = 1;
        n->enabled   = 1;
        n->attr     |= 0x80;      // node+0x24
    }

    unsigned sel = (u8)cRam006c5497;
    if (sel > 10) sel = 10;
    n->color = pos_tbl[sel];      // node+0x2c
}
```

## Evidence
- Raw decompile: FUN_00607fe0.c (164 bytes) — the unrolled 16-byte×2 + 8-byte table copy, the
  0x80 attr bit, sel clamp to 10, and store to +0x2c are literal.
- Node field roles consistent with the other draw callbacks in this cluster (005690/00607fe0).
- Runtime-unvalidated; **no callers** — cannot confirm it executes.

## Remaining uncertainty
- Whether it is live at all (no static caller). Whether pos_tbl entries are colours or packed
  X/Y positions (name kept generic). Exact table length (11 words assumed from the copy shape).
