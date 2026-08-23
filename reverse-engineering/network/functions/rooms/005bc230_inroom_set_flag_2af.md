# 0x005bc230 inroom_evt08_set_flag_6ff2af

| field | value |
|---|---|
| Original address | 0x005bc230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc230 |
| Resolved name | inroom_evt08_set_flag_6ff2af |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room game-message dispatcher, sub-event case 8)
**Callees:** —
**Referenced globals:** 0x6ff2af (in-room one-shot flag)
**Referenced strings:** —
**Referenced opcodes:** in-room sub-event 0x08 (dispatcher selector `msg[+8]`)
**State vars:** uRam006ff2af

## Behavioral explanation
Handler for in-room game-message **sub-event 8** (dispatched by `FUN_005bba20` on `msg[+8]==8`).
It unconditionally sets the one-shot in-room flag at 0x6ff2af to 1. 0x6ff2af sits in the in-room
state cluster (adjacent to 0x6ff2b0 host_flag / 0x6ff2b1 unlock_gate / 0x6ff2b2 in
lobby_state_block), so this marks a room-phase event has occurred. No payload is consumed
(the `param_1` handle argument is ignored).

## Input / output
- Input: `undefined8 param_1` — dispatcher-supplied context handle (`*(u32*)(param_1_dispatch+8)`),
  unused here.
- Output: `void`.

## Side effects
- `*(u8*)0x6ff2af = 1`.

## Important branches
None (single store).

## Constants & flags
- 0x6ff2af — in-room state byte, set to 1 (one-shot marker). Cleared elsewhere.

## Corrected reconstruction
```c
// Dispatched by inroom_game_dispatch (FUN_005bba20) case 8.
void inroom_evt08_set_flag_6ff2af(u32 ctx /*unused*/) {
    *(u8*)0x6ff2af = 1;                 // uRam006ff2af — in-room one-shot flag
}
```

## Evidence
- `FUN_005bc230.c`: `uRam006ff2af = 1;`
- `FUN_005bba20.c`: `case 8: FUN_005bc230(*(undefined4*)(param_1+8));` (selector = `*(u8*)(param_2+8)`).
- Flag cluster: structure-layouts/lobby_state_block.md (0x6ff2b0/b1/b2 neighbours).
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc230.c`  — untouched decompiler output.

## Remaining uncertainty
Semantic role of 0x6ff2af (which room-phase transition it gates) and its clear site are not
confirmed from this handler alone.
