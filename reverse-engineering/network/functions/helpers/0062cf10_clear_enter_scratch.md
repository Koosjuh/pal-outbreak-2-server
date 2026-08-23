# 0x0062cf10 clear_enter_scratch

| field | value |
|---|---|
| Original address | 0x0062cf10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cf10 |
| Resolved name | clear_enter_scratch |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062a6d0, FUN_0062bbc0
**Callees:** —
**Referenced globals:** 0x695d40 enter submachine state; 0x7154a0 name scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00695d40

## Behavioral explanation
Zeroes the enter-submachine state block at 0x695d40 (0x18) and the name scratch at 0x7154a0 (0x25).

## Notes / uncertainty
Two memsets: submachine block 0x695d40 (0x18) + name scratch 0x7154a0 (0x25). Deterministic; internal field layout defined by consumers, not this fn.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cf10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
