# 0x00631880 softkbd_cursor_advance

| field | value |
|---|---|
| Original address | 0x00631880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631880 |
| Resolved name | softkbd_cursor_advance |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0 (softkbd input dispatcher)
**Callees:** FUN_00637e90 (buffer length / strlen16), FUN_00634160 (next-glyph caret index)
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2a main cursor; +0x260 IME buffer; +0x2f IME state; +0x4c main buffer; +0x28 dirty; +0x248 result code

## Behavioral explanation
Handles a caret-right / advance key (raw dispatch key 0x4d) on the main text buffer. When idle (no IME composition) and the caret is not already at the end, it advances the main-buffer caret to the next glyph boundary computed by FUN_00634160 (multibyte/UTF-16 aware). Always marks dirty and posts result 1. (Prior name "cursor_to_end" is corrected: it advances by one glyph position, not straight to the end.)

## Input / output
- No parameters.
- Returns `void`; output = `+0x2a` caret, `+0x28` dirty, `+0x248 = 1`.

## Side effects
- If advance allowed: `main_cursor = next_glyph_index(main_buf)`.
- Unconditional: `+0x28 = 0` (dirty), `+0x248 = 1`.

## Important branches
- Guard (all): `ime_state==0` AND IME buffer empty (`+0x260==0`) AND `main_cursor < strlen16(main_buf)`.
  - passes -> `main_cursor = FUN_00634160(main_buf)`.
- Always: mark dirty + result 1.

## Constants & flags
- `+0x248 = 1` redraw; `+0x28 = 0` dirty.

## Corrected reconstruction
```c
// key 0x4d: caret-right (advance one glyph in main buffer)
void softkbd_cursor_advance(void)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;

    if (kb->ime_state == IME_IDLE &&           // +0x2f == 0
        kb->ime_buf[0] == 0 &&                 // +0x260 empty (editing main buffer)
        kb->main_cursor < strlen16(&kb->main_buf)) {   // +0x2a < len
        kb->main_cursor = next_glyph_index(&kb->main_buf); // FUN_00634160
    }
    kb->dirty  = 0;                            // +0x28
    kb->result = KBRES_REDRAW;                 // +0x248 = 1
}
```

## Evidence
- Raw: guard `uVar1 = +0x2a; uVar3 = FUN_00637e90(+0x4c); uVar1 < uVar3` then `+0x2a = FUN_00634160(+0x4c)`.
- FUN_00637e90 = strlen16 shared with FUN_00631810.

## Remaining uncertainty
- FUN_00634160 receives only the buffer pointer; it presumably reads the current caret from `+0x2a` internally and returns caret+1-glyph. Whether it clamps to end or returns exact next boundary is not decoded — hence the "advance by one" vs "to end" ambiguity (Medium).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631880.c` — untouched decompiler output.
