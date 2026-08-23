# 0x00616d30 room_phase00_roster_unpack_tick

| field | value |
|---|---|
| Original address | 0x00616d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616d30 |
| Resolved name | room_phase00_roster_unpack_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005bac60, FUN_005bad10, FUN_005c45b0, FUN_005c4600, FUN_005c6210
**Referenced globals:** 0x7012b0 (host flag byte); 0x874fa0/0x874fd8/0x874fd9 (shared roster mirror)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state; +0x16 countdown; +0x990 player-count; +0x97e branch flag

## Behavioral explanation
Room phase-0 sub-state machine (minor +0xf 0..5): initializes up to 4 player sub-structs (0x3b0 stride), runs a countdown (+0x16), then on finalize copies each player's name/profile/select fields out of the +0x1f5c net buffer into the roster.

## Notes / uncertainty
Phase-0 SM (minor 0-5); state 5 commits received room snapshot into 4x0x3b0 roster rows (name+0x21dc/profile+0x21ec/stats(0xf0)+0x2200/charsel+0x22f0/select+0x2308) via FUN_005c4600 then repacks via FUN_005bad10. Count obj+0x990 unclamped vs 4 slots (overrun hypothesis, unobserved). Snapshot/status internals not fully decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
