# 0x001eaf30 attr_table_byteswap_b

| field | value |
|---|---|
| Original address | 0x001eaf30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eaf30 |
| Resolved name | attr_table_byteswap_ntoh |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8 (memcpy), FUN_001e2394 (bswap32), FUN_001e23dc (bswap16)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
In-place endian conversion of an attribute TLV table (**network→host direction**): reads the count,
**swaps it first**, then uses the swapped (host-order) count as the loop bound, swapping each
record's `int16 key` (bswap16) and `uint32 value` (bswap32). Sampling the count *after* the swap is
the deserialize/`ntoh` pass — the buffer arrives big-endian and the record loop must iterate the
host-order count.

Mirror of `attr_table_byteswap_a` (0x001eaddc). The only structural difference is count-sampling
order (post-swap here, pre-swap there). It also calls the *duplicate* swap helpers
(FUN_001e23dc/FUN_001e2394) rather than FUN_001e234c/FUN_001e2304; both pairs are identical full
byte-swaps (verified from their bodies).

## Input / output
- `param_1` (`uint8_t *buf`): table buffer, mutated in place.
- **Returns** `0`.

## Side effects
Rewrites the count word and every record key+value in place (2 + count*6 bytes).

## Important branches
- `for (0 < count)` over the post-swap count; empty table → count word swapped only.

## Constants & flags
- Record stride `6`, header `2`. bswap16=FUN_001e23dc `(x>>8)|(x<<8)`; bswap32=FUN_001e2394.

## Corrected reconstruction
```c
int attr_table_byteswap_ntoh(uint8_t *buf /*param_1*/) {
    int16_t count;
    memcpy(&count, buf, 2);
    count = bswap16(count);           // FUN_001e23dc  (swap FIRST)
    int remaining = count;            // loop bound = POST-swap (host-order) count
    memcpy(buf, &count, 2);

    uint8_t *cur = buf + 2;
    for (; remaining > 0; remaining--) {
        int16_t k; uint32_t v;
        memcpy(&k, cur, 2);      k = bswap16(k);      memcpy(cur, &k, 2);       // FUN_001e23dc
        memcpy(&v, cur + 2, 4);  v = bswap32(v);      memcpy(cur + 2, &v, 4);   // FUN_001e2394
        cur += 6;
    }
    return 0;
}
```

## Evidence
- Raw lines 11-13: `sStack_28 = FUN_001e23dc(sStack_28);` **then** `iStack_20 = (int)sStack_28;` —
  count swapped before it becomes the loop bound (ntoh direction), the inverse ordering of
  0x001eaddc. Duplicate swap helpers confirmed: FUN_001e23dc bswap16, FUN_001e2394 bswap32.
- No callers recorded in the corpus (may be reached indirectly / unused in the traced paths).
- Confidence **High**; runtime-unvalidated.

## Remaining uncertainty
- ntoh label inferred from count-sampling order + mirror relationship, not a live trace. No known
  caller in the current xref set, so direction cannot be cross-checked against a call site yet.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eaf30.c`  — untouched decompiler output.
