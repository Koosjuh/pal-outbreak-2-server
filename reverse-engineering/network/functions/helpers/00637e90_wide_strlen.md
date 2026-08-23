# 0x00637e90 wide_strlen

| field | value |
|---|---|
| Original address | 0x00637e90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637e90 |
| Resolved name | wide_strlen |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631810, FUN_00631880, FUN_00631ec0, FUN_00632390, FUN_00634010, FUN_006340d0, FUN_00634160, FUN_006341d0, FUN_00634280, FUN_00634310
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wide-char length: (bytes/2)-1 = count of shorts before the null terminator.

## Notes / uncertainty
CORRECTED: prior name wide_strlen_minus1 was a misread; the -1 cancels the terminator-inclusive scan, so it is true wide strlen (worked example AB->2).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
