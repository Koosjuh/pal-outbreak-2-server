# 0x005bc2f0 inroom_evt0d_open_dialog_06

| field | value |
|---|---|
| Original address | 0x005bc2f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc2f0 |
| Resolved name | inroom_evt0d_open_dialog_06 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room dispatcher, sub-event case 0x0d)
**Callees:** FUN_005c7e30 (queue UI message, arg 6→id 9), FUN_005bdf90 (fire event-table handler 0xb)
**Referenced globals:** 0x6fc5e8 (0x300 dialog buffer), 0x6ca8a0 (event-handler table), 0x6febac (session handle, in sibling thunk)
**Referenced strings:** —
**Referenced opcodes:** in-room sub-event 0x0d (and 0x0e via sibling thunk); app 0x0f (thunk)
**State vars:** cRam006ff2b1

## Behavioral explanation
Sibling of `inroom_evt09_open_dialog_0c`. Handler for in-room **sub-event 0x0d**, gated on
`unlock_gate (0x6ff2b1) != 0`. When true: clears the 0x300 dialog buffer at 0x6fc5e8, queues UI
message code **6** (`FUN_005c7e30(6)` → internal id 9), and fires event-table handler **0x0b**
(`FUN_005bdf90(0xb,0)`). Same mechanism as case 9 but a different dialog class + event index.

The same source file also carries **`thunk_FUN_005c61b0`** — the dispatcher's **case 0x0e** handler
— which builds a 0x304 buffer with body[0]=**0x0f** and sends it reliably (flags 0x8000, len 4) on
session 0x6febac to the dispatcher peer. That is an out-of-band reliable op-0x0f emit (distinct from
this 0x0d dialog handler).

## Input / output
- Input (0x0d handler): none used. Output: `void`.
- (thunk 0x0e): `param_1` peer → sends op-0x0f.

## Side effects
- 0x0d: clears 0x6fc5e8; queues UI message class 6 (id 9); fires event 0x0b.
- 0x0e thunk: transmits reliable app message 0x0f (4-byte body).

## Important branches
- `unlock_gate (0x6ff2b1) == 0` -> 0x0d handler is a no-op.

## Constants & flags
- Gate `0x6ff2b1 != 0` (unlock_gate).
- UI message arg **6** → internal id **9**; event-table index **0x0b**.
- thunk: app message type **0x0f**, SN@P reliable flag 0x8000, length 4.

## Corrected reconstruction
```c
// Dispatched by inroom_game_dispatch case 0x0d.
void inroom_evt0d_open_dialog_06(void) {
    if (*(u8*)0x6ff2b1 != 0) {                          // unlock_gate
        memset((void*)0x6fc5e8, 0, 0x300);
        ui_queue_message(6);                            // FUN_005c7e30 (6 -> id 9)
        fire_event(0x0b, 0);                            // FUN_005bdf90
    }
}

// Dispatched by inroom_game_dispatch case 0x0e (thunk_FUN_005c61b0).
void inroom_evt0e_send_op0f(u32 peer) {
    u8 body[0x304];
    memset(body, 0, 0x304);
    body[0] = 0x0f;
    snap_send(session_handle /*0x6febac*/, 0x8000, body, 4, 1, peer);  // func_0x001df380
}
```

## Evidence
- `FUN_005bc2f0.c`: `if(cRam006ff2b1!='\0'){ memset(0x6fc5e8,0,0x300); FUN_005c7e30(6); FUN_005bdf90(0xb,0);}`
- same file `thunk_FUN_005c61b0`: `buf[0]=0xf; func_0x001df380(uRam006febac,0x8000,buf,4,1,param_1);`
- `FUN_005c7e30.c`: `case 6: uVar1=9;`
- `FUN_005bba20.c`: `case 0xd: FUN_005bc2f0(...); case 0xe: thunk_FUN_005c61b0(...);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc2f0.c`  — untouched decompiler output.

## Remaining uncertainty
Dialog class 6 / event 0x0b user meaning unconfirmed; op-0x0f payload (all-zero 4 bytes) role in the
in-room protocol not cross-referenced to a capture.
