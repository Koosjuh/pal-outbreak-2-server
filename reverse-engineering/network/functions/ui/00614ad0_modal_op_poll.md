# 0x00614ad0 modal_op_poll

| field | value |
|---|---|
| Original address | 0x00614ad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614ad0 |
| Resolved name | modal_text_dialog_poll |
| Subsystem | ui |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_00634ab0 (dialog step/state), FUN_00637180 (dialog teardown/close)
**Referenced globals:** iRam0070d1c0 (+0x54 target ptr, +0x58 edit buffer); uRam0070d1c8 (busy/pending flag); uRam003433b8, uRam003433b0 (input state args)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d1c8, iRam0070d1c0+0x54, iRam0070d1c0+0x58

## Behavioral explanation
Per-frame poll for the modal text dialog opened by `modal_text_dialog_begin` (0x006149f0). It advances
the dialog state machine (`FUN_00634ab0`) over the edit buffer (`+0x58`), passing two shared input-state
globals, then acts on the tri-state result: **cancel/error (-1)** → close the dialog, report done;
**confirm (1)** → close the dialog and copy the edited text back to the caller's target pointer
(`*(+0x54)`), report done; **pending (0)** → set the busy flag and report not-done. Returns 1 when the
dialog has finished (either way), 0 while it is still open.

## Input / output
- (no parameters)
- **returns** `undefined4`: `1` = dialog finished (closed), `0` = still pending / open.

## Side effects
- Confirm path: `strcpy(*(ui+0x54), ui+0x58)` — writes the edited text back into the caller's buffer.
- Pending path: `uRam0070d1c8 = 1` — raises the busy/pending flag (cleared elsewhere by
  `clear_busy_flag_0x70d1c8` @ 0x00614b80).
- Both terminal paths call `FUN_00637180()` — tears down / closes the dialog widget.

## Important branches
- `FUN_00634ab0(...) == -1` → close (`FUN_00637180`), `return 1` (cancelled/error, no write-back).
- `== 1` → close, `strcpy(target, editbuf)`, `return 1` (confirmed).
- `== 0` → `uRam0070d1c8 = 1`, `return 0` (still editing).
- else (any other value) → `return 0` (defensive; no state change).

## Constants & flags
- Dialog step result `-1` = cancel/error, `1` = confirm, `0` = pending (signed `char` return of `FUN_00634ab0`).
- `uRam0070d1c8` — modal busy/pending flag (1 while a dialog is open and awaiting input).

## Corrected reconstruction
```c
enum dlg_step { DLG_CANCEL = -1, DLG_PENDING = 0, DLG_CONFIRM = 1 };

// returns 1 when the dialog has closed (cancel or confirm), 0 while still open.
uint32_t modal_text_dialog_poll(void)
{
    struct overlay_ui_state *ui = (struct overlay_ui_state *)g_overlay_ui; // iRam0070d1c0
    char *editbuf = (char *)(ui + 0x58);

    char r = dialog_step(editbuf, g_input_state_b8, g_input_state_b0);  // FUN_00634ab0

    if (r == DLG_CANCEL) {
        dialog_close();                       // FUN_00637180
        return 1;
    } else if (r == DLG_CONFIRM) {
        dialog_close();                       // FUN_00637180
        strcpy((char *)ui->modal_target,      // *(ui+0x54)
               editbuf);                      //  ui+0x58 -> caller buffer
        return 1;
    } else if (r == DLG_PENDING) {
        g_modal_busy = 1;                     // uRam0070d1c8
        return 0;
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00614ad0.c` (size 164, 1 caller, callees 00634ab0/00637180).
- Tri-state `-1/1/0` handling, the confirm-path `strcpy(*(ui+0x54), ui+0x58)`, the busy-flag set, and
  the `FUN_00637180` close calls are all exact. Pairing with `modal_op_begin` (same `+0x54`/`+0x58`
  fields) confirms the write-back semantics.

## Remaining uncertainty
The roles of `uRam003433b8`/`uRam003433b0` (pad/button state vs cursor caret) and the internal state
machine of `FUN_00634ab0` are runtime-unvalidated. The busy flag's consumers beyond `0x00614b80` are
not enumerated here. Behavior contract (done vs pending, write-back on confirm) is unambiguous.
