# 0x00637250 kbd_clear_dismiss_request

| field | value |
|---|---|
| Original address | 0x00637250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637250 |
| Resolved name | kbd_clear_dismiss_request |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00637180
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x31 flag

## Behavioral explanation
Setter: clears struct+0x31=0 (disarm the dismiss/refresh request flag).

## Notes / uncertainty
Clears +0x31=0; inverse of 637230, consumed inside 637180. Trivial, no uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
