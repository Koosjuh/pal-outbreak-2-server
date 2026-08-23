# 0x00617980 modeB_state3_exit_tick

| field | value |
|---|---|
| Original address | 0x00617980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617980 |
| Resolved name | modeB_state3_exit_tick |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006177d0
**Callees:** FUN_00618b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x16 countdown; +0xe major-state

## Behavioral explanation
type-0x0b scene state-3: countdown on +0x16; at zero advances state and calls FUN_00618b60.

## Notes / uncertainty
EXIT: countdown obj+0x16; at 0 advance + FUN_00618b60 teardown. File also holds the two thunk_FUN_00617a00 trampolines. Trivial.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
