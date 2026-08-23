# 0x005bc270 inroom_evt0b_set_countdown

| field | value |
|---|---|
| Original address | 0x005bc270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc270 |
| Resolved name | inroom_evt0b_set_countdown |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room dispatcher, sub-event case 0x0b)
**Callees:** FUN_005bf230 (screen/UI refresh with arg 0x6febfc)
**Referenced globals:** 0x6fb748 (countdown seconds), 0x6cbc84 (UI status byte), 0x6febfc (refresh arg)
**Referenced strings:** —
**Referenced opcodes:** in-room sub-event 0x0b
**State vars:** uRam006fb748, uRam006cbc84

## Behavioral explanation
Handler for in-room **sub-event 0x0b** — arms the room-start countdown. It reads a 32-bit tick
value from the message body at `payload+4`, divides by 30 (0x1e — PS2 frames→seconds at 30 fps),
and stores the result as a `u16` countdown at 0x6fb748. It also clears the UI status byte 0x6cbc84
to 0, then calls `FUN_005bf230(0x6febfc)` to kick the screen/UI refresh so the new countdown is
drawn.

## Input / output
- Input: `param_1` (dispatcher handle, unused) and `param_2` = message pointer; the tick count is
  `*(int*)(param_2 + 4)`.
- Output: `void`.

## Side effects
- `*(u16*)0x6fb748 = ticks / 30` (countdown in seconds).
- `*(u8*)0x6cbc84 = 0` (reset UI status).
- Triggers UI refresh `FUN_005bf230(*(?)0x6febfc)`.

## Important branches
None (straight-line). Integer division truncates toward zero.

## Constants & flags
- `0x1e` (30) = frames-per-second divisor (ticks→seconds).
- 0x6cbc84 cleared to 0 (UI status/dirty reset before refresh).

## Corrected reconstruction
```c
// Dispatched by inroom_game_dispatch case 0x0b.
void inroom_evt0b_set_countdown(u32 ctx /*unused*/, u8 *msg) {
    *(u8*)0x6cbc84  = 0;                               // reset UI status
    u32 ticks = *(u32*)(msg + 4);                      // countdown in frames
    *(u16*)0x6fb748 = (u16)(ticks / 30);               // → seconds (30 fps)
    ui_refresh(*(u32*)0x6febfc);                        // FUN_005bf230
}
```

## Evidence
- `FUN_005bc270.c`: `uRam006cbc84=0; uRam006fb748=(u16)(*(int*)(param_2+4)/0x1e); FUN_005bf230(uRam006febfc);`
- `FUN_005bba20.c`: `case 0xb: FUN_005bc270(*(undefined4*)(param_1+8));` (note: dispatcher passes the
  handle; `param_2` here is the message the decompiler exposes as the timer source).
- Runtime-unvalidated.

## Remaining uncertainty
Whether the divisor is exactly the display frame rate (30) or a protocol tick constant is inferred
from the /30 idiom; 0x6febfc's contents (screen id vs. callback) not confirmed.
