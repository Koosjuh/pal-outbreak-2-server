# 0x001ca610 util_int_to_ascii

| field | value |
|---|---|
| Original address | 0x001ca610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca610 |
| Resolved name | util_int_to_ascii_fixed |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca6b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fixed-width unsigned-decimal formatter. Writes exactly `width` decimal digits for `value` into a
buffer, filling right-to-left starting at `buf + width - 1` (least-significant digit last-written slot)
back to `buf`. It is zero-padded on the left (no sign, no space) and truncates the high end silently:
if `value` has more than `width` digits, only the low `width` digits are emitted (the leading digits
are lost because the loop stops after `width` iterations). Used to lay out fixed-size numeric fields
inside protocol id/handle strings (see caller util_format_id_field).

## Input / output
- `param_1` (int) — destination buffer base pointer (`buf`).
- `param_2` (int) — the value to format (treated as a non-negative decimal via `% 10` / `/ 10`).
- `param_3` (int) — field width in digits (`width`).
- returns `0` (constant; ignored by caller).

## Side effects
- Writes `width` bytes at `buf[0 .. width-1]`. No NUL terminator written by this routine. No globals.

## Important branches
- Loop `iVar3 = 0 .. width-1`: each iteration writes one digit `'0' + (value % 10)` at the descending
  cursor and does `value /= 10`. No conditional branches — fixed iteration count = `width`.
- (Implicit) once `value` reaches 0, remaining higher slots receive `'0'` (zero-pad), because
  `0 % 10 == 0`.

## Constants & flags
- Base 10 (`% 10`, `/ 10`); digit encoding `'0'` = 0x30.

## Corrected reconstruction
```c
// Fixed-width, zero-padded, right-aligned unsigned decimal. No NUL. Truncates high digits.
int util_int_to_ascii_fixed(char *buf, int value, int width)
{
    char *cur = buf + width - 1;          // least-significant digit position
    for (int i = 0; i < width; i++) {
        int digit = value % 10;
        value    /= 10;
        *cur-- = (char)('0' + digit);
    }
    return 0;
}
```

## Evidence
- Raw decompile lines 9–16: descending cursor `buf+width-1`, `value%10 + '0'` store, `value/=10`,
  fixed `width` iterations.
- Sole caller FUN_001ca6b0 (util_format_id_field) uses it to emit fixed-length numeric subfields.
- Runtime-unvalidated.

## Remaining uncertainty
- Signedness: `value` is used as plain `int` with `%10`; negative inputs would produce negative
  `digit` (garbage). Callers appear to pass non-negative field values, but that is not proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca610.c`  — untouched decompiler output.
