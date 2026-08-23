# 0x005fd630 menu_item_anim_cb

| field | value |
|---|---|
| Original address | 0x005fd630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fd630 |
| Resolved name | menu_item_gate_anim_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as widget update cb at +0xc by build_select_menu_widgets 0x5fc850)
**Callees:** FUN_005bac80 (resolve selected entry by index), func_0x001ae3e0 (read slot-position field), func_0x001886c0 (sine), func_0x00188 helpers
**Referenced globals:** cRam006c550e mode selector; cRam006c5499 mode-A selection; bRam006c5498 mode-B (area) selection; sRam006c50ca player/member count; uRam006c4b96 entry index; 0x6947e8 area-record base (stride 0x14a8, +0 unlock flag, +2 index); 0x69715d scenario sub-table (stride 0x41); 0x649b50/0x649b62 y-coord tables; DAT_006930f0 sine frequency
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget +4 lifecycle; +1 visible/enabled; +2 kind; +9 phase-reset flag; +0x3a anim phase; +0x2c color

## Behavioral explanation
Per-frame update callback for an **animated, gated menu item** (scenario/area select tile). Two responsibilities:
1. **Enable/grey gating (+1):** decides whether the item is selectable or greyed-out, based on the current selection and the area-unlock tables. This is the code behind the observed "6+10 greyed areas" behavior — areas below index 2 or index 10 are always greyed, and areas ≥2 require their unlock flag (`0x6947e8 + idx*0x14a8`) to be set.
2. **Alpha pulse (+0x2c):** advances an anim phase and modulates the item's alpha channel via a sine table, so the active/selectable item breathes.

Mode is chosen by `cRam006c550e`: mode A (==0) is a simpler list (uses `cRam006c5499`), mode B (!=0) is the area-select grid (uses `bRam006c5498`). Pure UI/state read; no network opcodes.

## Input / output
- **param_1** (`int`, widget*): the menu-item widget; +1 visible, +2 kind, +4 state, +8/9/0xa anim params, +0x24 flags, +0x26/+0x28 x/y, +0x2c color(RGBA), +0x3a phase.
- **returns** `void`.

## Side effects
- **init (state 0):** +4=1, +8=0x14, +9=0, +0xa=0xff, +0x3a=0, +0x2c=0xffffffff (white), +0x24 |= 0x80; if kind(+2)==0 set +0x26=0x128 (default x).
- **each frame:** +1 recomputed (enable/grey), +0x26/+0x28 positioned, +0x3a advanced by 0x400 & masked 0x7fff, +0x2c alpha byte rewritten from sine.

## Important branches
- **mode A (`cRam006c550e==0`):** +1 = (`cRam006c5499==0`) ? 1 : 0; if kind≠0 set x=0x1e8; y = `*(u16*)(0x649b62 + cRam006c5499*2)`.
- **mode B (`cRam006c550e!=0`), by area index `bRam006c5498`:**
  - **==8:** if `sRam006c50ca < 2` → greyed (+1=0); else selectable, resolve entry `FUN_005bac80(uRam006c4b96)` (grey if null), x-base = `slot_pos*9`.
  - **==9:** selectable, x-base = 0x6c.
  - **<2, or ==10, or (≥2 and unlock flag `*(0x6947e8 + idx*0x14a8)==0`):** greyed (+1=0).
  - **else (≥2, unlocked):** selectable; x-base = `func_0x001ae3e0( 0x69715d + (idx-2)*0x14a8 + tbl2[idx]*0x41 ) * 9`, where `tbl2[idx] = *(0x6947ea + idx*0x14a8)`.
  - after: if kind≠0 set x = x-base + 0x158; y = `*(u16*)(0x649b50 + idx*2)`.
- **alpha animation (always):** phase += 0x400, &= 0x7fff; if +9 flag set → phase=0x4000, clear +9; `a = sin(DAT_006930f0 * phase/65536) * 255`; color +0x2c = (color & 0x00FFFFFF) | (a << 24).

