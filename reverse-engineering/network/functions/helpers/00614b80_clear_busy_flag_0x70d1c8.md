# 0x00614b80 clear_busy_flag_0x70d1c8

| field | value |
|---|---|
| Original address | 0x00614b80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614b80 |
| Resolved name | clear_modal_busy_flag |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** uRam0070d1c8 (modal busy/pending flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d1c8

## Behavioral explanation
Clears the modal busy/pending flag `uRam0070d1c8` to 0. It is the reset counterpart to
`modal_text_dialog_poll` (0x00614ad0), which sets the flag to 1 while a dialog is awaiting input.
Called from the overlay entry `FUN_0060f910` to reset dialog state (e.g. on screen enter/re-enter).

## Input / output
- (no parameters)
- **returns** void.

## Side effects
- `uRam0070d1c8 = 0`.

## Important branches
None.

## Constants & flags
- `uRam0070d1c8` — modal busy flag (0 = idle, 1 = a modal dialog is open/pending).

## Corrected reconstruction
```c
void clear_modal_busy_flag(void)
{
    g_modal_busy = 0;   // uRam0070d1c8
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00614b80.c` (size 12, 1 caller).
- Single store `uRam0070d1c8 = 0` is exact. Flag identity confirmed by the set-site in
  `modal_op_poll` (0x00614ad0).

## Remaining uncertainty
None of consequence. The full set of readers of `uRam0070d1c8` is not exhaustively enumerated, but the
flag's meaning (modal busy) is established by its set/clear sites.
