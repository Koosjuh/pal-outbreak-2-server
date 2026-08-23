# 0x00617870 modeB_state0_enter

| field | value |
|---|---|
| Original address | 0x00617870 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617870 |
| Resolved name | modeB_state0_enter |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006177d0
**Callees:** FUN_005af300, FUN_005b24c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe major-state

## Behavioral explanation
type-0x0b scene state-0: advances major state and kicks UI/sound (FUN_005b24c0, FUN_005af300).

## Notes / uncertainty
ENTER: bump state, UI setup FUN_005b24c0, sfx FUN_005af300(0,1). Trivial; callee semantics inferred from arg shape.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617870.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
