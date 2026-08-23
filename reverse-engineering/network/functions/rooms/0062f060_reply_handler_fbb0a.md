# 0x0062f060 enter_step_ack_handler (fbb0a)

| field | value |
|---|---|
| Original address | 0x0062f060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f060 |
| Resolved name | enter_step_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by the enter flow, de90 case2 / FUN_005c0960)
**Callees:** FUN_005be9a0 (error/notice)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4fbb pending_tag; 0x6c550e ready flag; 0x6c4ba0 screen_step; 0x6c4b9f screen_major; 0x6c4ba1 sub_step; 0x6c5530 timer; 0x6c517c error-arg
**Referenced strings:** —
**Referenced opcodes:** enter step reply (pending_tag 0x0a)
**State vars:** guard `screen_id != 6` AND `pending_tag == 0x0a`

## Behavioral explanation
Ack handler for one step of the **enter-room** sequence (pending_tag 0x0a). Distinct from the create handlers by status encoding: it treats `0x00` as success and `0xff` (−1) as failure, and **ignores every other status** (no state change — the step stays outstanding).
- **status == 0**: clear pending_tag, raise ready flag `0x6c550e=1`, advance `screen_step += 1`.
- **status == 0xff**: clear pending_tag, notice (FUN_005be9a0), reset `screen_step=0`, `sub_step=0`, `screen_major=1`, timer 0x6c5530=0x708 → bounce back to the room-list state.

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status (0x00 ok / 0xff fail). Void; output via globals.

## Side effects
- Success: `pending_tag=0`, `flag_550e=1`, `screen_step++`.
- Failure (0xff): `pending_tag=0`, `screen_step=0`, `sub_step=0`, `screen_major=1`, timer 0x708, notice.

## Important branches
- `screen_id==6 || pending_tag!=0x0a` → return.
- `status==0` → advance.
- `status==0xff` → error bounce.
- other status → no-op (step remains pending).

## Constants & flags
- `pending_tag == 0x0a` — enter step outstanding.
- `0x6c550e = 1` — enter step-complete/ready flag [inferred].
- status `0xff` is the sentinel failure (vs the create handlers' "any non-zero").

## Corrected reconstruction
```c
void enter_step_ack_handler(u32 *reply) {          // pending_tag 0x0a
    if (screen_id == SCREEN_BUSY || pending_tag != TAG_ENTER_STEP /*0x0a*/) return;
    u8 status = (u8)reply[0];
    if (status == 0x00) {
        pending_tag = 0;
        flag_550e = 1;                             // enter ready [inferred]
        screen_step++;
    } else if (status == 0xff) {
        pending_tag = 0;
        ui_notice(0x6c517c);                       // FUN_005be9a0
        screen_step = 0; screen_major = 1; timer_5530 = 0x708; sub_step = 0;
    }
    // other status: leave pending (retry/wait)
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062f060.c`.
- The 0x00/0xff-only fork (ignoring other values) distinguishes the enter path from the create acks. Registered from the enter flow (de90 case2).
- Runtime-unvalidated.

## Remaining uncertainty
- Meaning of flag 0x6c550e is inferred (enter-ready gate); not traced. Why other statuses are silently ignored (async multi-part reply?) is unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f060.c`  — untouched decompiler output.
