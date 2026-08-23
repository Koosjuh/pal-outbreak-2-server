# 0x005e9cd0 parse_cfg_str16_0x2d3

| field | value |
|---|---|
| Original address | 0x005e9cd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9cd0 |
| Resolved name | markup_attr_read_style2d3 |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (indirect: markup tag-dispatch table)
**Callees:** FUN_005ec1b0 (attribute-value reader)
**Referenced globals:** iRam007012a0 (markup-engine state base); +0x2d3 (16-byte pending named style attribute)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2d3

## Behavioral explanation
A markup tag/attribute handler for the overlay rich-text layout engine (the same engine whose
state block at `0x007012a0` holds the style stack, line records, table state, and link buffers used
by all functions in this batch). It reads the current attribute value out of the markup source
stream and stores it, NUL-terminated, into the pending named-style-attribute slot `+0x2d3`
(capacity 16). That slot is later consumed by the style-push routine `FUN_005ef220`, which resolves
the name (via `FUN_005ec800`) into the 1-byte style value written to the style-stack row at
`+0x169`. In other words: `<tag attr="value">` -> stash `value` -> next style scope uses it.

## Input / output
- `param_1` (`char **cursor`): pointer to the parser's current position in the markup string.
  `FUN_005ec1b0` advances `*cursor` past the consumed `="..."` token.
- Returns `0` (handlers report success via the constant return; dispatch ignores it).

## Side effects
- Writes up to 15 bytes + NUL into `g_markup+0x2d3`.
- Advances the shared parse cursor `*param_1`.
- No packets, no protocol state.

## Important branches
- All branching lives in the callee `FUN_005ec1b0`: it walks a small state machine
  (0: require `=`, 1: require opening `"`, 2/3: copy quoted bytes) and terminates on the closing
  quote, a stop-class byte (`DAT_006491b0[c] & 4`), a NUL, or when `count > len-3`. On any early
  termination it still NUL-terminates the destination. High-bit (`0x80`) bytes trigger a
  multibyte copy loop (SJIS-style lead/trail bytes copied verbatim).

## Constants & flags
- `0x10` — destination capacity (effective payload 13 chars, reader reserves `len-3`).
- `DAT_006491b0[]` — per-byte character class table; bit `0x04` marks a value-terminating char.

## Corrected reconstruction
```c
// Markup tag-dispatch handler: <tag attr="NAME"> -> stash NAME for next style push.
// g_markup = (MarkupState*)0x007012a0
int markup_attr_read_style2d3(char **cursor /*param_1*/)
{
    // read the ="..."-quoted attribute value into the 16-byte pending style-name slot
    markup_read_attr_value(cursor, g_markup->pending_style_name2d3, 0x10); // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x2d3, 0x10)`.
- `FUN_005ec1b0` (read): `="..."` attribute-value extractor, `len-3` bound, class table `DAT_006491b0`.
- Consumer `FUN_005ef220` reads `+0x2d3` via `FUN_005ec800` into style row `+0x169`.
- Runtime-unvalidated (static reconstruction).

## Remaining uncertainty
- Exact semantic of the `+0x2d3` attribute (named color vs. font/face) depends on `FUN_005ec800`'s
  lookup table, not yet decoded. Cursor-vs-descriptor param role inferred from the single-arg form.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9cd0.c`  — untouched decompiler output.
