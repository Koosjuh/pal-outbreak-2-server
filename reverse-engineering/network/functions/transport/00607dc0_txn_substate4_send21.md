# 0x00607dc0 txn_state4_send_msg21

| field | value |
|---|---|
| Original address | 0x00607dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607dc0 |
| Resolved name | txn_state4_send_msg21 |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10 (txn dispatcher; passes block 0x6c4b90)
**Callees:** FUN_005b8da0 (send msg-0x21), FUN_005b14b0 (poll response class), FUN_005b09b0 (pack payload), FUN_005b9110 (UI/audio cue)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** transport message selector 0x21; response classes 0x10 / 0x200
**State vars:** —

## Behavioral explanation
Handler for **major state 4** — the second-phase exchange, reached from state 2 when the *alternate* response (`0x200`) arrived. It sends message selector `0x21` (payload at `txn+0xb`), waits, and processes the reply through a 5-step sub-sequence, ultimately returning to state 2 to finish.

Sub-sequence (`substate`):
- **0 (entry):** substate→1, `countdown=0x10` (16), set `txn+0xb = 1`, send `FUN_005b8da0(0x21, txn+0xb)`.
- **1 (pre-wait):** decrement countdown; on `< 0` advance to substate 2.
- **2 (poll):** poll for reply —
  - primary (`0x10`): commit `001b0140(1)`, substate→3, set block flag `param_1+0x43f = 1`, reload `countdown=0x10`.
  - alternate (`0x200`): commit `001b0140(2)`, reset to **state 2 substate 0**, cue `0x4c`.
  - neither: re-pack payload `FUN_005b09b0(txn+0xb, 1, 3)` (retry send data) and stay.
- **3 (settle):** decrement countdown; on `< 0` advance to substate 4, cue `0x4c`.
- **4 (finalize):** decrement countdown; on `< 0`, branch on `txn+0xb`:
  - `== 0`: go to **state 2 substate 2** (failure settle), `001b0140()`, clear block busy `param_1+0x454 = 0`, `countdown=8`.
  - `!= 0`: go to **state 2 substate 0** (re-run ack path).

Always returns `0xffffffff`.

## Input / output
- `param_1` (int) — lobby_state_block (`0x6c4b90`); fields `+0x43f`, `+0x454` written.
- `param_2` (`txn_desc*`) — descriptor; `+0xb` used as msg-0x21 payload/flag.
- Return: always `0xffffffff` (terminal codes are produced later by state 2).

## Side effects
- Emits transport message selector `0x21` (payload `txn+0xb`).
- Repacks payload via `FUN_005b09b0(txn+0xb,1,3)` on poll-miss.
- Sets `lobby_state_block+0x43f = 1` (phase-2 acked flag) and clears `+0x454` (busy).
- Plays cue `0x4c`.
- Writes `txn->major_state`, `txn->substate`, `txn->countdown`, `txn->msg21_flag (+0xb)`.

## Important branches
| Condition | Consequence |
|---|---|
| substate 0 | arm: sub=1, countdown=0x10, +0xb=1, send msg-0x21 |
| substate 1 & countdown<0 | sub→2 |
| substate 2 & `poll(0x10)` | commit(1), sub→3, +0x43f=1, countdown=0x10 |
| substate 2 & `poll(0x200)` | commit(2), → state2/0, cue 0x4c |
| substate 2 & neither | repack payload (005b09b0(+0xb,1,3)) |
| substate 3 & countdown<0 | sub→4, cue 0x4c |
| substate 4 & countdown<0 & +0xb==0 | → state2/**2** (fail), commit(), +0x454=0, countdown=8 |
| substate 4 & countdown<0 & +0xb!=0 | → state2/**0** (retry ack) |

## Constants & flags
- `0x21` — transport message selector for phase-2 request (`FUN_005b8da0`).
- `0x10` / `0x200` — primary / alternate response poll classes (as in state 2).
- `0x10` (16) — per-step countdown.
- `0x4c` — UI/audio cue id.
- `param_1+0x43f` — [inferred] phase-2 acknowledged flag; `param_1+0x454` — [inferred] busy/pending-ack flag (shared with state 1/2).

## Corrected reconstruction
```c
undefined4 txn_state4_send_msg21(lobby_state_block *blk, txn_desc *t)
{
    switch (t->substate) {
    case 4:                                          // finalize
        if (--t->countdown < 0) {
            if (t->msg21_flag /*+0xb*/ == 0) {
                t->major_state = 2; t->substate = 2; // -> failure settle
                commit_send(/*default*/);            // 001b0140()
                blk->pending_ack /*+0x454*/ = 0;
                t->countdown = 8;
            } else {
                t->major_state = 2; t->substate = 0; // -> retry ack path
            }
        }
        break;
    case 3:                                          // settle
        if (--t->countdown < 0) { t->substate++; ui_cue(0x4c); }
        break;
    case 2:                                          // poll reply
        if (poll_response(RESP_PRIMARY /*0x10*/)) {
            commit_send(1);
            t->substate++;                           // -> 3
            blk->phase2_ack /*+0x43f*/ = 1;
            t->countdown = 0x10;
        } else if (poll_response(RESP_ALT /*0x200*/)) {
            commit_send(2);
            t->major_state = 2; t->substate = 0;
            ui_cue(0x4c);
        } else {
            pack_payload(&t->msg21_flag /*+0xb*/, 1, 3); // resend body
        }
        break;
    case 1:                                          // pre-wait
        if (--t->countdown < 0) t->substate++;       // -> 2
        break;
    case 0:                                          // entry: send msg-0x21
        t->substate = 1;
        t->countdown = 0x10;
        t->msg21_flag /*+0xb*/ = 1;
        send_msg_0x21(0x21, &t->msg21_flag);
        break;
    }
    return 0xffffffff;
}
```

## Evidence
- Dispatcher passes `0x6c4b90` to this handler → `param_1` = lobby_state_block, `+0x43f`/`+0x454` are block fields.
- Entered from state 2's `0x200` branch (`major=4`); returns control to state 2 in every exit → two-phase (0x20 then 0x21) transaction.
- Control flow fully determined; **runtime-unvalidated**.

## Remaining uncertainty
Selectors `0x20`/`0x21` mapping to concrete SN@P app opcodes (create vs enter handshake) unproven; `005b09b0(+0xb,1,3)` args (1,3) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607dc0.c`  — untouched decompiler output.
