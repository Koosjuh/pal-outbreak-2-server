# 0x005e8d90 tag_setattr_str_af6

| field | value |
|---|---|
| Original address | 0x005e8d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d90 |
| Resolved name | tag_copy_arg_af6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005ec1b0 (markup attribute-value extractor)
**Referenced globals:** TRC `iRam007012a0`: +0xaf6 (256-byte string attribute buffer #1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xaf6

## Behavioral explanation
Attribute-setter tag: parses the tag's `="value"` argument out of the markup stream and stores the
string (max 0x100 bytes, NUL-terminated) into attribute buffer **`+0xaf6`**. `FUN_005ec1b0` is the
shared attribute extractor — a small state machine that skips to `=`, honors an optional `"` quote,
copies bytes (with a high-bit multibyte run handled via table `&DAT_006491b0`) until the closing quote
or a delimiter, and advances the parse cursor (`*param_1`). The three string buffers `+0xaf6/+0xbf6/
+0xcf6` are the ones reset to empty by `FUN_005ee590`.

## Input / output
- `param_1` [inferred `ParseCursor* (undefined4*)`] — pointer to the current parse position; advanced
  past the consumed attribute by `FUN_005ec1b0`.
- Returns `0`.

## Side effects
- Writes up to 256 bytes into `+0xaf6` (NUL-terminated); advances `*param_1`.

## Important branches
- All inside `FUN_005ec1b0` (quote handling, delimiter/`"` termination, length cap `param_3-3`).

## Constants & flags
- `0x100` — destination buffer size / copy cap.

## Corrected reconstruction
```c
undefined8 tag_setattr_str_af6(ParseCursor *cur)
{
    markup_extract_attr(cur, &TRC->attrStrA /*+0xaf6*/, 0x100);  // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8d90.c` (44 bytes).
- `FUN_005ec1b0.c`: the `key="value"` extractor (state var iVar4: 0 expect `=`, 1 optional quote,
  2 quoted-copy, 3 unquoted-copy; cap `param_3 + -3`).
- Buffer membership from `FUN_005ee590.c` (clears `+0xaf6/+0xbf6/+0xcf6`).
- Runtime-unvalidated.

## Remaining uncertainty
- Which attribute name maps to `+0xaf6` (buffer role, e.g. font/color/label, not resolved).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d90.c`  — untouched decompiler output.
