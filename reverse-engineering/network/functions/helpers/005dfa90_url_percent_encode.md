# 0x005dfa90 url_percent_encode

| field | value |
|---|---|
| Original address | 0x005dfa90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfa90 |
| Resolved name | percent_encode_all_bytes |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7540
**Callees:** —
**Referenced globals:** s_0123456789ABCDEF_006465c0 (uppercase hex digit LUT)
**Referenced strings:** 0123456789ABCDEF
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Percent-encodes an entire NUL-terminated input string, emitting `%XX` (uppercase hex) for **every** byte with no "unreserved character" pass-through. Writes into `param_1`, NUL-terminates, and returns the number of bytes written (always `3 * strlen(input)`). Because it encodes unconditionally it is a "encode everything" variant — the caller (FUN_005d7540) is responsible for only feeding it the substring that must be escaped, or the result will be fully-escaped.

## Input / output
- **param_1** `char *out` — destination buffer; must hold `3*len + 1` bytes.
- **param_2** `const unsigned char *in` — NUL-terminated source.
- **return** `int` — number of encoded bytes written (excludes the NUL), == `3 * len`.

## Side effects
Writes `out`; NUL-terminates at `out[3*len]`. No globals mutated (LUT is read-only).

## Important branches
- `*param_2 != 0` loop guard: process until NUL.
- No conditional per byte — every byte becomes `'%'`, high-nibble hex, low-nibble hex.

## Constants & flags
- `'%'` = 0x25 prefix.
- `s_0123456789ABCDEF_006465c0` — 16-entry uppercase hex LUT; high nibble = `(b & 0xf0) >> 4`, low nibble = `b & 0x0f`.

## Corrected reconstruction
```c
// Percent-encode EVERY byte of `in` as %XX (uppercase). Returns bytes written (3*len).
int percent_encode_all_bytes(char *out, const unsigned char *in)   // FUN_005dfa90
{
    static const char HEX[] = "0123456789ABCDEF";  // s_..._006465c0
    int written = 0;
    for (; *in != 0; in++) {
        out[0] = '%';                              // 0x25
        out[1] = HEX[(*in & 0xf0) >> 4];
        out[2] = HEX[ *in & 0x0f];
        out    += 3;
        written += 3;
    }
    *out = '\0';
    return written;
}
```

## Evidence
- Raw: `FUN_005dfa90.c` — unconditional `*p='%'; +=3; hi/lo nibble from s_0123456789ABCDEF_006465c0; NUL; return count`.
- Uppercase alphabet confirms `%XX` uppercase output.

## Remaining uncertainty
- Whether the caller pre-filters which characters reach this (i.e. selective escaping happens upstream) is unconfirmed. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfa90.c`  — untouched decompiler output.
