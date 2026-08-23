# 0x00637ca0 is_special_punct_char

| field | value |
|---|---|
| Original address | 0x00637ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637ca0 |
| Resolved name | is_digit_or_dialpad_symbol |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** FUN_00637c40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Dialpad-page (page 7) glyph filter: permits any ASCII digit (delegated to `is_ascii_digit`) plus the
three keypad symbols `'-'`, `'*'`, `'#'`. Everything else is rejected. This is the classic telephone
keypad set used when the field expects a numeric/PIN-style entry.

## Input / output
- `param_1` — `short` glyph.
- **Returns** `undefined8` — 1 if digit or `- * #`, else 0.

## Important branches
- `is_ascii_digit(cp) == 1` -> 1.
- else `cp == '-' (0x2d) || cp == '*' (0x2a) || cp == '#' (0x23)` -> 1.
- else -> 0.

## Constants & flags
- `0x2d` `-`, `0x2a` `*`, `0x23` `#` — dialpad symbols.

## Corrected reconstruction
```c
int is_digit_or_dialpad_symbol(short cp)
{
    if (is_ascii_digit((u16)cp) == 1)
        return 1;
    if (cp == '-' || cp == '*' || cp == '#')
        return 1;
    return 0;
}
```

## Notes / uncertainty
The decompile compares `FUN_00637c40()` result to `1` explicitly (`lVar1 != 1`); preserved. Renamed to
`is_digit_or_dialpad_symbol` for clarity. Not on the network path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637ca0.c`  — untouched decompiler output.

## Evidence
- Raw: `lVar1 = FUN_00637c40(); ... (0x2d|0x2a|0x23) -> 1 else 0`. Runtime unvalidated.
