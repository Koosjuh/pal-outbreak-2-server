# 0x00605d00 recv_framer_reset

| field | value |
|---|---|
| Original address | 0x00605d00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605d00 |
| Resolved name | recv_framer_reset |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00605d30, FUN_00605d60
**Callees:** —
**Referenced globals:** uRam0070cdd8 (consumed); uRam0070cde0 (expected len); uRam0070cde8 (seq); uRam0070cdf0 (active)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70cdd8; 0x70cde0; 0x70cde8; 0x70cdf0

## Behavioral explanation
Resets the length-prefixed receive framer state (bytes-consumed, expected-length, sequence, active flag).

## Notes / uncertainty
Resets length-prefixed TCP stream framer (0x70cdd8 cursor, 0x70cde0 len, 0x70cde8 state=1 header-read, 0x70cdf0 flag). Field roles inferred from reset values.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605d00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
