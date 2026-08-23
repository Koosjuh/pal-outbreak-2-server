# 0x005e98e0 textbuf_end_commit_0x7f0

| field | value |
|---|---|
| Original address | 0x005e98e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e98e0 |
| Resolved name | textbuf_end_commit_0x7f0 |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ede80 (textbuf_trim_and_commit)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x7f0 (flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
"End the multi-line text block." Commits the provided text via FUN_005ede80 (leading-space skip,
trailing SP/TAB trim, multibyte-aware width count into `cfg+0x18`, copy into `cfg+0x7f1` under the
0x186/0xe96b flag guard) and then clears the open flag `cfg+0x7f0 = 0`. Unlike the flush helper
0x005e9790, this passes an explicit text pointer (`param_2`) to be committed and always clears the flag
(no pending-check).

## Input / output
- `param_1`: unused.
- `param_2` (`char *text`): the text to trim/commit into the accumulation buffer.
- Returns `0`.

## Side effects
- FUN_005ede80(param_2): trims + width-counts + copies into `cfg+0x7f1`; may raise `cfg+0x18` (max
  width) and clears `cfg+0x8f1` (continuation flag) after copying.
- `cfg+0x7f0 = 0` (block closed).

## Important branches
- None locally. The copy step inside FUN_005ede80 is gated by `cfg+0x186 == 0 && cfg+0xe96b == 0`.

## Constants & flags
- `cfg+0x7f0` — block-open flag (cleared to 0).

## Corrected reconstruction
```c
// end the text block: commit param_2 then close
uint64_t textbuf_end_commit_0x7f0(void *unused, char *text)
{
    textbuf_trim_and_commit(text);   // FUN_005ede80
    cfg[0x7f0] = 0;                  // close
    return 0;
}
```

## Evidence
- Raw decompile: FUN_005ede80(param_2); cfg[0x7f0]=0.
- FUN_005ede80 body read directly (trim/width/copy, flag guard).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether `param_2` is the same buffer as `cfg+0x7f1` or a separate source line.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e98e0.c`  — untouched decompiler output.
