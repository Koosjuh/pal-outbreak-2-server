# 0x005bc2a0 inroom_evt09_open_dialog_0c

| field | value |
|---|---|
| Original address | 0x005bc2a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc2a0 |
| Resolved name | inroom_evt09_open_dialog_0c |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room dispatcher, sub-event case 9)
**Callees:** FUN_005c7e30 (queue UI message, arg 0xc→id 4), FUN_005bdf90 (fire event-table handler 7)
**Referenced globals:** 0x6fc5e8 (0x300 message/dialog buffer), 0x6ca8a0 (event-handler table, via callee)
**Referenced strings:** —
**Referenced opcodes:** in-room sub-event 0x09
**State vars:** cRam006ff2b1

## Behavioral explanation
Handler for in-room **sub-event 9**. Gated on `unlock_gate` (0x6ff2b1 == 1) — i.e. only fires once
the room is fully in-room/unlocked. When gated true it (1) zeroes the 0x300-byte dialog/message
buffer at 0x6fc5e8, (2) queues UI message code 0xc via `FUN_005c7e30` (which itself re-clears the
buffer, remaps 0xc→internal id 4, allocates a message object and stores its pointer at 0x6fc5e8),
and (3) fires event-table handler index 7 via `FUN_005bdf90` (calls `(*0x6ca8a0[7])({1,7},0)`).
Net: pops a room dialog/notice (message class 0xc) and drives the associated screen event.

## Input / output
- Input: none used (dispatcher handle ignored).
- Output: `void`.

## Side effects
- Clears 0x6fc5e8[0..0x300); installs a queued UI message (class 0xc / id 4) there.
- Invokes registered event handler 7 (if non-NULL).

## Important branches
- `unlock_gate (0x6ff2b1) != 1` -> no-op (whole body skipped).

## Constants & flags
- Gate `0x6ff2b1 == 1` (lobby_state_block.unlock_gate — in-room).
- UI message arg **0xc** → `FUN_005c7e30` maps to internal id **4**.
- Event-table index **7** (table @0x6ca8a0, stride 4).

## Corrected reconstruction
```c
// Dispatched by inroom_game_dispatch case 9.
void inroom_evt09_open_dialog_0c(void) {
    if (*(u8*)0x6ff2b1 == 1) {                          // unlock_gate (in-room)
        memset((void*)0x6fc5e8, 0, 0x300);              // dialog buffer
        ui_queue_message(0x0c);                         // FUN_005c7e30 (0xc -> id 4)
        fire_event(7, 0);                               // FUN_005bdf90 -> (*0x6ca8a0[7])
    }
}
```

## Evidence
- `FUN_005bc2a0.c`: `if (cRam006ff2b1=='\x01'){ memset(0x6fc5e8,0,0x300); FUN_005c7e30(0xc); FUN_005bdf90(7,0); }`
- `FUN_005c7e30.c`: `case 0xc: uVar1=4;` then `store ptr at 0x6fc5e8`.
- `FUN_005bdf90.c`: `pcVar1=*(code**)((param_1&0xffff)*4+0x6ca8a0); if(pcVar1) (*pcVar1)(&{1,param_1},0);`
- `FUN_005bba20.c`: `case 9: FUN_005bc2a0(...);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc2a0.c`  — untouched decompiler output.

## Remaining uncertainty
The user-visible meaning of dialog class 0xc / event 7 (e.g. a specific room notice) is not
confirmed; `FUN_005bdf90(7,0)` second arg fixed 0.
