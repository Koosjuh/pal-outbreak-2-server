# 0x00606fa0 set_substate5_with_val

| field | value |
|---|---|
| Original address | 0x00606fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606fa0 |
| Resolved name | set_substate5_with_val |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_00607260, FUN_00607370
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets a small request-struct: byte0=5, byte1=0, dword+8=arg (parks a txn sub-state at step 5).

## Notes / uncertainty
Arms txn_request: state=5, substep=0, arg@+8. Semantic of the +8 arg (room/entry index vs reply code) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
