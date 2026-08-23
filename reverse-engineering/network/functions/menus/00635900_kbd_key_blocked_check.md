# 0x00635900 kbd_key_blocked_check

| field | value |
|---|---|
| Original address | 0x00635900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635900 |
| Resolved name | kbd_key_blocked_check |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006352e0, FUN_006353e0
**Callees:** FUN_006379e0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x248 status

## Behavioral explanation
Wraps the key-allowed predicate (FUN_006379e0); on 'allowed' sets widget status 0x248=5 (reject) and returns whether NOT allowed.

## Notes / uncertainty
RENAMED (sense clarified): wraps FUN_006379e0 (1=blocked/full), sets status +0x248=5 on block, returns true=proceed. Underlying predicate (full vs disabled) not reconstructed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
