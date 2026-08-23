# 0x00616570 parse_dotted_field

| field | value |
|---|---|
| Original address | 0x00616570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616570 |
| Resolved name | extract_tagged_field_3 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00613600, FUN_006140d0 (both list/row draw paths)
**Callees:** func_0x00102790 (bzero/clear dst), func_0x0010a338 (strncmp/memcmp), func_0x00109be0 (strchr)
**Referenced globals:** —
**Referenced strings:** 0x693930 (7-byte tag/prefix constant)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Normalizes a display string into a bounded output buffer. It first zero-fills the destination. If the
source begins with a specific 7-byte tag (constant at `0x693930`) **and** contains exactly 5 dots
(i.e. 6 dot-separated fields), it extracts **the 3rd field** (the text between the 2nd and 3rd dot) and
copies it, bounded to `size-1`, NUL-terminated. Otherwise it copies the whole source verbatim, bounded
to `size-1`. Returns 0 on success, `-101` (`0xffffff9b`) if either the source or destination pointer is
NULL. Used by the two list-row draw functions to reduce a tagged, multi-field internal identifier to the
one human-facing field before rendering.

## Input / output
- `param_1` (`char*`): source string. NULL → returns `-101`.
- `param_2` (`long`, used as `char*`): destination buffer. NULL → returns `-101`.
- `param_3` (`undefined8`, used as `int`): destination capacity; at most `param_3 - 1` bytes are copied,
  leaving room for the NUL. Also passed to the initial clear.
- **returns** `undefined4`: `0` on success, `0xffffff9b` (-101) on NULL src/dst.

## Side effects
- `func_0x00102790(dst, size)` — clears the destination buffer up front.
- Writes the extracted/copied field + NUL terminator into `dst`.

## Important branches
- `src == NULL` → return `-101`.
- `dst == NULL` → return `-101`.
- `strncmp(src, TAG7, 7) == 0` → enter dot-count loop; `matched = (dot_count == 5)`.
- `matched` (tagged, 6 fields):
  - locate the 3rd field via two successive `strchr('.')`; if `size-1 > 0` and the field is non-empty
    and does not start with `'.'`, copy chars until `'.'`, end-of-string, or the `size-1` cap.
  - if the 3rd field is empty / starts with `'.'` → dst stays empty (just NUL).
- else (untagged or wrong dot count) → copy whole `src` up to `size-1` or its NUL.
- All paths converge to `*dst = 0` and `return 0`.

## Constants & flags
- Tag at `0x693930`, compared for its first `7` bytes (`strncmp` length 7).
- Dot delimiter `0x2e` (`'.'`); required count `5` (⇒ 6 fields) to trigger field extraction.
- Extracted field ordinal: index `2` (3rd field — after skipping the first two `'.'`).
- Bound `size - 1` (reserve for NUL).
- Error code `0xffffff9b` = `-101`.

## Corrected reconstruction
```c
// TAG7 = the 7-byte constant at 0x693930.
// Returns 0 ok, -101 on NULL src/dst.
int extract_tagged_field_3(const char *src, char *dst, int size)
{
    bool matched = false;
    int  n = 0;

    bzero(dst, size);                                   // func_0x00102790
    if (src == NULL) return -101;                       // 0xffffff9b
    if (dst == NULL) return -101;

    int cap = size - 1;

    if (strncmp(src, (const char *)0x693930, 7) == 0) { // func_0x0010a338
        const char *p = src;
        for (;;) {                                       // count dots
            const char *dot = strchr(p, '.');            // func_0x00109be0
            if (dot == NULL) break;
            n++;
            p = dot + 1;
        }
        matched = (n == 5);                              // exactly 6 fields
    }

    char *out = dst;
    if (matched) {
        // skip first two dots -> start of 3rd field
        const char *f3 = strchr(strchr(src, '.') + 1, '.') + 1;
        int i = 0;
        if (cap > 0 && *f3 != '\0' && *f3 != '.') {
            do {
                out[i] = f3[i];
                i++;
                if (cap <= i) break;
            } while (f3[i] != '\0' && f3[i] != '.');
            out += i;
        }
    } else {
        // copy whole source, bounded
        int i = 0;
        if (cap > 0 && *src != '\0') {
            do {
                out[i] = src[i];
                i++;
            } while (cap > i && src[i] != '\0');
            out += i;
        }
    }
    *out = '\0';
    return 0;
}
```
(The raw decompile's index-then-reread copy loop is flattened above; byte-for-byte it copies the same
`min(field_len, size-1)` characters and NUL-terminates.)

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00616570.c` (size 380, callers 613600/6140d0).
- The 7-byte `strncmp` against `0x693930`, the dot-count `== 5` gate, the two `strchr('.')` hops to the
  3rd field, the `size-1` bound, and the `-101` NULL returns are all exact from the decompile.
- Callee roles (`00102790` clear, `0010a338` strncmp, `00109be0` strchr) from fan-out classification.

## Remaining uncertainty
The literal 7-byte tag at `0x693930` was not dumped here, so the exact string format ("TAG.a.b.NAME.c.d")
and the domain meaning of field 3 (display name vs status token) are runtime-unvalidated. `func_0x00102790`
is inferred to be `bzero(dst,size)` (2-arg clear) rather than a copy. High confidence on control flow;
the semantic label of the extracted field is the open item.
