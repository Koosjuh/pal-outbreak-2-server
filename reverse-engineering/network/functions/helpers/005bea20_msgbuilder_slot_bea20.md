# 0x005bea20 msgbuilder_slot_bea20

| field | value |
|---|---|
| Original address | 0x005bea20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea20 |
| Resolved name | msgbuilder_slot_bea20 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005bda80, FUN_005bee40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns).

## Notes / uncertainty
Inert slot; callers bda80/bee40. Behavior (no-op) certain; specific builder role Unknown from empty body.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
