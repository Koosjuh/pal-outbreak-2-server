# 0x0060f350 internal_to_sjis_text (decode)  [filename says sjis_to_internal — DIRECTION IS REVERSED]

| field | value |
|---|---|
| Original address | 0x0060f350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f350 |
| Resolved name | internal_to_sjis_text (decode: 3-byte internal → 2-byte Shift-JIS) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e440
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Text transcoder — the **decode** half of the wide-char codec pair with `FUN_0060f480`. It is the exact inverse of 0x0060f480 (each range offset here is negated there; see below), so despite the record filename the direction is: **game-internal 3-byte encoding → real 2-byte Shift-JIS**.

For each source unit:
- byte `< 0x80` → ASCII, copied verbatim (1 in, 1 out).
- byte `>= 0x80` → a wide char stored as a **3-byte group**: `[marker>=0x80][hi][lo]`. The marker (in practice `0xE3`, the tag `FUN_0060f480` writes) is discarded; the 16-bit code is `hi<<8 | lo`. That code is remapped by a piecewise range-offset table into a Shift-JIS double-byte value and written **big-endian, 2 bytes**.

Any wide code outside the five known ranges maps to the fallback `0x815b` (Shift-JIS "long-vowel/dash" glyph) — used as the "unrepresentable" placeholder.

## Input / output
- `param_1` — `byte *dst`: output buffer, receives Shift-JIS text, NUL-terminated.
- `param_2` — `byte *src`: input, NUL-terminated internal-encoded text (ASCII + 3-byte `0xE3` groups).
- Returns `void`.

## Side effects
Writes transcoded bytes + trailing NUL into `dst`. No globals. No output bounds check (unlike the encoder, which caps length).

## Important branches
- `*src == 0` → break, then write NUL terminator.
- `*src < 0x80` → copy 1 ASCII byte; advance both by 1.
- else → read 3-byte group (`src += 3`), remap 16-bit `hi:lo` via the range ladder, emit 2 SJIS bytes.
- Range ladder on the internal code `u` (each else-if narrows):
  - `0x8181..0x81bf` → `u + 0x11e`
  - `0x8280..0x8293` → `u + 0x5e`
  - `0x82a1..0x82bf` → `u + 0x9f`
  - `0x8380..0x839f` → `u - 0x21`
  - `0x83a0..0x83b6` → `u - 0x20`
  - else → `0x815b` (fallback glyph). *(decompile writes `-0x7ea5`, i.e. unsigned `0x815b`.)*

## Constants & flags
- `0x80` — single/double-byte boundary.
- Offsets `+0x11e / +0x5e / +0x9f / -0x21 / -0x20` — per-range SJIS remap deltas (exact negatives of 0x0060f480's deltas).
- `0x815b` — Shift-JIS fallback / unrepresentable placeholder.

## Corrected reconstruction
```c
/* 0x0060f350 — decode internal 3-byte wide text (0xE3-tagged) to Shift-JIS.
 * Inverse of FUN_0060f480. NOTE: record filename labels this "sjis_to_internal"
 * but the byte flow (3-byte in, 2-byte SJIS out) is the DECODE direction. */
void internal_to_sjis_text(unsigned char *dst, const unsigned char *src)
{
    unsigned char b;
    while ((b = *src) != 0) {
        if (b < 0x80) {                     /* ASCII passthrough */
            *dst++ = b;
            src++;
        } else {
            /* 3-byte group: [marker>=0x80][hi][lo]; marker (0xE3) discarded */
            unsigned short u = ((unsigned short)src[1] << 8) | src[2];
            src += 3;
            short sjis;
            if      (u >= 0x8181 && u <= 0x81bf) sjis = u + 0x11e;
            else if (u >= 0x8280 && u <= 0x8293) sjis = u + 0x5e;
            else if (u >= 0x82a1 && u <= 0x82bf) sjis = u + 0x9f;
            else if (u >= 0x8380 && u <= 0x839f) sjis = u - 0x21;
            else if (u >= 0x83a0 && u <= 0x83b6) sjis = u - 0x20;
            else                                 sjis = (short)0x815b; /* fallback */
            *dst++ = (unsigned char)(sjis >> 8);   /* big-endian */
            *dst++ = (unsigned char)sjis;
        }
    }
    *dst = 0;
}
```

## Evidence
- Raw decompile: `uVar2 = param_2[1]*0x100 + param_2[2]; param_2 += 3;` then range ladder; output `*param_1 = sVar3>>8; param_1[1] = sVar3;`.
- Inverse-symmetry check vs 0x0060f480: every range/offset here is the negation of a range/offset there (verified: `0x829f-0x11e=0x8181`, `0x835f+0x21=0x8380`, etc.).
- Confidence **High** on mechanics. Not runtime validated.

## Remaining uncertainty
Which encoding is "canonical" is a naming nuance — both sides use 0x81xx-0x83xx values; the internal side is the compact/contiguous one, the output is the SJIS the OSD font expects. The **record filename direction is reversed** (this is decode); left un-renamed to keep the raw-link path stable — flagged here and in resolved_name.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f350.c`  — untouched decompiler output.
