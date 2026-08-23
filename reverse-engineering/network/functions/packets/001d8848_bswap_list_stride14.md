# 0x001d8848 bswap_list_stride14

| field | value |
|---|---|
| Original address | 0x001d8848 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8848 |
| Resolved name | bswap_varlist_len14 |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound per-opcode endian dispatch)
**Callees:** FUN_001d8710 (bswap_list_hdr_3w), FUN_001d80c8 (bswap_2w_10_14)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** — (one inbound variable-length list message)
**State vars:** —

## Behavioral explanation
Endian-normalizes a **variable-stride** inbound record list. It swaps the 3-word list header (giving
the host-order entry count at +0x08), then walks each entry: swaps the entry's two leading words
(+0x10,+0x14 relative to the entry) via `bswap_2w_10_14`, and advances to the next entry by the
per-entry length stored at entry+0x14. Stride = `(entry_len + 0x1b) & ~3` = 4-byte-aligned
`(0x18 + entry_len)`, i.e. each entry is a fixed 0x18-byte head plus a variable `entry_len`-byte
body, rounded up to a word. A count guard (`< 0x37d`, 893) caps the loop so a corrupt/huge count
cannot run away.

Note the entry's length word (+0x14) is byte-swapped *before* it is read for the stride, so stride
math uses the host-order length — correct ordering.

## Input / output
- `param_1` (`u8 *list`) — list header at base; entries begin at +0x0c.
- **Returns** void; swaps the header and every entry's +0x10/+0x14 words in place.

## Side effects
- In-place swap of header (3 words) and, per entry, words at entry+0x10 and entry+0x14.
- No writes outside the list buffer.

## Important branches
- **`count (list+0x08) < 0x37d`** → run the entry loop. **False (≥0x37d)** → skip the loop entirely
  (header already swapped) — bounds guard against a corrupt count.
- Loop: `for i in [0, count)` — swap entry, advance `entry += (entry[+0x14] + 0x1b) & ~3`.

## Constants & flags
- `0x37d` (893) — max entry count (loop guard).
- `0x1b` (27) — `0x18` fixed head + `3` for the round-up in `(len + 0x1b) & 0xfffffffc`.
- `& 0xfffffffc` — 4-byte (word) alignment of the stride.
- Entries begin at list+0x0c (after the 0xC header); each entry's length is at entry+0x14.

## Corrected reconstruction
```c
// Variable-length record list: [3-word header | entry0 | entry1 | ...]
// each entry = 0x18-byte fixed head + entry_len body, word-aligned.
void bswap_varlist_len14(u8 *list)
{
    bswap_list_hdr_3w((u32 *)list);            // swap {word0, word1, count} at +0x00..+0x08
    u8 *entry = list + 0xc;                     // entries follow the 0xC header
    int count = *(int *)(list + 8);             // host-order after header swap
    if (count < 0x37d) {                        // guard runaway count
        for (int i = 0; i < count; i++) {
            bswap_2w_10_14(entry);              // swap entry[+0x10], entry[+0x14]=len
            u32 entry_len = *(u32 *)(entry + 0x14);
            entry += (entry_len + 0x1b) & 0xfffffffc;   // align4(0x18 + len)
        }
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d8848.c` — header swap, `< 0x37d` guard, loop `< *(int*)(param+8)`, per-entry `FUN_001d80c8`, advance `+= (uStack_14[+0x14]+0x1b)&~3`.
- Callee `FUN_001d8710` = bswap_list_hdr_3w (count at +0x08); `FUN_001d80c8` = bswap_2w_10_14 (+0x14 = entry length).
- Dispatched from `FUN_001d9f78`. Runtime-unvalidated.

## Remaining uncertainty
- Which app/transport opcode this variable list belongs to (needs the FUN_001d9f78 switch / a live capture). The 0x18-head + var-body entry shape suggests a text-bearing record (name/message list).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8848.c`  — untouched decompiler output.
