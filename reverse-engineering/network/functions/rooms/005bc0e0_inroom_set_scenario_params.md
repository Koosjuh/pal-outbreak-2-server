# 0x005bc0e0 inroom_set_scenario_params

| field | value |
|---|---|
| Original address | 0x005bc0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc0e0 |
| Resolved name | inroom_set_player_counts |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (sub-selector 5)
**Callees:** —
**Referenced globals:** 0x6ff2b3 (in-room current players), 0x6ff2b4 (in-room max players); 0x6ff2b1 in-room gate
**Referenced strings:** —
**Referenced opcodes:** — (op0x13 sub-event 5; the in-room count push == op10 sub-5 pair)
**State vars:** cRam006ff2b1 gate

## Behavioral explanation
Sub-event **5** of the in-room dispatcher: the server pushes the room's **player counts**. Gated on the in-room flag `0x6ff2b1`, it copies two bytes from the message body into the in-room panel count fields: `body+4 → 0x6ff2b4` (max players) and `body+5 → 0x6ff2b3` (current players). These are exactly the `cur/max` fields the in-room header renders (lobby_state_block: `0x6ff2b3/0x6ff2b4 cur/max, op10 sub-5`). This is the push that should turn the host's own created room from "1/0p" into a real count — it only fires when the server sends a sub-5 event AND `0x6ff2b1` is already set, which ties the count display directly to the ownership-commit gate.

## Input / output
- `param_1` (u32): unused here (record pointer from the dispatcher).
- `param_2` (int): message body base. `+4` = max players, `+5` = current players.
- Returns `void`.

## Side effects
- `0x6ff2b4 = body+4` (max), `0x6ff2b3 = body+5` (current) — only when `0x6ff2b1 != 0`.

## Important branches
- **cRam006ff2b1 == 0** → no-op (not seated in a room / ownership not committed): counts stay at their default (1/0p).

## Constants & flags
- `0x6ff2b3` = current player count; `0x6ff2b4` = max player count (rendered by the in-room header).
- Gate `0x6ff2b1`: in-room ownership/unlock flag.

## Corrected reconstruction
```c
// op0x13 sub-event 5: in-room player-count push (cur/max)
void inroom_set_player_counts(uint32_t rec /*param_1, unused*/, int body /*param_2*/) {
    if (cRam006ff2b1 != 0) {                        // must be seated / committed
        uRam006ff2b3 = *(uint8_t *)(body + 5);      // current players
        uRam006ff2b4 = *(uint8_t *)(body + 4);      // max players
    }
}
```

## Evidence
- Raw decompile `FUN_005bc0e0.c`.
- `0x6ff2b3/0x6ff2b4 cur/max (op10 sub-5)` and gate `0x6ff2b1` from lobby_state_block.md.
- Directly relevant to the G12 "1/0p" create-room count blocker (MEMORY.md handoff).
- Runtime-unvalidated (no captured sub-5 count push confirming byte order cur vs max).

## Remaining uncertainty
- Byte assignment (`+5`=current, `+4`=max) follows the 0x6ff2b3/0x6ff2b4 field labels but is not wire-confirmed; a sub-5 capture would settle it.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc0e0.c`  — untouched decompiler output.
