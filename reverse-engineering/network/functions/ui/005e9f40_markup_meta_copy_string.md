# 0x005e9f40 markup_meta_copy_string

| field | value |
|---|---|
| Original address | 0x005e9f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9f40 |
| Resolved name | markup_meta_copy_string |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0x1120 (gate); +0x1128 (string buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1120

## Behavioral explanation
If meta-tag flag +0x1120 set, copies the tag field string into buffer +0x1128.

## Notes / uncertainty
Gated on +0x1120: copy ="..." into meta string buffer +0x1128 (0x100). Consumed by 0x9f80.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
