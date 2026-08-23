# 0x00634a50 expand_ext_button_bits

| field | value |
|---|---|
| Original address | 0x00634a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634a50 |
| Resolved name | expand_ext_button_bits |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Folds extended pad bits (0x10000/0x20000/0x40000/0x80000) down into the low nibble (1/2/4/8) — normalizes L/R-style extended buttons.

## Notes / uncertainty
Pure fold of extended pad bits 0x10000/20000/40000/80000 into low nibble 1/2/4/8; caller ORs back into low16. Which physical buttons those bits are is unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
