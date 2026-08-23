# 0x005e82b0 message_render_phase_reset

| field | value |
|---|---|
| Original address | 0x005e82b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e82b0 |
| Resolved name | message_render_phase_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005de110 (message-box open/close)
**Callees:** —
**Referenced globals:** uRam007012a8 / cRam007012a8 (message-render phase byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007012a8 (render phase 0-4)

## Behavioral explanation
One-line reset: sets the message-render phase byte `cRam007012a8` (aliased `uRam007012a8`)
to 0, forcing the phase machine in FUN_005e7e30 to restart at phase 0 (re-init the context
and re-measure) on its next call. Called by FUN_005de110 when a message box is (re)opened or
dismissed so the next message renders from scratch rather than resuming a stale pass.

## Input / output
- Input: none (`void`).
- Output: none. Single global write.

## Side effects
- `cRam007012a8 = 0` (message-render phase). Nothing else.

## Important branches
- None.

## Constants & flags
- Phase `0` = "init" state of the FUN_005e7e30 state machine.

## Corrected reconstruction
```c
// Force the message-box renderer back to phase 0 (fresh init) on next tick.
void message_render_phase_reset(void)
{
    g_msgPhase /*cRam007012a8*/ = 0;
}
```

## Evidence
- Raw decompile: `uRam007012a8 = 0; return;` (12-byte body, no callees).
- `cRam007012a8` is the same phase byte driven by FUN_005e7e30 and its reset semantics follow
  directly. Runtime-unvalidated.

## Remaining uncertainty
- None material — the write and its consumer are unambiguous. Only the caller's exact trigger
  (open vs close) is not pinned, but both reduce to "restart the renderer".

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e82b0.c`  — untouched decompiler output.
