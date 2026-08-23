# 0x001d8cc0 bswap_list_fixed28

| field | value |
|---|---|
| Original address | 0x001d8cc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8cc0 |
| Resolved name | bswap_inbound_roomlist_op49 (op0x49 room-list normalizer) |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (inbound demux, switch case 0x46 → opcode 0x49)
**Callees:** FUN_001d8710 (swap 3-word header), FUN_001d7d20 (swap entry +0x10/+0x14/+0x18/+0x1c/+0x20/+0x24)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x49 room-list (inbound); handler = conn+0x610
**State vars:** —

## Behavioral explanation
Inbound endian normalizer for opcode **0x49 (SN@P room-list)**. BE → host-endian, in place, over a
counted **fixed 0x28-stride** record array (`seg+0x3c`) before the `conn+0x610` callback. Three-word
header (word[2] = count), then `count` records of 0x28 bytes; per record `FUN_001d7d20` swaps six u32
fields (+0x14, +0x10, +0x18, +0x1c, +0x20, +0x24). The 0x28 stride and field set match the app-level
`room_record` (op49, size 0x28) documented in `structure-layouts/room_record.md`.

## Input / output
- `param_1` (int): app payload / room-list header. Void.
- Post: header + per-record six u32s host-endian; leading bytes 0x00–0x0f = room name text, untouched.

## Side effects
- In-place payload mutation. No globals/packets. Feeds the room-list render/handle-table build downstream.

## Important branches
- `if (count < 0x37d)` guards the loop (893-room cap). `entry += 0x28` per record.

## Constants & flags
- `0x37d`: room-count cap.
- Swapped u32s at 0x10,0x14,0x18,0x1c,0x20,0x24 → align with room_record op49 numeric fields
  (current@+0x14, flags@+0x1c, max@+0x20, handle@+0x24). Room title occupies the leading (unswapped) bytes.

## Corrected reconstruction
```c
// Inbound normalizer, SN@P opcode 0x49 (room list). Fixed 0x28-byte room_record entries.
void bswap_inbound_roomlist_op49(list_hdr_t *p /*[inferred]*/)
{
    bswap_list_header3(p);                     // FUN_001d8710
    if (p->count < 0x37d) {
        room_record_op49 *r = (room_record_op49*)((u8*)p + 0x0c);  // stride 0x28
        for (int i = 0; i < p->count; i++) {
            bswap_roomrec_fields(r);           // FUN_001d7d20: +0x14,+0x10,+0x18,+0x1c,+0x20,+0x24
            r = (room_record_op49*)((u8*)r + 0x28);
        }
    }
}
```

## Evidence
- Raw: `FUN_001d8cc0.c`; callee `FUN_001d7d20.c` (six swaps at +0x10..+0x24).
- Dispatch: `FUN_001d9f78.c` case 0x46 → `FUN_001d8cc0(param_2+0x3c)` → `conn+0x610`. opcode = case+3 = 0x49.
- Cross-check: `structure-layouts/room_record.md` op49 stride 0x28.
- Runtime-unvalidated at the byteswap layer (op49 fields themselves are rig-derived).

## Remaining uncertainty
- `room_record.md` labels name as char[20] (+0x00) and handle@+0x24 as **LE**, but this swapper touches
  +0x10 and +0x24. Reconciliation: the swapped region begins at +0x10, implying the name text is ≤0x10
  bytes here (or the last name word is tolerated), and +0x24 is swapped on receive (the "LE" note likely
  describes a value the client echoes back unchanged). Field-exact mapping to confirm against a live op49 capture.
