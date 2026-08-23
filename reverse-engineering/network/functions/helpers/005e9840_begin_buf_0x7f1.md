# 0x005e9840 textbuf_begin_0x7f1

| field | value |
|---|---|
| Original address | 0x005e9840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9840 |
| Resolved name | textbuf_begin_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005e9790 (textbuf_flush_if_pending)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x7f0 (flag); cfg+0x7f1 (0x101 buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0

## Behavioral explanation
"Begin a new multi-line text block" — the lighter variant of 0x005e97d0. Flushes any pending block
(FUN_005e9790), sets the open flag `cfg+0x7f0 = 1`, and zeroes the 0x101-byte accumulation buffer at
`cfg+0x7f1`. Unlike 0x005e97d0 it does NOT reset the counter `cfg+4` and does NOT clear `param_2`, so
this is used to open a text block that continues an existing sequence/index.

## Input / output
- `param_1`: unused. `param_2`: passed through to FUN_005e9790 (the flush target); not otherwise used.
- Returns `0`.

## Side effects
- FUN_005e9790: commits+closes any open block.
- `cfg+0x7f0 = 1` (block open).
- `memset(cfg+0x7f1, 0, 0x101)`.

## Important branches
- Only the `if pending` inside FUN_005e9790.

## Constants & flags
- `0x101` — accumulation buffer size.
- `cfg+0x7f0` — block-open flag (set 1).

## Corrected reconstruction
```c
// begin a new text block (keep the seq counter)
uint64_t textbuf_begin_0x7f1(void *unused, void *flush_arg)
{
    textbuf_flush_if_pending_0x7f0(flush_arg);   // FUN_005e9790
    cfg[0x7f0] = 1;
    memset(&cfg[0x7f1], 0, 0x101);
    return 0;
}
```

## Evidence
- Raw decompile: FUN_005e9790(param_2); cfg[0x7f0]=1; memset(cfg+0x7f1,0,0x101).
- Diff vs FUN_005e97d0: missing `cfg[4]=0` and `*param_2=0`.
- Runtime-unvalidated.

## Remaining uncertainty
- Why two begin variants coexist (which keywords map to reset vs. non-reset) — dispatch table not mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9840.c`  — untouched decompiler output.
