# 0x001d89f8 bswap_inbound_list_var18

| field | value |
|---|---|
| Original address | 0x001d89f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d89f8 |
| Resolved name | bswap_inbound_list_var18 (op0x43 payload normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (SN@P inbound demux, switch case 0x40 → opcode 0x43)
**Callees:** FUN_001d8710 (swap 3-word list header), FUN_001d891c (swap entry fields +0x10/+0x18)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x43 (inbound); handler = conn+0x600, gated who-byte != DATA (seg+0x2c & 0x1000 == 0)
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode 0x43. The SN@P receive demux `FUN_001d9f78` calls it with the
payload base (`seg + 0x3c`). The wire is big-endian; this pass rewrites the numeric fields to host
little-endian **in place** before the registered app callback at `conn+0x600` runs. The payload is a
counted, **variable-stride** record list: a 3-word list header (whose word[2] = entry count) followed
by `count` records. Each record's length lives at record+0x18, so the loop advances by a length-derived,
4-byte-aligned stride. Unlike its fixed-stride siblings it has **no `count < 0x37d` sanity cap** — it
trusts the header count.

## Input / output
- `param_1` (int): pointer to the app payload (list header). No return (void).
- Precondition: fields are big-endian as received off the wire.
- Postcondition: header word[0..2] and each record's +0x10 and +0x18 fields are host-endian.

## Side effects
- Mutates the payload buffer in place (header 12 bytes + per-record fields). No globals, no packets sent.
- `FUN_001d891c` swaps record+0x10 **and** record+0x18; +0x18 is swapped *before* it is read as the
  stride length, so the stride computation uses the host-endian value.

## Important branches
- `for (i=0; i < header.count; i++)`: header.count = `*(int*)(param_1+8)` (already swapped by the header
  pass). Zero count → no records touched. No upper bound guard (contrast fixed-stride variants).
- Stride: `entry += (entry[0x18] + 0x1f) & ~3` = `round_up(0x1c + entry_len, 4)` — 0x1c-byte record
  prefix + variable body, aligned to 4.

## Constants & flags
- `0x1f`/`0xfffffffc`: 4-byte alignment of `(len + 0x1c)`. (0x18 field offset + 7 = 0x1f rounding bias.)
- Dispatch: opcode = `*(u16*)(seg+0x2e) & 0x7f`; demux switch index = opcode − 3.

## Corrected reconstruction
```c
// Inbound normalizer for SN@P app opcode 0x43. payload = seg+0x3c.
// Wire is big-endian; convert numeric fields to host order in place.
void bswap_inbound_list_var18(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);              // FUN_001d8710: swap word[0],[1],[2]; word[2]=count
    u8 *entry = (u8*)p + 0x0c;          // records begin after the 12-byte header
    for (int i = 0; i < p->count; i++) {
        bswap_entry_10_18(entry);       // FUN_001d891c: swap *(u32*)(entry+0x10), *(u32*)(entry+0x18)
        u32 body_len = *(u32*)(entry + 0x18);          // now host-endian
        entry += (body_len + 0x1f) & 0xfffffffc;        // round_up(0x1c + body_len, 4)
    }
}
```

## Evidence
- Raw: `FUN_001d89f8.c`. Callee bodies: `FUN_001d8710.c` (3-word header swap), `FUN_001d891c.c`
  (swaps +0x10, +0x18).
- Dispatch proof: `FUN_001d9f78.c` case 0x40 → `FUN_001d89f8(param_2+0x3c)` then `conn+0x600` callback;
  opcode = (seg+0x2e & 0x7f) = case+3 = 0x43 (op28 = case 0x25 confirms the +3 offset).
- Runtime-unvalidated (no PINE/pcap trace of a 0x43 packet).

## Remaining uncertainty
- Opcode 0x43 semantics not tied to a named lobby message; the +0x18 length field's meaning
  (payload vs. sub-record count) is inferred from the stride math only.
