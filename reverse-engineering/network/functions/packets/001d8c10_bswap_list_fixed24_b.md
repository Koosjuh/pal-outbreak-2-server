# 0x001d8c10 bswap_list_fixed24_b

| field | value |
|---|---|
| Original address | 0x001d8c10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8c10 |
| Resolved name | bswap_inbound_list_fixed24_b (op0x48 name-query normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0x45 → opcode 0x48)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d81a4 (swap entry +0x10/+0x14/+0x18/+0x1c/+0x20)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x48 name-query (inbound); handler = conn+0x60c
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode **0x48 (name-query response)**. BE → host-endian, in place, over a
counted **fixed 0x24-stride** record array (`seg+0x3c`) before the `conn+0x60c` callback. Three-word
header (word[2] = count), then `count` 0x24-byte records; per record `FUN_001d81a4` swaps five u32s
(+0x10, +0x14, +0x20, +0x18, +0x1c), leaving the leading 0x10 bytes (name/handle text) intact.

**Byte-identical body to `FUN_001d8b60` (opcode 0x47)** — same stride and per-entry swapper; the two are
kept as separate functions so the demux can bind distinct callbacks (0x48→conn+0x60c, 0x47→conn+0x608).
Consistent with 0x48 being the SN@P name-query: a list of name/id records the client renders.

## Input / output
- `param_1` (int): app payload / list header. Void.
- Post: header + per-record five u32s host-endian; name text bytes unchanged.

## Side effects
- In-place payload mutation. No globals/packets.

## Important branches
- `if (count < 0x37d)` guards the loop (893-record cap). `entry += 0x24` per record.

## Constants & flags
- `0x37d`: record cap. Swapped u32s: 0x10,0x14,0x18,0x1c,0x20. Bytes 0x00–0x0f = untouched name/ident prefix.

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x48 (name-query reply). Fixed 0x24-byte records.
void bswap_inbound_list_fixed24_b(list_hdr_t *p /*[inferred]*/)
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
- Raw: `FUN_001d8c10.c` (identical to `FUN_001d8b60.c`); callee `FUN_001d81a4.c`.
- Dispatch: `FUN_001d9f78.c` case 0x45 → `FUN_001d8c10(param_2+0x3c)` → `conn+0x60c`. opcode = case+3 = 0x48;
  matches the documented 0x48 name-query.
- Runtime-unvalidated (no captured 0x48 payload dissected against the 0x24 record).

## Remaining uncertainty
- Exact name-query record field map (which u32 is id vs. status vs. flags) not confirmed against a live capture.
