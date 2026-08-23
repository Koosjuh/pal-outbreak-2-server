# 0x006188b0 async_request_tick

| field | value |
|---|---|
| Original address | 0x006188b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006188b0 |
| Resolved name | async_request_tick |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** cRam006cbb40 step; cRam006cbb44 active; cRam007006a7 cancel-flag; uRam006fe8f4 status; pcRam006cbb24 completion-cb; 0x368474/0x36846c source records
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbb40 step (0/1/2/4/5); cRam006cbb44; cRam007006a7

## Behavioral explanation
Per-frame tick for the async request machine: polls the resolver (0x1c33xx), on success copies two result records into 0x6fe8f8+ and invokes the stored completion callback with a status byte.

## Notes / uncertainty
Frame body of the request machine; step machine 0/1/2/4/5 over cRam006cbb40. Step2 stages two {ptr,len} source records (0x368474/0x368478) into the request buffer; delivers 0x00/0xFF to completion cb on finish. Poll codes 3/4 from 001c3380 inferred from consequences; case 3 absent and step 5 has no in-overlay writer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006188b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
