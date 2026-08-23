# 0x005e9e20 close_buf_reset_ee010

| field | value |
|---|---|
| Original address | 0x005e9e20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e20 |
| Resolved name | markup_tag_linebreak |
| Subsystem | helpers |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005e9790 (close open inline object), FUN_005ee010 (advance layout line)
**Referenced globals:** iRam007012a0; +0x7f0 (inline-object-open flag); +0x4 (pending-run counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x7f0; +0x4

## Behavioral explanation
Markup **line-break / paragraph-advance** handler (e.g. `<br>` or end-of-line). It first closes any
open inline object via `FUN_005e9790` (which, if the inline-object flag `+0x7f0` is set, runs
`FUN_005ede80` to finalize it and clears `+0x7f0`), then calls `FUN_005ee010` to advance the layout
to a new line — `FUN_005ee010` computes the next baseline/row geometry, updates the running layout
cursor (`+0xd8bc/+0xd8c0`), and (in the visible pass) emits the line's hit-region via
`FUN_005d9350`. Finally it zeroes the pending-run counter `+0x4` and the parser cursor byte
(`*param_2 = 0`), starting a fresh run on the new line.

## Input / output
- `param_1`: tag descriptor (unused).
- `param_2` (`char *cursor`): its first byte is zeroed to reset the pending run.
- Returns `0`.

## Side effects
- Closes/finalizes open inline object; clears `+0x7f0`.
- Advances layout row (`FUN_005ee010`): mutates `+0xd8bc/+0xd8c0/+0xd8cc`, table-cell geometry,
  emits line hit-box (visible pass).
- Resets `+0x4 = 0` and `*param_2 = 0`.

## Important branches
- `FUN_005e9790`: only acts if `+0x7f0 != 0`.
- `FUN_005ee010`: `+0xd892` table-mode -> `FUN_005f2b10` (table path) else normal line advance;
  within it, wrap check vs. `+0x10` width; hit-box emit gated by `+0x186==0 && +0xe96b==0`;
  measure-pass minimum row height clamp to `0x14`.

## Constants & flags
- `+0x7f0` = inline-object-open flag; `+0x4` = current run glyph count.
- `0x14` (20) — minimum line height in measure mode.

## Corrected reconstruction
```c
int markup_tag_linebreak(void *tag /*param_1, unused*/, char *cursor /*param_2*/)
{
    markup_close_inline_object();   // FUN_005e9790: if (+0x7f0) finalize + clear
    markup_advance_line();          // FUN_005ee010: next baseline, cursor, line hit-box
    g_markup->run_count /*+0x4*/ = 0;
    *cursor = 0;                    // reset pending run
    return 0;
}
```

## Evidence
- Raw: `FUN_005e9790(param_2); FUN_005ee010(); *(+0x4)=0; *param_2=0;`.
- `FUN_005e9790` (read): guarded by `+0x7f0`, calls `FUN_005ede80`, clears flag.
- `FUN_005ee010` (read): line-geometry advance, `FUN_005d9350` hit-box, table branch `FUN_005f2b10`.
- Runtime-unvalidated.

## Remaining uncertainty
- `FUN_005e9790`'s `param_2` argument is passed but the callee takes void — decompiler artifact;
  arg is ignored. Exact inline-object type (image/ruby) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e20.c`  — untouched decompiler output.
