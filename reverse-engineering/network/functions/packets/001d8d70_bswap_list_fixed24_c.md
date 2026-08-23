# 0x001d8d70 bswap_list_fixed24_c

| field | value |
|---|---|
| Original address | 0x001d8d70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8d70 |
| Resolved name | bswap_inbound_list_fixed24_c (op0x0b payload normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 8 → opcode 0x0b)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d7b30 (swap entry +0x10/+0x14/+0x18/+0x1c/+0x20)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x0b (inbound); handler = conn+0x5b4. (FUN_001d7b30 is also used inline for op0x04, demux case 1.)
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode 0x0b. BE → host-endian, in place, over a counted **fixed
0x24-stride** record array (`seg+0x3c`) before the `conn+0x5b4` callback. Three-word header (word[2] =
count), then `count` records of 0x24 bytes; per record `FUN_001d7b30` swaps five **contiguous** u32s
(+0x10, +0x14, +0x18, +0x1c, +0x20). Distinct from `FUN_001d8b60`/`FUN_001d8c10` (also 0x24 stride) in
field set: this one swaps a contiguous 0x10..0x20 run; those swap 0x10,0x14,0x20,0x18,0x1c.

## Input / output
- `param_1` (int): app payload / list header. Void.
- Post: header + per-record five u32s host-endian; leading 0x10 bytes untouched.

## Side effects
- In-place payload mutation. No globals/packets.

## Important branches
- `if (count < 0x37d)` guards the loop (893-record cap). `entry += 0x24` per record.

## Constants & flags
- `0x37d`: record cap. Swapped u32s: 0x10,0x14,0x18,0x1c,0x20 (contiguous 5-word tail after a 0x10-byte prefix).

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x0b. Fixed 0x24-byte records, contiguous 5-word swap.
void bswap_inbound_list_fixed24_c(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);                     // FUN_001d8710
    if (p->count < 0x37d) {
        u8 *entry = (u8*)p + 0x0c;
        for (int i = 0; i < p->count; i++) {
            bswap_fields_10_to_20(entry);      // FUN_001d7b30: +0x10,+0x14,+0x18,+0x1c,+0x20
            entry += 0x24;
        }
    }
}
```

## Evidence
- Raw: `FUN_001d8d70.c`; callee `FUN_001d7b30.c` (five contiguous swaps).
- Dispatch: `FUN_001d9f78.c` case 8 → `FUN_001d8d70(param_2+0x3c)` → `conn+0x5b4`. opcode = case+3 = 0x0b.
  (The same leaf `FUN_001d7b30` is also invoked inline at demux case 1 = opcode 0x04 for a single record.)
- Runtime-unvalidated.

## Remaining uncertainty
- Opcode 0x0b unmapped to a named lobby message; record field semantics unknown.
