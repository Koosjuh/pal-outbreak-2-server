# 0x00618800 async_request_begin

| field | value |
|---|---|
| Original address | 0x00618800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618800 |
| Resolved name | async_request_begin |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae8a0, FUN_005b3790
**Callees:** —
**Referenced globals:** cRam006cbb44 active-flag; pcRam006cbb20 tick-cb=FUN_006188b0; pcRam006cbb24 completion-cb; iRam006fe8ec buffer base; uRam006fe8f4 status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbb44 in-progress guard; cRam006cbb40 step

## Behavioral explanation
Initializes an async network request (resolver-style) state machine: clears a 0x180 result buffer, stores base ptr + completion callback, and registers the per-frame tick FUN_006188b0.

## Notes / uncertainty
Single-slot async request latch: rejects (-1) if cRam006cbb44 already active, else arms guard, stores request buf (param_1) + completion cb (param_2), publishes tick=FUN_006188b0, memsets 0x180 result buf @0x6fe8f8. Exact control flow. Uncertainty: request payload type (DNS-resolve vs lobby query) depends on out-of-overlay 001c33xx.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
