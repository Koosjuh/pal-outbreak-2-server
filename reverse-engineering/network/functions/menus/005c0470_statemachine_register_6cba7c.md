# 0x005c0470 statemachine_register_6cba7c

| field | value |
|---|---|
| Original address | 0x005c0470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0470 |
| Resolved name | create_slot_sm_arm (statemachine_register_6cba7c) |
| Subsystem | menus |
| Relevance | **core** (create-room registration path) |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f99c0 (room create/join UI action), FUN_0062de90 (room-list action dispatcher)
**Callees:** — (arms async pump `FUN_005c3490`, called later by the overlay frame dispatcher)
**Referenced globals:** 0x6cc01a (37×u16 create-request block, copied from param_1); 0x6cba7c (SM once-guard); 0x6cba78 (SM step = create *owner_substate*); 0x6cba58 (pump fnptr ← FUN_005c3490); 0x6cba5c (completion callback ← param_2)
**Referenced strings:** —
**Referenced opcodes:** the pump emits the create/prepare request over the SN@P conn (op04 create-slot / op26 prepare family via `func_0x001dc508`)
**State vars:** 0x6cba7c guard, 0x6cba78 step (lobby_state_block owner_substate), 0x6cba7d ack (op04_complete)

## Behavioral explanation
**Arms the create-slot (room-ownership) state machine.** It first copies a **37-entry (0x25 × u16,
74 bytes) request block** from `param_1` into the fixed staging buffer at 0x6cc01a — this is the
room-create descriptor the pump later transmits. Then, guarded by the once-flag 0x6cba7c (so a second
call while armed returns -1 without disturbing the in-flight op), it installs the async pump
`FUN_005c3490` at 0x6cba58, resets the step byte 0x6cba78 (= the create `owner_substate` in
`lobby_state_block`) to 0, and stores the caller's completion callback `param_2` at 0x6cba5c.

The pump `FUN_005c3490` then runs per-frame: step0 marshals the request (area index, cast/scenario
selectors, sub-ids) and hands 0x6cc01a/0x6cc03b to the transport send `func_0x001dc508` on conn
`uRam006febac`; step1 awaits ack; step2 on ack==1 **commits the create** — sets the unlock gate
`0x6ff2b1 = 1`, room-mode `0x6cbc7e = 0x10` (roster panel active), publishes the area index to
`0x6d2158`, and triggers screen transition `FUN_005bdfe0(0x18)`; on ack==2 it fails with status
0xFF. Either terminal fires the stored callback and clears the guard.

This is the client half of the create-room handshake the G12 work is chasing (create-registration
must commit → op04 mint). See MEMORY `g12-room-registry-layer`.

## Input / output
- **Params:** `param_1` — pointer to a 37×u16 create-request descriptor (title/pw/scenario/cast/area
  selectors — layout not fully mapped); `param_2` — completion callback (`void(*)(u8*,u8*)`).
- **Returns:** `u32` — **0** if the SM was armed, **0xFFFFFFFF (-1)** if it was already armed
  (guard set).

## Side effects
- Writes 74 bytes into 0x6cc01a (create-request staging).
- Sets guard 0x6cba7c=1, step 0x6cba78=0, pump ptr 0x6cba58=FUN_005c3490, callback 0x6cba5c=param_2.
- **Downstream (via pump):** transmits the create request on the SN@P conn; on success mutates
  0x6ff2b1, 0x6cbc7e, 0x6d2158 and drives a screen transition. **The table copy always happens, even
  on the guarded-reject path** (the copy precedes the guard check).

## Important branches
| condition | consequence |
|---|---|
| always (top) | copy 37×u16 from param_1 → 0x6cc01a (loop `iVar3` 0x25→0) |
| `cRam006cba7c == 0` (not armed) | arm SM: guard=1, pump ptr set, step=0, callback=param_2; return 0 |
| `cRam006cba7c != 0` (already armed) | return -1 (do **not** re-arm; in-flight op preserved) |

## Constants & flags
- `0x25` (37) — u16 count of the create-request block (74 bytes).
- `0x6cc01a` — create-request staging buffer (source for the pump's `func_0x001dc508` send).
- `0` / `-1` — armed-ok / already-armed return codes.
- Pump-set: `0x6ff2b1 = 1` (create unlock gate — title/pw/scenario/char become editable),
  `0x6cbc7e = 0x10` (roster panel active), `FUN_005bdfe0(0x18)` (screen id 0x18 transition).

## Corrected reconstruction
```c
// Arm the create-slot (room-ownership) state machine. Returns 0 if armed, -1 if already busy.
// param_1 -> 37×u16 create-request descriptor; param_2 -> completion callback.
i32 create_slot_sm_arm(const u16 *req /*param_1*/, txn_done_cb done /*param_2*/)
{
    // Stage the create request (always, even if we then reject).
    u16 *dst = (u16 *)0x6cc01a;                 // create-request staging buffer
    for (int i = 0x25; i > 0; --i)              // 37 u16 = 74 bytes
        *dst++ = *req++;

    if (g_create_guard /*0x6cba7c*/ != 0)       // already armed -> refuse, keep in-flight op
        return -1;

    g_create_guard      = 1;
    g_create_pump       /*0x6cba58*/ = &create_slot_pump /*FUN_005c3490*/;
    g_create_step       /*0x6cba78, owner_substate*/ = 0;
    g_create_done_cb    /*0x6cba5c*/ = done;
    return 0;
}
```

## Evidence
- Raw decompile: 37-iteration u16 copy to 0x6cc01a; guard/arm block writing 0x6cba7c/0x6cba58
  (=FUN_005c3490)/0x6cba78/0x6cba5c.
- Pump `FUN_005c3490` (read): consumes 0x6cc01a/0x6cc03b via `func_0x001dc508(uRam006febac,…)`,
  and on step2/ack1 sets `uRam006ff2b1=1`, `uRam006cbc7e=0x10`, `uRam006d2158=FUN_005bf1e0(2)`,
  `FUN_005bdfe0(0x18)` — confirming the create-commit semantics.
- Globals: 0x6cba78 = create owner_substate, 0x6cba7d = op04_complete (lobby_state_block); 0x6ff2b1 =
  create unlock gate; 0x6cbc7e = room_mode 0x10 = roster panel (lobby_state_block / GLOBALS).

## Remaining uncertainty
- Field layout of the 37×u16 request block is unmapped; exact opcode emitted by
  `func_0x001dc508` (op04 vs op26) not confirmed from this record alone. The "no op04 mint" G12
  blocker means the *server* side of this handshake is what fails — client-side arm here looks
  correct. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0470.c`  — untouched decompiler output.
