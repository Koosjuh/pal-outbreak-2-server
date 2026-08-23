# 0x0062ec90 create_room_ack_handler (fbb11)

| field | value |
|---|---|
| Original address | 0x0062ec90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ec90 |
| Resolved name | create_room_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by the create-room flow)
**Callees:** FUN_005be9a0 (error/notice)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4fbb pending_tag; 0x6c4ba0 screen_step; 0x6c4ba1 sub-step; 0x6c517c error-arg
**Referenced strings:** —
**Referenced opcodes:** create-room step reply (pending_tag 0x11)
**State vars:** guard `screen_id != 6` AND `pending_tag == 0x11`

## Behavioral explanation
Terminal ack handler for one step of the **create-room** sequence (pending_tag 0x11). `param_1[0]` low byte is the status. It always clears `pending_tag` (the step is answered), then forks:
- **status == 0**: success → advance the create SM by one (`screen_step (0x6c4ba0) += 1`).
- **status != 0**: failure → emit a notice (FUN_005be9a0(0x6c517c)), reset `sub_step (0x6c4ba1)=0` and force `screen_step=5` (an error/recover state in the create SM).

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status. Void; output via globals.

## Side effects
- Clears `pending_tag`.
- Success: `screen_step += 1`.
- Failure: `screen_step = 5`, `sub_step = 0`, UI notice.

## Important branches
- `screen_id==6 || pending_tag!=0x11` → return.
- `status==0` → step++.
- `status!=0` → error recover (step=5).

## Constants & flags
- `pending_tag == 0x11` — create-room step outstanding (per HANDOFF, 0x11 = enter/create pending tag family).
- `screen_step == 5` — create-flow error/recover state.

## Corrected reconstruction
```c
void create_room_ack_handler(u32 *reply) {           // pending_tag 0x11
    if (screen_id == SCREEN_BUSY || pending_tag != TAG_CREATE_STEP /*0x11*/) return;
    u8 status = (u8)reply[0];
    pending_tag = 0;                                  // step answered
    if (status == 0) {
        screen_step++;                                // advance create SM
    } else {
        ui_notice(0x6c517c);                          // FUN_005be9a0
        sub_step = 0;
        screen_step = 5;                              // error/recover
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062ec90.c`.
- pending_tag 0x11 = create/enter step per MEMORY/HANDOFF create-room notes; registered from create_room_flow (dc40 case2).
- Runtime-unvalidated.

## Remaining uncertainty
- Meaning of `screen_step==5` (which UI state) is inferred as the create error/recover branch; not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ec90.c`  — untouched decompiler output.
