# 0x005bc1c0 inroom_recv_chat_text

| field | value |
|---|---|
| Original address | 0x005bc1c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc1c0 |
| Resolved name | inroom_recv_member_text_fragment |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room sub-event dispatcher, case 7)
**Callees:** FUN_001069a8 (memcpy)
**Referenced globals:** 0x6fffd1(per-member relayed record table, stride 0x114); 0x6ff2b1(in-room / slot-owned gate)
**Referenced strings:** —
**Referenced opcodes:** — (in-room DATA sub-event 7)

## Behavioral explanation
The **in-room DATA sub-event 7 handler**: writes an incoming variable-length text/state fragment into
a *specific member's* relayed record. It is gated by the in-room flag `cRam006ff2b1` (the known
slot-owned gate) — if not in a room it does nothing. When in-room, it computes the destination as
`0x6fffd1 + member_slot*0x114 + dst_offset` and copies `len` bytes from `payload+8`. The `0x114`
stride matches the relayed `member_record` size (member_record.md: "0x114 relayed"), so this is the
per-player chat/state buffer being filled fragment-by-fragment: `payload[4]` selects the member slot,
`payload[6..7]` the destination offset within that member's buffer, `payload[5]` the fragment length.

## Input / output
- `param_1` (`undefined8`) — unused here (dispatcher context/handle).
- `param_2` (`u8 *payload`) — the DATA sub-event body:
  - `+4` (u8) member slot index.
  - `+5` (u8) fragment length.
  - `+6` (u16) destination offset within the member record.
  - `+8..` fragment bytes.
- Returns void.

## Side effects
- `memcpy(0x6fffd1 + slot*0x114 + offset, payload+8, len)` — writes into the per-member table
  (only when in-room).

## Important branches
- `cRam006ff2b1 == 0` (not in a room / slot not owned) → **no-op**, return. Same gate that locks the
  create/roster path elsewhere.

## Constants & flags
- `0x114` (276) — per-member record stride (= relayed `member_record`; `0x45*4`, decompiled as `(slot*0x44 + slot)*4`).
- `0x6fffd1` — member table base for this fragment channel.
- Gate `0x6ff2b1` — in-room / slot-owned flag.

## Corrected reconstruction
```c
// In-room DATA sub-event 7: deposit a text/state fragment into member[slot]'s relayed record.
struct inroom_text_frag { u8 pad0[4]; u8 slot; u8 len; u16 offset; u8 data[]; }; // payload
#define MEMBER_RELAY_BASE   0x6fffd1
#define MEMBER_RELAY_STRIDE 0x114

void inroom_recv_member_text_fragment(void *ctx, inroom_text_frag *p) {
    if (in_room_flag /*0x6ff2b1*/ == 0) return;         // gate
    u8 *dst = (u8*)(MEMBER_RELAY_BASE + p->slot * MEMBER_RELAY_STRIDE + p->offset);
    memcpy(dst, p->data, p->len);                        // FUN_001069a8
}
```

## Evidence
- Raw: `func_0x001069a8((uint)*(ushort*)(param_2+6) + ((uint)*(byte*)(param_2+4)*0x44 + *(byte*)(param_2+4))*4 + 0x6fffd1, param_2+8, *(byte*)(param_2+5));`
  — `(slot*0x44 + slot)*4 = slot*0x114`.
- Guard `if (cRam006ff2b1 != '\0')` = the in-room/slot-owned gate (lobby_state_block 0x6ff2b1).
- `0x114` stride confirmed against member_record.md relayed size.
- Sole caller FUN_005bba20 = the in-room sub-event dispatcher (this is its case 7).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether the fragment is chat text vs. character-stat streaming (both live in the 0x114 relayed record). The `dst_offset` at payload+6 is what disambiguates at runtime; not traced. Bytes `payload[0..3]` unlabeled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc1c0.c`  — untouched decompiler output.
