# 0x00637ed0 wide_strncpy_padded

| field | value |
|---|---|
| Original address | 0x00637ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637ed0 |
| Resolved name | wide_strncpy_padded |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631ff0, FUN_006320f0, FUN_00632390
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wide-char strncpy into param_1, up to param_3 elems, zero-padding the remainder.

## Notes / uncertainty
Standard wide strncpy with zero-pad; includes the no-terminator-when-full quirk. Pointer bookkeeping preserved verbatim.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
