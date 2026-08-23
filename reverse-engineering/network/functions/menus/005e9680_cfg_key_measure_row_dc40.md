# 0x005e9680 cfg_key_measure_row_dc40

| field | value |
|---|---|
| Original address | 0x005e9680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9680 |
| Resolved name | cfg_key_measure_row_dc40 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005edc40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper invoking FUN_005edc40 (refresh/rebuild).

## Notes / uncertainty
Tail-call to FUN_005edc40 (row measure: switch cfg+0x4e4 type 0..7 → width from 0x4e6/0x3e4/0x6ec → text-measure). Selector value semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
