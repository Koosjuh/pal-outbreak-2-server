# 0x00631ec0 softkbd_delete_to_end

| field | value |
|---|---|
| Original address | 0x00631ec0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631ec0 |
| Resolved name | softkbd_delete_char_at_caret |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631790
**Callees:** FUN_006341d0, FUN_00637e10, FUN_00637e90
**Referenced globals:** iRam00715da8 (on-screen-keyboard widget state block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME/predictive buffer; +0x4c main buffer; +0x2a main caret; +0x2c composition caret; +0x28 dirty

## Behavioral explanation
Delete-forward (delete char under the caret) on whichever buffer is active. Only runs when NOT converting (`+0x2f==0`). It picks the target buffer and caret:
- if no predictive composition (`+0x260==0`): target = main text buffer `+0x4c`, caret = `+0x2a`.
- else: target = predictive buffer `+0x260`, caret = `+0x2c`.

It converts the caret's column position to an element index via `FUN_006341d0(buf, caret)` (count of elements that fit within `caret` columns), and if that index is within the buffer length (`FUN_00637e90`, element count), it deletes one element there: null it, then `FUN_00637e10(p, p+1)` copies the tail one element left (compaction). Marks the widget dirty (`+0x28 = 0`).

Despite the interim name "delete_to_end", the operation is a **single-character forward delete with tail-shift**, not a truncate. Renamed `softkbd_delete_char_at_caret`.

## Input / output
- **Params:** none. **Returns:** void.

## Side effects
- Removes one UTF-16 element from the active buffer and shifts the remainder left.
- `+0x28 = 0` (dirty/redraw).

## Important branches
- `+0x2f != 0` (converting) -> no-op.
- `+0x260 == 0` -> operate on `+0x4c` with caret `+0x2a`.
- `+0x260 != 0` -> operate on `+0x260` with caret `+0x2c`.
- inner: `elem_index < buf_len(FUN_00637e90)` -> delete+shift; else no-op (caret at/after end).

## Constants & flags
- none numeric; buffer selection driven by `+0x260` presence.

## Corrected reconstruction
```c
void softkbd_delete_char_at_caret(void)
{
    if (g_softkbd->ime_state /*+0x2f*/ != 0) return;   // don't edit while converting

    short *buf; unsigned short caret_cols;
    if (g_softkbd->predictive[0] /*+0x260*/ == 0) {
        buf = &g_softkbd->text /*+0x4c*/;  caret_cols = g_softkbd->caret_col /*+0x2a*/;
    } else {
        buf = &g_softkbd->predictive;      caret_cols = g_softkbd->comp_caret /*+0x2c*/;
    }

    unsigned idx = cols_to_index(buf, caret_cols) & 0xffff; // FUN_006341d0
    long len = strlen_elems(buf);                           // FUN_00637e90
    if ((long)idx < len) {
        short *p = &buf[idx];
        *p = 0;
        wstr_shift_left(p, p + 1);   // FUN_00637e10: copy tail one element left
        g_softkbd->dirty /*+0x28*/ = 0;
    }
}
```

## Evidence
- Raw: `FUN_00631ec0.c` lines 14-30.
- `FUN_006341d0` confirmed as columns->element-index counter (raw FUN_006341d0.c: accumulates glyph widths until reaching `param_2` columns, returns element count).
- `FUN_00637e10(p, p+1)` is the same shift-left primitive used by FUN_00631f80 (delete-char).
- Runtime-unvalidated.

## Remaining uncertainty
- None significant; the only naming caveat was the misleading prior label.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631ec0.c`  — untouched decompiler output.
