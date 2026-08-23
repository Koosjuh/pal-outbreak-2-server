# 0x001cb360 gfx_decode_image

| field | value |
|---|---|
| Original address | 0x001cb360 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb360 |
| Resolved name | gfx_decode_image_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cb0e0 and ~40 sibling gfx builders (FUN_001cb7f0, FUN_001ccb80 … FUN_001d40e0)
**Callees:** FUN_001a0df0 (decoder A), FUN_001a0e90 (decoder B)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Image-decode dispatcher — pure graphics, no protocol. Given a mode/size word `param_3`, it selects
between two decoder backends: if bit `0x10000` is set it calls `FUN_001a0df0` (decoder A — the
"format/streamed" path); otherwise, only if the low 16 bits (`param_3 & 0xFFFF`, a size/length) are
nonzero, it calls `FUN_001a0e90` (decoder B — the "sized/raw" path). If neither condition holds
(`0x10000` clear and low-16 zero) it returns 0 without decoding. The return value is whatever the
chosen backend returns (decoded size / status). This is the leaf all ~40 texture builders funnel
through to actually turn asset bytes into pixels.

Important: the `0x10000` bit here is an **image-format selector**, entirely unrelated to the SN@P
transport who-byte `0x1000`/`0x2000` or reliable `0x8000` bits — the address neighbourhood is
coincidental.

## Input / output
- `param_1` (undefined8) — source/name or input buffer (passed through to backends implicitly).
- `param_2` (undefined8) — destination buffer (passed through implicitly).
- `param_3` (ulong) — mode/size word: bit `0x10000` = use decoder A; low 16 bits = size for decoder B.
- returns (undefined8) — backend result (decoded size/handle), or `0` if neither path taken.

## Side effects
- None directly; decoding side effects belong to `FUN_001a0df0` / `FUN_001a0e90` (they write pixels to
  the destination buffer set up by the caller).

## Important branches
- `(param_3 & 0x10000) != 0` → `return FUN_001a0df0(...)` (decoder A).
- else `(param_3 & 0xFFFF) != 0` → `return FUN_001a0e90(...)` (decoder B).
- else → `return 0` (nothing to decode).

## Constants & flags
- `0x10000` — image-format/mode selector bit (decoder A vs. B). NOT a transport bit.
- `0xFFFF` — low-16 size/length mask (decoder B guard).

## Corrected reconstruction
```c
// Image-decode dispatch (NOT protocol). 0x10000 = format flag; low 16 = size.
unsigned long gfx_decode_image_dispatch(const void *src, void *dst, unsigned long mode)
{
    if (mode & 0x10000)
        return FUN_001a0df0(/*src, dst, ...*/);   // decoder A (format/streamed)
    if (mode & 0xFFFF)
        return FUN_001a0e90(/*src, dst, ...*/);   // decoder B (sized/raw)
    return 0;                                     // nothing to decode
}
```
(The decompiler drops the arg forwarding; backends receive the same src/dst/size — preserved as
comments rather than invented.)

## Evidence
- Raw decompile lines 7–16: `if ((param_3 & 0x10000) == 0) { if ((param_3 & 0xffff)!=0) FUN_001a0e90();
  } else FUN_001a0df0();`.
- ~40 callers are the texture/sprite builders in the 0x1cb–0x1d4 gfx cluster (incl. gfx_build_texture_desc).
- Runtime-unvalidated; backend semantics (A vs. B) inferred from the flag/size split, not traced.

## Remaining uncertainty
- What distinguishes decoder A from B (compression format vs. raw copy) and the exact forwarded
  arguments. Firmly non-protocol — the `0x10000` bit is an image flag, not a who-byte.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb360.c`  — untouched decompiler output.
