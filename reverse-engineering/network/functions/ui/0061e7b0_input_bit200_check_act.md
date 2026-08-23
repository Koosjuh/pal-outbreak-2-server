# 0x0061e7b0 input_bit200_check_act

| field | value |
|---|---|
| Original address | 0x0061e7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e7b0 |
| Resolved name | input_bit200_check_act |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0061e740
**Referenced globals:** 0x29a528 (input/pad context ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x29a528+0x10 (input flag word)

## Behavioral explanation
Tests input-context bit 0x200 at (0x29a528+0x10); if set fires FUN_0061e740 and returns bool.

## Notes / uncertainty
Test bit 0x200, fire e740, return bool; call-less variant (live twin is e800).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e7b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
