# 0x005c6500 room_roster_sync_sm

| field | value |
|---|---|
| Original address | 0x005c6500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6500 |
| Resolved name | room_roster_sync_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c28f0, FUN_005c5120, FUN_005c5bb0, FUN_005c5cd0, FUN_005c5d30, FUN_005c5db0, FUN_005c5e30, FUN_005c5eb0, FUN_005c6360
**Referenced globals:** 0x6cbb90 sm-phase; 0x6cbb94 sm-active; 0x6ff2b3 member-count; 0x6ff2b5 accept-flags; 0x6ff70d member-tbl; 0x6cbb7c timeout; 0x6cbb74 done-cb
**Referenced strings:** —
**Referenced opcodes:** 0x03, 0x05, 0x06, 0x07, 0x08, 0x09
**State vars:** cRam006cbb90 phase; cRam006cbb94 active; bRam006ff2b3 member-count; iRam006cbb7c wait-timer

## Behavioral explanation
Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.

## Notes / uncertainty
CORE create/enter roster pump. 14-phase SM: build/announce -> wait accepts (0x6ff2b5) w/ 900-tick timeout -> assign player#/reject -> peer-entry + char-stats cross-sync (>=2) -> publish display arrays -> done-cb. Phase-5 accept gate = host-1/0p crux. Callee opcodes (5bb0/5cd0/5d30/5db0/5e30/5eb0) inferred (op03/06/07/08/09/0a-class), bodies not decompiled; phase 1->4 driver external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
