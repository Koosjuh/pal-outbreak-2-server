# 0x005d6a50 node_flag_test

| field | value |
|---|---|
| Original address | 0x005d6a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6a50 |
| Resolved name | node_flag_test |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d73c0, FUN_005d7760
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+1 flags

## Behavioral explanation
Generic helper: returns the node flag byte at +1 masked by param.

## Notes / uncertainty
Read (flags@+0x01 & mask); pure accessor paired with 0x6a10.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
