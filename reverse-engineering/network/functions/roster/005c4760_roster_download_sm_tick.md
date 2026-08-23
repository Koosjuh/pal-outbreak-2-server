# 0x005c4760 roster_download_sm_tick

| field | value |
|---|---|
| Original address | 0x005c4760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4760 |
| Resolved name | roster_download_sm_tick |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x6cbaa0/a4/a5 (SM state/busy/reply); 0x6ff2b0 (own flag); 0x6ff2b3/b4 (room key bytes); 0x6fffad (source member table, stride 0x114); 0x6fb86c/0x6fb890/0x6fb9b8 (dest roster, stride 0x150); 0x6cba8c (timeout counter); 0x6cba84 (callback)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbaa4; cRam006cbaa0; cRam006ff2b0; cRam006ff2af

## Behavioral explanation
Roster-fill state machine (0x6cbaa0, states 0-7): when the room is owned (0x6ff2b0) it stages the 4 player records (copying id/name/0xf0-blob from the 0x114-stride source at 0x6fffad into the 0x150-stride roster at 0x6fb86c) and issues the fetch via 0x1de648; otherwise polls/times out; on done fires callback pcRam006cba84.

## Notes / uncertainty
Final render hop: 8-state SM stages 4-player roster from 0x6fffad/bd/d1 (stride 0x114, written by inroom_set_player_names) into render roster 0x6fb86c/... (stride 0x150) + cur/max header, gated on host_flag 0x6ff2b0; sends via 0x1de648 cb 0x5c4720; fires completion cb. Directly relevant to 1/0p-creator-only. 0x6ff2af peer-ready gate and cb 0x5c4720 inferred/untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
