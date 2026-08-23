# 0x001ca6b0 util_reformat_id_string

| field | value |
|---|---|
| Original address | 0x001ca6b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca6b0 |
| Resolved name | util_reformat_id_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ca610, FUN_001ca660
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Formats an id/number field by combining ascii→int parse and int→ascii emit into a fixed layout; validates both pointers non-null.

## Notes / uncertainty
Real body: null-guard then parse 2 decimal fields (util_ascii_to_int len4) and re-emit 2 zero-padded 5-digit fields (util_int_to_ascii), NUL@10 -> 10-char id normalization. Callee semantics now confirmed from 0x1ca610/0x1ca660. Control-flow skeleton reliable; this fn's own register lineage (extraout_*) garbled, so source-offset/value-to-field pairing unproven -> Low.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca6b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
