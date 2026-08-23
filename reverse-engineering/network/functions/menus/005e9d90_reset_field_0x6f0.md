# 0x005e9d90 reset_field_0x6f0

| field | value |
|---|---|
| Original address | 0x005e9d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d90 |
| Resolved name | markup_tag_link_reset |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005eef70 (flush run), func_0x00106b60 (memset)
**Referenced globals:** iRam007012a0; +0x6f0 (0x101-byte link/href target buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x6f0; pending run +0x4 (via callee)

## Behavioral explanation
Markup handler that flushes the pending styled text run (`FUN_005eef70`) and clears the 0x101-byte
link-target buffer at `+0x6f0` — but, unlike `markup_tag_link_close` (0x9d50), it does **not** call
`FUN_005ede30`, so no link is submitted and the link char-span counter `+0x18` is left untouched.
This is the "abandon/reset current link target" variant: it commits accumulated text and drops any
pending href without registering a clickable region. Likely the handler for an inline tag that ends
the *text* of a link scope without finalizing it, or a `<a>` open that resets any stale target.

## Input / output
- `param_1`: tag descriptor (unused).
- `param_2` (`char **cursor`): flushed/reset by `FUN_005eef70`.
- Returns `0`.

## Side effects
- Commits pending text run; resets run counter `+0x4`, `*param_2`.
- `memset(g_markup+0x6f0, 0, 0x101)` — clears link target buffer.
- No hyperlink submission (contrast 0x9d50).

## Important branches
- Only the callee `FUN_005eef70` branches (`+0xd892` table-mode -> `FUN_005f3ac0`).

## Constants & flags
- `0x101` — link-buffer clear length.

## Corrected reconstruction
```c
int markup_tag_link_reset(void *tag /*param_1, unused*/, char **cursor /*param_2*/)
{
    markup_flush_run(cursor);                          // FUN_005eef70
    memset(g_markup->link_target /*+0x6f0*/, 0, 0x101); // clear href, DO NOT finalize
    return 0;
}
```

## Evidence
- Raw: `FUN_005eef70(param_2); memset(iRam007012a0+0x6f0,0,0x101); return 0;` — identical to 0x9d50
  minus the trailing `FUN_005ede30()`.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether this is the link-*open* (reset stale target) or a non-finalizing close; both fit. The
  absence of `FUN_005ede30` is the only behavioral distinction from 0x9d50.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d90.c`  — untouched decompiler output.
