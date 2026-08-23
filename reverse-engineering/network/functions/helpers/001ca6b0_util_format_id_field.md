# 0x001ca6b0 util_reformat_id_string

| field | value |
|---|---|
| Original address | 0x001ca6b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca6b0 |
| Resolved name | util_reformat_id_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Low |
| Runtime validated | no |

**Callers:** — (none indexed)
**Callees:** FUN_001ca610 (util_int_to_ascii, ×2), FUN_001ca660 (util_ascii_to_int, ×2)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Canonicalizes a packed numeric id/handle string: it reads decimal subfields out of a source buffer and
re-emits them as fixed-width, zero-padded decimal subfields into a destination buffer, then NUL-
terminates at offset **10**. The output is therefore a fixed **10-character** all-digit string composed
of two 5-digit fields. This matches a lobby/room/member id being normalized to a fixed wire form
(two 5-digit groups) regardless of how many digits the source carried.

The two callees are now fully decoded, which pins the *operation* even though the decompiler garbled
the *register lineage* (`extraout_*`):
- **`util_ascii_to_int(src, len)`** (0x1ca610's sibling 0x1ca660): scans up to `len` chars, accumulates
  `acc = acc*10 + (c-'0')` **only for ASCII digits** (`'0' <= c <= '9'`, i.e. `'/' < c < ':'`), silently
  skipping non-digits. Returns the int. → tolerant fixed-width decimal parse.
- **`util_int_to_ascii(dst, value, width)`** (0x1ca610): writes exactly `width` digits into
  `dst[0..width-1]`, filling **right-to-left from `dst+width-1`** (`value%10`, `value/=10` each step),
  so the field is right-aligned and zero-padded. Returns 0.

So the visible skeleton is: parse a 4-char field at `src`, parse a second field at `src+4`, emit a
5-digit field at `dst`, emit a 5-digit field at `dst+5`, write `dst[10]=0`, return 0. The source-side
offset/width of the *second* parse and the value→field pairing are uncertain (registers lost).

## Input / output
- `param_1` (long) — destination buffer [inferred] (non-null; receives 10 digits + NUL at `+10`).
- `param_2` (long) — source id string [inferred] (non-null; first field parsed at `+0`, 4 chars).
- `param_3` (ulong) — a field/length parameter; only low 16 bits used (`param_3 & 0xFFFF`) and forwarded
  into the first parse call [inferred].
- `param_4` (undefined8) — forwarded to the first parse helper [inferred].
- returns (undefined4) — `0` on success; `0xFFFFFFFF` (-1) if either pointer is null.

## Side effects
- Writes 10 decimal chars into the destination and a NUL at destination `+10`. No globals touched.

## Important branches
- `param_1 == 0 || param_2 == 0` → return `0xFFFFFFFF` (-1), no writes. Null-guard.
- else → `util_ascii_to_int(src,4)` → `util_ascii_to_int(src+4, …)` → `util_int_to_ascii(dst, v0, 5)`
  → `util_int_to_ascii(dst+5, v1, …)` → `dst[10]=0` → return `0`.

## Constants & flags
- Return `0` = OK; `0xFFFFFFFF` = null-pointer error.
- First parse width `4` (2nd arg to first `util_ascii_to_int`); second parse reads at `src+4`.
- Emit width `5` (visible 3rd arg to first `util_int_to_ascii`); second emit targets `dst+5`; NUL at
  `dst+10` ⇒ two 5-digit fields, 10-char output.
- `param_3 & 0xFFFF` — low-16 mask on a size/field argument threaded into the first parse.

## Corrected reconstruction
```c
// Reformat a packed numeric id (src) into a fixed 10-digit string (dst) = two 5-digit fields.
// Callee semantics are confirmed (0x1ca610 / 0x1ca660); the decompiler lost this function's own
// register lineage (extraout_*), so the source offsets / value-to-field pairing marked [inferred]
// are the best-supported reading, NOT proven. Control-flow skeleton is reliable.
int util_reformat_id_string(char *dst, const char *src, unsigned param3, unsigned long param4)
{
    if (dst == NULL || src == NULL)
        return -1;                                      // 0xFFFFFFFF

    // tolerant fixed-width decimal parse (skips non-digits):
    int a = util_ascii_to_int(src,     4);              // parse first field (len 4)          [inferred]
    int b = util_ascii_to_int(src + 4, /*len*/ 4);      // parse second field at src+4         [inferred]

    // right-aligned, zero-padded emit:
    util_int_to_ascii(dst,     /*value*/ a, 5);         // 5-digit field
    util_int_to_ascii(dst + 5, /*value*/ b, 5);         // 5-digit field                       [inferred width]
    dst[10] = '\0';                                     // terminate 10-char output            (exact)
    return 0;
}

// Confirmed callees (for reference):
//   int util_ascii_to_int(const char *s, int len) {           // 0x1ca660
//       int acc = 0;
//       for (int i = 0; i < len; i++, s++)
//           if (*s >= '0' && *s <= '9') acc = acc*10 + (*s - '0');
//       return acc;
//   }
//   int util_int_to_ascii(char *dst, int value, int width) {  // 0x1ca610
//       char *p = dst + width - 1;
//       for (int i = 0; i < width; i++) { *p-- = '0' + value % 10; value /= 10; }
//       return 0;                                             // right-aligned, zero-padded
//   }
```

## Evidence
- Raw decompile lines 16–26: null-guard returning `0xFFFFFFFF`; two `FUN_001ca660` calls (first with
  explicit len `4`), two `FUN_001ca610` calls (first with explicit width `5`); `*(dst+10)=0`; success
  `0`.
- Callee bodies read directly (`FUN_001ca610.c`, `FUN_001ca660.c`) — int_to_ascii is right-aligned/
  zero-padded fixed-width; ascii_to_int is a digit-filtering fixed-width accumulator. This upgrades the
  field-width reading from guess to callee-grounded.
- The **dataflow wiring inside this function** remains inferred: `extraout_t0/t1/t2/a3` show the
  decompiler could not recover register lineage, so which parsed value feeds which emitted field, and
  the exact second-parse offset/width, are not proven. No callers indexed to pin the layout.
- Runtime-unvalidated.

## Remaining uncertainty
- Control-flow skeleton (null-guard → parse×2 → emit×2 width-5 → NUL@10 → return 0) is reliable and the
  callee semantics are confirmed. Still uncertain: exact source-field widths/offsets for the second
  parse, the value→field pairing, and which pointer arg is source vs destination — all lost to register
  garble. Confidence kept **Low** on the operand map despite `reconstructed` status. Promote with a
  caller that has intact registers or a runtime trace of `dst`/`src`.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca6b0.c`  — untouched decompiler output.
