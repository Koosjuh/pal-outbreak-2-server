# 0x005f4fd0 scroll_input_repeat_b

| field | value |
|---|---|
| Original address | 0x005f4fd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4fd0 |
| Resolved name | scroll_input_repeat_b |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f54d0
**Callees:** —
**Referenced globals:** uRam006c4618/4610(pad masks); cRam006c4628/462a; cRam0070a148(repeat timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0070a148

## Behavioral explanation
Reads pad bits 0x20002 with key-repeat timing (Q/N keys) and returns a scroll step (0/1/5).

## Notes / uncertainty
Mirror of scroll_input_repeat_a for axis B (mask 0x20002, 'Q'/'N', timer cRam0070a148). Same 0/1/5 step key-repeat logic. Direction mapping inferred. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
