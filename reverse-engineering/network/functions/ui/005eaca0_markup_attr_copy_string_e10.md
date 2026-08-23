# 0x005eaca0 markup_attr_copy_string_e10

| field | value |
|---|---|
| Original address | 0x005eaca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eaca0 |
| Resolved name | markup_attr_copy_string_e10 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0xe10 (string attr buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Attribute handler: copies the tag field string into buffer +0xe10 (unconditional).

## Notes / uncertainty
Copies attr value string straight into +0xe10, no gate; 256-byte cap enforced by extractor. Role (name/href) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eaca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
