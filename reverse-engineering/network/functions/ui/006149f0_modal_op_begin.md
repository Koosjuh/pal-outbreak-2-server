# 0x006149f0 modal_op_begin

| field | value |
|---|---|
| Original address | 0x006149f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006149f0 |
| Resolved name | modal_text_dialog_begin |
| Subsystem | ui |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_006345e0 (dialog dispatch), FUN_006371d0 (place/animate dialog widget)
**Referenced globals:** iRam0070d1c0 (overlay UI state; +0x54 target ptr, +0x58 edit buffer[0x200])
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x54, iRam0070d1c0+0x58

## Behavioral explanation
Opens a modal text dialog (message box / on-screen soft-keyboard editor). It clears a 512-byte edit
buffer inside the overlay UI state (`+0x58`), records the caller's target pointer (`+0x54`), seeds the
edit buffer with the initial/prompt text (`strcpy` from `param_2`), positions/animates the dialog widget
via `FUN_006371d0(66.0f, 300)`, and dispatches one of three dialog variants (action code 8, 9, or 10)
selected by `param_1`. The companion `modal_op_poll` (0x00614ad0) later drives it to completion and, on
confirm, copies the edited buffer back to the target pointer stored at `+0x54`.

## Input / output
- `param_1` (`int`): dialog variant selector: `0`→code 8, `1`→code 9, `2`→code 10.
- `param_2` (`char*`, passed as `undefined8`): in/out text buffer — supplies the initial text and is the
  target the poll writes the result back into (stored at `+0x54`).
- **returns** void.

## Side effects
- `memset(ui+0x58, 0, 0x200)` — clears the 512-byte working edit buffer.
- `*(ui+0x54) = param_2` — stores the result target pointer.
- `strcpy(ui+0x58, param_2)` — seeds the buffer with the current/prompt text.
- `FUN_006371d0(66.0f, 300)` — places/animates the dialog widget (float `0x42840000` = `66.0`, `300` =
  duration/frames or timeout).
- `FUN_006345e0(0, code, 0xff, param_2)` — dispatches the dialog with the selected action code.

## Important branches
- `param_1 == 2` → `FUN_006345e0(0, 10, 0xff, msg)`.
- `param_1 == 1` → `FUN_006345e0(0, 9, 0xff, msg)`.
- `param_1 == 0` → `FUN_006345e0(0, 8, 0xff, msg)`.
- (no default; any other value dispatches nothing.)

## Constants & flags
- `0x200` (512) — edit buffer size at `+0x58`.
- `0x42840000` — IEEE-754 float `66.0` (dialog Y position or scale) passed to `FUN_006371d0`.
- `300` — duration / timeout for the widget animation.
- `8 / 9 / 10` — dialog action variants (e.g. info / confirm / keyboard); exact meaning unconfirmed.
- `0xff` — full alpha / max param passed to the dispatcher.

## Corrected reconstruction
```c
enum modal_variant { MODAL_V0 = 0, MODAL_V1 = 1, MODAL_V2 = 2 };
// dispatch action codes (FUN_006345e0 arg2): 8 for V0, 9 for V1, 10 for V2
#define DLG_ACTION_BASE 8

void modal_text_dialog_begin(int variant, char *text_inout)
{
    struct overlay_ui_state *ui = (struct overlay_ui_state *)g_overlay_ui; // iRam0070d1c0
    char *editbuf = (char *)(ui + 0x58);

    memset(editbuf, 0, 0x200);          // func_0x00106b60
    ui->modal_target = (int)text_inout; // +0x54
    strcpy(editbuf, text_inout);        // func_0x00109eb8 seed with current text

    place_dialog_widget(66.0f, 300);    // FUN_006371d0

    if (variant == MODAL_V2)      dialog_dispatch(0, 10, 0xff, text_inout); // FUN_006345e0
    else if (variant == MODAL_V1) dialog_dispatch(0,  9, 0xff, text_inout);
    else if (variant == MODAL_V0) dialog_dispatch(0,  8, 0xff, text_inout);
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_006149f0.c` (size 224, 1 caller, callees 006345e0/006371d0).
- `memset` size `0x200`, `+0x54`/`+0x58` writes, the `66.0f`/`300` args, and the 8/9/10 branch mapping
  are exact from the decompile. The in/out-buffer role of `param_2` is corroborated by `modal_op_poll`
  copying `ui+0x58` back to `*(ui+0x54)` on confirm.

## Remaining uncertainty
The concrete semantics of dialog codes 8/9/10 (message vs confirm vs soft-keyboard) and whether
`FUN_006371d0`'s `66.0f` is a Y coordinate or scale are runtime-unvalidated. Confidence Medium pending
a trace or decode of `FUN_006345e0`/`FUN_006371d0`.
