# 0x00637250 kbd_clear_flag31

| field | value |
|---|---|
| Original address | 0x00637250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637250 |
| Resolved name | kbd_clear_dismiss_request |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00637180 (kbd_close_if_flagged)
**Callees:** —
**Referenced globals:** 0x715da8 (soft-keyboard widget state base pointer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x31 dismiss-request flag

## Behavioral explanation
Disarms the deferred-dismiss request: `kbd+0x31 = 0`. Called by kbd_close_if_flagged (637180) to consume the request just before teardown, and by the layout/open path (006345e0) to clear any stale request when (re)initializing the keyboard. Inverse of kbd_request_dismiss (637230).

## Input / output
- Params: none.
- Returns: void.

## Side effects
- `kbd->dismiss_req(+0x31) = 0;`.

## Important branches
- None.

## Constants & flags
- +0x31: 0=idle here.

## Corrected reconstruction
```c
void kbd_clear_dismiss_request(void)
{
    KbdState *kbd = *(KbdState **)0x715da8;
    kbd->dismiss_req /*+0x31*/ = 0;
}
```

## Evidence
- Raw decompile FUN_00637250.c line 9.
- Consumed inside 637180 reconstruction; inverse of 637230.

## Remaining uncertainty
- None material; trivial setter.
