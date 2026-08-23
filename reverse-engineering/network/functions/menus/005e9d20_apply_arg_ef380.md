# 0x005e9d20 apply_arg_ef380

| field | value |
|---|---|
| Original address | 0x005e9d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d20 |
| Resolved name | markup_tag_style_pop |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005eef70 (flush pending text run), FUN_005ef380 (style-stack pop)
**Referenced globals:** iRam007012a0 (markup state, via callees)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** style stack depth +0x124; pending run +0x4 (via callee)

## Behavioral explanation
Markup **close-scope** handler (the counterpart to `markup_tag_style_push`/`FUN_005ef220`). It first
flushes the pending styled text span accumulated so far (`FUN_005eef70`, which commits the current
run into the active line record and resets the run counter `+0x4` and the parse cursor), then pops
the top style-stack frame via `FUN_005ef380` (decrements depth `+0x124`, floor 0, re-applies the
active color). Net effect: `</style>` — text after this tag reverts to the enclosing style.

## Input / output
- `param_1`: tag descriptor (unused by this handler).
- `param_2` (`char **cursor`): parse cursor; passed to the flush, which sets `*cursor = 0` and
  advances layout.
- Returns `0`.

## Side effects
- Commits the pending text run to the current line (`FUN_005eef70`): appends glyphs, updates the
  layout cursor (`+0xd8bc/+0xd8be`), resets run length `+0x4 = 0`, `*param_2 = 0`.
- Decrements style depth `+0x124` (floor 0) and re-latches color (`FUN_005ec100`).

## Important branches
- `FUN_005eef70`: `+0xd892` table-mode -> `FUN_005f3ac0` (table path) else the normal line-append
  path.
- `FUN_005ef380`: if `+0x124 < 1` -> set 0 (no underflow) else depth -= 1.

## Constants & flags
- Style depth floored at 0 on pop.

## Corrected reconstruction
```c
int markup_tag_style_pop(void *tag /*param_1, unused*/, char **cursor /*param_2*/)
{
    markup_flush_run(cursor);      // FUN_005eef70: commit current span, reset run+cursor
    markup_style_stack_pop();      // FUN_005ef380: depth-- (floor 0), re-apply color
    return 0;
}
```

## Evidence
- Raw: `FUN_005eef70(param_2); FUN_005ef380(); return 0;`.
- `FUN_005eef70` (read): non-table branch appends run, `*(+0x4)=0`, `*param_1=0`; table branch
  `FUN_005f3ac0`.
- `FUN_005ef380` (read): `+0x124` decrement with floor 0, `FUN_005ec100(color)`.
- Runtime-unvalidated.

## Remaining uncertainty
- `param_1` role assumed to be the tag/self descriptor (unused here); confirmed only by arity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d20.c`  — untouched decompiler output.
