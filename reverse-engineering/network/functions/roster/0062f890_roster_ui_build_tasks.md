# 0x0062f890 roster_ui_build_tasks

| field | value |
|---|---|
| Original address | 0x0062f890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f890 |
| Resolved name | roster_ui_build_tasks |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062e5b0
**Callees:** FUN_00618ba0
**Referenced globals:** 0x6c5c45 built-once guard; 0x66af68/6a/78 layout tables
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c5c45 init guard

## Behavioral explanation
One-shot (guard cRam006c5c45) builder of player-slot UI: 3 FUN_0062f990 tasks and 2 FUN_0062fa80 tasks, positioned from tables 0x66af68/6a and 0x66af78.

## Notes / uncertainty
One-shot (guard 0x6c5c45) builder of 5 UI task nodes (3x handler 0x62f990 player rows + 2x 0x62fa80) positioned from 0x66af68/6a/78 tables; early-return on alloc fail leaves guard set. Handler roles + layout-table meaning inferred. No runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
