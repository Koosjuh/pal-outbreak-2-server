# 0x0060f480 sjis_to_internal_text (encode)  [filename says internal_to_sjis — DIRECTION IS REVERSED]

| field | value |
|---|---|
| Original address | 0x0060f480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f480 |
| Resolved name | sjis_to_internal_text (encode: 2-byte Shift-JIS → 3-byte internal, 0xE3-tagged) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e250
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
The **encode** half of the codec pair; exact inverse of `FUN_0060f350`. Direction: **real 2-byte Shift-JIS → game-internal 3-byte encoding** (each wide char expanded to `0xE3, hi, lo`). Contrary to the record filename, the byte flow (2-byte SJIS in, 3-byte tagged out) is the encode direction.

For each source unit:
- byte `< 0x80` → ASCII, copied verbatim (1 in, 1 out), consuming 1 output slot.
- byte `>= 0x80` → Shift-JIS lead; combine with the next byte into a 16-bit SJIS code (`src += 2`), remap by the range ladder into the internal 16-bit code, and emit **3 bytes**: constant tag `0xE3`, then the internal code big-endian. Consumes 3 output slots.

Output length is capped: it stops before overflowing a ~255-byte field — ASCII path breaks if the running length would exceed `0xFE`, wide path breaks if it would exceed `0xFC` (needs room for 3). This is the fixed-width name/text field guard.

## Input / output
- `param_1` — `byte *dst`: output, internal-encoded text, NUL-terminated. Bounded to ≤ ~255 bytes.
- `param_2` — `byte *src`: input NUL-terminated Shift-JIS text.
- Returns `void`.

## Side effects
Writes internal-encoded bytes + NUL into `dst`. No globals. Enforces the length cap (may truncate long input).

## Important branches
- `*src == 0` → break, write NUL.
- ASCII (`b < 0x80`): if `len > 0xFE` → break (cap); else copy 1 byte, `len++`.
- Wide (`b >= 0x80`): if `len > 0xFC` → break (no room for 3); else read 2-byte SJIS (`src += 2`), remap, emit `0xE3,hi,lo`, `len += 3`.
- Range ladder on SJIS code `u` (inverse of 0x0060f350):
  - `0x829f..0x82dd` → `u - 0x11e`
  - `0x82de..0x82f1` → `u - 0x5e`
  - `0x8340..0x835e` → `u - 0x9f`
  - `0x835f..0x837e` → `u + 0x21`
  - `0x8380..0x8396` → `u + 0x20`
  - else → `0x83bc` fallback *(decompile `-0x7c44` = unsigned `0x83bc`)*.

## Constants & flags
- `0xE3` — internal wide-char tag byte (matches the `>=0x80` marker `FUN_0060f350` discards).
- `0xFE` / `0xFC` — output length caps (255-byte field, minus 1 / minus 3 headroom).
- Offsets `-0x11e / -0x5e / -0x9f / +0x21 / +0x20` — per-range remap deltas (negatives of 0x0060f350's).
- `0x83bc` — fallback internal code.

## Corrected reconstruction
```c
/* 0x0060f480 — encode Shift-JIS text to internal 3-byte (0xE3-tagged) form.
 * Inverse of FUN_0060f350. Output length-capped for a ~255-byte name field.
 * NOTE: record filename labels this "internal_to_sjis" but byte flow
 * (2-byte SJIS in, 3-byte tagged out) is the ENCODE direction. */
void sjis_to_internal_text(unsigned char *dst, const unsigned char *src)
{
    int len = 0;
    unsigned char b;
    while ((b = *src) != 0) {
        if (b < 0x80) {                      /* ASCII */
            if (len > 0xFE) break;           /* field-length cap */
            *dst++ = b; src++; len++;
        } else {                             /* Shift-JIS double byte */
            if (len > 0xFC) break;           /* need 3 output bytes */
            unsigned short u = ((unsigned short)b << 8) | src[1];
            src += 2;
            short code;
            if      (u >= 0x829f && u <= 0x82dd) code = u - 0x11e;
            else if (u >= 0x82de && u <= 0x82f1) code = u - 0x5e;
            else if (u >= 0x8340 && u <= 0x835e) code = u - 0x9f;
            else if (u >= 0x835f && u <= 0x837e) code = u + 0x21;
            else if (u >= 0x8380 && u <= 0x8396) code = u + 0x20;
            else                                 code = (short)0x83bc; /* fallback */
            *dst++ = 0xE3;                    /* internal wide tag */
            *dst++ = (unsigned char)(code >> 8);
            *dst++ = (unsigned char)code;
            len += 3;
        }
    }
    *dst = 0;
}
```

## Evidence
- Raw decompile: `uVar3 = bVar1*0x100 + param_2[1]; param_2 += 2;` range ladder; output `*param_1 = 0xe3; param_1[1]=sVar4>>8; param_1[2]=sVar4;`; caps `if (0xfe < iVar2) break;` / `if (0xfc < iVar2) break;`.
- Inverse-symmetry vs 0x0060f350 verified range by range.
- Confidence **High**. Not runtime validated.

## Remaining uncertainty
Exact 255-byte field owner (name vs title vs chat) not pinned from this fn alone; caller FUN_0060e250 supplies the buffer. **Record filename direction is reversed** (this is encode); left un-renamed to preserve the raw-link path — flagged here and in resolved_name.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f480.c`  — untouched decompiler output.
