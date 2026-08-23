# 0x005fb010 screen_advance_or_error

| field | value |
|---|---|
| Original address | 0x005fb010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb010 |
| Resolved name | screen_advance_or_error |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005fb670 (connection/link guard)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** screen_obj+0xf (page/step), screen_obj+0x10 (substate)

## Behavioral explanation
A one-step screen/page advance gated by the connection guard `FUN_005fb670`. If the guard
reports the link is still healthy (returns 0), it advances the page counter `+0xf` by one and
resets the substate `+0x10` to 0 (entering the next screen from its first substate). If the
guard reports a fault (nonzero), it forces the page to **4** (the error/disconnect screen) and
resets the substate. This is one handler in the screen state machine that runs `FUN_005fa0b0`
drives; the `+0x10=0` on every path means each page transition always begins at substate 0.

## Input / output
- `param_1` (ptr): screen object. Reads/writes `+0xf` (page) and `+0x10` (substate).
- `void` return.

## Side effects
- Healthy: `+0xf += 1`, `+0x10 = 0`.
- Fault: `+0xf = 4`, `+0x10 = 0`.

## Important branches
- `FUN_005fb670() == 0` (link OK) → advance page (`+0xf`++), reset substate.
- `FUN_005fb670() != 0` (link fault/disconnect) → jump to error page `+0xf = 4`, reset substate.

## Constants & flags
- Page `4` = error/disconnect screen (the forced-fault target).
- Guard `FUN_005fb670`: `0` = connected/OK, nonzero = fault.

## Corrected reconstruction
```c
enum { SCREEN_PAGE_ERROR = 4 };

void screen_advance_or_error(screen_obj_t *s)
{
    if (link_guard() == 0) {            // FUN_005fb670: 0 = OK
        s->page /* +0xf */ += 1;        // next screen
    } else {
        s->page = SCREEN_PAGE_ERROR;    // 4: disconnect/error
    }
    s->substate /* +0x10 */ = 0;        // always restart substate
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005fb010.c` — guard call, if/else on result,
  `+0xf` increment vs `=4`, `+0x10 = 0` on both paths.
- Caller `FUN_005fa0b0` is a screen-SM pump. Runtime-unvalidated.

## Remaining uncertainty
- What `FUN_005fb670` actually checks (socket state vs a session flag).
- The full page-number map (only page 4 = error is established here).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb010.c`  — untouched decompiler output.
