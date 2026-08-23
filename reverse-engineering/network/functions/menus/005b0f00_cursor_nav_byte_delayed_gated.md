# 0x005b0f00 cursor_nav_byte_delayed_gated

| field | value |
|---|---|
| Original address | 0x005b0f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0f00 |
| Resolved name | cursor_nav_byte_delayed_combo |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00629200
**Callees:** FUN_005b14b0 (input_pressed / edge), FUN_005b16c0 (input_held / level)
**Referenced globals:** 0x6ca078 (vertical) / 0x6ca07a (horizontal) repeat-delay counters (i16); 0x6c462a cRam006c462a pad edge-char latch; 0x6c4628 cRam006c4628 pad held-char latch; 0x6c462b bRam006c462b pad modifier-bit mask
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (repeat state in the 0x6ca078/7a globals)

## Behavioral explanation
Same typematic byte-cursor logic as `cursor_nav_byte_delayed` (initial 0x14-frame delay, 10-frame repeat, primary=decrement / secondary=increment, wrap vs clamp by mode), with one addition: the **'+' combo button** (edge char `'+'`, held char `'+'`) also triggers the **primary** direction when the modifier-bit mask `bRam006c462b & 0x22` is set. The '+' char is additionally excluded from the secondary-direction path, so a '+' press/hold never increments — it only drives the primary step (a page/jump-style control). Distinct delay counters (0x6ca078/7a) keep its repeat timing independent of the plain delayed variant.

## Input / output
- `param_1` (`byte *cursor`) — advanced in place.
- `param_2` (`byte max`) — wrap/clamp boundary.
- `param_3` (`byte mode`) — 0/2 vertical, 1/3 horizontal; <2 wrap, ≥2 clamp.
- returns `1` if moved this frame, `0` if suppressed.

## Side effects
- Mutates `*param_1`; writes delay counter 0x6ca078 (vert) / 0x6ca07a (horiz).
- Fires `func_0x001b0140(0)` on a move.
- Reads edge latch 0x6c462a, held latch 0x6c4628, and modifier mask 0x6c462b.

## Important branches
- **primary active** (edge OR held): `input_pressed(prim)!=0` OR `edgechar==cVar2` OR (`edgechar=='+' && (mods&0x22)!=0`) -> decrement (via `LAB_005b1108`).
- **secondary active**: `input_pressed(sec)!=0` OR `edgechar==cVar6` OR `edgechar=='+'` gates it OUT of the "no fresh edge" branch — but '+' is only consumed by primary, so secondary fires only on the real Down/Right edge/hold -> increment.
- **no fresh edge**: `*delay != 0` -> `--; return 0`; else held tests (primary held incl. '+'+mods -> decrement, delay=10; secondary held -> increment, delay=10; neither -> return 0).
- wrap/clamp inside each move tail as in the plain variant.

## Constants & flags
- combo trigger char `'+'`; modifier mask `bRam006c462b & 0x22` (must be set for '+' to count as primary).
- initial delay `0x14`; repeat delay `10`.
- vertical: masks `0x10001`/`0x20002` ('R'/'Q'), counter 0x6ca078; horizontal: `0x40004`/`0x80008`, counter 0x6ca07a; crossed guard chars as in cursor_nav_byte.

## Corrected reconstruction
```c
// typematic byte cursor with a '+' combo that also drives the primary direction
// when modifier bits (0x6c462b & 0x22) are set. mode as cursor_nav_byte.
int cursor_nav_byte_delayed_combo(unsigned char *cursor, unsigned char max, unsigned char mode) {
    unsigned prim, sec; char cPrim, cSec; short *delay;
    if (mode == 0 || mode == 2) {
        prim=0x10001; sec=0x20002; cPrim='R'; cSec='Q'; delay=(short*)0x6ca078;
    } else {
        prim=0x40004; sec=0x80008; cPrim='P'; cSec='O'; delay=(short*)0x6ca07a;
    }
    #define COMBO_ON  (g_pad_mods /*0x6c462b*/ & 0x22)

    int prim_edge = input_pressed(prim) != 0
                 || g_pad_edge /*0x6c462a*/ == cPrim
                 || (g_pad_edge == '+' && COMBO_ON);

    if (!prim_edge) {
        int sec_edge = input_pressed(sec) != 0
                    || g_pad_edge == cSec
                    || g_pad_edge == '+';           // '+' excluded from secondary
        if (!sec_edge) {
            if (*delay != 0) { (*delay)--; return 0; }
            if (input_held(prim) != 0 || g_pad_held /*0x6c4628*/ == cPrim
                || (g_pad_held == '+' && COMBO_ON)) { *delay = 10; goto decrement; }
            if (input_held(sec) == 0 && g_pad_held != cSec && g_pad_held != '+')
                return 0;
            *delay = 10;                            // secondary held
        } else {
            *delay = 0x14;                          // secondary edge
        }
        if (mode < 2) *cursor = (*cursor == max) ? 0 : *cursor + 1;
        else { if (*cursor == max) return 0; *cursor += 1; }
        nav_feedback(0);
    } else {
        *delay = 0x14;                              // primary/combo edge
    decrement:
        if (mode < 2) *cursor = (*cursor == 0) ? max : *cursor - 1;
        else { if (*cursor == 0) return 0; *cursor -= 1; }
        nav_feedback(0);
    }
    return 1;
}
```

## Evidence
- FUN_005b0f00.c: structure mirrors FUN_005b0cd0 but with the extra `cRam006c462a != '+' || (bRam006c462b & 0x22)==0` guard on the primary branch (line 32), `cRam006c462a != '+'` on the secondary (line 34), and the matching held-side `cRam006c4628 == '+' && (bRam006c462b & 0x22)!=0` / `!= '+'` conditions (lines 40-46); delay counters `0x6ca078`/`0x6ca07a`; shared decrement `LAB_005b1108`.
- input_pressed/input_held char table (0x5b14b0/0x5b16c0) — '+' is the combo/Start-style code.
- Single caller FUN_00629200 (paginated room/scenario list).
- Runtime-unvalidated.

## Remaining uncertainty
Meaning of the modifier bits `0x22` in `bRam006c462b` (which physical button/combo) not resolved — likely L/R or Start held. '+' char's physical mapping inferred as a combo/jump key. Crossed horizontal guard chars as in the sibling nav functions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0f00.c`  — untouched decompiler output.
