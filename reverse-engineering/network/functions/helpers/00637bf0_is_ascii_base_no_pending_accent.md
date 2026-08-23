# 0x00637bf0 is_ascii_base_no_pending_accent

| field | value |
|---|---|
| Original address | 0x00637bf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637bf0 |
| Resolved name | is_ascii_base_no_pending_accent |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** FUN_00635500
**Referenced globals:** 0x715b78 accent-class
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Predicate: true iff the char is NOT a recognized dead-key accent (635500 returns -1) and is <0x80 — i.e. a plain ASCII base char.

## Notes / uncertainty
Renamed from is_deadkey_accent: true iff no dead-key armed (FUN_00635500==-1) AND cp<0x80. -1 sentinel semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637bf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
