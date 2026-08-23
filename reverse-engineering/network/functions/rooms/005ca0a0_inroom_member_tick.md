# 0x005ca0a0 inroom_member_tick

| field | value |
|---|---|
| Original address | 0x005ca0a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca0a0 |
| Resolved name | inroom_member_tick |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005cd1d0, FUN_005d0a40, FUN_005d5c20
**Referenced globals:** 0x701070+0x2e sub-state; 0x701070+0x38 timer; 0x701070+0x18 pad; 0x701068+0x4f8a4 buttons; 0x701068+0x68e85 phase; 0x701068+0x68e84 sub-phase
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** 0x701070+0x2e; 0x701068+0x68e85; 0x701068+0x68e84; 0x701070+0x34

## Behavioral explanation
State-8 (in-room) tick: on pad+phase==1 sends op06 and advances to state 9, otherwise runs the roster-fill pass (FUN_005cce30) and the room timeout tick (FUN_005cd1d0).

## Notes / uncertainty
In-room (kind 8) tick: sends op06 on confirm when phase 0x68e85==1 && 0x68e84==2, else runs roster-fill poll (FUN_005cce30, -1=complete) + timeout tick. Roster-fill internals not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca0a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
