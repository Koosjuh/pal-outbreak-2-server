# 0x001c0de0 advance_rotation_flag

| field | value |
|---|---|
| Original address | 0x001c0de0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0de0 |
| Resolved name | advance_rotation_flag |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** —
**Referenced globals:** 0x35cc60 rot-state; 0x35baa0 target
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35cc60; 0x35baa0

## Behavioral explanation
Rotates state var 0x35cc60 through a fixed 0->1->3->2->0 cycle and returns whether it now equals 0x35baa0.

## Notes / uncertainty
Raised Medium->High. Advances 2-bit rotor 0x35cc60 through Gray cycle 0->1->3->2->0, returns -1 when it equals expected phase 0x35baa0 else 0. Transition table fully determined; protocol role inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
