# 0x00618890 async_request_get_result

| field | value |
|---|---|
| Original address | 0x00618890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618890 |
| Resolved name | async_request_get_result |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aeb10, FUN_005b6300
**Callees:** —
**Referenced globals:** uRam006fe8f4 status; 0x6fe8f8 result buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006fe8f4

## Behavioral explanation
Getter: returns the async request status byte (uRam006fe8f4) and a pointer to the result buffer (0x6fe8f8).

## Notes / uncertainty
Pure getter: writes status byte uRam006fe8f4 and fixed buffer ptr 0x6fe8f8 to out params, returns 0. No mutation. Terminal status enum (0x00 ok / 0xFF err) is delivered via callback in the tick, only partly observable here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
