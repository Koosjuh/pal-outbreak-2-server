# 0x005e8e80 tag_setattr_str_cf6

| field | value |
|---|---|
| Original address | 0x005e8e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8e80 |
| Resolved name | tag_copy_arg_cf6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005ec1b0 (markup attribute-value extractor)
**Referenced globals:** TRC `iRam007012a0`: +0xcf6 (256-byte string attribute buffer #3)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xcf6

## Behavioral explanation
Attribute-setter tag identical in form to `FUN_005e8d90`, but the destination is the third string
attribute buffer **`+0xcf6`**. Parses the `="value"` argument via `FUN_005ec1b0` and copies up to 256
bytes (NUL-terminated). `+0xcf6` is one of the trio (`+0xaf6/+0xbf6/+0xcf6`) cleared by `FUN_005ee590`.
Unlike `FUN_005e8e40` (`+0xbf6`), this variant does **not** run token expansion afterward.

## Input / output
- `param_1` [inferred `ParseCursor* (undefined4*)`] — parse cursor, advanced by the extractor.
- Returns `0`.

## Side effects
- Writes up to 256 bytes into `+0xcf6`; advances `*param_1`.

## Important branches
- All inside `FUN_005ec1b0`.

## Constants & flags
- `0x100` — copy cap.

## Corrected reconstruction
```c
undefined8 tag_setattr_str_cf6(ParseCursor *cur)
{
    markup_extract_attr(cur, &TRC->attrStrC /*+0xcf6*/, 0x100);  // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8e80.c` (44 bytes).
- Same extractor `FUN_005ec1b0.c`; buffer trio from `FUN_005ee590.c`.
- Runtime-unvalidated.

## Remaining uncertainty
- Attribute-name role of `+0xcf6` unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8e80.c`  — untouched decompiler output.
