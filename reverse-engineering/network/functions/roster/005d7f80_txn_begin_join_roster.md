# 0x005d7f80 txn_begin_join_roster

| field | value |
|---|---|
| Original address | 0x005d7f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7f80 |
| Resolved name | txn_begin_join_roster |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d80c0
**Callees:** FUN_005d7410, FUN_005d78d0, FUN_005d7cf0, FUN_005dedc0, FUN_005df340
**Referenced globals:** 0x00701020 buffer-index table; 0x00701000 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00701000; record+0x104 state

## Behavioral explanation
Processes a state-4 subtype-2 txn record via roster_lookup_or_insert; on accept allocates a send object with a 0x4000 buffer indexed by mode byte (0x701020 table) and fills its descriptor, reliability set when mode==5.

## Notes / uncertainty
Subtype-2 sibling of txn_begin_enter; arms a 0x4000-buffer send obj for op03 roster-sync when session node state==3, short-circuits to done on state==2, fails on lookup miss. Reliability arg from cRam00701000==5 inferred; buffer-class distinction 0x4000 vs 0x8000 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
