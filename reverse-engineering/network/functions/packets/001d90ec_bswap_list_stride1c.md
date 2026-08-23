# 0x001d90ec bswap_list_stride1c

| field | value |
|---|---|
| Original address | 0x001d90ec |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d90ec |
| Resolved name | bswap_inbound_list_var1c (op0x25 payload normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0x22 → opcode 0x25)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d8f58 (swap entry +0x10/+0x14/+0x18/+0x1c)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x25 (inbound); handler = conn+0x5ec
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode 0x25. BE → host-endian, in place, over a counted **variable-stride**
record list (`seg+0x3c`) before the `conn+0x5ec` callback. Three-word header (word[2] = count), then
`count` records; per record `FUN_001d8f58` swaps four u32s (+0x10, +0x14, +0x18, +0x1c). The record
length lives at +0x1c, so the stride is length-derived and 4-byte aligned. Bounded by `count < 0x37d`.

## Input / output
- `param_1` (int): app payload / list header. Void.
- Post: header + each record's four u32s host-endian.

## Side effects
- In-place payload mutation. No globals/packets.

## Important branches
- `if (count < 0x37d)` guards the loop (893-record cap).
- Stride: `entry += (entry[0x1c] + 0x23) & ~3` = `round_up(0x20 + entry_len, 4)` — 0x20-byte record
  prefix + variable body at 4-byte alignment. (+0x1c length is host-endian by the time it's read.)

## Constants & flags
- `0x37d`: record cap. `0x23`/`0xfffffffc`: 4-byte alignment of `(len + 0x20)` (0x1c offset + 7 = 0x23 bias).

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x25. Variable-stride records, length at +0x1c.
void bswap_inbound_list_var1c(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);                     // FUN_001d8710
    if (p->count < 0x37d) {
        u8 *entry = (u8*)p + 0x0c;
        for (int i = 0; i < p->count; i++) {
            bswap_rec_4w_10(entry);            // FUN_001d8f58: +0x10,+0x14,+0x18,+0x1c
            u32 body_len = *(u32*)(entry + 0x1c);          // now host-endian
            entry += (body_len + 0x23) & 0xfffffffc;        // round_up(0x20 + body_len, 4)
        }
    }
}
```

## Evidence
- Raw: `FUN_001d90ec.c`; callee `FUN_001d8f58.c` (four swaps incl. the +0x1c length).
- Dispatch: `FUN_001d9f78.c` case 0x22 → `FUN_001d90ec(param_2+0x3c)` → `conn+0x5ec`. opcode = case+3 = 0x25.
- Runtime-unvalidated.

## Remaining uncertainty
- Opcode 0x25 unmapped to a named message; +0x1c is inferred as length purely from the stride math.
