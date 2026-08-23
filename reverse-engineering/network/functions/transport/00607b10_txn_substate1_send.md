# 0x00607b10 txn_state1_send_msg20

| field | value |
|---|---|
| Original address | 0x00607b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607b10 |
| Resolved name | txn_state1_send_msg20 |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10 (txn dispatcher)
**Callees:** FUN_005b7fd0 (send msg-0x20)
**Referenced globals:** uRam008744f8 (send sequence/counter)
**Referenced strings:** —
**Referenced opcodes:** transport message selector 0x20 (not an app opcode)
**State vars:** uRam008744f8

## Behavioral explanation
Handler for **major state 1** of the reliable-transaction state machine dispatched by `FUN_00607a10` on `txn->major_state`. `param_1` is the lobby/connection block (`0x6c4b90` = lobby_state_block); `param_2` is the small txn descriptor.

State 1 = "send request 0x20 and arm the round-trip timer":
- **Entry (substate 0):** arms the descriptor — resets the tick counter, loads the RTT timer with `0x15` (21 ticks), advances substate to 1, and fires one outbound message of selector `0x20` via `FUN_005b7fd0`, carrying the payload at `txn+7` and the current send-sequence `uRam008744f8`.
- **Wait (substate 1):** each tick increments the attempt counter (`+0x14`) and decrements the timer (`+0x16`). When the timer reaches 0 it sets the block's busy/ack flag (`param_1+0x454 = 1`) and advances: normally to **state 2** (`major++`), but if the error flag (`txn+4`) is set it diverts to **state 3** (the recovery/resend path) and clears the flag.

Always returns `0xffffffff` (-1 = "stay in machine, not done").

## Input / output
- `param_1` (int) — lobby_state_block base (`0x6c4b90`); fields `+0x454` written.
- `param_2` (char* / `txn_desc*`) — transaction descriptor (see struct below).
- Return `undefined4` — always `0xffffffff` (in-progress sentinel).

## Side effects
- Writes `txn->substate`, `txn->tick`, `txn->timer`, `txn->major_state`, `txn->err_flag`.
- Writes `lobby_state_block+0x454` (busy/pending-ack flag) = 1 on timer expiry.
- Emits transport message selector `0x20` (payload `txn+7`, seq `uRam008744f8`).

## Important branches
| Condition | Consequence |
|---|---|
| `substate == 0` | arm: substate=1, tick=0, timer=0x15, send msg-0x20 |
| `substate == 1` && `timer != 0` | timer-- (keep waiting) |
| `substate == 1` && `timer == 0` && `err_flag == 0` | busy=1; major_state++ (→ state 2), substate=0 |
| `substate == 1` && `timer == 0` && `err_flag != 0` | busy=1; major_state=3, substate=0, err_flag=0 (recovery) |

## Constants & flags
- `0x20` — transport message selector for this transaction's request (send primitive `FUN_005b7fd0`). Not a SN@P app opcode.
- `0x15` (21) — RTT/resend timer in dispatch ticks.
- `0xffffffff` — machine "in progress" return sentinel; `0xfffffffe`/`0` (done) are produced by sibling states.

## Corrected reconstruction
```c
// txn descriptor shared by states 1-4 (0x607b10/bd0/cf0/dc0)
typedef struct {
    uint8_t  major_state;   // +0x00  dispatched by FUN_00607a10 (0..4)
    uint8_t  substate;      // +0x01
    uint8_t  _pad2[2];
    uint8_t  err_flag;      // +0x04  set -> divert state1 to recovery state3
    uint8_t  _pad5[2];
    uint8_t  msg20_payload; // +0x07  body for msg-0x20 (FUN_005b7fd0 / 005b09b0)
    // +0x0b msg21_payload  (state4)
    int16_t  tick;          // +0x14  attempt/round counter
    int16_t  timer;         // +0x16  RTT countdown (state1)
    int32_t  countdown;     // +0x18  wait countdown (states 2/3/4)
} txn_desc; // [inferred field names]

undefined4 txn_state1_send_msg20(lobby_state_block *blk, txn_desc *t)
{
    if (t->substate == 1) {
        t->tick++;
        if (t->timer == 0) {
            blk->pending_ack /*+0x454*/ = 1;
            if (t->err_flag == 0) {          // normal: advance to wait state
                t->major_state++;            // -> state 2
                t->substate = 0;
            } else {                          // recovery path
                t->major_state = 3;
                t->substate = 0;
                t->err_flag = 0;
            }
        } else {
            t->timer--;                       // still waiting for RTT window
        }
    }
    else if (t->substate == 0) {              // entry: arm + send
        t->substate = 1;
        t->tick  = 0;
        t->timer = 0x15;                      // 21-tick window
        send_msg_0x20(0x20, 0, &t->msg20_payload /*+7*/, g_send_seq /*uRam008744f8*/);
    }
    return 0xffffffff;                        // in progress
}
```

## Evidence
- Dispatcher `FUN_00607a10` switches on `*param_1` (major_state 0..4) and passes `0x6c4b90` (lobby_state_block) as the block arg → confirms `param_1` = state block, `param_2` = txn descriptor.
- Send primitive `FUN_005b7fd0(0x20,0,param_2+7,uRam008744f8)` = message selector 0x20 with payload+seq.
- Control flow fully determined from the raw decompile; **runtime-unvalidated** (no trace of a 0x20 send captured).

## Remaining uncertainty
Selector `0x20`/`0x21` are transport message types, not confirmed SN@P app opcodes; `+0x454` named "pending_ack" by inference. Which lobby action (create vs enter) drives this machine is not proven from this function alone (dispatcher has 3 callers).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607b10.c`  — untouched decompiler output.
