# 0x005f97c0 confirm_char_select

| field | value |
|---|---|
| Original address | 0x005f97c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f97c0 |
| Resolved name | confirm_room_text_field (aka confirm_char_select) |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_00632ce0, FUN_006345e0, FUN_00634ab0, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6970a2 (field A buffer, 8B); 0x6970b2 (field B buffer, 15B); 0x6c4610/0x6c4618/0x6c4620 (pad/net-status snapshot); param+0x908 (user choice); param+0x10 (step); param+0x16 (dwell); param+0xf (major-state out)
**Referenced strings:** —
**Referenced opcodes:** — (request rides the 0x634xxx submit pipeline)
**State vars:** param+0x10 (step); param+0x908 (choice)

## Behavioral explanation
A confirm sub-screen in the create/room-detail flow (shared driver `FUN_005f9150`). Depending on the user's choice byte `param+0x908`, it submits one of two fixed-length text fields to the server through the `0x634xxx` request pipeline and then polls that request to completion, on success advancing the enclosing screen's major state (`param+0xf`). Field **A** = buffer `0x6970a2`, 8 bytes (submit type 1); field **B** = buffer `0x6970b2`, 15 bytes (submit type 2). These are the same name/handle buffers `submit_room_entry` (`0x005f99c0`) later copies into the join record, i.e. the room title / password / player-name fields. Choice `0x0a` is the cancel/back path (jumps major state to 4 without sending).

## Input / output
- `param_1` — create/room-detail screen object.
- `param+0x908` — user choice: `0`=submit field B (15B), `1`=submit field A (8B), `0x0a`=cancel.
- Outputs: sets `param+0xf` (major state for the parent SM) and resets `param+0x10`.
- Returns `void`.

## Side effects
- **Send**: `FUN_006345e0(type, 0, len, buf)` — type 1 len 8 buf `0x6970a2`, or type 2 len 15 buf `0x6970b2`.
- **Timing arg**: `FUN_006371d0(0x42980000 /*=76.0f*/, 0x118)` before each send.
- **Poll/ack**: `FUN_00634ab0(buf, pad_snapshot, btn_mask)`; return `-1` (error) or `1` (done) → finalize.
- **Commit** (field B only): `FUN_00632ce0(0x6970b2)` applies the confirmed value.
- **Cleanup**: `FUN_00637180()` tears down the request UI on completion.

## Important branches
- **step 3** (field-A in flight): `FUN_00634ab0(0x6970a2,…)` returns `-1`|`1` → `major(0xf)=2`, `step=0`, cleanup. Else keep waiting.
- **step 2** (field-B in flight): `FUN_00634ab0(0x6970b2,…)` returns `-1`|`1` → commit `FUN_00632ce0(0x6970b2)`, `major=2`, `step=0`, cleanup.
- **step 1** (dispatch on choice `+0x908`):
  - `== 0x0a` → `major=4`, `step=0` (cancel/back).
  - `== 1` → `step=3`; `FUN_006371d0(76.0f,0x118)`; `FUN_006345e0(1,0,8,0x6970a2)` (send field A).
  - `== 0` → `step=2`; `FUN_006371d0(76.0f,0x118)`; `FUN_006345e0(2,0,0xf,0x6970b2)` (send field B).
- **step 0** (`--dwell < 0`) → advance to step 1 (intro delay).

## Constants & flags
- Field lengths: **8** (`0x6970a2`, field A), **15/0xf** (`0x6970b2`, field B).
- Submit types: **1** (field A), **2** (field B) — first arg to `FUN_006345e0`.
- `0x42980000` = IEEE-754 `76.0f` — a layout/timeout constant paired with id `0x118` for `FUN_006371d0`.
- Poll return codes: `-1` = error/abort, `1` = done (both finalize identically here).
- `major(+0xf)` targets: `2` (proceed) / `4` (cancel).

## Corrected reconstruction
```c
typedef struct roomdetail_screen {
    /* +0xf  */ uint8_t major;   // parent-SM next major state (out)
    /* +0x10 */ uint8_t step;
    /* +0x16 */ int16_t dwell;
    /* +0x908*/ uint8_t choice;  // which field / cancel
} roomdetail_screen;

// 0x6970a2 = field A (8B), 0x6970b2 = field B (15B)  [room title / pw / name]
void confirm_room_text_field(roomdetail_screen *s)
{
    uint32_t btn = uRam006c4618 | uRam006c4620;   // pad snapshot

    if (s->step == 3) {                                   // field A submit in flight
        int8_t r = req_poll(0x6970a2, uRam006c4610, btn);  // FUN_00634ab0
        if (r == -1 || r == 1) { s->major = 2; s->step = 0; req_close(); }
    }
    else if (s->step == 2) {                              // field B submit in flight
        int8_t r = req_poll(0x6970b2, uRam006c4610, btn);
        if (r == -1 || r == 1) { req_commit(0x6970b2);     // FUN_00632ce0
                                 s->major = 2; s->step = 0; req_close(); }
    }
    else if (s->step == 1) {                              // dispatch on choice
        switch (s->choice) {
        case 0x0a: s->major = 4; s->step = 0; break;       // cancel
        case 1:    s->step = 3; req_set_param(76.0f, 0x118);
                   req_send(1, 0, 8, 0x6970a2); break;      // FUN_006345e0
        case 0:    s->step = 2; req_set_param(76.0f, 0x118);
                   req_send(2, 0, 0xf, 0x6970b2); break;
        }
    }
    else if (s->step == 0 && --s->dwell < 0) {
        s->step++;
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005f97c0.c`.
- Buffers `0x6970a2`/`0x6970b2` are re-read as name buffers by `submit_room_entry` (`005f99c0`, case 4 `strcpy` from `0x6970b2`/`0x6970a2`).
- Shared caller `FUN_005f9150` with `create_room_enter_transition` and `submit_room_entry` places this in the create/room-detail screen family.
- **Runtime-unvalidated**: field semantics (title vs password) inferred from lengths; poll/send glue (`0x634xxx`) not traced.

## Remaining uncertainty
- Which field is title vs password vs player-name (8B vs 15B) — inferred, not confirmed.
- `FUN_006345e0`/`FUN_00634ab0`/`FUN_006371d0` internals (the `0x634xxx` request pipeline) are outside this set; whether the submit reaches the wire as an app opcode or stays local is unconfirmed.
</content>
