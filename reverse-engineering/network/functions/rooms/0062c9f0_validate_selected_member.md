# 0x0062c9f0 validate_selected_member

| field | value |
|---|---|
| Original address | 0x0062c9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c9f0 |
| Resolved name | validate_selected_member |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c750
**Callees:** FUN_005bae30, FUN_005bafc0, FUN_005bb010
**Referenced globals:** +0x10b8 selected id; +0x8ec/+0x8ed name-out; 0x6c45f8 self id; 0x342f30/0x342f31/0x343571 status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00342f30; cRam00342f31; cRam00343571

## Behavioral explanation
Validates the selected id (+0x10b8) against globals: looks up type/status (FUN_005bafc0/5bb010/5bae30) and returns an action code 0..4, writing name fields +0x8ec/+0x8ed.

## Notes / uncertainty
Roster-action classifier returning code 0..4 from status-class (FUN_005bae30) x mode 0x343571; self-exclusion via 0x6c45f8. Nested ternary reproduced from raw; action-code semantics (kick/invite/promote) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
