# 0x00634880 reset_deadkey_state

| field | value |
|---|---|
| Original address | 0x00634880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634880 |
| Resolved name | reset_deadkey_state |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630e40, FUN_00631ff0, FUN_006345e0, FUN_006355a0, FUN_00635cb0
**Callees:** —
**Referenced globals:** 0x715b78 (repeat timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715b78

## Behavioral explanation
Clears the key auto-repeat timer/state (0x715b78=0).

## Notes / uncertainty
RENAMED from reset_key_repeat: 0x715b78 is the dead-key accent class (shared w/ FUN_00635500/006355a0), not the pad-repeat timer. Store width (byte vs wider) is the only caveat.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
