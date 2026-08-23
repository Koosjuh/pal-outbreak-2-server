# 0x00606a50 async_op_state_reset

| field | value |
|---|---|
| Original address | 0x00606a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606a50 |
| Resolved name | async_op_state_reset |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606ac0, FUN_006076c0, FUN_00623670
**Callees:** —
**Referenced globals:** uRam0070cd90 (req handle); uRam0070cd88 (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70cd90; 0x70cd88

## Behavioral explanation
Resets the async request handle/state pair (0x70cd90/0x70cd88) to idle.

## Notes / uncertainty
Zeros the async-op poll pair 0x70cd90/0x70cd88 (same slot polled by FUN_00606a70). Split of the two words inferred; both simply zeroed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
