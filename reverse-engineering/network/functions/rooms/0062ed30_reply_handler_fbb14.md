# 0x0062ed30 create_room_ack_handler_step14 (fbb14)

| field | value |
|---|---|
| Original address | 0x0062ed30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ed30 |
| Resolved name | create_room_ack_handler_step14 |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by the create-room flow)
**Callees:** FUN_005f6970 (fatal/error transition, arg 4)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4fbb pending_tag; 0x6c4ba0 screen_step; 0x6c4ba1 sub-step; 0x6c5539 flag
**Referenced strings:** —
**Referenced opcodes:** create-room step reply (pending_tag 0x14)
**State vars:** guard `screen_id != 6` AND `pending_tag == 0x14`

## Behavioral explanation
Ack handler for create-room step 0x14. Clears `pending_tag`; on success jumps the create SM to `screen_step=7` with `sub_step=0` and raises the flag `0x6c5539=0xff` (a "step committed"/ready gate). On failure it invokes FUN_005f6970(4) — a hard error transition (arg 4), not a soft recover — i.e. this step's failure aborts the flow rather than looping.

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status. Void; output via globals.

## Side effects
- Clears `pending_tag`.
- Success: `screen_step=7`, `sub_step=0`, flag 0x6c5539=0xff.
- Failure: FUN_005f6970(4) (error/abort transition).

## Important branches
- `screen_id==6 || pending_tag!=0x14` → return.
- `status==0` → step=7 + set flag.
- `status!=0` → FUN_005f6970(4).

## Constants & flags
- `pending_tag == 0x14` — this create-room step outstanding.
- `screen_step == 7` — next create state.
- `0x6c5539 = 0xff` — step-committed/ready flag [inferred].
- FUN_005f6970(4) — shared error-screen entry with numeric code 4.

## Corrected reconstruction
```c
void create_room_ack_handler_step14(u32 *reply) {    // pending_tag 0x14
    if (screen_id == SCREEN_BUSY || pending_tag != 0x14) return;
    u8 status = (u8)reply[0];
    pending_tag = 0;
    if (status == 0) {
        sub_step = 0;
        screen_step = 7;
        flag_5539 = 0xff;                            // committed / ready gate [inferred]
    } else {
        goto_error_screen(4);                        // FUN_005f6970 — hard abort
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062ed30.c`.
- FUN_005f6970 appears across handlers as the error-screen jump with a small integer code; here code 4.
- Registered by create_room_flow (dc40 case5 via FUN_005c0750).
- Runtime-unvalidated.

## Remaining uncertainty
- Exact meaning of flag 0x6c5539 (0xff) and step 7 (which sub-screen) not traced; names [inferred] from position in the create sequence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ed30.c`  — untouched decompiler output.
