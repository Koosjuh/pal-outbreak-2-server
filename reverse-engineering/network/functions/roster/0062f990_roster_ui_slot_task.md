# 0x0062f990 roster_ui_slot_task

| field | value |
|---|---|
| Original address | 0x0062f990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f990 |
| Resolved name | roster_ui_slot_task |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20, FUN_0062fc20, FUN_0062fc40
**Referenced globals:** 0x6c4fd5 teardown flag; 0x6c4fd4 slot index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fd5 teardown

## Behavioral explanation
Player-slot UI task update: while cRam006c4fd5==0, on subtype 2 animates the slot (FUN_0062fc40) and positions it from bRam006c4fd4; destroys itself when 0x6c4fd5 set.

## Notes / uncertainty
Per-frame roster-slot widget task callback (one of 3 spawned by builder 0x0062f890). Runs a 3-state lifecycle (0 init -> 1 active, >1 dead/return) under teardown guard 0x6c4fd5; for mode(+3)==2 (animated highlight variant) it pulses alpha via fc40 and repositions to slot table 0x66af68/6a indexed by active-slot global 0x6c4fd4; teardown frees via 618c20. Pure client UI, no protocol. Uncertainty: field/mode names inferred, static-only (no runtime proof), non-2 mode semantics set externally by builder.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
