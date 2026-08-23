# 0x005f9150 join_room_router

| field | value |
|---|---|
| Original address | 0x005f9150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9150 |
| Resolved name | join_room_router |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8e20
**Callees:** FUN_005f91f0, FUN_005f9280, FUN_005f9540, FUN_005f97c0, FUN_005f99c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xf (join step)

## Behavioral explanation
Routes the join-room flow on +0xf (0-4) to FUN_005f91f0/9280/9540/97c0/99c0 (send enter -> receive detail -> char select -> confirm -> submit).

## Notes / uncertainty
Routes screen_major(+0xf) 0..4 through enter pipeline (send->await->char-select->confirm->submit). Per-step wire opcode mapping inferred from flow, not confirmed in these bytes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
