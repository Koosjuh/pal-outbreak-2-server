# 0x0062e2a0 lobby_state4_exit_cleanup

| field | value |
|---|---|
| Original address | 0x0062e2a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e2a0 |
| Resolved name | lobby_exit_teardown_sm |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950 (major-state-2/exit dispatcher)
**Callees:** FUN_00637180 (net/session teardown), FUN_005b8cf0 (screen transition, code 0xae), FUN_005b14b0 (async-completion / fade query, tag 0x210), FUN_005b9110 (free UI resource 0x4c), FUN_00617a00 (reset lobby_state_block)
**Referenced globals:** 0x6c4b90(lobby_state_block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state+0x10(exit step 0..4); state+0x16(frame countdown)

## Behavioral explanation
A small **linear teardown state machine** that runs the lobby-exit sequence over several frames.
The controlling struct's `step` byte (`+0x10`) advances 0→1→2→3→4, with `countdown` (`+0x16`) pacing
the timed waits. Per tick:
- **step 0** — kick off teardown: `FUN_00637180()` (session/net teardown) and
  `FUN_005b8cf0(0xae)` (request the outgoing screen transition, signed byte -0x52 = 0xae); advance.
- **step 1** — arm a short wait: `step = 2`, `countdown = 8` frames.
- **step 2** — decrement `countdown`; when it goes negative, advance and re-arm a long wait
  (`countdown = 0x708` = 1800 frames).
- **step 3** — decrement `countdown`; advance when it expires **or** when `FUN_005b14b0(0x210)`
  returns non-zero (the transition/fade for tag 0x210 completed) — i.e. wait-with-timeout.
- **step 4** — finalize: `FUN_005b9110(0x4c)` frees the UI resource and `FUN_00617a00(0x6c4b90)`
  resets the master `lobby_state_block`. Terminal (no further advance).

## Input / output
- `param_1` (`lobby_exit_ctx *`) — teardown context: `+0x10` step, `+0x16` countdown.
- Returns void.

## Side effects
- Mutates `step` (+0x10) and `countdown` (+0x16).
- step 0: session teardown + screen-transition request (0xae).
- step 4: frees UI resource 0x4c and memset/reset of `lobby_state_block` (0x6c4b90).

## Important branches
- `step == 4` → free UI 0x4c + reset lobby block; **terminal**.
- `step == 3` → `countdown--`; advance if `countdown < 0` **or** `FUN_005b14b0(0x210) != 0`.
- `step == 2` → `countdown--`; if `countdown < 0` → advance, set `countdown = 0x708`.
- `step == 1` → `step = 2`, `countdown = 8`.
- `step == 0` → teardown + transition, advance.

## Constants & flags
- `8` — short wait (step 1→2).
- `0x708` (1800) — long wait armed at step 2.
- `0x210` — completion tag polled by `FUN_005b14b0` at step 3.
- `0xae` (as signed -0x52) — screen-transition code to `FUN_005b8cf0`.
- `0x4c` — UI resource id freed at step 4.

## Corrected reconstruction
```c
// Timed lobby-exit teardown. step @+0x10, countdown @+0x16.
typedef struct { u8 pad[0x10]; u8 step; u8 _p[5]; s16 countdown; } lobby_exit_ctx; // +0x10 step, +0x16 cd

void lobby_exit_teardown_sm(lobby_exit_ctx *c) {
    switch (c->step) {
    case 4:                                             // finalize (terminal)
        ui_free_resource(0x4c);                          // FUN_005b9110
        lobby_state_block_reset((void*)0x6c4b90);        // FUN_00617a00
        break;
    case 3:                                             // wait for fade/txn 0x210 or timeout
        if (--c->countdown < 0 || async_query(0x210) != 0) // FUN_005b14b0
            c->step++;
        break;
    case 2:                                             // wait, then arm long wait
        if (--c->countdown < 0) { c->step++; c->countdown = 0x708; }
        break;
    case 1:                                             // arm short wait
        c->step = 2; c->countdown = 8;
        break;
    case 0:                                             // begin teardown
        session_teardown();                              // FUN_00637180
        request_screen_transition(0xae);                 // FUN_005b8cf0(-0x52)
        c->step++;
        break;
    }
}
```

## Evidence
- Raw dispatch on `*(char*)(param_1+0x10)` with cases 4/3/2/1/0 exactly as above; countdown at `*(short*)(param_1+0x16)`.
- step 4 calls `FUN_005b9110(0x4c)` + `FUN_00617a00(0x6c4b90)` (0x6c4b90 = lobby_state_block base per structure-layouts).
- step 3 gate `FUN_005b14b0(0x210) != 0` OR countdown<0 (wait-with-timeout).
- Caller FUN_0062d950 selects this as the exit branch.
- Runtime-unvalidated.

## Remaining uncertainty
- The exact roles of `FUN_00637180` (session vs. render teardown), `FUN_005b8cf0(0xae)` (target screen id), and `FUN_005b14b0(0x210)` (fade vs. server-reply completion) are inferred from call shape, not decoded. Struct field padding around +0x10/+0x16 is nominal.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e2a0.c`  — untouched decompiler output.
