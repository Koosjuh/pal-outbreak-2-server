# 0x00637260 kbd_find_enabled_neighbor

| field | value |
|---|---|
| Original address | 0x00637260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637260 |
| Resolved name | kbd_resolve_enabled_key_for_dir |
| Subsystem | menus |
| Relevance | unrelated (soft-keyboard cursor nav; not network) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006313a0, FUN_00631560, FUN_00631670, FUN_00635f80, FUN_00637430
**Callees:** —
**Referenced globals:** 0x715da8 (soft-keyboard widget state base pointer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x20 per-key enable bitmask (bit SET = key disabled); +0x10 page-descriptor pointer (fields +0x20/+0x28 = region-present flags)

## Behavioral explanation
Directional cursor resolver for the on-screen keyboard. Given a direction/key code `param_1` (0..5, else literal), it builds an ordered set of candidate key/cell indices for that move and returns the FIRST candidate that is currently enabled (its bit is clear in the enable bitmask `kbd+0x20`). It writes the primary key into `*param_2` and the resolved enabled key into `*param_3`. Returns 0 = a landing key was found (move allowed), 1 = every candidate is disabled / the target region is absent (move blocked). Cases 4 and 5 additionally gate on the current page descriptor (`kbd+0x10 -> +0x20 / +0x28`): if that region is not present on the page, the move is rejected outright. The numeric constants (8, 0xe, 0x10, 0xf, 0xb, 6, 7, 10, 2) are fixed grid-geometry neighbor indices for the standard layout.

## Input / output
- `param_1` (uint, low byte used): direction/key code. 0..5 have special candidate maps; other values fall to `default` (candidate = the code itself).
- `param_2` (byte*): OUT primary key (low byte of the possibly-remapped code). If NULL, redirected to an internal scratch and the "already there" early-out is skipped.
- `param_3` (byte*): OUT resolved enabled key index. If NULL, redirected to scratch.
- Returns undefined4: 0 = enabled key found (out-params written), 1 = none found / blocked.

## Side effects
- Writes `*param_2` and `*param_3` only when a candidate is enabled; leaves them untouched on the blocked path.
- No struct mutation, no packets. Reads enable mask +0x20 and page descriptor via +0x10.

## Important branches
- `param_2 != NULL && (param_1 & 0xff) == *param_2` -> return 0 (cursor already on this key; no-op success).
- `switch(code & 0xff)` builds candidate list `{param_1, uVar2, uVar7, uVar4, uVar6}`:
  - case 0: uVar2=8, uVar7=0, uVar6=0.
  - case 1: param_1=0xe, uVar4=6, uVar2=6, uVar7=0xe, uVar6=0x10.
  - case 2: param_1=10, uVar2=2, uVar4=7, uVar7=0xf, uVar6=0x10.
  - case 3: uVar7=0xb, uVar6=0xb, uVar2=3.
  - case 4: `if (page->+0x20 == 0) return 1;` else default candidate = code.  (region-present gate)
  - case 5: `if (page->+0x28 == 0) return 1;` else default candidate = code.
  - default: all candidates = code.
- Candidate scan (in order param_1, uVar2, uVar7, uVar4, uVar6): first with `(enable_mask & (1<<cand)) == 0` -> write out-params, return 0. If none clear -> return 1.

## Constants & flags
- Enable bitmask `kbd+0x20`: bit N SET = key N disabled/unavailable (consistent with 637570). A candidate is selectable only when its bit is CLEAR.
- Page-descriptor gate words `page+0x20` / `page+0x28` (page pointer at `kbd+0x10`): 0 = region absent -> reject.
- Direction codes 0..5; geometry indices {2,6,7,8,0xb,0xe,0xf,0x10}.

## Corrected reconstruction
```c
/* Returns 0 if an enabled landing key was found (out-params set), 1 if blocked. */
uint32_t kbd_resolve_enabled_key_for_dir(uint dir, uint8_t *out_primary, uint8_t *out_resolved)
{
    KbdState *kbd = *(KbdState **)0x715da8;
    uint8_t scratch;
    if (out_primary == NULL)      out_primary = &scratch;
    else if ((dir & 0xff) == *out_primary) return 0;   /* already on this key */
    if (out_resolved == NULL)     out_resolved = &scratch;

    uint c0 = dir, c1, c2, c3, c4;             /* candidate ring for this direction */
    uint code = dir & 0xff;
    switch (code) {
    case 0:  c1 = code | 8; c2 = code; c4 = code; c3 = code; break;                 /* {0,8,0,0,0} */
    case 1:  code=6; c0=0xe; c1=6; c2=0xe; c4=0x10; c3=code; break;                 /* {0xe,6,0xe,6,0x10} */
    case 2:  c0=10; c1=2; code=7; c2=0xf; c4=0x10; c3=code; break;                  /* {10,2,0xf,7,0x10} */
    case 3:  c2 = (code+8)&0xff; c4 = c2; c1 = code; c3 = code; break;              /* {3,3,0xb,3,0xb} */
    case 4:  if (kbd->page /*+0x10*/->region_a /*+0x20*/ == 0) return 1;
             goto def;
    case 5:  if (kbd->page /*+0x10*/->region_b /*+0x28*/ == 0) return 1;
             goto def;
    default: def: code = dir & 0xff; c2 = code; c4 = code; c1 = code; c3 = code; break;
    }

    uint32_t mask = kbd->enable_mask /*+0x20*/;   /* bit set = disabled */
    uint8_t primary = (uint8_t)dir;               /* note: dir may have been remapped above */
    /* first candidate whose enable bit is clear wins; order: dir, c1, c2, c3, c4 */
    if      (!(mask & (1u << (dir  & 0x1f)))) { *out_primary = primary; *out_resolved = primary;      return 0; }
    else if (!(mask & (1u << (c1   & 0x1f)))) { *out_primary = primary; *out_resolved = (uint8_t)c1;  return 0; }
    else if (!(mask & (1u << (c2   & 0x1f)))) { *out_primary = primary; *out_resolved = (uint8_t)c2;  return 0; }
    else if (!(mask & (1u << (code & 0x1f)))) { *out_primary = primary; *out_resolved = (uint8_t)code;return 0; }
    else if (!(mask & (1u << (c4   & 0x1f)))) { *out_primary = primary; *out_resolved = (uint8_t)c4;  return 0; }
    return 1;   /* all candidates disabled -> blocked */
}
```
(Variable roles mapped: decompiler `uVar2`=c1, `uVar7`=c2, `uVar4`=code/c3, `uVar6`=c4. Control flow preserved exactly.)

## Evidence
- Raw decompile FUN_00637260.c lines 18-98 (switch cases 0-5 + default, then 5-way enable scan).
- case 4/5 page gate: `*(int*)(*(int*)(base+0x10)+0x20)` / `+0x28`.
- Enable mask read `*(uint*)(base+0x20)` line 71; bit-test pattern lines 73-97.
- Called by kbd_validate_key_enabled (637430) for key-class < 6 (delegation).

## Remaining uncertainty
- The physical grid meaning of each geometry index (which visual key) is not mapped; only the numeric candidate rings are certain. `param_2`/`param_3` named primary/resolved by role. Runtime-unvalidated.
