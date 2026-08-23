# 0x0062e3c0 lobby_state3_dispatch

| field | value |
|---|---|
| Original address | 0x0062e3c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e3c0 |
| Resolved name | lobby_state3_substate_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d640 (major-state dispatcher)
**Callees:** FUN_0062e440 (sub 0), FUN_0062e5b0 (sub 1), FUN_0062e720 (sub 2), FUN_0062e800 (sub 3)
**Referenced globals:** — (operates on the caller-supplied state struct)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state+0xf(sub-state 0..3)

## Behavioral explanation
A thin **sub-state jump table** for lobby major-state 3 (the in-room / joined branch). It reads the
sub-state byte at `state+0xf` and tail-calls exactly one of four per-substate step functions. No
logic of its own — it exists to fan the per-frame tick out to the correct in-room phase handler:
0 = enter/join-flow step (`e440`), 1 = member/roster gate step (`e5b0`), 2 = leave step (`e720`),
3 = back/exit step (`e800`). Note it keys on `+0xf`, one byte before the `+0x10` step byte that the
sibling exit machine (0x62e2a0) uses — i.e. `+0xf` is the *major* sub-selector, `+0x10` a nested step.

## Input / output
- `param_1` (`lobby_state *`) — the lobby state struct; only `+0xf` is read.
- Returns void.

## Side effects
- None directly; delegates to the selected sub-handler (which mutate the struct / drive the UI).

## Important branches
- `state+0xf == 3` → `FUN_0062e800()` (back/exit).
- `== 2` → `FUN_0062e720()` (leave).
- `== 1` → `FUN_0062e5b0()` (member/roster gate).
- `== 0` → `FUN_0062e440()` (enter/join flow).
- (any other value → no-op)

## Constants & flags
- sub-state enum `{0:join_flow, 1:member_gate, 2:leave, 3:back_exit}` at `state+0xf`.

## Corrected reconstruction
```c
// Major-state-3 (in-room) per-frame sub-dispatch on state+0xf.
enum { INROOM_JOIN=0, INROOM_MEMBER_GATE=1, INROOM_LEAVE=2, INROOM_BACK=3 };

void lobby_state3_substate_dispatch(lobby_state *s) {
    switch (s->substate /*+0xf*/) {
    case INROOM_BACK:        FUN_0062e800(); break;   // back / exit
    case INROOM_LEAVE:       FUN_0062e720(); break;   // leave
    case INROOM_MEMBER_GATE: FUN_0062e5b0(); break;   // member / roster gate
    case INROOM_JOIN:        FUN_0062e440(); break;   // enter / join flow
    }
}
```

## Evidence
- Raw: `cVar1 = *(char*)(param_1+0xf); if (cVar1==3) FUN_0062e800(); else if (==2) FUN_0062e720(); else if (==1) FUN_0062e5b0(); else if (==0) FUN_0062e440();`.
- Caller FUN_0062d640 = the major-state dispatcher (this is its state-3 arm).
- Runtime-unvalidated; sub-handler roles inferred from the create/join SM ordering (join → member gate → leave/back).

## Remaining uncertainty
- The precise action of each sub-handler (e440/e5b0/e720/e800) is not decoded here; the labels (join/member/leave/back) are inferred from the conventional in-room SM order and should be confirmed by reading those four functions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e3c0.c`  — untouched decompiler output.
