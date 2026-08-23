# 0x00631a30 softkbd_grid_nav_special_mode

| field | value |
|---|---|
| Original address | 0x00631a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631a30 |
| Resolved name | softkbd_grid_nav_special_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00631ac0, FUN_00631bb0, FUN_00631c80, FUN_00631cf0 (D-pad handlers), FUN_00636890
**Callees:** —
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1f field mode; +0x2f IME state; +0x30 widget mode; +0x35 flags (low nibble); +0x4a status flags

## Behavioral explanation
Predicate consulted by the D-pad handlers before moving the key-grid highlight. It returns non-zero **only** for the two "special" field modes (`+0x1f == 4` or `== 5`) while the widget is idle and unlocked; for ordinary modes, or when composing/locked, it returns 0. The prior name "grid_nav_allowed" is retained cautiously but the truth table shows it actually flags the *special* field modes — the direction handlers use its result to branch to special-field navigation rather than the normal glyph grid. Exact polarity (special-path vs block) is caller-dependent.

## Input / output
- No parameters.
- Returns `undefined4` — 1 = special field mode active (mode 4 with clean flags, or mode 5); 0 otherwise.

## Side effects
- None (pure read; the `uVar1=…` assignments are decompiler renderings of C short-circuit side effects, not stores to memory).

## Important branches (exact truth table)
Preconditions for any non-zero result: `+0x30 == 0` (widget mode idle) AND `+0x2f == 0` (IME idle) AND `(+0x4a & 1) == 0` (not locked). If any fails -> **return 0**. Then:
- `field_mode (+0x1f) == 4`:
  - `(+0x35 & 0x0f) == 0` -> **return 1**.
  - `(+0x35 & 0x0f) != 0` -> **return 0**.
- `field_mode == 5` -> **return 1**.
- any other field_mode (and != 4) -> **return 0**.

## Constants & flags
- `+0x1f` field mode: `4` and `5` = special field types (e.g. picker/list fields, not the free-text grid). [inferred]
- `+0x35 & 0x0f` = sub-state flags for mode 4 (must be 0 to treat mode 4 as special-nav).
- `+0x30 == 0` idle, `+0x2f == 0` IME idle, `+0x4a bit0` = lock.

## Corrected reconstruction
```c
// returns non-zero when the active field is a "special" mode (4/5) and the
// widget is idle+unlocked; D-pad handlers branch on this.
undefined4 softkbd_grid_nav_special_mode(void)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;

    if (kb->mode != 0)         return 0;       // +0x30 not idle
    if (kb->ime_state != 0)    return 0;       // +0x2f composing
    if (kb->flags4a & 1)       return 0;       // +0x4a locked

    if (kb->field_mode == 4)                   // +0x1f
        return ((kb->flags35 & 0x0f) == 0) ? 1 : 0;   // +0x35 clean
    if (kb->field_mode == 5)
        return 1;
    return 0;
}
```
(Structure preserved from the decompiler's fused short-circuit expression; the truth table above is exact.)

## Evidence
- Raw: the nested `&&`/`||` with embedded `uVar1=` assignments; carefully unfolded per short-circuit order (see truth table).
- Guards `+0x30==0`, `+0x2f==0`, `+0x4a&1==0` match the idle/unlocked preconditions used across the softkbd family.

## Remaining uncertainty
- Return **polarity/meaning** (does 1 enable special-nav or suppress grid-nav?) depends on how callers FUN_00631ac0/bb0/c80/cf0 branch — not decoded here (hence Medium). The numeric truth table is exact; the semantic label is the uncertain part.
- Field-mode identities 4/5 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631a30.c` — untouched decompiler output.
