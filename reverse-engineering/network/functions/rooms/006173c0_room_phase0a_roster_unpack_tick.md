# 0x006173c0 room_phase0a_roster_unpack_tick

| field | value |
|---|---|
| Original address | 0x006173c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006173c0 |
| Resolved name | room_phase0a_roster_unpack_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005bac60, FUN_005bad10, FUN_005c45b0, FUN_005c4600, FUN_005c6210
**Referenced globals:** 0x7012b0 (host flag); 0x874fa0/0x874fd8/0x874fd9 (roster mirror)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state; +0x990 player-count; +0x97e branch flag

## Behavioral explanation
Room phase-0x0a variant of the setup/roster-unpack handler (minor +0xf 0..4): same per-player name/profile/select extraction from +0x1f5c into the roster, with a different entry table (0x6181b0).

## Notes / uncertainty
Twin of 0x616d30; commit in state 4 (not 5), roster table 0x6181b0 (vs 0x6181e0), no intro timer/SE. Likely the roster-refresh/re-entry path. Same count-clamp and snapshot-internals uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006173c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
