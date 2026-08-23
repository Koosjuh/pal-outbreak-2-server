# 0x001d8b60 bswap_list_fixed24_a

| field | value |
|---|---|
| Original address | 0x001d8b60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8b60 |
| Resolved name | bswap_inbound_list_fixed24_a (op0x47 payload normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0x44 → opcode 0x47)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d81a4 (swap entry +0x10/+0x14/+0x18/+0x1c/+0x20)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x47 (inbound); handler = conn+0x608
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode 0x47. BE → host-endian, in place, over a counted **fixed
0x24-stride** record array (`seg+0x3c`) before the `conn+0x608` callback. Three-word header (word[2] =
count), then `count` records of 0x24 bytes, five u32 fields swapped per record (via `FUN_001d81a4`:
+0x10, +0x14, +0x20, +0x18, +0x1c). Bounded by `count < 0x37d`.

**Body-identical to `FUN_001d8c10` (opcode 0x48).** Same stride, same per-entry swapper — two distinct
opcodes sharing one record shape; the demux table distinguishes them (0x47→conn+0x608, 0x48→conn+0x60c).

## Input / output
- `param_1` (int): app payload / list header. Void.
- Post: header + per-record five u32s host-endian.

## Side effects
- In-place payload mutation. No globals/packets.

## Important branches
- `if (count < 0x37d)` guards the loop (893-record cap). `entry += 0x24` per record.

## Constants & flags
- `0x37d`: record cap. Record bytes 0x00–0x0f untouched (opaque/name prefix); u32s at 0x10,0x14,0x18,0x1c,0x20 swapped.

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x47. Fixed 0x24-byte records. (Identical body to op0x48.)
void bswap_inbound_list_fixed24_a(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);                     // FUN_001d8710
    if (p->count < 0x37d) {
        u8 *entry = (u8*)p + 0x0c;
        for (int i = 0; i < p->count; i++) {
            bswap_fields_5(entry);             // FUN_001d81a4: +0x10,+0x14,+0x20,+0x18,+0x1c
            entry += 0x24;
        }
    }
}
```

## Evidence
- Raw: `FUN_001d8b60.c`; callee `FUN_001d81a4.c` (five swaps).
- Dispatch: `FUN_001d9f78.c` case 0x44 → `FUN_001d8b60(param_2+0x3c)` → `conn+0x608`. opcode = case+3 = 0x47.
- Runtime-unvalidated.

## Remaining uncertainty
- Opcode 0x47 unmapped to a named message; whether 0x47/0x48 are a request/reply or two data classes is unknown.
