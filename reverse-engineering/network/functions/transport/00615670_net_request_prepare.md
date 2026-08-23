# 0x00615670 net_request_prepare

| field | value |
|---|---|
| Original address | 0x00615670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615670 |
| Resolved name | net_request_prepare |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e060, FUN_006156b0, FUN_00615778, FUN_006158c8, FUN_00615930, FUN_006159c0, FUN_00615e20, FUN_00615ea8, FUN_00615f48, FUN_00615fc8, FUN_00616048, FUN_006160a0, FUN_006160f8, FUN_00616150, FUN_006161d8, FUN_00616210, FUN_00616250, FUN_00616288
**Callees:** FUN_006155c8
**Referenced globals:** 0x70d240 (request buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70d240

## Behavioral explanation
Ensures the resolver is open (6155c8) then zeroes the 0x310-byte request buffer at 0x70d240 before a new request.

## Notes / uncertainty
Shared prologue (18 callers): ensure channel open + memset 0x310 request buffer 0x70d240. Buffer size reconciles with result_copy.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
