# 0x00637e90 wide_strlen_minus1

| field | value |
|---|---|
| Original address | 0x00637e90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637e90 |
| Resolved name | wide_strlen |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631810, FUN_00631880, FUN_00631ec0, FUN_00632390, FUN_00634010, FUN_006340d0, FUN_00634160, FUN_006341d0, FUN_00634280, FUN_00634310
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wide-char (`short*`) `strlen`. The loop scans to and one past the NUL, so `(end - start)` counts the
terminator; the `>>1` converts bytes->shorts and the `-1` removes the terminator — netting the true
character count (NOT length-1). The prior name `wide_strlen_minus1` was a misread of the terminator
cancellation; corrected to `wide_strlen`.

## Input / output
- `param_1` — `short*` NUL-terminated wide string.
- **Returns** `int` — number of shorts before the NUL (character count).

## Side effects
None.

## Important branches
- Scan loop advances until the NUL is read (pointer ends one past it).
- `iVar3 = end - start` (in bytes); `if (iVar3 < 0) iVar3++` (rounding guard for arithmetic
  right-shift of a negative — defensive, unreachable for valid strings).
- return `(iVar3 >> 1) - 1`.

## Corrected reconstruction
```c
// True wide-string length (chars before NUL). Terminator-inclusive scan is
// cancelled by the trailing -1.
int wide_strlen(short *s)
{
    short *p = s;
    short c;
    do { c = *p++; } while (c != 0);   // p ends one past the NUL
    int bytes = (int)p - (int)s;       // includes the terminator (2 bytes)
    if (bytes < 0) bytes += 1;         // negative-shift rounding guard
    return (bytes >> 1) - 1;           // /2 -> shorts, -1 -> drop terminator
}
```

## Worked example
`"AB\0"`: pointer walks A,B,NUL then one more -> `bytes = 6`; `6>>1 = 3`; `3-1 = 2` = strlen("AB"). ✓

## Notes / uncertainty
Renamed `wide_strlen_minus1` -> `wide_strlen`; behavior is standard strlen. Generic text util.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637e90.c`  — untouched decompiler output.

## Evidence
- Raw lines 13-22: terminator-inclusive scan, `(iVar3 >> 1) + -1`. Worked example confirms strlen.
