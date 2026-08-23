# 0x00618460 periph_open_and_poll

| field | value |
|---|---|
| Original address | 0x00618460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618460 |
| Resolved name | periph_open_and_poll |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_006186e0
**Referenced globals:** 0x3908cc (device-busy flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +1 phase; +5 unit/arg

## Behavioral explanation
Opens the async peripheral (guarded by +5 arg and busy-flag iRam003908cc) then polls to completion and forwards the result to FUN_006186e0.

## Notes / uncertainty
Open specific unit (desc+5, gated <=1) + poll to completion, forward to FUN_006186e0; -0x0f out-of-range, -2 busy/pending. Same API as 0x618230; device unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
