# 0x00637b90 kbd_predicate_true

| field | value |
|---|---|
| Original address | 0x00637b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637b90 |
| Resolved name | kbd_predicate_true |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006379e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constant predicate returning 1 (always-allow) for the 0x0f page character class.

## Notes / uncertainty
Const-1 stub; body certain but role (page-0x0f filter placeholder) uncertain. Caller inverts so page 0x0f always rejects via this path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
