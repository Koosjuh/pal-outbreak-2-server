# 0x00631720 softkbd_home_cursor

| field | value |
|---|---|
| Original address | 0x00631720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631720 |
| Resolved name | softkbd_home_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0 (softkbd input dispatcher)
**Callees:** —
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x28 dirty flag; +0x2a main cursor; +0x2c IME cursor; +0x2f IME state; +0x260 IME buffer; +0x248 result code

## Behavioral explanation
Handles the Home / cursor-to-start key (raw dispatch key 0x4a). When not mid-IME, it moves the caret of the active buffer back to position 0 — the IME cursor (`+0x2c`) if a composition is in progress, otherwise the main-buffer cursor (`+0x2a`). Always marks the widget dirty and posts result 1. (Named "clear_line" in the prior pass; it resets the caret to the line start, it does not erase text.)

## Input / output
- No parameters.
- Returns `void`; output = caret at 0, `+0x28` dirty, `+0x248 = 1`.

## Side effects
- Sets active cursor to 0 (only if currently non-zero).
- `+0x28 = 0` (mark dirty/redraw), `+0x248 = 1`.

## Important branches
- `ime_state==0` (`+0x2f`):
  - IME buffer empty (`+0x260==0`): if `main_cursor != 0`, set `main_cursor = 0`.
  - else (composing): if `ime_cursor != 0`, set `ime_cursor = 0`.
- Regardless: `+0x28 = 0`, `+0x248 = 1`.

## Constants & flags
- `+0x28` dirty flag written 0 to trigger repaint. [inferred — 0 flags "needs redraw"]
- `+0x248 = 1` redraw.

## Corrected reconstruction
```c
// key 0x4a: Home (caret to start of active buffer)
void softkbd_home_cursor(void)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;

    if (kb->ime_state == IME_IDLE) {           // +0x2f == 0
        if (kb->ime_buf[0] == 0) {             // +0x260 empty -> main buffer active
            if (kb->main_cursor != 0)          // +0x2a
                kb->main_cursor = 0;
        } else {                               // composing -> IME buffer active
            if (kb->ime_cursor != 0)           // +0x2c
                kb->ime_cursor = 0;
        }
    }
    kb->dirty  = 0;                            // +0x28 mark redraw
    kb->result = KBRES_REDRAW;                 // +0x248 = 1
}
```

## Evidence
- Raw: nested test of `+0x260` selecting which cursor (`+0x2a`/`+0x2c`) is zeroed; unconditional `+0x28=0`, `+0x248=1`.
- Cursor/buffer offsets consistent with the whole edit-handler family.

## Remaining uncertainty
- The prior name "clear_line" is corrected to "home_cursor": no buffer bytes are written, only the caret index — but the exact semantic (caret-to-start vs select-to-start) is inferred from the single write.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631720.c` — untouched decompiler output.
