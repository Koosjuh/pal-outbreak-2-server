# 0x005f4ed0 scroll_input_repeat_a

| field | value |
|---|---|
| Original address | 0x005f4ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4ed0 |
| Resolved name | scroll_input_repeat_a |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f54d0
**Callees:** —
**Referenced globals:** uRam006c4618/4610(pad masks); cRam006c4628/462a(repeat key chars); cRam0070a140(repeat timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0070a140

## Behavioral explanation
Reads pad bits 0x10001 with key-repeat timing (R/K keys) and returns a scroll step (0/1/5).

## Notes / uncertainty
Menu auto-repeat, axis A (mask 0x10001, dir chars 'R'/'K'), returns step 0/1/5, timer cRam0070a140 (0x14 initial/0x04 repeat). 'R'/'K' are key ids not opcodes. Physical direction mapping inferred from step magnitude. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
