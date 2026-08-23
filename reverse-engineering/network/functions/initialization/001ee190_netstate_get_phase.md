# 0x001ee190 netstate_get_phase

| field | value |
|---|---|
| Original address | 0x001ee190 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee190 |
| Resolved name | netstate_get_phase |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0ca0, FUN_001c2770
**Callees:** —
**Referenced globals:** 0x0037a288 phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a288 phase

## Behavioral explanation
Getter for global net phase at 0x37a288.

## Notes / uncertainty
Getter for phase global 0x37a288. Enum {0 idle,1 started,3 up}; intermediate phase 2 not observed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
