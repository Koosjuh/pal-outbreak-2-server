# 0x005e9540 cfg_key_str_0x3e4_unescape

| field | value |
|---|---|
| Original address | 0x005e9540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9540 |
| Resolved name | cfg_key_str_0x3e4_unescape |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (invoked via the keyword-dispatch table, not a direct call)
**Callees:** FUN_005ec1b0 (cfg_read_value), FUN_005e82c0 (cfg_unescape)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x3e4 (0x100-byte string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x3e4

## Behavioral explanation
One keyword handler in the overlay's menu/config-markup text parser. It reads the token's `=value`
(optionally `"quoted"`) out of the parse cursor into the string field at `cfg+0x3e4`, then runs the
in-place entity/escape decoder on it. `cfg+0x3e4` is later consumed as the label/caption text measured
by the row-layout routine (FUN_005edc40 cases 2..5 iterate `cfg+0x3e4` byte-by-byte to compute width),
so this field is a displayed text string. The unescape pass (FUN_005e82c0) converts markup escape
sequences (`&…;`-style, matched against the 9-entry table at 0x6484c0 → single chars at 0x6484e8)
into their literal bytes in place.

## Input / output
- `param_1` (`char **cursor`): pointer to the parser's read cursor; advanced past the consumed value.
- Returns `0` (undefined8) — ignored by caller; success is implicit.

## Side effects
- Writes up to 0x100 bytes (NUL-terminated) to `cfg+0x3e4`.
- Rewrites `*cursor` to the position after the value token.
- Mutates `cfg+0x3e4` in place during unescape (may shorten the string).

## Important branches
- No branches in this function itself. All decision logic lives in the callees:
  - `cfg_read_value`: requires a leading `=`; if absent, emits an empty string. Quoted values stop at
    `"`, unquoted values stop at a CTYPE-delimiter (DAT_006491b0 bit 0x04). Payload capped at
    `dst_size-3` (0xFD) bytes.
  - `cfg_unescape`: loops while the delimiter char (0x6484f8) is found; unmatched delimiters are left
    untouched.

## Constants & flags
- `0x100` — destination field size (payload ≤ 0xFD after the -3 guard in cfg_read_value).
- `cfg+0x3e4` — caption/label string field [inferred: caption from FUN_005edc40 usage].

## Corrected reconstruction
```c
// keyword handler: caption/label text with entity unescape → cfg+0x3e4
uint64_t cfg_key_str_0x3e4_unescape(char **cursor)
{
    cfg_read_value(cursor, &cfg[0x3e4], 0x100);   // FUN_005ec1b0: read "=value" / "=\"value\""
    cfg_unescape(&cfg[0x3e4]);                     // FUN_005e82c0: in-place &…; → literal
    return 0;
}
```

## Evidence
- Raw decompile: two calls, `FUN_005ec1b0(param_1, iRam007012a0+0x3e4, 0x100)` then
  `FUN_005e82c0(iRam007012a0+0x3e4)`.
- FUN_005ec1b0 (54 callers) is the shared `=value` token reader (state machine on `=`,`"`, CTYPE
  table 0x006491b0). FUN_005e82c0 (3 callers) is the shared entity-unescape (tables 0x6484c0/e8/f8).
- Field role inferred from FUN_005edc40 (measure routine) reading `cfg+0x3e4` as measured text.
- Runtime-unvalidated (decompile + xref only).

## Remaining uncertainty
- Exact keyword string that dispatches here is not resolved (dispatch table not yet mapped).
- Semantic label of `cfg+0x3e4` (caption vs. some other displayed text) is inferred, not confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9540.c`  — untouched decompiler output.
