# 0x00614960 strcpy_or_clear

| field | value |
|---|---|
| Original address | 0x00614960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614960 |
| Resolved name | strcpy_or_clear |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If src ptr null writes empty string, else strcpy (safe copy helper).

## Notes / uncertainty
NULL-guarded strcpy; strcpy identity by classification, arg order convention-inferred (decompiler dropped call args).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
