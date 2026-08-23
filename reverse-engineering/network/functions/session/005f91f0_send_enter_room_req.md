# 0x005f91f0 create_room_enter_transition

| field | value |
|---|---|
| Original address | 0x005f91f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f91f0 |
| Resolved name | create_room_enter_transition (was: send_enter_room_req) |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005c0400, FUN_005fe300
**Referenced globals:** param+0x10 (step); param+0x42b (overlay/fade id); param+0x97e (flag)
**Referenced strings:** —
**Referenced opcodes:** — (no wire opcode; local create-screen transition)
**State vars:** param+0x10 (step 0→1)

## Behavioral explanation
Two-step entry transition that hands the create-room screen its context. On the first tick it prepares the screen (`FUN_005fe300`), seats the currently-selected room descriptor into room-register **2** and asserts the **host/creator** flag via `FUN_005c0400` (= `create_room_enter_screen_set_host`, which sets `0x6ff2b0 = 1` and clears the create scratch `0x7006d0`), then advances. Step 1 simply spins the frame (`FUN_005b6900`) until the enclosing driver moves on. **No packet is emitted here** — the original name "send_enter_room_req" is a misread; `FUN_005c0400` fires its completion callback (`0x5fc2b0`) synchronously with an ok status and sends nothing on the wire. This is the client-local commit of "I am the host of the room I just created," which is exactly the gate (`0x6ff2b0`) the create-side STAT/commit send paths (`0x5c0750`, `0x5c0f60`) test downstream.

## Input / output
- `param_1` — pointer to the create/enter screen state object (`+0x10` step, `+0x42b` overlay id, `+0x97e` flag).
- `FUN_005adc80(2)` → the room-slot value for register 2 (current/new-room descriptor id) passed to `FUN_005c0400`.
- Returns `void`.

## Side effects
- `param+0x10`: 0 → 1.
- `FUN_005fe300()` — screen prep (clears the room detail/entry panel state).
- `FUN_005b68e0()` — arm/refresh the screen widgets.
- `param+0x97e = 0`; `param+0x42b = 0xa` (overlay/fade id 0x0a).
- `FUN_005c0400(room_slot, cb=0x5fc2b0)`: `room_reg_set_candidate(2,room_slot)` + `room_reg_commit(2)`, **`uRam006ff2b0 = 1`** (host flag), `memset(0x7006d0,0,0x20)`, then `cb(buf,buf)` with `buf[0]=0`.

## Important branches
- `step == 0` → the prep + host-set + advance path above.
- `step == 1` → `FUN_005b6900()` (idle/spin); no state change here (the outer SM `FUN_005f9150` advances the step).
- other → no-op.

## Constants & flags
- `param+0x42b = 0x0a` — overlay/fade id for the create-room screen (GLOBALS: `+0x42b overlay id`).
- `0x5fc2b0` — completion callback pointer handed to `FUN_005c0400` (runs a follow-up create sub-screen SM).
- `0x6ff2b0 = 1` (set inside the callee) — **host/creator flag** (lobby_state_block `host_flag`, Confirmed).

## Corrected reconstruction
```c
typedef struct create_screen {
    /* +0x10 */ uint8_t step;
    /* +0x42b*/ uint8_t overlay_id;
    /* +0x97e*/ uint8_t flag;
} create_screen;

void create_room_enter_transition(create_screen *s)
{
    if (s->step == 1) {
        frame_spin();                         // FUN_005b6900 — idle until driver advances
    }
    else if (s->step == 0) {
        screen_prep();                        // FUN_005fe300
        s->step++;
        widgets_arm();                        // FUN_005b68e0
        s->flag       = 0;                    // +0x97e
        s->overlay_id = 0x0a;                 // +0x42b
        uint16_t room_slot = room_reg2_value();          // FUN_005adc80(2)
        create_room_enter_screen_set_host(room_slot,     // FUN_005c0400:
                                          /*cb=*/0x5fc2b0);//  seats reg2, uRam006ff2b0=1,
                                                           //  clears 0x7006d0, cb(ok)
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005f91f0.c`.
- Callee `FUN_005c0400` reconstructed as `create_room_enter_screen_set_host` (`functions/rooms/005c0400_create_room_enter_screen_set_host.md`) — sets `0x6ff2b0=1`, no packet.
- `0x6ff2b0` host flag confirmed in `structure-layouts/lobby_state_block.md` and GLOBALS.md.
- **Runtime-unvalidated**: step wiring read from the decompile; the "no packet" claim rests on the callee reconstruction, not a live capture.

## Remaining uncertainty
- Exact return semantics of `FUN_005adc80(2)` vs `FUN_005bf1e0(2)` (both index room register 2); assumed to yield the same current-room descriptor.
- The follow-on behavior lives in callback `0x5fc2b0` (not in this set).
</content>
