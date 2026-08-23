# 0x001ee6e0 snap_session_reset

| field | value |
|---|---|
| Original address | 0x001ee6e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee6e0 |
| Resolved name | snap_session_reset |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001ef4f0
**Referenced globals:** 0x37a2a0 (SNAP mode flag); 0x37a288 (SNAP state-machine var); 0x37a298 (SNAP mode flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288; 0x37a2a0; 0x37a298

## Behavioral explanation
Resets the SN@P session: calls FUN_001ef4f0() and clears state-machine var and two mode flags to 0 (init/teardown of session state).

## Notes / uncertainty
delegates to FUN_001ef4f0, zeroes SNAP SM var 0x37a288 (2 active->0 idle) and mode flags 0x37a298/0x37a2a0. Distinct roles of the two mode flags and return-word meaning open.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee6e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
