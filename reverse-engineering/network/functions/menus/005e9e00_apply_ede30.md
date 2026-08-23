# 0x005e9e00 apply_ede30

| field | value |
|---|---|
| Original address | 0x005e9e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e00 |
| Resolved name | markup_tag_link_finalize |
| Subsystem | menus |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** FUN_005ede30 (finalize link region)
**Referenced globals:** iRam007012a0 (via callee); +0x18, +0x6f0, +0x186, +0xe96b
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18 (link span), +0x6f0 (target), gates +0x186/+0xe96b

## Behavioral explanation
Markup handler that finalizes the current hyperlink without a preceding text flush or buffer clear:
it is a thin trampoline to `FUN_005ede30`, which zeroes the link char-span counter `+0x18` and,
when not in measure mode (`+0x186==0`) and not collapsed (`+0xe96b==0`), submits the accumulated
link target `+0x6f0` through `FUN_005d9290` (register clickable region / dispatch). Compared with
`markup_tag_link_close` (0x9d50) this omits the run-flush and the `+0x6f0` memset — so it commits the
link but leaves the target buffer intact.

## Input / output
- No parameters (void). Returns `0`.

## Side effects
- `FUN_005ede30`: `+0x18 = 0`; conditional `FUN_005d9290(+0x6f0)`.

## Important branches
- `FUN_005ede30` gate: `+0x186 == 0 && +0xe96b == 0` -> submit link, else skip.

## Constants & flags
- `+0x186` measure_mode; `+0xe96b` collapse/suppress.

## Corrected reconstruction
```c
int markup_tag_link_finalize(void)
{
    markup_finalize_link();   // FUN_005ede30: +0x18=0; if visible-pass submit link_target(+0x6f0)
    return 0;
}
```

## Evidence
- Raw: single `FUN_005ede30(); return 0;`.
- `FUN_005ede30` shared with 0x9d50; gates on `+0x186`/`+0xe96b`, submits `+0x6f0`.
- Runtime-unvalidated.

## Remaining uncertainty
- Distinct trigger vs. 0x9d50 (which also flushes+clears) not disambiguated without the tag table.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e00.c`  — untouched decompiler output.
