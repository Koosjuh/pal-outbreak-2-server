# 0x006052f0 prepare_ctx_state_machine

| field | value |
|---|---|
| Original address | 0x006052f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006052f0 |
| Resolved name | prepare_ctx_state_machine |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe620
**Callees:** FUN_005b14b0, FUN_00603d50, FUN_00603d70, FUN_00603d90, FUN_00605430
**Referenced globals:** ctx+0xe (phase)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0xe

## Behavioral explanation
Variant room-context driver: state0 builds the screen (FUN_00605430); state1 polls reliable-reply gates (FUN_005b14b0 across masks) and dispatches to finish handlers FUN_00603d90 (data present) or d70/d50 (param branch) — i.e. resolves a prepare/enter transaction outcome.

## Notes / uncertainty
Prepare/enter txn resolver (sibling of 00603e40 but polls L1 pools not member engine). phase0 builds screen; phase1: request pools 0x10/0x200 free & reply pool 0x400/0x800 busy -> SFX1 + late-reply d70(param2==0)/d50; else -> SFX2 + commit d90. Pool->op mapping and d70 vs d50 distinction inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006052f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
