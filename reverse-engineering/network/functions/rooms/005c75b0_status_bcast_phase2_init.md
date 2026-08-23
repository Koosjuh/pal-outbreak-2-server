# 0x005c75b0 status_bcast_phase2_init

| field | value |
|---|---|
| Original address | 0x005c75b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c75b0 |
| Resolved name | status_bcast_phase2_init |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7540
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** context+0x21

## Behavioral explanation
Phase-2 entry: bumps +0x21, resets page/counter/ack fields of the SM context.

## Notes / uncertainty
Phase-2 initialiser: substep 0->1, re-seeds paginator; accumulators untouched. Straight-line, certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c75b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
