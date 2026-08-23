# 0x005e9890 textbuf_read_value_0x7f1

| field | value |
|---|---|
| Original address | 0x005e9890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9890 |
| Resolved name | textbuf_read_value_0x7f1 |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (keyword-dispatch table)
**Callees:** FUN_005ec1b0 (cfg_read_value)
**Referenced globals:** 0x007012a0 (cfg base ptr); cfg+0x7f1 (0x101 accumulation buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x7f1

## Behavioral explanation
Reads the `=value` token directly into the text-block accumulation buffer at `cfg+0x7f1` (the buffer
opened by 0x005e97d0/0x005e9840 and committed by FUN_005ede80). Effectively the "body line" handler:
whereas begin opens/zeroes the buffer and end trims/commits it, this writes the raw parsed value into
it. Capacity is passed as 0x100 (the reader's `-3` guard keeps it within the 0x101 buffer).

## Input / output
- `param_1` (`char **cursor`): parser cursor; advanced past the value.
- Returns `0`.

## Side effects
- Writes up to 0x100 bytes (NUL-terminated) into `cfg+0x7f1`.
- Advances `*cursor`.

## Important branches
- None locally; see cfg_read_value.

## Constants & flags
- `0x100` — copy limit into the 0x101-byte buffer.

## Corrected reconstruction
```c
// read a value line into the text-block buffer → cfg+0x7f1
uint64_t textbuf_read_value_0x7f1(char **cursor)
{
    cfg_read_value(cursor, &cfg[0x7f1], 0x100);   // FUN_005ec1b0
    return 0;
}
```

## Evidence
- Raw decompile: single `FUN_005ec1b0(param_1, cfg+0x7f1, 0x100)`.
- Buffer identity with the begin/end handlers (same `cfg+0x7f1`, size 0x101).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether this overwrites vs. is meant to precede an ede80 append; behavior depends on block flag state.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9890.c`  — untouched decompiler output.
