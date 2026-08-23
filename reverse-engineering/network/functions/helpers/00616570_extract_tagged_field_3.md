# 0x00616570 extract_tagged_field_3

| field | value |
|---|---|
| Original address | 0x00616570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616570 |
| Resolved name | extract_tagged_field_3 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00613600, FUN_006140d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** 0x693930 (7-byte compare prefix)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
String util: validates a dotted token (6 fields / 5 dots after a 7-byte prefix compare) and copies the 3rd dot-delimited field into a bounded output buffer; else copies the whole string.

## Notes / uncertainty
If src starts with 7B tag@0x693930 AND has exactly 5 dots, extract 3rd field bounded by size-1; else copy verbatim; -101 on NULL. Control flow exact; literal tag string + field's domain meaning unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
