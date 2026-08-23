# 0x001eaddc attr_table_byteswap_a

| field | value |
|---|---|
| Original address | 0x001eaddc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eaddc |
| Resolved name | attr_table_byteswap_hton |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001db7e8
**Callees:** FUN_001069a8 (memcpy), FUN_001e2304 (bswap32), FUN_001e234c (bswap16)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
In-place endian conversion of an attribute TLV table (**host→network direction**): reads the count
in the buffer's *current* order to know the loop bound, swaps the count word, then swaps each
record's `int16 key` (bswap16) and `uint32 value` (bswap32). Because it captures the loop count
from the **pre-swap** value (`iStack_20` saved before the count is rewritten), it operates on a
host-order (little-endian PS2) table and writes big-endian — i.e. the serialize/`hton` pass.

Distinguished from its counterpart `attr_table_byteswap_b` (0x001eaf30) only by *when* the count is
sampled: here the count is read for the loop **before** it is swapped, so the loop bound is the
host-order count. On PS2 the byte-swap op itself is identical (swap is its own inverse); the pair
is a hton/ntoh split by direction of use.

## Input / output
- `param_1` (`uint8_t *buf`): table buffer, mutated in place.
- **Returns** `0`.

## Side effects
Rewrites the count word and every record's key+value in place (2 + count*6 bytes touched).

## Important branches
- `for (0 < count)` loop; empty table (count 0) → only the count word is swapped, no records.

## Constants & flags
- Record stride `6`, header `2`. bswap16=FUN_001e234c, bswap32=FUN_001e2304 (full swaps; see those
  records).

## Corrected reconstruction
```c
int attr_table_byteswap_hton(uint8_t *buf /*param_1*/) {
    int16_t count;
    memcpy(&count, buf, 2);
    int remaining = count;            // iStack_20: loop bound from PRE-swap count
    count = bswap16(count);           // FUN_001e234c
    memcpy(buf, &count, 2);

    uint8_t *cur = buf + 2;
    for (; remaining > 0; remaining--) {
        int16_t k; uint32_t v;
        memcpy(&k, cur, 2);      k = bswap16(k);      memcpy(cur, &k, 2);       // FUN_001e234c
        memcpy(&v, cur + 2, 4);  v = bswap32(v);      memcpy(cur + 2, &v, 4);   // FUN_001e2304
        cur += 6;
    }
    return 0;
}
```

## Evidence
- Raw lines 11-13: `iStack_20 = (int)sStack_28;` captured **before** `sStack_28 = FUN_001e234c(...)`
  — loop bound is the un-swapped count (hton direction). Lines 16-23: per-record key(bswap16) +
  value(bswap32) in place. Helper `FUN_001e234c` = `(x>>8)|(x<<8)` bswap16; `FUN_001e2304` = bswap32
  (verified against the 0x001e23dc/0x001e2394 duplicate pair).
- Confidence **High**; runtime-unvalidated.

## Remaining uncertainty
- The hton-vs-ntoh label is inferred from count-sampling order and the mirror function; not proven
  by a live trace. On little-endian both byteswap directions are byte-identical, so mislabeling is
  harmless to behavior.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eaddc.c`  — untouched decompiler output.
