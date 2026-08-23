# 0x0062cfd0 confirm_dialog_member_gate

| field | value |
|---|---|
| Original address | 0x0062cfd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cfd0 |
| Resolved name | confirm_dialog_member_gate |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062cf50
**Callees:** FUN_00604810 (count_occupied_slots), FUN_005b8da0 (spawn_message_with_deco), FUN_005b09b0 (cursor_nav_byte), FUN_005b14b0 (input_pressed), FUN_005b9110 (set_msg_channel_id), func_0x001b0140 (dismiss/close message widget)
**Referenced globals:** 0x694700 persistent member pool (stride 0x38, cap 0x32)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** dialog control struct passed in `param_2` (see field map)

## Behavioral explanation
Per-frame handler for a two-option (Yes/No) confirmation message box, gated on the current member
count. `param_2` points to a small dialog-control struct. On the **open** pass (`st[1]==0`) it snapshots
the number of occupied entries in the persistent member pool `0x694700` (leading-contiguous count, cap
50) into `st+8`, resets the selection index `st+0x10=0`, marks the dialog open (`st[1]=1`), and spawns
the message widget with decoration mode for message type `0xaf`. On subsequent **poll** passes
(`st[1]==1`) it reads the pad: a cancel-class button (mask 0x200) dismisses the box (channel 2) and
returns 1; otherwise the confirm button (mask 0x10) commits, and with no confirm it moves the Yes/No
cursor. The member count acts as a gate: when the pool is empty (`st+8==0`) the selection is forced to
1 rather than being navigable.

## Input / output
- **param_1** (undefined8): unused screen/context handle (passed through, not read).
- **param_2** (`dlg *`): dialog-control struct. Field map (from access pattern):
  - `+0` u8 `result` — 0 = none, 1 = "No"/negative commit, 2 = "Yes"/affirmative commit.
  - `+1` u8 `open` — 0 = closed (needs open), 1 = open (poll).
  - `+4` u16 `next_state` — set to 6 on affirmative commit (hands off to caller SM).
  - `+8` u16 `member_count` — snapshot of pool occupancy at open.
  - `+0x10` u16 `sel` — cursor / selected option (0 = No, nonzero = Yes).
- **Returns:** u32 — `1` only on the cancel-button dismiss path; `0` otherwise (still running / committed).

## Side effects
- Reads member pool `0x694700` occupancy via `count_occupied_slots(0x694700, 0x32)`.
- Writes dialog struct fields `+0/+1/+4/+8/+0x10`.
- Spawns / dismisses a message widget (`spawn_message_with_deco`, `func_0x001b0140`).
- Plays UI feedback / sets message channel (`set_msg_channel_id(0x4c)` on affirmative commit).
- No network packets emitted directly.

## Important branches
- `st[1] != 1` (dialog not open):
  - `st[1] != 0` -> early `return 0` (transient/invalid state, do nothing).
  - else (open pass): count members -> `st+8`; `st+0x10=0`; `st[1]=1`; spawn message `0xaf`.
- `st[1] == 1` (poll):
  - `input_pressed(0x10)` (confirm) == 0:
    - `input_pressed(0x200)` (cancel) != 0 -> `func_0x001b0140(2)`; `return 1`.
    - member_count `st+8 == 0` -> force `st+0x10 = 1` (only "Yes" reachable).
    - else -> `cursor_nav_byte(st+0x10, 1, 2)` (toggle Yes/No).
  - confirm pressed:
    - `sel (st+0x10) == 0` (No) AND `member_count != 0` -> `st=1; st[1]=0; func_0x001b0140()` (close, result=No).
    - `sel != 0` (Yes) -> `st=2; st[1]=0; func_0x001b0140(1); st+4=6; set_msg_channel_id(0x4c)`.

## Constants & flags
- `0x694700` persistent member pool base; `0x32` (50) = pool cap / stride-0x38 scan limit.
- `0x10` = confirm button mask; `0x200` = cancel button mask ([inferred] pad-bit assignments).
- `0xaf` = message-type passed to `spawn_message_with_deco` (deco mode 2 branch — a caption dialog).
- `0x4c` = message-channel id set on affirmative commit.
- `result` enum: 1 = negative/No, 2 = affirmative/Yes.
- `func_0x001b0140` arg alias: `(2)` cancel, `()` back/No, `(1)` confirm/Yes — feedback/dismiss selector.

## Corrected reconstruction
```c
// Two-option confirmation box gated on member-pool occupancy.
// Returns 1 only when dismissed via the cancel button; 0 while running or on commit.
typedef struct {
    uint8_t  result;       // +0x00  0 none / 1 No / 2 Yes
    uint8_t  open;         // +0x01  0 closed / 1 open
    uint8_t  _pad2[2];
    uint16_t next_state;   // +0x04  -> 6 on affirmative commit
    uint8_t  _pad6[2];
    uint16_t member_count; // +0x08  pool occupancy snapshot
    uint8_t  _padA[6];
    uint16_t sel;          // +0x10  0 = No, nonzero = Yes
} confirm_dlg; // [inferred] field names

uint32_t confirm_dialog_member_gate(void *screen /*param_1, unused*/, confirm_dlg *st)
{
    if (st->open == 1) {                       // poll an open dialog
        if (!input_pressed(0x10)) {            // confirm not pressed
            if (input_pressed(0x200)) {        // cancel pressed
                msg_dismiss(2);                // func_0x001b0140(2)
                return 1;
            }
            if (st->member_count == 0)
                st->sel = 1;                   // no members -> only "Yes" selectable
            else
                cursor_nav_byte(&st->sel, 1, 2); // toggle Yes/No
        }
        else if (st->sel == 0) {               // confirm on "No"
            if (st->member_count != 0) {
                st->result = 1;                // No
                st->open   = 0;
                msg_dismiss();                 // func_0x001b0140()
            }
        }
        else {                                 // confirm on "Yes"
            st->result     = 2;                // Yes
            st->open       = 0;
            msg_dismiss(1);                    // func_0x001b0140(1)
            st->next_state = 6;
            set_msg_channel_id(0x4c);
        }
    }
    else if (st->open == 0) {                   // first pass: open the dialog
        st->member_count = count_occupied_slots((void *)0x694700, 0x32);
        st->sel          = 0;
        st->open         = 1;
        spawn_message_with_deco(0xaf, &st->sel); // type 0xaf caption box
    }
    // else st->open != 0/1 -> transient; return 0
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062cfd0.c` (size 288).
- Callee identities from records: `00604810_count_occupied_slots`, `005b8da0_spawn_message_with_deco`
  (mode 2 for type 0xaf), `005b09b0_cursor_nav_byte`, `005b14b0_input_pressed`, `005b9110_set_msg_channel_id`.
- `0x694700` = persistent member pool (GLOBALS: "table B; persistent member pool"), stride 0x38, cap 0x32.
- Runtime-unvalidated.

## Remaining uncertainty
Exact pad-bit semantics of 0x10 / 0x200 and the precise UX meaning of the box (e.g. "start with N
members?" vs "kick/leave?") are not provable from statics — Medium. `func_0x001b0140` is a raw thunk
(dismiss vs SE-play) inferred from its call-site argument pattern. `next_state=6` couples to the parent
SM in `FUN_0062cf50`, not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cfd0.c`  — untouched decompiler output.
