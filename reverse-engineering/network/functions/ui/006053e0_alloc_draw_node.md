# 0x006053e0 alloc_draw_node

| field | value |
|---|---|
| Original address | 0x006053e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006053e0 |
| Resolved name | alloc_draw_node |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00605430
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a UI draw node from pool FUN_00618ba0, initialising it with element id (+0x22), enabled flags, and default fields; returns node ptr or 0.

## Notes / uncertainty
Display-list node factory over FUN_00618ba0; sets active/enabled/elem_id(+0x22)/field30. draw_node field map inferred from callers/callbacks, not runtime-validated. Meaning of node+0x30 (=1) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006053e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
