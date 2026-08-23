# 0x005e9d50 reset_field_0x6f0_ede30

| field | value |
|---|---|
| Original address | 0x005e9d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d50 |
| Resolved name | markup_tag_link_close |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005eef70 (flush run), func_0x00106b60 (memset), FUN_005ede30 (finalize link region)
**Referenced globals:** iRam007012a0; +0x6f0 (0x101-byte link/href target buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x6f0; +0x18 (link char span); +0x186/+0xe96b mode gates (via callee)

## Behavioral explanation
Markup **link-close** handler (e.g. end of an `<a href="...">...</a>` span). It flushes the pending
styled text run (`FUN_005eef70`), then clears the 0x101-byte link-target buffer at `+0x6f0`, and
calls `FUN_005ede30` to finalize the link: `FUN_005ede30` zeroes the link char-span counter `+0x18`
and — only when not in measure mode (`+0x186==0`) and not collapsed (`+0xe96b==0`) — registers the
hyperlink target string via `FUN_005d9290(+0x6f0)`. Clearing `+0x6f0` *before* the finalize means the
current link scope's href is consumed then reset for the next.

## Input / output
- `param_1`: tag descriptor (unused).
- `param_2` (`char **cursor`): flushed/reset by `FUN_005eef70`.
- Returns `0`.

## Side effects
- Commits pending text run (`FUN_005eef70`), resets run counter `+0x4` and `*param_2`.
- `memset(g_markup+0x6f0, 0, 0x101)` — clears link target.
- `FUN_005ede30`: `+0x18 = 0`; conditionally submits link via `FUN_005d9290`.

## Important branches
- `FUN_005ede30` gate: `+0x186 == 0 && +0xe96b == 0` -> `FUN_005d9290(+0x6f0)`, else skip
  (measure pass / collapsed content emit nothing).
- `FUN_005eef70` table-mode branch as in `markup_tag_style_pop`.

## Constants & flags
- `0x101` — link-buffer clear length (buffer capacity 0x100 + NUL).
- `+0x186` = measure_mode; `+0xe96b` = collapse/suppress flag.

## Corrected reconstruction
```c
int markup_tag_link_close(void *tag /*param_1, unused*/, char **cursor /*param_2*/)
{
    markup_flush_run(cursor);                 // FUN_005eef70
    memset(g_markup->link_target /*+0x6f0*/, 0, 0x101);
    markup_finalize_link();                   // FUN_005ede30
    return 0;
}

// FUN_005ede30 (reference):
void markup_finalize_link(void) {
    g_markup->link_span /*+0x18*/ = 0;
    if (!g_markup->measure_mode /*+0x186*/ && !g_markup->collapsed /*+0xe96b*/)
        markup_submit_link(g_markup->link_target /*+0x6f0*/);  // FUN_005d9290
}
```

## Evidence
- Raw: `FUN_005eef70(param_2); memset(iRam007012a0+0x6f0,0,0x101); FUN_005ede30();`.
- `FUN_005ede30` (read): `*(+0x18)=0`; gated `FUN_005d9290(+0x6f0)`.
- Sibling `reset_field_0x6f0` (0x9d90) is the same minus the finalize call.
- Runtime-unvalidated.

## Remaining uncertainty
- `FUN_005d9290` treated as "register hyperlink hit-region/target"; not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d50.c`  — untouched decompiler output.
