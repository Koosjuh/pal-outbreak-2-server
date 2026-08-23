# 0x00604180 member_sync_state_machine

| field | value |
|---|---|
| Original address | 0x00604180 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604180 |
| Resolved name | member_sync_state_machine |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603e40
**Callees:** FUN_005af3c0, FUN_005af3e0, FUN_005af400, FUN_005b09b0, FUN_005b1190, FUN_005b14b0, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_00604940, FUN_006049b0, FUN_00604a80, FUN_0061ded0, FUN_006278e0
**Referenced globals:** 0x70b4d0 (member status); 0x70b4b0/0x70b4c0 (roster); 0x694700 (member pool); ctx+0x900/0x901 (major/minor state); ctx+0x905/0x907/0x908/0x909; ctx+0x914 (free count); ctx+0x918 (step timer); ctx+0x43c/0x43f/0x45a (flags)
**Referenced strings:** —
**Referenced opcodes:** 0x0c
**State vars:** ctx+0x900; ctx+0x901; ctx+0x918

## Behavioral explanation
Large 6-case (0x900 selector) member add/remove/sync engine: manages join/leave transactions against the roster status table (0x70b4d0) and pool 0x694700, driving reliable sends (005b8cf0/005b9110/005b8da0) with per-step countdown timers (ctx+0x918) and playing UI feedback (0x1b0140).

## Notes / uncertainty
6-state member add/remove/sync engine; state 2 = pool commit via roster_insert_or_find/pool_remove (mode 0x0c), states 1/3/4 drive reliable sends+timers. THE create-registration commit path (prime failure suspect). Some state-3 minor-substate ordering is decompiler-flattened/inferred; FUN_00604940 return codes and send msg-ids->wire-ops inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
