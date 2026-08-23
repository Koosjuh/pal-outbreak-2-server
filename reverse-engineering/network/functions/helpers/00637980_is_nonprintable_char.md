# 0x00637980 is_nonprintable_char

| field | value |
|---|---|
| Original address | 0x00637980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637980 |
| Resolved name | kbd_char_is_rejected |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_00630910, FUN_006379e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Character-admissibility predicate for the on-screen keyboard / entered text. Returns 0 = ACCEPT, 1 = REJECT.
- `9999` (the empty-glyph sentinel, matches FUN_006362e0) -> ACCEPT (0): the "no character / blank cell" placeholder is allowed to pass.
- `0x2c` (',' comma) -> REJECT (1): comma is explicitly disallowed even though it is printable ASCII. This is a reserved delimiter (comma separates fields in the lobby/name wire formatting), so it must be filtered out of user-entered strings.
- Otherwise: ACCEPT only if in printable ASCII range `0x20 <= c <= 0x7e`; all other codes REJECT.

NOTE — corrects the prior classified record, which stated comma returns 0 (allowed). The decompile forces `0x2c -> 1` (rejected).

## Input / output
- `param_1` (u16): character/glyph code.
- Returns undefined4: 0 = accepted/printable, 1 = rejected (non-printable OR reserved comma).

## Side effects
- None (pure function).

## Important branches
- `c == 9999` -> return 0 (empty sentinel allowed).
- `c == 0x2c` -> return 1 (comma reserved -> reject).
- else -> `return (0x1f < c && c < 0x7f) ? 0 : 1;` (printable ASCII accepted, else reject).

## Constants & flags
- `9999` = empty-glyph sentinel (shared with FUN_006362e0).
- `0x2c` = ',' — reserved wire delimiter, always rejected.
- Printable window `0x20..0x7e` inclusive (`0x1f < c < 0x7f`).
- Return polarity: 0 = accept, 1 = reject.

## Corrected reconstruction
```c
/* 0 = accept, 1 = reject */
uint32_t kbd_char_is_rejected(uint16_t c)
{
    if (c == 9999)   return 0;   /* empty-glyph sentinel: allowed */
    if (c == 0x2c)   return 1;   /* comma: reserved delimiter, rejected */
    if (c > 0x1f && c < 0x7f) return 0;  /* printable ASCII: allowed */
    return 1;                    /* everything else: rejected */
}
```

## Evidence
- Raw decompile FUN_00637980.c lines 11-23. The `param_1 == 0x2c -> uVar1 = 1` branch (line 14-15) is the load-bearing correction.
- Sentinel 9999 cross-referenced with FUN_006362e0 (empty-glyph).

## Remaining uncertainty
- The precise wire context where comma is the reserved delimiter (name field vs message vs list encoding) is inferred, not traced here. Runtime-unvalidated.
