# 0x005be9f0 msgbuilder_set_msgtype

| field | value |
|---|---|
| Original address | 0x005be9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be9f0 |
| Resolved name | msgbuilder_set_msgtype |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00606780
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Empty stub (returns).

## Notes / uncertainty
Inert 8-byte slot. Called once as (0x7018d0,0x1031) in FUN_00606780 reply path after inbound type match. Role inferred from single callsite; no writes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
