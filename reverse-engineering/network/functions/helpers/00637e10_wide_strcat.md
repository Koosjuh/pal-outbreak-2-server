# 0x00637e10 wide_strcat

| field | value |
|---|---|
| Original address | 0x00637e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637e10 |
| Resolved name | wide_strcat |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631ec0, FUN_00631f80, FUN_006320f0, FUN_00635cb0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wide-char (short*) strcat: seeks null of dest then copies src including terminator.

## Notes / uncertainty
Standard wide (short*) strcat. No uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637e10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
