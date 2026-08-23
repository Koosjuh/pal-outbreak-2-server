# 0x005bebf0 construct_composite_object_slot

| field | value |
|---|---|
| Original address | 0x005bebf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bebf0 |
| Resolved name | construct_composite_object_slot |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005befa0
**Callees:** FUN_005be0a0, FUN_005bec80, FUN_005becf0, FUN_005bed60, FUN_005bedd0, FUN_005bee40, FUN_005bee90, FUN_005bef00
**Referenced globals:** 0x6ca97e slot handle-id; 0x7018d0 object registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a task slot then runs a 7-step object construction sequence (bec80/becf0/bed60/bedd0/bee40/bee90/bef00) and stamps the resulting id into the slot handle.

## Notes / uncertainty
Allocs registry slot via FUN_005be0a0(mode=1), runs 7 sub-builders, stamps handle-id (FUN_005bef00) at slot*0x20+0x6ca97e; returns -1 on alloc fail. Sub-builder field semantics + be0a0 mode arg inferred, not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bebf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
