# 0x00607cf0 txn_state3_recover_resend

| field | value |
|---|---|
| Original address | 0x00607cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607cf0 |
| Resolved name | txn_state3_recover_resend |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10 (txn dispatcher)
**Callees:** FUN_005b8cf0 (send/schedule msg -101), FUN_005b14b0 (poll response class), FUN_005b9110 (UI/audio cue)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** response class 0x10; message selector 0xffffff9b (-101)
**State vars:** —

## Behavioral explanation
Handler for **major state 3** — the recovery / long-timeout resend stage reached from state 1 when `err_flag` was set. It re-issues the request with selector `-101` and waits up to `0x13c` (316) ticks for the primary response, then always falls back to **state 2** to re-run the ack/await logic.

- **Entry (substate 0):** substate→1, `countdown = 0x13c` (316), fire `FUN_005b8cf0(-101)` (re-send / re-schedule).
- **Wait (substate 1):** decrement `countdown`.
  - if `countdown < 0x11e` (286) **and** the primary response arrived (`FUN_005b14b0(0x10)`): commit `001b0140(1)`, reset to **state 2** substate 0, play cue `0x4c` — i.e. the reply came back within the early window.
  - else if `countdown < 0` (full 316-tick timeout elapsed): reset to **state 2** substate 0, play cue `0x4c` — give the ack-state another pass even with no reply.

Always returns `0xffffffff` (in progress).

## Input / output
- `param_1` (undefined8) — lobby_state_block base (unused here beyond ABI).
- `param_2` (`txn_desc*`) — descriptor.
- Return: always `0xffffffff`.

## Side effects
- Emits recovery message selector `-101` (`FUN_005b8cf0`).
- Plays UI/audio cue `0x4c` (`FUN_005b9110`).
- Writes `txn->major_state`, `txn->substate`, `txn->countdown`.

## Important branches
| Condition | Consequence |
|---|---|
| `substate == 0` | substate=1, countdown=0x13c, send msg(-101) |
| `substate == 1` & countdown<0x11e & `poll(0x10)` | commit 001b0140(1); → state 2/0; cue 0x4c (reply within window) |
| `substate == 1` & countdown<0 | → state 2/0; cue 0x4c (timeout, no reply) |
| `substate == 1` & 0x11e≤countdown | keep waiting (decrement only) |

## Constants & flags
- `0x13c` (316) — recovery timeout in ticks; `0x11e` (286) — earliest tick at which a reply is accepted (a 30-tick guard so an immediate stale reply is ignored).
- `0xffffff9b` (-101) — message selector for the recovery send (`FUN_005b8cf0`).
- `0x10` — primary response poll class (same as state 2).
- `0x4c` — UI/audio cue id (`FUN_005b9110`).

## Corrected reconstruction
```c
undefined4 txn_state3_recover_resend(lobby_state_block *blk, txn_desc *t)
{
    if (t->substate == 1) {
        if (--t->countdown < 0x11e && poll_response(RESP_PRIMARY /*0x10*/)) {
            commit_send(1);                 // 001b0140(1)
            t->major_state = 2;             // hand back to await-ack
            t->substate    = 0;
            ui_cue(0x4c);
        } else if (t->countdown < 0) {      // full 316-tick timeout
            t->major_state = 2;
            t->substate    = 0;
            ui_cue(0x4c);
        }
    }
    else if (t->substate == 0) {            // entry: re-send + arm long timer
        t->substate  = 1;
        t->countdown = 0x13c;               // 316 ticks
        send_recover(0xffffff9b);           // FUN_005b8cf0(-101)
    }
    return 0xffffffff;
}
```

## Evidence
- Reached from `txn_state1_send_msg20` when `err_flag` set (that function sets `major_state=3`).
- Guard band: reply only accepted once `countdown < 0x11e` while timeout at `< 0`, i.e. a 0x1e (30) tick window is skipped first.
- Control flow fully determined; **runtime-unvalidated**.

## Remaining uncertainty
Meaning of selector `-101` vs the state-1 `0x20` (retransmit of same request vs distinct recovery message) unproven; cue `0x4c` assumed cosmetic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607cf0.c`  — untouched decompiler output.
