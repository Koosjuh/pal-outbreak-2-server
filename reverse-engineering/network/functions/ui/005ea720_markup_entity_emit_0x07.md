# 0x005ea720 markup_entity_emit_0x07

| field | value |
|---|---|
| Original address | 0x005ea720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea720 |
| Resolved name | markup_entity_emit_ctrl07 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eee00 (line/overflow flush)
**Referenced globals:** +0x04 (output length counter); +0xd8e4 (flush target)
**Referenced strings:** —
**Referenced opcodes:** — (`0x07` is an in-band control byte, not a packet opcode)
**State vars:** +0x04

## Behavioral explanation
Entity handler that appends the control byte `0x07` to the output text buffer with the shared near-full flush guard. Unlike the printable-ASCII siblings (`<`,`>`,`"`,`&`,`'`), `0x07` is a non-printable control code — most likely an internal markup/inline-formatting sentinel consumed by the text renderer (e.g. a color/marker escape) rather than a displayable glyph. Same append+NUL+guard shape as the whole emitter family.

## Input / output
- `param_1` — parser context (unused). [inferred]
- `param_2` — output buffer base.
- returns 0.

## Side effects
- `out_buf[len] = 0x07`; NUL at `len+1`; `len (+0x04) += 1`; optional flush.

## Important branches
- `len > 0x7d` → flush FUN_005eee00(`+0xd8e4`) before append.

## Constants & flags
- `0x7d` threshold. `0x07` = emitted control byte (internal formatting sentinel [inferred]).

## Corrected reconstruction
```c
undefined8 markup_entity_emit_ctrl07(void *ctx, char *out_buf)
{
    MarkupCtx *c = mkctx;
    if (c->out_len > 0x7d)
        line_flush(&c->wrap_struct);          // FUN_005eee00

    int i = c->out_len;
    c->out_len = i + 1;
    out_buf[i]     = 0x07;                     // internal control byte
    out_buf[c->out_len] = '\0';
    return 0;
}
```

## Evidence
- Raw: `FUN_005ea720.c` — identical to the emitter family except emitted byte `0x07`.
- Runtime-unvalidated.

## Remaining uncertainty
- The concrete meaning of the emitted `0x07` control code (which renderer feature it triggers) is not resolved. `param_1` [inferred].
