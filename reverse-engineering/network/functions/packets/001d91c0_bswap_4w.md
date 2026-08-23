# 0x001d91c0 bswap_4w

| field | value |
|---|---|
| Original address | 0x001d91c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d91c0 |
| Resolved name | bswap_hdr_4w (op0x6e / op0x78 fixed header normalizer) |
| Subsystem | packets |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, case 0x6b → opcode 0x6e; case 0x75 → opcode 0x78)
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x6e (handler conn+0x5f4), 0x78 (handler conn+0x5f8)
**State vars:** —

## Behavioral explanation
Leaf endian normalizer for a fixed 16-byte header: byte-swaps the first four u32 words (+0x00, +0x04,
+0x08, +0x0c). Shared by two inbound opcodes — 0x6e and 0x78 — whose payloads open with the same
four-word fixed header. Each swaps the header in place, then the demux calls the opcode's callback
(conn+0x5f4 for 0x6e, conn+0x5f8 for 0x78).

## Input / output
- `param_1` (uint*): pointer to a 4-word header. Void.
- Post: `param_1[0..3]` host-endian.

## Side effects
- In-place mutation of four words. No globals/packets.

## Important branches
- None (straight-line, four swaps).

## Constants & flags
- Swaps words at 0x00/0x04/0x08/0x0c (no length/count fields — a flat fixed header, not a list).

## Corrected reconstruction
```c
// Fixed 16-byte header swap, shared by inbound opcodes 0x6e and 0x78.
void bswap_hdr_4w(u32 *h)
{
    h[0] = bswap32(h[0]);
    h[1] = bswap32(h[1]);
    h[2] = bswap32(h[2]);
    h[3] = bswap32(h[3]);
}
```

## Evidence
- Raw: `FUN_001d91c0.c`.
- Dispatch: `FUN_001d9f78.c` case 0x6b → `FUN_001d91c0(param_2+0x3c)` → `conn+0x5f4` (opcode 0x6e);
  case 0x75 → `FUN_001d91c0(param_2+0x3c)` → `conn+0x5f8` (opcode 0x78). opcode = case+3.
- Runtime-unvalidated.

## Remaining uncertainty
- Opcodes 0x6e/0x78 are not mapped to named messages; the four header words' meaning is unknown.
