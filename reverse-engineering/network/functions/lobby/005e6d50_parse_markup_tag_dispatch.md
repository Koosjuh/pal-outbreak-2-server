# 0x005e6d50 parse_markup_tag_dispatch

| field | value |
|---|---|
| Original address | 0x005e6d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e6d50 |
| Resolved name | parse_markup_tag_dispatch |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30
**Callees:** —
**Referenced globals:** iRam007012a0[0] (parse mode), [2] (pending code), [3], +0x365a (counter); DAT_00648090 (charmap), 0x6470c0 (delimiter string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** piRam007012a0[0] (parse state machine mode)

## Behavioral explanation
Markup tokenizer/dispatcher: matches the token at the cursor against a keyword table (param_2, stride 0x10) via charmap, updates parser mode state (@0x7012a0[0..3]) and invokes the matched entry's handler fn-ptr (entry+3).

## Notes / uncertainty
Core markup SM: 3 modes (idle/open/close) at iRam007012a0[0]; matches 0x10-stride tag table {key,len,code,handler}, calls entry handler, codes 2/0x12 reset to idle, '<'/'&' start, delimiter-skip via 0x6470c0. Tag vocabulary/handlers unresolved; +0x365a counter offset inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e6d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
