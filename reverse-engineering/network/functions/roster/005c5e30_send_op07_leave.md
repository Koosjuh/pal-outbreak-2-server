# 0x005c5e30 send_op07_leave

| field | value |
|---|---|
| Original address | 0x005c5e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5e30 |
| Resolved name | send_op07_charstats (was send_op07_leave) |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500 (room_roster_sync_sm, phase 10/11)
**Callees:** func_0x00106b60 (memset), func_0x001069a8 (memcpy), func_0x001df380 (op10 transport multicast send)
**Referenced globals:** 0x6febac SN@P connection handle
**Referenced strings:** —
**Referenced opcodes:** inner app-op 0x07, transport op0x10
**State vars:** —

## Behavioral explanation
Host→member relay of app-opcode **0x07** carrying a **0x36-byte** body. Despite the generated "leave" label, in the roster-sync SM this op07 broadcasts a **character-stats / member-detail chunk**: the caller (FUN_005c6500 phase '\v') builds a 0x36 buffer `{ srcMemberByte, sizeByte(0x32 or 0x28), lenWord, charstats-slice }` and copies a 0x28/0x32 slice of the member's 0xf0 charstats block (`0x700734`, stride 0x114) into it. Sent reliably via op10 multicast to recipient `param_1` (declared length 0x3a = 4 + 0x36). Chunking advances `bRam007006f0` (0..4) so a member's charstats are delivered in slices.

## Input / output
- `param_1` — `connID` : recipient member id.
- `param_2` — `u8[0x36]` : caller's `bStack_80` block: `[0]=srcMemberIndex (bRam007006f8)`, `[1]=chunkSizeSel (0x32 if member<4 else 0x28)`, `[2..3]=offset word ((5+0x14)*idx*2)`, `[4..]=charstats slice`.
- returns `void`.

## Side effects
- Transmits reliable op10 frame to `param_1`, payload = `{07,00,00,00}` + 0x36-byte charstats chunk.

## Important branches
None locally. Caller: chunk size = `0x32` for member index <4 else `0x28`; iterates member/chunk cursors `bRam007006f0/f8/00`.

## Constants & flags
- inner opcode `0x07`; body 0x36; declared len `0x3a`; count `1`; who `0x8000`.
- charstats chunk sizes `0x32` / `0x28`; source block 0xf0 per member at `0x700734` (stride 0x114) — matches member_record charstats (+0x18, len 0xf0).

## Corrected reconstruction
```c
void send_op07_charstats(connID target, u8 chunk[0x36])
{
    u8 buf[0x304];
    memset(buf, 0, 0x304);
    buf[0] = 0x07;
    memcpy(buf + 4, chunk, 0x36);
    snap_send_op10_multi(uRam006febac, 0x8000, buf, 0x3a, 1, target);
}
```

## Evidence
- Raw: `FUN_005c5e30.c` — memset 0x304, buf[0]=7, `memcpy(buf+4,param_2,0x36)`, `func_0x001df380(...,0x3a,1,param_1)`.
- Caller `FUN_005c6500.c` phase '\v' (11): builds `bStack_80[0x36]` from the 0xf0 charstats at `0x700734` in 0x28/0x32 chunks; this is charstats delivery, not a leave.
- struct member_record.md: charstats len 0xf0 at member +0x18.

## Remaining uncertainty
Name upgraded from send_op07_leave → send_op07_charstats based on the SM body (charstats chunking), but the inner op07 could still map to the transport "leave/notify" opcode reused as a detail carrier; wire capture would disambiguate. Offset-word formula preserved verbatim from the decompile.
