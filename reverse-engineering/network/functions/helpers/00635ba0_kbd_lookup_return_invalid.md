# 0x00635ba0 kbd_lookup_return_invalid

| field | value |
|---|---|
| Original address | 0x00635ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635ba0 |
| Resolved name | kbd_lookup_return_invalid |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00635bb0, FUN_00637430
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constant stub returning 0xffffffff (-1); used as an always-'no such key' lookup in the key-validation path.

## Notes / uncertainty
Constant return -1 (=invalid/not-found); callers gate on sign. Args ignored (stubbed lookup). Real lookup may live in another mode; Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
