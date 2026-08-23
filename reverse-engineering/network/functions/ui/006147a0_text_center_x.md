# 0x006147a0 text_center_x

| field | value |
|---|---|
| Original address | 0x006147a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006147a0 |
| Resolved name | text_center_x |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612ca0, FUN_00612fd0, FUN_00613600, FUN_00613da0, FUN_00613e70, FUN_00613f40, FUN_00613fb0, FUN_00614600
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes centered X for a multibyte (SJIS/UTF-8) string given per-char width, using half-width 0x280 (=640/… half screen).

## Notes / uncertainty
UTF-8 lead-byte width classing (narrow/wide) + 0x280 center formula exact; half-vs-full width ratio and param_2 units (px vs cell) runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006147a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
