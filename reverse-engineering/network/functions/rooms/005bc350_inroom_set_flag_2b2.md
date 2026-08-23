# 0x005bc350 inroom_evt0f_set_state_6ff2b2

| field | value |
|---|---|
| Original address | 0x005bc350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc350 |
| Resolved name | inroom_evt0f_set_state_6ff2b2 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room dispatcher, sub-event case 0x0f)
**Callees:** —
**Referenced globals:** 0x6ff2b2 (in-room/scenario state byte)
**Referenced strings:** —
**Referenced opcodes:** in-room sub-event 0x0f
**State vars:** uRam006ff2b2

## Behavioral explanation
Handler for in-room **sub-event 0x0f**. Unconditionally writes 3 into the in-room state byte
0x6ff2b2. This byte lives in the in-room state cluster right after host_flag(0x6ff2b0)/
unlock_gate(0x6ff2b1) (lobby_state_block); value 3 is a phase/state marker set on this event
(candidate: scenario/cast-selection stage — cf. the 0x6ff2b1 1→3 unlock note in G12). No payload
consumed.

## Input / output
- Input: dispatcher handle (ignored). Output: `void`.

## Side effects
- `*(u8*)0x6ff2b2 = 3`.

## Important branches
None (single store).

## Constants & flags
- 0x6ff2b2 ← 3 (in-room/scenario state phase).

## Corrected reconstruction
```c
// Dispatched by inroom_game_dispatch case 0x0f.
void inroom_evt0f_set_state_6ff2b2(u32 ctx /*unused*/) {
    *(u8*)0x6ff2b2 = 3;                 // uRam006ff2b2 — in-room state phase
}
```

## Evidence
- `FUN_005bc350.c`: `uRam006ff2b2 = 3;`
- `FUN_005bba20.c`: `case 0xf: FUN_005bc350(*(undefined4*)(param_1+8));`
- Cluster: structure-layouts/lobby_state_block.md (0x6ff2b0/b1 neighbours).
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc350.c`  — untouched decompiler output.

## Remaining uncertainty
Exact meaning of state value 3 for 0x6ff2b2 (which room/scenario phase) not confirmed; relation to
the 0x6ff2b1 unlock gate is inferred from adjacency, not proven.
