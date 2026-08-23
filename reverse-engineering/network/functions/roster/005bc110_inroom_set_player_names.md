# 0x005bc110 inroom_set_player_names

| field | value |
|---|---|
| Original address | 0x005bc110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc110 |
| Resolved name | inroom_set_player_names |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6fffad (per-player name field A, stride 0x114); 0x6fffbd (per-player name field B)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1

## Behavioral explanation
Sub-event 6: when in-room, copies two 0x10-byte name/id strings into the per-player table at 0x6fffad/0x6fffbd indexed by player-slot (payload+4, stride 0x114).

## Notes / uncertainty
Case 6: gated on unlock_gate 0x6ff2b1; copies two 16-byte name fields (payload+6,+0x16) into 0x6fffad/0x6fffbd[slot*0x114]. These are the exact source tables read by roster_download_sm_tick. field A/B render meaning uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
