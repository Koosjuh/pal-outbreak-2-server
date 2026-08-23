# 0x00637ba0 kbd_symbol_allowed

| field | value |
|---|---|
| Original address | 0x00637ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637ba0 |
| Resolved name | kbd_symbol_excluded |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Symbol blocklist predicate for the software keyboard's symbol/accent pages. Returns **false** for four
specific glyphs and **true** for everything else. Its callers (`kbd_key_allowed_for_page` symbol tail)
treat a *false* return as "this excluded glyph is permitted here", so the function's real semantic is
"is this NOT one of the four reserved punctuation codes". The excluded codes are halfwidth-katakana
corner brackets and two mid-dot/percent glyphs reserved by the UI.

## Input / output
- `param_1` — `short` codepoint (signed compare in the decompile).
- **Returns** `bool` — false for the four reserved codes, true otherwise.

## Side effects
None.

## Important branches
- `== -0x9e` (0xFF62, halfwidth `｢`) -> false
- `== -0x9d` (0xFF63, halfwidth `｣`) -> false
- `== 0x25` (`%`) -> false
- else -> `param_1 != 0xb7` (0x00B7 mid dot `·`) — false for 0xb7, true otherwise.

## Constants & flags
- `0xFF62` / `0xFF63` — halfwidth katakana corner brackets `｢ ｣` [inferred from the JIS layout].
- `0x25` — `%`.
- `0xB7` — middle dot `·`.

## Corrected reconstruction
```c
// Returns false for the 4 reserved punctuation glyphs, true otherwise.
// Callers invert: a false result = "glyph allowed on this symbol page".
bool kbd_symbol_excluded(short cp)
{
    if (cp == (short)0xFF62) return false;  // ｢  (-0x9e)
    if (cp == (short)0xFF63) return false;  // ｣  (-0x9d)
    if (cp == 0x25)          return false;  // %
    return cp != 0xB7;                      // ·  -> false, else true
}
```

## Notes / uncertainty
Exact glyph identities (0xFF62/0xFF63 as corner brackets) inferred from JIS X 0201 halfwidth ranges;
values themselves are exact. Renamed to `kbd_symbol_excluded` to reflect the inverted semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637ba0.c`  — untouched decompiler output.

## Evidence
- Raw comparisons (lines 11-21): -0x9e, -0x9d, 0x25, 0xb7. Runtime unvalidated.
