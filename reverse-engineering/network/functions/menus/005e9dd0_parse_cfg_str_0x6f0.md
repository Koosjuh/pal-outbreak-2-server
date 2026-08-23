# 0x005e9dd0 parse_cfg_str_0x6f0

| field | value |
|---|---|
| Original address | 0x005e9dd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9dd0 |
| Resolved name | markup_attr_read_link_target |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005ec1b0 (attribute-value reader)
**Referenced globals:** iRam007012a0; +0x6f0 (0x100-byte link/href target buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x6f0

## Behavioral explanation
Markup attribute handler that reads the current `="..."` attribute value from the source stream and
copies it (NUL-terminated) into the link-target buffer at `+0x6f0` (capacity 0x100). This is the
setter that populates the href consumed by `markup_tag_link_close` (0x9d50) via
`FUN_005ede30`/`FUN_005d9290`, and cleared by the link reset handlers. I.e. the `href="URL"` (or
target/action id) of an `<a>`-style tag.

## Input / output
- `param_1` (`char **cursor`): parse cursor, advanced by `FUN_005ec1b0` past the token.
- Returns `0`.

## Side effects
- Writes up to 0xFD bytes + NUL into `g_markup+0x6f0` (reader bound is `len-3`).
- Advances `*param_1`.

## Important branches
- All in `FUN_005ec1b0` (state machine: require `=`, `"`, copy quoted, stop on `"`, class-4 char,
  NUL, or `count > len-3`; multibyte high-bit copy loop).

## Constants & flags
- `0x100` — destination capacity (`+0x6f0` buffer; the reset handlers clear `0x101` = buffer+NUL).
- `DAT_006491b0[]` — char-class table; bit `0x04` = value terminator.

## Corrected reconstruction
```c
int markup_attr_read_link_target(char **cursor /*param_1*/)
{
    // <a href="URL"> -> stash URL for finalize/submit on link close
    markup_read_attr_value(cursor, g_markup->link_target /*+0x6f0*/, 0x100); // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x6f0, 0x100)`.
- Same `+0x6f0` buffer cleared (`0x101`) by 0x9d50/0x9d90 and submitted by `FUN_005ede30`.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether `+0x6f0` is a URL string or an action/target identifier depends on `FUN_005d9290`.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9dd0.c`  — untouched decompiler output.
