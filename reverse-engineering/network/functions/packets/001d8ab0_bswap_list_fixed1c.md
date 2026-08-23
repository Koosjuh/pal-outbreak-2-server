# 0x001d8ab0 bswap_list_fixed1c

| field | value |
|---|---|
| Original address | 0x001d8ab0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8ab0 |
| Resolved name | bswap_inbound_list_fixed1c (op0x0e payload normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0xb → opcode 0x0e)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d8394 (swap entry +0x10/+0x14/+0x18)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x0e (inbound); handler = conn+0x5b0
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode 0x0e. Big-endian → host-endian conversion, in place, over a
counted **fixed 0x1c-stride** record array in the app payload (`seg+0x3c`) before the `conn+0x5b0`
callback. Three-word list header (word[2] = count), then `count` records of 0x1c bytes each, three u32
fields swapped per record (+0x10, +0x14, +0x18). Records are bounded by a `count < 0x37d` sanity cap.

## Input / output
- `param_1` (int): app payload / list header. Void return.
- Post: header + each record's +0x10/+0x14/+0x18 host-endian.

## Side effects
- In-place mutation of payload. No globals/packets.

## Important branches
- `if (count < 0x37d)`: guards the loop; an oversized/garbage count skips all record swaps (header is
  still swapped). 0x37d = 893 record cap.
- `for (i=0; i<count; i++) entry += 0x1c;`.

## Constants & flags
- `0x37d` (893): max record count sanity bound (shared by all fixed-stride inbound list parsers here).
- Bytes 0x00–0x0f of each record left untouched (string/opaque prefix; e.g. a 16-byte name), only the
  three trailing u32s are swapped.

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x0e. Fixed 0x1c-byte records.
void bswap_inbound_list_fixed1c(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);                 // FUN_001d8710
    if (p->count < 0x37d) {                // record-count sanity cap
        u8 *entry = (u8*)p + 0x0c;
        for (int i = 0; i < p->count; i++) {
            bswap_fields_10_14_18(entry);  // FUN_001d8394: swap +0x10, +0x14, +0x18
            entry += 0x1c;
        }
    }
}
```

## Evidence
- Raw: `FUN_001d8ab0.c`; callee `FUN_001d8394.c` (three swaps at +0x10/+0x14/+0x18).
- Dispatch: `FUN_001d9f78.c` case 0xb → `FUN_001d8ab0(param_2+0x3c)` → `conn+0x5b0`. opcode = case+3 = 0x0e.
- Runtime-unvalidated.

## Remaining uncertainty
- Opcode 0x0e is not mapped to a named lobby message; record field semantics unknown beyond "three u32s".
