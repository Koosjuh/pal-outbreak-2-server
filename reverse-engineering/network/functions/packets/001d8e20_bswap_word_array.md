# 0x001d8e20 bswap_word_array

| field | value |
|---|---|
| Original address | 0x001d8e20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8e20 |
| Resolved name | bswap_inbound_word_array (op0x10 room-info normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0xd → opcode 0x10)
**Callees:** FUN_001d8048 (swap one u32)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x10 room-info (inbound); handlers = conn+0x59c / +0x594 / +0x578 / +0x580 (flag-selected)
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode **0x10 (room-info, sub-selector message)**. Unlike the record-list
parsers, the payload here is a **flat u32 array**: a leading count word followed by `count` data words.
It swaps the count word first (`FUN_001d8048`), reads the now host-endian count, then swaps that many
following words, advancing one word (4 bytes) at a time. Bounded by `count < 0xe0` (224). After this
pass the demux invokes one of four callbacks selected by the segment flag bits.

## Input / output
- `param_1` (uint*): app payload = `{ u32 count; u32 data[count]; }`. Void.
- Post: count and all data words host-endian.

## Side effects
- In-place payload mutation. No globals/packets.

## Important branches
- `if (count < 0xe0)`: guards the loop. Oversized/garbage count → only the count word is swapped.
- Loop: `puStack_14 = param_1 + 1` (points one word past current base) each iteration; swaps that word,
  then `param_1 = puStack_14` — advances the base by one word per step (walks the array).
- Demux flag-select (in caller): `(seg+0x2c & 0x1000)` DATA who-byte, `& 0x400`, `& 0x8000` reliable →
  choose conn+0x59c (plain), +0x594 (reliable), +0x578 (0x400 set), +0x580 (DATA+0x400).

## Constants & flags
- `0xe0` (224): max word count sanity bound (distinct from the 0x37d cap used by fixed-stride list parsers).
- Header layout differs from `FUN_001d8710` lists: **count at +0x00** (not +0x08), data at +0x04.

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x10 (room-info). Flat count-prefixed u32 array.
void bswap_inbound_word_array(u32 *p)
{
    bswap_u32(p);                  // FUN_001d8048: swap count word at [0]
    u32 count = p[0];              // now host-endian
    if (count < 0xe0) {
        for (int i = 0; i < (int)count; i++) {
            bswap_u32(p + 1);      // swap next data word
            p = p + 1;             // advance one word
        }
    }
}
```

## Evidence
- Raw: `FUN_001d8e20.c`; callee `FUN_001d8048.c` (single-word swap).
- Dispatch: `FUN_001d9f78.c` case 0xd → `FUN_001d8e20(param_2+0x3c)` → flag-selected conn+0x59c/+0x594/
  +0x578/+0x580. opcode = case+3 = 0x10 (documented room-info).
- Runtime-unvalidated.

## Remaining uncertainty
- The data words' meaning (member ids? sub-command codes?) for op0x10 is not decoded; only the array
  shape and count bound are certain.
