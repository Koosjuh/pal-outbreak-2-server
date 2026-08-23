# 0x005fec10 screen_advance_step

| field | value |
|---|---|
| Original address | 0x005fec10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fec10 |
| Resolved name | screen_advance_step |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xf step; param_1+0x10 sub-step

## Behavioral explanation
Trivial screen transition: increment major step (+0xf) and reset sub-step (+0x10) to 0.

## Notes / uncertainty
Trivial one-shot transition: +0xf major step++, +0x10 sub-step=0. Generic, reused across FUN_005fe730 screens.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fec10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
