# 0x00637e60 wide_strcpy

| field | value |
|---|---|
| Original address | 0x00637e60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637e60 |
| Resolved name | wide_strcpy |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00633590, FUN_00633650, FUN_00633930, FUN_00633ab0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wide-char (short*) strcpy: copies src to dest including null terminator, returns dest.

## Notes / uncertainty
Standard wide (short*) strcpy. No uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637e60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
