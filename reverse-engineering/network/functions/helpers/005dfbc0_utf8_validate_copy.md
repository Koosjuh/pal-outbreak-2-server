# 0x005dfbc0 utf8_validate_copy

| field | value |
|---|---|
| Original address | 0x005dfbc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfbc0 |
| Resolved name | utf8_validate_copy_budgeted |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cab10, FUN_005e2fa0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a UTF-8 string from `in` to `out` while validating byte sequences and enforcing a **budget**: each character consumes a fixed `step` amount from a remaining `avail` budget, and the copy stops (NUL-terminating) once the budget can no longer cover another character or the string ends. This budget/step model is a display-fit clamp (fit text into a field of `avail/step` characters). Lead-byte classification:
- `<0x80` — 1-byte ASCII, copied verbatim.
- `0xC0–0xDF` — 2-byte sequence; the 1 continuation byte must be `0x80–0xBF`, else NUL-terminate and abort.
- `0xE0–0xEF` — 3-byte sequence; both continuation bytes must be `0x80–0xBF`; a bad 2nd continuation aborts, a bad 3rd terminates.
- else (`0xF0+`, or a stray `0x80–0xBF`) — copied as a single raw byte (no 4-byte handling; passes lead through).

The function always returns 0; success/failure is expressed only by where the output NUL lands.

## Input / output
- **param_1** `unsigned char *out` — destination.
- **param_2** `const unsigned char *in` — NUL-terminated UTF-8 source.
- **param_3** `int avail` — remaining budget.
- **param_4** `int step` — budget cost charged per character.
- **return** `undefined8` — always 0 (status conveyed via truncation point).

## Side effects
Writes `out` and NUL-terminates it. No globals.

## Important branches
- `*in == 0` -> `*out = 0; return 0` (end of input, clean).
- `avail < step` -> `*out = 0; return 0` (budget exhausted before this char).
- decrement `avail -= step` per accepted character.
- lead `<0x80` -> copy 1 byte, continue.
- lead `0xC0–0xDF`: copy lead; `in[1]` in `0x80–0xBF`? no -> `out[1]=0; return` ; yes -> copy 2 bytes.
- lead `0xE0–0xEF`: copy lead + `in[1]` (validated) ; `in[2]` in `0x80–0xBF`? no -> `out[2]=0; return` ; yes -> copy 3 bytes.
- otherwise -> copy the single lead byte raw and advance 1.

## Constants & flags
- Lead-byte class boundaries: `0x80` (ASCII/non-ASCII), `0xC0`/`0xDF` (2-byte), `0xE0`/`0xEF` (3-byte).
- Continuation-byte valid range: `0x80–0xBF`.

## Corrected reconstruction
```c
// Budgeted UTF-8 validating copy. Each glyph costs `step` from `avail`.
// Stops (NUL-terminates) at end-of-input, budget exhaustion, or malformed sequence.
// Always returns 0; the truncation point is the only result signal.
unsigned long utf8_validate_copy_budgeted(unsigned char *out,
                                          const unsigned char *in,
                                          int avail, int step)     // FUN_005dfbc0
{
    for (;;) {
        unsigned char c = in[0];
        if (c == 0)          { *out = 0; return 0; }   // end of input
        if (avail < step)    { *out = 0; return 0; }   // budget exhausted
        avail -= step;

        if (c < 0x80) {                                // ASCII
            *out++ = c; in += 1; continue;
        }
        if (c >= 0xC0 && c <= 0xDF) {                  // 2-byte
            out[0] = c;
            unsigned char c1 = in[1];
            if (c1 < 0x80 || c1 > 0xBF) { out[1] = 0; return 0; }
            out[1] = c1; in += 2; out += 2; continue;
        }
        if (c >= 0xE0 && c <= 0xEF) {                  // 3-byte
            out[0] = c;
            unsigned char c1 = in[1];
            if (c1 < 0x80 || c1 > 0xBF) { out[1] = 0; return 0; }
            out[1] = c1;
            unsigned char c2 = in[2];
            if (c2 < 0x80 || c2 > 0xBF) { out[2] = 0; return 0; }
            out[2] = c2; in += 3; out += 3; continue;
        }
        // 0xF0+ or stray continuation: pass one byte through
        *out++ = c; in += 1;
    }
}
```

## Evidence
- Raw: `FUN_005dfbc0.c` — nested `while(true)` structure with the `<0x80`, `0xc0..0xdf`, `0xe0..0xef` ladders, continuation checks `<0x80 || >0xbf` -> write terminator + return, and the `param_3 < param_4` budget guard with `param_3 -= param_4`.
- The associated `thunk_EXT_FUN_001ae3e0` (0x5dfce0, halt_baddata stub) is in the same source file but is a separate symbol, not this function.

## Remaining uncertainty
- No 4-byte (`0xF0+`) sequence handling — those leads are passed through as a lone byte, which is technically lossy; whether callers ever supply 4-byte UTF-8 is unknown. The exact meaning of `step` (pixel width? fixed 1?) is inferred as a per-glyph budget. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfbc0.c`  — untouched decompiler output.
