# 0x00637230 kbd_request_dismiss

| field | value |
|---|---|
| Original address | 0x00637230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637230 |
| Resolved name | kbd_request_dismiss |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x31 flag

## Behavioral explanation
Setter: sets struct+0x31=1 (arm the dismiss/refresh request flag read by FUN_00637180).

## Notes / uncertainty
Sets deferred-dismiss request flag +0x31=1, consumed next frame by 637180. Single caller (006345e0); trigger condition in caller not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