## Constants & flags
- `cRam006c550e`: 0 = mode A (list), ≠0 = mode B (area grid).
- Area gating: idx `<2` or `==10` always greyed; idx `≥2` gated by unlock flag at `0x6947e8 + idx*0x14a8`; idx `8`/`9` special-cased (8 needs `sRam006c50ca ≥ 2`).
- `0x14a8` = area-record stride; `+0` unlock flag, `+2` sub-index; `0x69715d` scenario sub-table (stride 0x41).
- `0x128`/`0x1e8`/`0x158` = x anchors; `+0x150`-family y from tables `0x649b50`(B)/`0x649b62`(A).
- Anim: `0x400` phase step, `0x7fff` phase mask, `0x4000` reset phase; +0x24 bit `0x80` set on init; init color `0xffffffff`.
- `sRam006c50ca` = current member/player count (used to gate area 8) [inferred].

## Corrected reconstruction
```c
// Animated + gated menu tile update cb. cRam006c550e picks mode.
void menu_item_gate_anim_cb(widget *w)           // param_1
{
    if (w->state != 1) {                          // +4
        if (w->state != 0) return;
        w->state = 1; w->anim8 = 0x14; w->reset9 = 0; w->pad_a = 0xff;
        w->phase = 0; w->color = 0xffffffff; w->flags24 |= 0x80;  // +0x24
        if (w->kind == 0) w->x = 0x128;           // +2 == 0 default x
    }

    short xbase = 0;
    if (cRam006c550e == 0) {                       // ---- mode A (list) ----
        w->visible = (cRam006c5499 == 0);
        if (w->kind != 0) w->x = 0x1e8;
        w->y = *(u16*)(0x649b62 + cRam006c5499*2);
    } else {                                       // ---- mode B (area grid) ----
        int idx = (char)bRam006c5498;
        if (bRam006c5498 == 8) {
            if (sRam006c50ca < 2) { w->visible = 0; }
            else {
                w->visible = 1;
                void *e = entry_by_index(uRam006c4b96);   // FUN_005bac80
                if (!e) w->visible = 0;
                else xbase = entry_slot_pos(e) * 9;       // func_0x001ae3e0
            }
        } else if (bRam006c5498 == 9) {
            xbase = 0x6c; w->visible = 1;
        } else if (bRam006c5498 < 2 || bRam006c5498 == 10 ||
                   (idx > 1 && *(char*)(idx*0x14a8 + 0x6947e8) == 0)) {
            w->visible = 0;                        // locked/greyed area
        } else {
            char sub = *(char*)(idx*0x14a8 + 0x6947ea);
            char v = entry_slot_pos((void*)(sub*0x41 + (idx-2)*0x14a8 + 0x69715d));
            w->visible = 1; xbase = v * 9;
        }
        if (w->kind != 0) w->x = xbase + 0x158;
        w->y = *(u16*)(0x649b50 + idx*2);
    }

    // alpha pulse
    w->phase = (w->phase + 0x400) & 0x7fff;
    if (w->reset9) { w->phase = 0x4000; w->reset9 = 0; }
    float a = sinf(DAT_006930f0 * (float)w->phase / 65536.0f) * 255.0f;  // func_0x001886c0
    w->color = (w->color & 0x00FFFFFF) | ((int)a << 24);
}
```

## Evidence
- Raw decompile `FUN_005fd630.c` (mode split, area gating, sine alpha all exact).
- Area-unlock stride `0x14a8` at base `0x6947e8` matches the area-data model (6+10 greyed areas validated on rig 2026-07-21 per FACTS/session log).
- Installed by `build_select_menu_widgets` (0x5fc850) as the menu-item cb.
- Runtime-unvalidated at the pixel/anim level (the *gating outcome* — greyed areas — is rig-observed).

## Remaining uncertainty
- Exact semantics of special indices 8/9 (likely the two scenario/mode slots vs. the 10 areas) not fully mapped.
- `func_0x001ae3e0` field read and `DAT_006930f0` sine frequency are thunks/constants not individually traced.
- `sRam006c50ca` identified as a count by the `< 2` gate; its writer (member-list handler) not confirmed here.
```
