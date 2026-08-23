# 0x005e88c0 tag_set_digit_2d3

| field | value |
|---|---|
| Original address | 0x005e88c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e88c0 |
| Resolved name | tag_store_digit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef200 (save/enter render state), FUN_005ef040 (flush + line-feed), FUN_005ef220 (restore + reload palette)
**Referenced globals:** 0x6494b0 (256-byte digit remap table); 0x648248 (delimiter string); ctx+0x2d3 (digit char); +0x2d4 (nul terminator)
**Referenced strings:** delimiter at 0x648248
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x2d3; +0x2d4

## Behavioral explanation
Markup tag with a single numeric argument. It normalizes the digit character immediately
preceding the parse cursor and stores it as a one-character string in the context, then skips the
source cursor past a delimiter, then flushes with a line-feed. The whole body is bracketed by
`FUN_005ef200` (enter/save render state) and `FUN_005ef220` (restore state + reapply palette via
`FUN_005ec100`), i.e. a push/pop so the digit substitution does not leak attribute changes.

Digit normalization: it takes the byte at `*param_1 - 1` (the character just consumed before this
handler ran), subtracts `'0'` (0x30), masks to a byte, indexes the 256-entry remap table
`0x6494b0`, then adds `'0'` back — producing a canonical ASCII digit at `ctx+0x2d3`, NUL-terminated
at `ctx+0x2d4`. It then advances the cursor: `strchr/strpbrk(*param_1, 0x648248)` finds the
delimiter and `*param_1 = found + 1` steps just past it, so parsing resumes after the tag's
terminator.

## Input / output
- `param_1` (int* → source cursor): points to the markup source position; on exit advanced to just after the delimiter `0x648248`. The byte at `*param_1 - 1` is the raw digit input.
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005ef040`.
- returns 0.

## Side effects
- `ctx+0x2d3 = '0' + digit_remap[ (raw - '0') & 0xff ]` — stored canonical digit.
- `ctx+0x2d4 = 0` — makes `+0x2d3` a 1-char C string.
- `*param_1` advanced past the delimiter (`func_0x0010a700(*param_1, 0x648248) + 1`).
- `FUN_005ef040(param_2)`: flush run + line-feed.
- Bracketed by `FUN_005ef200()` / `FUN_005ef220()` (state push / pop + palette reload).

## Important branches
None (straight-line). No bounds check on the `strchr` result — a missing delimiter would deref/advance past a NULL match [potential fragility, source assumed well-formed].

## Constants & flags
- `0x6494b0` — 256-byte digit remap/normalization table (indexed by `raw - 0x30`).
- `0x648248` — delimiter string used to find the tag terminator (`strchr`/`strpbrk` argument).
- `ctx+0x2d3` / `+0x2d4` — 1-char digit field + its NUL terminator.
- `func_0x0010a700(s, set)` — `strchr`/`strpbrk`-style scan returning a pointer [inferred].
- `func_0x0010a700` result `+ 1` — step past the matched delimiter byte.

## Corrected reconstruction
```c
extern const uint8_t digit_remap[256];      // 0x6494b0
extern const char    tag_delim[];           // 0x648248

undefined8 tag_store_digit(uint32_t *src_cursor, uint8_t *run_acc)
{
    render_state_push();                                     // FUN_005ef200
    {
        uint8_t raw = ((uint8_t*)*src_cursor)[-1];          // char consumed before this handler
        g_txtctx->digit_char = '0' + digit_remap[(raw - '0') & 0xff];  // +0x2d3
        g_txtctx->digit_nul  = 0;                            // +0x2d4
        char *end = strchr((char*)*src_cursor, tag_delim);  // func_0x0010a700
        *src_cursor = (uint32_t)(end + 1);                  // resume past delimiter
    }
    txtmarkup_flush_and_linefeed(run_acc);                  // FUN_005ef040
    render_state_pop();                                     // FUN_005ef220 (reapplies palette)
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e88c0.c`.
- `func_0x0010a700(cursor, 0x648248)` used as a delimiter scan with `+1` advance — standard `strchr`+skip idiom; same `func_0x00109eb8/…a700` library-thunk family seen in `FUN_005e83c0`.
- `FUN_005ef220` appears in `FUN_005ec100`'s caller set → the pop reapplies the color palette.
- `FUN_005ef040` (read) = flush + line-feed.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Contents of remap table `0x6494b0` and delimiter `0x648248` (not dumped) — whether the remap does simple identity, full-width→ASCII, or slot mapping.
- Downstream consumer of `ctx+0x2d3` (which text/menu field the stored digit feeds) is not traced here.
