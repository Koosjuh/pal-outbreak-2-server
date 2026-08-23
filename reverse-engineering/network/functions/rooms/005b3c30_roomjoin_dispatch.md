# 0x005b3c30 roomjoin_dispatch

| field | value |
|---|---|
| Original address | 0x005b3c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3c30 |
| Resolved name | roomjoin_dispatch |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070
**Callees:** FUN_005b3cb0, FUN_005b3d80, FUN_005b3ed0, FUN_005b41b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x900 join phase

## Behavioral explanation
Room enter/create sub-dispatcher: switches on +0x900 (0-3) to the four join/create phase handlers; returns -1 on invalid.

## Notes / uncertainty
Phase dispatcher on join-widget byte obj+0x900: 0 open-list / 1 pick / 2 enter / 3 create(FUN_005b41b0); default -1. Returns handler result (1=commit). state1/2 called register-passed (args inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
