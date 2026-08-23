# 0x001c4020 put_string_field

| field | value |
|---|---|
| Original address | 0x001c4020 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4020 |
| Resolved name | put_string_field |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4100, FUN_001c48c0, FUN_001c5900, FUN_001c5bd0, FUN_001c7580, FUN_001c7980, FUN_001c85c0, FUN_001c8b60, FUN_001c8f50, FUN_001c94c0
**Callees:** FUN_0010a050, FUN_001c3f40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
strlen(arg) then appends it as a length-prefixed encoded string via put_tlv_blob.

## Notes / uncertainty
strlen(s) then put_tlv_blob; NUL not sent. Fully determined by callee; used by the 10 app-message text-field serializers. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
