# 0x005dedc0 strncpy_255

| field | value |
|---|---|
| Original address | 0x005dedc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dedc0 |
| Resolved name | strncpy_255 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6630, FUN_005d6770, FUN_005d6c10, FUN_005d7e00, FUN_005d7f80, FUN_005d8340, FUN_005dee00, FUN_005df640
**Callees:** func_0x0010a4f0 (memcpy/strncpy libc thunk)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fixed-size bounded string copy into a 256-byte field. Copies exactly 0xFF (255) bytes from `src`
into `dst` via the libc block-copy thunk, then unconditionally writes a NUL terminator at
`dst[0xFF]`. This is the canonical "copy into a `char name[256]`" primitive used all over the 3.DAT
overlay for URL/name buffers (all eight callers hand it a 256-byte destination field).

Note: because it always transfers 255 bytes, the semantics are `strncpy`-like (fixed width), not
`strlcpy`-like (stop at src NUL). Whether trailing garbage past the src NUL is copied depends on the
thunk (`func_0x0010a4f0`): if it is `memcpy`, bytes past the src terminator are copied verbatim; the
guaranteed terminator at [0xFF] still bounds the string to 255 usable chars.

## Input / output
- `param_1` (`char *dst`): destination, must be >= 256 bytes.
- `param_2` (`const char *src`): source buffer.
- Returns: void.

## Side effects
- Writes `dst[0..254]` from src and forces `dst[255] = 0`. No globals touched.

## Important branches
- None. Straight-line copy + terminate.

## Constants & flags
- `0xFF` = 255 = copy length / terminator index → destination is a 256-byte field.

## Corrected reconstruction
```c
/* Bounded copy into a 256-byte string field. Always writes 255 bytes + NUL. */
void strncpy_255(char *dst /*[256]*/, const char *src)
{
    memcpy_thunk(dst, src, 0xFF);   /* func_0x0010a4f0 — libc block copy */
    dst[0xFF] = '\0';               /* guarantee termination at index 255 */
}
```

## Notes / uncertainty
`func_0x0010a4f0` is a libc thunk assumed to be `memcpy`/`strncpy`. If it is `strncpy`, it also
NUL-pads a short src; if `memcpy`, it copies past the src NUL. Either way the [0xFF] store bounds the
result. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dedc0.c`  — untouched decompiler output.

## Evidence
- Raw: `func_0x0010a4f0(param_1,param_2,0xff); *(dst+0xff)=0`.
- 8 callers each pass a 256-byte field (URL/name buffers), consistent with a fixed 256 copy.
- Confidence **High** (behavior unambiguous); runtime validation pending.
