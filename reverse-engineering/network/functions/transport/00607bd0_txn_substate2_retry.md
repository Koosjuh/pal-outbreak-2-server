# 0x00607bd0 txn_state2_await_ack

| field | value |
|---|---|
| Original address | 0x00607bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607bd0 |
| Resolved name | txn_state2_await_ack |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10 (txn dispatcher)
**Callees:** FUN_005b09b0 (pack payload), FUN_005b14b0 (poll response class)
**Referenced globals:** cRam008744f8 (send seq); uRam00874f33 (flag, cleared)
**Referenced strings:** —
**Referenced opcodes:** response classes 0x10 / 0x200 (poll masks)
**State vars:** cRam008744f8; uRam00874f33

## Behavioral explanation
Handler for **major state 2** — "await the reply to the 0x20 request and branch on which response class arrives". Also emits the follow-up commit sends via `func_0x001b0140`.

- **Entry (substate 0):** packs the outbound payload (`FUN_005b09b0(txn+7, seq-1)`), then polls the receive path for a response:
  - **primary response present** (`FUN_005b14b0(0x10) != 0`): substate→1, clears flag `uRam00874f33`, fires commit send `001b0140(1)`, clears block busy flag (`param_1+0x454 = 0`), and loads `countdown = 8` (a short settle window).
  - **else alternate response present** (`FUN_005b14b0(0x200) != 0`): jumps to **state 4** (`major=4`, substate=0) and fires commit send `001b0140(2)`.
  - **else** neither: returns -1 (keep polling next tick).
- **substate 1:** decrement `countdown`; while `>= 0` return -1, once it goes negative return **0** (transaction SUCCESS / done).
- **substate 2:** decrement `countdown`; while `>= 0` return -1, once negative return **0xfffffffe** (-2 = timeout / give-up). This substate is entered from state 4's failure tail.

Every tick also increments `tick` (`+0x14`).

## Input / output
- `param_1` (int) — lobby_state_block (`0x6c4b90`); field `+0x454` cleared.
- `param_2` (`txn_desc*`) — descriptor.
- Return: `0xffffffff` in progress, `0` success (substate 1 expiry), `0xfffffffe` failure (substate 2 expiry). Codes propagate up through the dispatcher to the caller SM.

## Side effects
- Packs payload buffer via `FUN_005b09b0`.
- Fires commit/advance send `func_0x001b0140(1)` (primary) or `(2)` (alternate).
- Clears `uRam00874f33` and `lobby_state_block+0x454`.
- Writes `txn->substate`, `txn->major_state`, `txn->countdown`, `txn->tick`.

## Important branches
| Condition | Consequence |
|---|---|
| `substate == 0` & `poll(0x10)` | substate=1, flag873f=0, send 001b0140(1), busy=0, countdown=8 |
| `substate == 0` & `poll(0x200)` | major=4, substate=0, send 001b0140(2) |
| `substate == 0` & neither | return -1 |
| `substate == 1` & countdown≥0 | -1; else return **0** (success) |
| `substate == 2` & countdown≥0 | -1; else return **0xfffffffe** (fail) |
| default (`major` mismatch) | return -1 |

## Constants & flags
- `FUN_005b14b0(mask)` — poll for a received response of class `mask`. `0x10` = primary/ack class, `0x200` = alternate/redirect class. (bitmask selectors, evidence: two distinct literal masks gating two outcomes).
- `func_0x001b0140(n)` — commit/advance send trigger; `1` = primary commit, `2` = alternate commit.
- Return codes: `0` done-ok, `0xfffffffe` done-fail, `0xffffffff` in-progress.

## Corrected reconstruction
```c
undefined4 txn_state2_await_ack(lobby_state_block *blk, txn_desc *t)
{
    int c;
    t->tick++;

    if (t->substate == 2) {                       // failure settle (entered from state4)
        c = --t->countdown;
        return (c >= 0) ? 0xffffffff : 0xfffffffe; // -2 = give up
    }
    if (t->substate == 1) {                        // success settle
        c = --t->countdown;
        return (c >= 0) ? 0xffffffff : 0;          //  0 = transaction done
    }
    if (t->substate != 0) return 0xffffffff;

    // substate 0: pack request and poll for the reply
    pack_payload(&t->msg20_payload /*+7*/, g_send_seq - 1 /*cRam008744f8-1*/);

    if (poll_response(RESP_PRIMARY /*0x10*/)) {     // ack arrived
        t->substate++;                              // -> 1
        g_flag_874f33 = 0;
        commit_send(1);                             // 001b0140(1)
        blk->pending_ack /*+0x454*/ = 0;
        t->countdown = 8;
        return 0xffffffff;
    }
    if (poll_response(RESP_ALT /*0x200*/)) {        // redirect / alternate reply
        t->major_state = 4;
        t->substate    = 0;
        commit_send(2);                             // 001b0140(2)
        return 0xffffffff;
    }
    return 0xffffffff;                              // keep polling
}
```

## Evidence
- Two literal poll masks `0x10`/`0x200` gate the two success/redirect branches; `001b0140(1|2)` mirrors them.
- Return-code plumbing: `0xfffffffe` and `0` are the only non-(-1) exits, produced by the two settle substates → confirms this state carries the terminal result codes.
- Control flow fully determined; **runtime-unvalidated**.

## Remaining uncertainty
Exact semantics of the 0x10 vs 0x200 response classes (ack vs error/redirect) not proven on the wire; `001b0140` is a send/advance stub whose payload is set elsewhere.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607bd0.c`  — untouched decompiler output.
