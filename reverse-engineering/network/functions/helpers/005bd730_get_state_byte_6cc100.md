# 0x005bd730 get_state_byte_6cc100

| field | value |
|---|---|
| Original address | 0x005bd730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd730 |
| Resolved name | get_state_byte_6cc100 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070
**Callees:** —
**Referenced globals:** 0x6cc100 (state byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cc100

## Behavioral explanation
Accessor returning the state byte at 0x6cc100.

## Notes / uncertainty
Pure 1-byte read of overlay state global 0x6cc100; copy mechanic certain, semantic role of the byte inferred (consumed by FUN_005b3070).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
