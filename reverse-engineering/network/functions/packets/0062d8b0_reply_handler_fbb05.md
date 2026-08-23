# 0x0062d8b0 reply_handler_fbb05

| field | value |
|---|---|
| Original address | 0x0062d8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d8b0 |
| Resolved name | lobby_reply_step5_handler (was reply_handler_fbb05) |
| Subsystem | packets |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as a function-pointer reply callback)
**Callees:** FUN_005b9110 (show error dialog / code 0x4c), FUN_00617a00 (reset lobby_state_block @0x6c4b90)
**Referenced globals:** lobby_state_block: 0x6c4b90 screen_id; 0x6c4fbb pending_tag; 0x6c4b9e lobby_sm; 0x6c4b9f screen_major; 0x6c4ba0 screen_step
**Referenced strings:** —
**Referenced opcodes:** — (status-byte reply convention)
**State vars:** 0x6c4fbb pending_tag(==5 gate, cleared); 0x6c4b90 screen_id(!=6 guard)

## Behavioral explanation
Reply-completion callback for a lobby operation whose pending step is `5`. Installed as a function
pointer and invoked with the reply payload; `payload[0]` is the **status byte** (0 = success, non-zero =
error — the shared convention across the overlay reply-handler family). It only acts while the UI is in
the expected state: `screen_id (0x6c4b90) != 6` **and** `pending_tag (0x6c4fbb) == 5`. It clears the
pending tag, then on **success** advances the lobby state machine — zeroing the create/join sub-state
(`screen_major 0x6c4b9f`, `screen_step 0x6c4ba0`) and incrementing `lobby_sm (0x6c4b9e)` — or on **error**
pops an error dialog (`FUN_005b9110(0x4c)`) and resets the whole `lobby_state_block` via
`FUN_00617a00(0x6c4b90)`.

## Input / output
- `param_1` (`u8 *reply`): reply payload; `reply[0]` = status byte.
- Returns `void`.

## Side effects (success path, status==0)
- `pending_tag (0x6c4fbb) = 0`; `screen_major (0x6c4b9f) = 0`; `screen_step (0x6c4ba0) = 0`;
  `lobby_sm (0x6c4b9e) += 1`.

## Side effects (error path, status!=0)
- `pending_tag (0x6c4fbb) = 0`; `FUN_005b9110(0x4c)` (error dialog id 0x4c);
  `FUN_00617a00(0x6c4b90)` (reset lobby_state_block).

## Important branches
- **Gate**: `if (screen_id != 6 && pending_tag == 5)` — otherwise the callback is a no-op (wrong screen,
  or no op pending on step 5). Prevents stale replies from mutating unrelated UI state.
- **status == 0** → advance SM; **status != 0** → error dialog + full reset.

## Constants & flags
- `pending_tag == 5` — this handler's expected pending step (`lobby_state_block +0x6c4fbb`; cf. `0x11`
  enter / `0x17` join tags documented for the same field).
- `screen_id != 6` guard — skip while on screen 6.
- Error dialog id `0x4c` (arg to `FUN_005b9110`).
- Status byte: `0` = OK, non-zero = failure (overlay reply-handler convention).

## Corrected reconstruction
```c
/* lobby_state_block @ 0x6c4b90 (see structures/lobby_state_block.md) */
void lobby_reply_step5_handler(u8 *reply /*param_1*/)
{
    lobby_state_block *L = (lobby_state_block *)0x6c4b90;

    if (L->screen_id != 6 && L->pending_tag == 5) {   /* 0x6c4b90, 0x6c4fbb */
        u8 status = reply[0];
        L->pending_tag = 0;                           /* consume the pending step */

        if (status == 0) {                            /* success */
            L->screen_major = 0;                      /* 0x6c4b9f */
            L->screen_step  = 0;                      /* 0x6c4ba0 */
            L->lobby_sm    += 1;                       /* 0x6c4b9e — advance */
        } else {                                      /* failure */
            show_error_dialog(0x4c);                   /* FUN_005b9110 */
            lobby_state_reset((void*)0x6c4b90);        /* FUN_00617a00 */
        }
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062d8b0.c`.
- Global offsets map directly onto `structures/lobby_state_block.md`: `0x6c4b90 screen_id`, `0x6c4b9e
  lobby_sm`, `0x6c4b9f screen_major`, `0x6c4ba0 screen_step`, `0x6c4fbb pending_tag`.
- No static callers ⇒ registered as a reply callback (address handed to a send routine); the
  `status==0`-advances-else-error pattern is shared by the overlay reply-handler family.

## Remaining uncertainty
- Which specific lobby op registers this callback (i.e. what "step 5"/tag corresponds to on the wire) is
  not pinned — needs the caller that installs the pointer. Error id `0x4c` semantics and `FUN_00617a00`
  reset scope inferred. Not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d8b0.c`  — untouched decompiler output.
