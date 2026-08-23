# 0x005e8e40 tag_setattr_str_bf6_expand

| field | value |
|---|---|
| Original address | 0x005e8e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8e40 |
| Resolved name | tag_setattr_str_bf6_expand |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e82c0, FUN_005ec1b0
**Referenced globals:** +0xbf6 (string field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: extracts string arg into +0xbf6 then runs token expansion (FUN_005e82c0) on it.

## Notes / uncertainty
Extract to +0xbf6 then FUN_005e82c0 in-place escape expansion (9-entry table PTR_DAT_006484c0 -> chars 0x6484e8, delim 0x6484f8). Table contents/delimiter char not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
