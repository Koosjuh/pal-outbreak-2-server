# 0x005cd1d0 room_handshake_retx_tick

| field | value |
|---|---|
| Original address | 0x005cd1d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd1d0 |
| Resolved name | room_handshake_retx_tick |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca0a0
**Callees:** FUN_005dedf0 (build room key), FUN_005d5c20 (abort+resend path), FUN_005d59f0 (send-next path)
**Referenced globals:** session ctx `iRam00701068` / `iRam00701070` / `iRam00701078`
**Referenced strings:** —
**Referenced opcodes:** in-room handshake retransmit (0x2b enter / 0x2d transfer family)
**State vars:** ctx+0x69014 (retx timer1), ctx+0x69018 (timer2), ctx+0x68e83/0x68e84/0x68e85 (phase gates), ctx+0x2e (op selector)

## Behavioral explanation
Per-frame retransmit/timeout tick for the in-room handshake. It runs two independent countdowns
off the session context (`iRam00701068`, the large network block; `iRam00701070`, the room SM
block). The primary timer (`+0x69014`) only actually counts down while three phase gates agree
(not busy / phase==2 / subphase==1); when it reaches 0 the client rebuilds the room key and fires
the next handshake message — choosing an abort+resend vs a plain send by the op-selector byte
`+0x2e`. The secondary timer (`+0x69018`) is a simpler watchdog that, when drained, clears a
one-byte busy/pending flag at `iRam00701078+3`.

## Input / output
- No parameters. Returns `undefined4`: `1` when the primary timeout fired and a message was
  (re)sent this tick; otherwise `0`.

## Side effects
- Decrements the small counter `+0x38` (room SM block) toward 0 (a separate short cooldown).
- May decrement/persist `+0x69014` (only when all three gates pass — see branches).
- On primary fire: `FUN_005dedf0(ctx+0x4f97c, room_sm+0x3b)` rebuilds the room key, then either
  `FUN_005d5c20()` (abort active txns + resend) or `FUN_005d59f0()` (send next).
- Decrements `+0x69018`, or clears `*(u8*)(iRam00701078+3)=0` when it is already ≤0.

## Important branches
- `*(ctx70+0x38) != 0` → decrement it (independent short timer; no other effect).
- `timer1 (+0x69014) > 0`:
  - `+0x68e83 != 0` → **return 0** (a lock/busy gate holds off retransmit).
  - `+0x68e84 != 2` → **return 0** (phase must equal 2).
  - compute `timer1-1` locally.
  - `+0x68e85 != 1` → **return 0** (subphase must equal 1) — **timer1 in memory is NOT written**,
    so the countdown only persists when all three gates pass this tick.
  - store `timer1-1`; if it became `0`:
    - rebuild room key `FUN_005dedf0(...)`.
    - `+0x2e == 8` → `FUN_005d5c20()` (abort+resend), **return 1**.
    - else → `FUN_005d59f0()` (send next), **return 1**.
- `timer2 (+0x69018) < 1` → `*(iRam00701078+3) = 0` (clear busy flag); else `timer2--`.
- fallthrough → **return 0**.

## Constants & flags
- `+0x68e84 == 2` = handshake phase "awaiting reply"; `+0x68e85 == 1` = active subphase;
  `+0x68e83 != 0` = busy/lock (suppresses retx). (Values observed; semantics inferred.)
- `+0x2e == 8` selects the abort+resend variant (`FUN_005d5c20`, which calls `txn_abort_active`)
  vs the normal resend (`FUN_005d59f0`).
- `ctx+0x4f97c` = room-key buffer (also cleared by the overlay-init `thunk_FUN_005c8ed0`).

## Corrected reconstruction
```c
// returns 1 if the retransmit fired this tick, else 0
u32 room_handshake_retx_tick(void)
{
    if (room_sm->cooldown_38 != 0)                 // *(ctx70+0x38)
        room_sm->cooldown_38--;

    int t1 = net->retx_timer1;                     // *(ctx68+0x69014)
    if (t1 > 0) {
        if (net->hs_busy   != 0) return 0;         // +0x68e83 lock
        if (net->hs_phase  != 2) return 0;         // +0x68e84
        t1 -= 1;
        if (net->hs_subphase != 1) return 0;       // +0x68e85 (t1 not committed)
        net->retx_timer1 = t1;
        if (t1 == 0) {
            build_room_key(&net->room_key /*+0x4f97c*/, &room_sm->key_src /*+0x3b*/); // FUN_005dedf0
            if (room_sm->op_sel_2e == 8) { abort_and_resend(); return 1; }  // FUN_005d5c20
            send_next_handshake();                  // FUN_005d59f0
            return 1;
        }
    }

    int t2 = net->watchdog_timer2;                 // *(ctx68+0x69018)
    if (t2 < 1) *(u8*)(g_ctx78 + 3) = 0;           // clear busy flag
    else        net->watchdog_timer2 = t2 - 1;
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005cd1d0.c` — branch structure preserved
  exactly, including the "timer1 decrement not committed unless subphase==1" quirk.
- `FUN_005d5c20` reaches `txn_abort_active` (0x005d8930) — consistent with an abort+resend path.
- Retransmit semantics inferred from the two-timer + phase-gate shape; runtime-unvalidated.

## Remaining uncertainty
- Concrete meaning of phase values (2 / 1) and which wire op (0x2b/0x2d vs a 0x26 prepare) is (re)sent.
- Distinction in intent between `FUN_005d5c20` and `FUN_005d59f0` beyond "abort-first vs not".

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd1d0.c`  — untouched decompiler output.
