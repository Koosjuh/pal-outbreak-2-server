# 0x005eee00 text_flush_keep_trailing_char

| field | value |
|---|---|
| Original address | 0x005eee00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eee00 |
| Resolved name | text_flush_keep_trailing_char |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30, FUN_005ea520, FUN_005ea5a0, FUN_005ea620, FUN_005ea6a0, FUN_005ea720, FUN_005ea7a0
**Callees:** FUN_005eef70 (render_text_token)
**Referenced globals:** iRam007012a0 (UI ctx); ctx+0x4 = pending text-buffer length
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4 (buffer length)

## Behavioral explanation
Auto-flush splitter for the pending text-accumulation buffer (`param_1`, whose length is held in
`ctx+0x4`). It walks the buffer as a multibyte (Shift-JIS / high-bit-lead) string to locate the
**start of the final character**, then, if that final character is a multibyte glyph (lead byte
`>= 0x80`), it detaches those trailing bytes, truncates the buffer just before them, renders the
head via `render_text_token` (0x005eef70), and repopulates the buffer with only the carried glyph.
Net effect: when a text run is force-flushed, a multibyte glyph is never split across the flush —
the last glyph is carried forward as the new buffer contents. If the final character is single-byte
(no high bit), nothing is carried and the buffer is emptied after the flush.

## Input / output
- `param_1` : `char*` — pending text buffer (also the UI ctx text scratch). Mutated in place.
- `param_2/param_3/param_4` : scratch/ABI-spill; `param_4` is reused internally as the running
  last-char-start index (masked to a byte). No meaningful caller value.
- Returns `void`.

## Side effects
- Calls `render_text_token(param_1)` which emits the head text and resets the cursor/buffer.
- Rewrites `ctx+0x4` (buffer length) to either 0 (nothing carried) or the carried-glyph byte count.
- Rewrites `param_1[]` to the carried glyph (NUL-terminated) or empties it.

## Important branches
- **memset head:** the leading `while` zero-fills the 8-byte stack temp `acStack_8` (6-byte compiler
  memset idiom) that will hold the carried glyph.
- **scan loop `for(uVar5..)`:** for each byte, if `(byte & 0x80)!=0` it runs the inner
  `do{ uVar9<<=1 } while(high bit)` — counting the multibyte lead-byte run length (UTF-8/JIS-style
  lead-bit count) and advancing the index past the whole glyph. `param_4` tracks the start index of
  the last glyph reached.
- **carry gate:** `if (iVar7 <= uVar6 && (buf[param_4] & 0x80))` — only when the scan consumed the
  whole buffer *and* the final glyph is multibyte: copy `buf[param_4..len]` into `acStack_8`,
  `buf[param_4]=0` (truncate), `iVar10` = carried byte count.
- **post-flush rebuild:** after `render_text_token`, `if (acStack_8[0]==0)` → `ctx+0x4=0`,
  `buf[0]=0` (empty); `else` → `ctx+0x4 = iVar10`, copy carried bytes back and NUL-terminate.

## Constants & flags
- `0x80` — multibyte lead-byte / continuation high bit.
- buffer capacity implied `iRam007012a0+4` element count; carry temp is 8 bytes.

## Corrected reconstruction
```c
// Flush the pending text run but carry a trailing multibyte glyph to the next run,
// so a glyph is never split across an auto-flush boundary.
void text_flush_keep_trailing_char(char *buf /*param_1*/)
{
    UiCtx *ctx = (UiCtx *)iRam007012a0;
    char carry[8];
    memset(carry, 0, sizeof carry);       // 6-byte memset idiom in decompile

    int last_len   = ctx->text_len - 1;   // ctx+0x4
    unsigned idx   = 0, last_start = 0;

    for (unsigned i = 0; (int)i <= last_len; i = (i + 1) & 0xff) {
        unsigned b = (unsigned char)buf[i];
        if (b & 0x80) {                   // multibyte lead: skip its continuation bytes
            do { b = (b << 1) & 0xff; i = (i + 1) & 0xff; } while (b & 0x80);
            i = (i - 1) & 0xff;
        }
        last_start = i;                   // param_4
    }
    last_start &= 0xff;

    int carried = 0;
    if (last_len <= (int)last_start && (buf[last_start] & 0x80)) {
        // final glyph is multibyte -> detach it
        for (unsigned p = last_start; (int)p <= ctx->text_len - 1; p++)
            carry[carried++] = buf[p];
        buf[last_start] = 0;              // truncate head
    }

    render_text_token(buf);              // 0x005eef70: emit head, reset cursor/buffer

    if (carry[0] == 0) {                 // nothing carried
        ctx->text_len = 0;
        buf[0] = 0;
    } else {                             // re-seed buffer with the carried glyph
        ctx->text_len = carried;
        int k = 0;
        for (; k < carried; k++) buf[k] = carry[k];
        buf[k] = 0;
    }
}
```

## Evidence
- Raw `FUN_005eee00.c`: high-bit scan + `<<1` continuation-count loop; `acStack_8[8]` carry temp;
  `ctx+0x4` len read/rewrite; single callee `FUN_005eef70`.
- 7 callers are all sibling text emitters in the 0x005ea* cluster (auto-flush call sites).
- Runtime-unvalidated (static reconstruction).

## Remaining uncertainty
- Exact buffer capacity / when callers trigger the flush (mid-append overflow vs. explicit break).
- Whether the multibyte encoding is strictly Shift-JIS or a game-specific high-bit scheme.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eee00.c`  — untouched decompiler output.
