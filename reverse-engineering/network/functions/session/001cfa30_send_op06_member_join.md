# 0x001cfa30 send_op06_member_join

| field | value |
|---|---|
| Original address | 0x001cfa30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cfa30 |
| Resolved name | libsnap_send_op06_member_join |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (libsnap app-API; issued by the create/enter overlay flow)
**Callees:** FUN_001cbc20 (select_channel), FUN_001ab460 (alloc_msg tag), FUN_001cce80 (reliable_send online), FUN_001a0eb0 (offline_send)
**Referenced globals:** cRam00343577 = offline-mode flag; bRam005a9048 = channel toggle (0/1); 0x4ddba0 = op06 send buffer; 0x4de3a8 = alloc handle; 0x4de3b2 = member count (u8); 0x4de3e0 = per-member "sent/pending" flag array; uRam0034357a/7c/7e = offline-path args
**Referenced strings:** —
**Referenced opcodes:** 0x06 (member JOIN/enter, C->S)
**State vars:** cRam00343577; bRam005a9048

## Behavioral explanation
The libsnap application-layer emitter for **op06 member-JOIN/enter**. Online (`cRam00343577 == 0`):
1. `FUN_001cbc20(toggle*0x80 + 0x1800)` selects the op06 send channel — `bRam005a9048` toggles between two channel slots (`0x1800` / `0x1880`), the ping-pong the transport uses to keep two JOINs in flight.
2. `FUN_001ab460(0x80, 6)` reserves a 0x80-byte message with **alloc tag 6** (= wire op06); handle → `0x4de3a8`, and `0x4de3b8 = 0`.
3. `FUN_001cce80(key, -1, 0x4ddba0, 2)` opens the reliable send of buffer `0x4ddba0`, where `key = param_3 | (param_1 << 16) | (param_2 << 8)` (only the low byte of each param is used) and mode `2` = reliable.
4. It then marks the first `0x4de3b2` (member-count) entries of the flag array `0x4de3e0[]` to `1` — flagging those roster members as "join in progress / awaiting ack".

Offline (`cRam00343577 != 0`): delegates to `FUN_001a0eb0(uRam0034357a, uRam0034357c, uRam0034357e)` — the loopback JOIN using the cached session/room args.

## Input / output
- **Params:** `param_1, param_2, param_3` (uint) — packed low-bytes into the send key `p3 | p1<<16 | p2<<8`. Domain: a member/room routing triple (member idx, room-hi, room-lo [inferred]).
- **Returns:** `void`.

## Side effects
- Selects channel `bRam005a9048*0x80 + 0x1800`.
- Allocates op06 msg (tag 6) → `0x4de3a8`; `0x4de3b8 = 0`.
- Transmits reliable buffer `0x4ddba0`.
- Sets `0x4de3e0[0 .. count-1] = 1` (member pending flags; count = `0x4de3b2`).
- Offline: forwards to `FUN_001a0eb0`.

## Important branches
- `cRam00343577 == 0` → online reliable send + member-flag marking.
- else → offline `FUN_001a0eb0` loopback.

## Constants & flags
- alloc tag `6` = wire op06.
- channel base `0x1800`, stride `0x80`, toggle `bRam005a9048`.
- send mode `2` = reliable.
- key packing: `p3 | (p1<<16) | (p2<<8)` (per-byte).

## Corrected reconstruction
```c
extern u8  g_offline;          // cRam00343577
extern u8  g_ch_toggle;        // bRam005a9048
extern u8  g_op06_buf[0x80];   // 0x4ddba0
extern void *g_op06_alloc;     // 0x4de3a8
extern u32 g_op06_alloc2;      // 0x4de3b8
extern u8  g_member_count;     // 0x4de3b2
extern u8  g_member_pending[]; // 0x4de3e0
extern u32 g_off_a, g_off_b, g_off_c; // uRam0034357a/7c/7e

void libsnap_send_op06_member_join(uint p1, uint p2, uint p3) {
    if (g_offline == 0) {
        select_channel(g_ch_toggle * 0x80 + 0x1800);        // FUN_001cbc20
        g_op06_alloc  = alloc_msg(0x80, /*tag=*/6);          // FUN_001ab460 -> op06
        g_op06_alloc2 = 0;
        u32 key = (p3 & 0xff) | ((p1 & 0xff) << 16) | ((p2 & 0xff) << 8);
        reliable_send(key, -1, g_op06_buf, /*mode=*/2);      // FUN_001cce80
        for (int i = 0; i < g_member_count; i++)             // 0x4de3b2
            g_member_pending[i] = 1;                         // 0x4de3e0
    } else {
        offline_send(g_off_a, g_off_b, g_off_c);             // FUN_001a0eb0
    }
}
```

## Evidence
- Decompile `FUN_001cfa30.c`: the `cRam00343577` online/offline fork; `FUN_001cbc20((uint)bRam005a9048*0x80 + 0x1800)`; `FUN_001ab460(0x80,6)`→`0x4de3a8`, `0x4de3b8=0`; `FUN_001cce80(p3&0xff|(p1&0xff)<<16|(p2&0xff)<<8, -1, 0x4ddba0, 2)`; the `for i<uRam004de3b2 { 0x4de3e0[i]=1 }` flag loop; offline `FUN_001a0eb0(uRam0034357a/7c/7e)`.
- alloc tag 6 ↔ wire op06 confirmed by the opcode/tag convention shared with `send_op04_create_slot` (tag 4) and PACKET_INDEX op06.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact meaning of the packed key triple (`p1/p2/p3`) — routing/member/room bytes inferred, not proven.
- Whether `0x4de3e0` is per-roster-slot or per-in-flight-send; count source `0x4de3b2` is the member count filled by the roster builder.
- `FUN_001cce80` mode-2 vs the mode-2 used by op04 (both "reliable") — parameter 2's full meaning unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cfa30.c`  — untouched decompiler output.
