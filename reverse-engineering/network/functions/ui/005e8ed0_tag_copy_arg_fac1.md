# 0x005e8ed0 tag_setattr_str_fac1

| field | value |
|---|---|
| Original address | 0x005e8ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8ed0 |
| Resolved name | tag_copy_arg_fac1 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005ec1b0 (markup attribute-value extractor)
**Referenced globals:** TRC `iRam007012a0`: +0xfac1 (256-byte string attribute buffer, separate region)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xfac1

## Behavioral explanation
Attribute-setter tag: extracts the `="value"` argument via `FUN_005ec1b0` and stores up to 256 bytes
(NUL-terminated) into buffer **`+0xfac1`**. Unlike the `+0xaf6/+0xbf6/+0xcf6` trio (which
`FUN_005ee590` resets each run), `+0xfac1` sits in a far higher region of the render context — likely a
persistent / page-scoped attribute (e.g. a title or resource name) rather than an inline per-run string.

## Input / output
- `param_1` [inferred `ParseCursor* (undefined4*)`] — parse cursor, advanced by the extractor.
- Returns `0`.

## Side effects
- Writes up to 256 bytes into `+0xfac1`; advances `*param_1`. Not cleared by the per-run reset
  `FUN_005ee590`.

## Important branches
- All inside `FUN_005ec1b0`.

## Constants & flags
- `0x100` — copy cap.

## Corrected reconstruction
```c
undefined8 tag_setattr_str_fac1(ParseCursor *cur)
{
    markup_extract_attr(cur, &TRC->attrStrPage /*+0xfac1*/, 0x100);  // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8ed0.c` (48 bytes).
- Same extractor `FUN_005ec1b0.c`. `+0xfac1` absent from the `FUN_005ee590.c` per-run clear set —
  basis for the "persistent/page-scoped" inference.
- Runtime-unvalidated.

## Remaining uncertainty
- Role of `+0xfac1` (title / resource id?) unresolved; persistence inferred, not confirmed.
- Unaligned offset `0xfac1` (odd address) suggests a byte-string field, consistent with a string buffer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8ed0.c`  — untouched decompiler output.
