# 0x005e5f80 parse_token_lookup_code

| field | value |
|---|---|
| Original address | 0x005e5f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5f80 |
| Resolved name | parse_token_normalize_lookup |
| Subsystem | lobby |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7070 (passes keyword table 0x647e30)
**Callees:** func_0x0010a338 (case-insensitive/length-bounded string compare, memcmp/strnicmp-style)
**Referenced globals:** DAT_00648090 (256-byte charmap / case-fold table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** local 48-byte normalized-token buffer

## Behavioral explanation
Normalizes an attribute/keyword token, then matches it against a caller-supplied keyword table and
returns the table entry's associated code byte. Two stages:
1. **Normalize** the input token `param_1` (up to 0x1e=30 chars) into a 48-byte stack buffer:
   - single-byte chars (<0x80): fold through `DAT_00648090[c]` (a case/normalize map); stop early on
     NUL or on `>` (0x3e, tag close).
   - multi-byte chars (high bit set, SJIS lead byte): copy the whole multi-byte sequence verbatim,
     consuming continuation bytes while the shifted top bit stays set. NUL-terminate the result.
2. **Look up**: walk the table `param_2` (`param_3>>3` entries, each 8 bytes: `{char* key; u8 len; …;
   u8 code@+5}`). For each entry compare the normalized token against `entry.key` for `entry.len-1`
   bytes via func_0x0010a338. On the first match, return the entry's code byte at `+5`. If no entry
   matches, return 0.

Net: token -> code byte (a small enum the caller switches on). This is the keyword→opcode resolver
for one class of the lobby text/markup protocol (e.g. attribute names or tag names).

## Input / output
- `param_1` (int/char*): pointer to the raw token in the stream.
- `param_2` (int): base of the keyword table (array of 8-byte entries).
- `param_3` (uint): table size in **bytes**; entry count = `param_3 >> 3`.
- Return (u8): matched entry's code byte (`table[i*8 + 5]`), or `0` if none matched.

## Side effects
- None global. Uses a 48-byte local scratch buffer for the normalized token.

## Important branches
- Normalize loop bound: `uVar7 < 0x1e` (30 chars max).
- char == 0 -> break (end of token).
- single-byte char == 0x3e (`>`) -> break (tag terminator ends the token).
- high-bit char -> inner loop copies the multi-byte (SJIS) sequence verbatim until the running
  `<<1` top bit clears, then back up one (`uVar6 - 1`).
- lookup loop: `uVar7 >= (param_3>>3)` -> return 0 (no match).
- compare `func_0x0010a338(norm, entry.key, entry.len-1) == 0` -> match -> return `table[i*8+5]`.

## Constants & flags
- `0x1e` (30): max normalized token length.
- `0x80`: SJIS/multi-byte high-bit test.
- `0x3e` (`>`): tag-close terminator.
- Table entry stride `8`: `{u32 key_ptr; u8 key_len; u8 ?; u8 ?; u8 code}` — code at `+5`.
- Charmap `DAT_00648090`: 256-entry case/normalize table.

## Corrected reconstruction
```c
// Normalize a token (case-fold via charmap, SJIS-safe) then resolve it to a code
// byte via the caller's keyword table. Returns 0 if unmatched.
extern const uint8_t g_charmap[256];   // DAT_00648090

typedef struct kw_entry {              // 8 bytes
    const char *key;   // +0
    uint8_t     len;   // +4  (compared for len-1 bytes)
    uint8_t     _r5, _r6;
    uint8_t     code;  // +5  <-- returned on match   (note: field order per raw offsets)
} kw_entry;

uint8_t parse_token_normalize_lookup(const uint8_t *tok /*param_1*/,
                                     const kw_entry *table /*param_2*/,
                                     unsigned table_bytes /*param_3*/)
{
    char norm[48];
    unsigned i = 0;
    while (i < 0x1e) {
        uint8_t b = tok[i];
        if (b == 0) break;
        if ((b & 0x80) == 0) {                 // single byte
            if (b == '>') break;               // 0x3e terminator
            norm[i] = (char)g_charmap[b];
        } else {                               // SJIS multi-byte: copy verbatim
            uint8_t v = b;
            do { norm[i] = (char)tok[i]; i++; v = (uint8_t)(v << 1); } while (v & 0x80);
            i--;                               // loop's i++ will re-add
        }
        i++;
    }
    norm[i] = '\0';

    unsigned n = table_bytes >> 3;             // entry count
    for (unsigned k = 0; k < n; k++) {
        // func_0x0010a338 = bounded string compare over (key_len - 1) bytes
        if (str_cmp_n(norm, table[k].key, table[k].len - 1) == 0)
            return table[k].code;              // *(u8*)(&table[k] + 5)
    }
    return 0;                                   // no match
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e5f80.c` (size 312). Normalize loop (0x1e cap,
  0x80/0x3e tests, charmap DAT_00648090), 8-byte table stride (`param_2 + i*8`, key `*puVar4`, len
  `puVar4[1]-1`, code `+5`) read directly. Caller FUN_005e7070 supplies table 0x647e30.

## Remaining uncertainty
- Field bytes at entry `+5/+6/+7` beyond key/len/code not fully characterised.
- The SJIS verbatim-copy inner loop's exact continuation-byte accounting (`uVar6-1` fixup) preserved
  as-decompiled; edge behaviour on malformed multi-byte not runtime-validated.
- Renamed from parse_token_lookup_code -> parse_token_normalize_lookup to reflect the normalize stage.
