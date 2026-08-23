# 0x005bb4d0 member_join_op06_handler

| field | value |
|---|---|
| Original address | 0x005bb4d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb4d0 |
| Resolved name | member_join_op06_handler |
| Subsystem | roster |
| Relevance | unknown |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Confirmed |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005c50a0, FUN_005c7d00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
(pending)

## Notes / uncertainty
op06 member-JOIN: builds 0x114 scratch member entry (idstr/name/charstats), trims trailing '-' from name, fires event 0x1f ADD, bumps room count (clamp 4) via FUN_005bf1e0(2) room index, sets HUD scalars, fires event 0x19 refresh. Runtime-validated rig 2026-07-26. Event 0x19 terminal repaint still UNRESOLVED (outside overlay dump).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb4d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Confirmed**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
