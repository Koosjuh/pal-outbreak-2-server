# 0x001c3450 rate_clamp_step

| field | value |
|---|---|
| Original address | 0x001c3450 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3450 |
| Resolved name | rate_clamp_step |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00, FUN_001ca410
**Callees:** —
**Referenced globals:** 0x35ccb3 clamp-disable; obj+0xe0 watermark
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35ccb3

## Behavioral explanation
Increments the watermark (obj+0xe0) by param_3 toward ceiling param_2 unless override 0x35ccb3 set — companion to FUN_001c3420.

## Notes / uncertainty
Saturating-add step on accumulator obj+0xE0 toward ceiling param_2, bypassed by clamp-disable byte 0x35ccb3. Increase-companion to FUN_001c3420. Mechanics exact; semantic of the accumulator (send-window/rate credit) inferred, not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3450.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
