# 0x005e97d0 textbuf_begin_reset_0x7f1

| field | value |
|---|---|
| Original address | 0x005e97d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e97d0 |
| Resolved name | textbuf_begin_reset_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005e9790 (textbuf_flush_if_pending), func_0x00106b60 (memset)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x7f0 (flag); cfg+0x7f1 (0x101 buf); cfg+0x4 (counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f0; cfg+0x4

## Behavioral explanation
"Begin a new multi-line text block, resetting the sequence counter." First flushes any pending block
(FUN_005e9790), then opens a fresh block: sets the open flag `cfg+0x7f0 = 1`, zeroes the 0x101-byte
accumulation buffer at `cfg+0x7f1`, resets the counter/offset `cfg+4 = 0`, and clears the caller's
output byte `*param_2 = 0`. This is the variant used where the block's line/seq counter (`cfg+4`) must
also be reset — vs. 0x005e9840 which begins without touching `cfg+4` or `param_2`.

## Input / output
- `param_1`: unused.
- `param_2` (`char *out`): a caller output/scratch byte that is zeroed (NUL-terminated to empty).
- Returns `0`.

## Side effects
- FUN_005e9790: commits+closes any previously-open block.
- `cfg+0x7f0 = 1` (block open).
- `memset(cfg+0x7f1, 0, 0x101)` — clears accumulation buffer.
- `cfg+4 = 0` — resets the block counter/offset.
- `*param_2 = 0`.

## Important branches
- The only conditional is inside FUN_005e9790 (`if pending`). This function is otherwise straight-line.

## Constants & flags
- `0x101` (257) — accumulation buffer size at `cfg+0x7f1`.
- `cfg+0x7f0` — block-open flag (set to 1).
- `cfg+0x4` — per-block counter/offset (reset to 0).

## Corrected reconstruction
```c
// begin a new text block AND reset the seq counter
uint64_t textbuf_begin_reset_0x7f1(void *unused, char *out)
{
    textbuf_flush_if_pending_0x7f0();     // FUN_005e9790: commit any open block
    cfg[0x7f0] = 1;                       // open
    memset(&cfg[0x7f1], 0, 0x101);        // func_0x00106b60
    *(uint32_t *)&cfg[0x4] = 0;           // reset counter/offset
    *out = 0;                             // clear caller output byte
    return 0;
}
```

## Evidence
- Raw decompile: FUN_005e9790(param_2); cfg[0x7f0]=1; memset(cfg+0x7f1,0,0x101); cfg[4]=0; *param_2=0.
- `func_0x00106b60` used elsewhere as memset(dst,val,len).
- Runtime-unvalidated.

## Remaining uncertainty
- Meaning of `cfg+4` (line index vs. byte offset into 0x7f1) not confirmed.
- `param_2` semantics (which caller buffer) inferred as an output cursor byte.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e97d0.c`  — untouched decompiler output.
