# 0x005e8f00 tag_clear_namebuf_fac1

| field | value |
|---|---|
| Original address | 0x005e8f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8f00 |
| Resolved name | tag_clear_namebuf_fac1 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** func_0x00106b60 (memset)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0xfac1` (0x100-byte name buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0xfac1

## Behavioral explanation
Markup-tag handler in the overlay rich-text/message renderer. Zeroes the 256-byte
name buffer at `ctx+0xfac1`. That buffer is the "current link/anchor target name":
`FUN_005ee470` (the anchor-draw routine reached via `tag_apply_if_name_matches_1528`)
compares each of 16 candidate records (stride 0x104 at `ctx+0xea81`) against
`ctx+0xfac1` with `func_0x00109d70` (strcmp) to decide which region to highlight/draw.
This handler resets that target back to empty before a new anchor tag is parsed.

## Input / output
- Input: none (void). Operates purely on the global markup context.
- Output: `undefined8` 0 (handlers return 0 = "consumed, continue parsing").

## Side effects
- Writes: `ctx+0xfac1[0..0x100) = 0`.
- No packets, no state-machine transition beyond clearing the name field.

## Important branches
None — straight-line memset.

## Constants & flags
- `0x100` = buffer length (256), matches the compare-record name width used by `FUN_005ee470`.

## Corrected reconstruction
```c
/* markup render context: base = *(void**)0x007012a0 (aliased iRam007012a0).
   +0xfac1 = current anchor/link target name (256B), matched by FUN_005ee470. */
undefined8 tag_clear_namebuf_fac1(void)
{
    memset((u8*)g_markup_ctx + 0xfac1, 0, 0x100);  /* func_0x00106b60 = memset */
    return 0;
}
```

## Evidence
- Raw: `func_0x00106b60(iRam007012a0 + 0xfac1,0,0x100)` (memset base,0,len).
- Cross-ref: `FUN_005ee470` reads `iRam007012a0 + 0xfac1` as the strcmp key against the
  0x104-stride record array at `+0xea81` — confirms +0xfac1 is a name/keyword buffer.
- Runtime-unvalidated (static only).

## Remaining uncertainty
Field *semantics* (link vs generic anchor name) inferred from the single consumer
`FUN_005ee470`; the mechanical clear itself is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8f00.c`  — untouched decompiler output.
