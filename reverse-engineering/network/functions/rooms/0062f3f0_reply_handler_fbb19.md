# 0x0062f3f0 back_exit_ack_handler (fbb19)

| field | value |
|---|---|
| Original address | 0x0062f3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f3f0 |
| Resolved name | back_exit_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by room_back_exit e800 / FUN_005c0750)
**Callees:** FUN_005f6970 (error-screen jump, arg 4)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4fbb pending_tag; 0x6c4ba0 screen_step; 0x6c4ba1 sub_step
**Referenced strings:** —
**Referenced opcodes:** back/exit step reply (pending_tag 0x19)
**State vars:** guard `screen_id != 6` AND `pending_tag == 0x19`

## Behavioral explanation
Ack handler for a **back/exit** step (pending_tag 0x19) — leaving a room/menu. Structurally identical to the create step-0x14 handler except the success path: clears `pending_tag`, and on success clears `sub_step=0` and advances `screen_step += 1`; on failure jumps to the shared error screen FUN_005f6970(4).

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status. Void; output via globals.

## Side effects
- Clears `pending_tag`.
- Success: `sub_step=0`, `screen_step++`.
- Failure: FUN_005f6970(4).

## Important branches
- `screen_id==6 || pending_tag!=0x19` → return.
- `status==0` → advance.
- `status!=0` → error screen (code 4).

## Constants & flags
- `pending_tag == 0x19` — back/exit step outstanding.
- FUN_005f6970(4) — shared error-screen entry, code 4 (same as step-0x14 handler).

## Corrected reconstruction
```c
void back_exit_ack_handler(u32 *reply) {           // pending_tag 0x19
    if (screen_id == SCREEN_BUSY || pending_tag != 0x19) return;
    u8 status = (u8)reply[0];
    pending_tag = 0;
    if (status == 0) {
        sub_step = 0;
        screen_step++;
    } else {
        goto_error_screen(4);                       // FUN_005f6970
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062f3f0.c`.
- Same shape as 0x0062ed30 (fbb14) minus the 0x6c5539 flag; registered by room_back_exit (e800 via FUN_005c0750).
- Runtime-unvalidated.

## Remaining uncertainty
- Which specific back/exit transition (room→list vs lobby→top) fires this is inferred from the registration note only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f3f0.c`  — untouched decompiler output.
