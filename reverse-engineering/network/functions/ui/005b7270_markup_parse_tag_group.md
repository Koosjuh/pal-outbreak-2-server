# 0x005b7270 markup_parse_tag_group

| field | value |
|---|---|
| Original address | 0x005b7270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7270 |
| Resolved name | markup_parse_tag_group |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b7320
**Callees:** FUN_005b6ea0, FUN_005b6f90, FUN_005b7f00
**Referenced globals:** pcRam006ca87c (parse cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** pcRam006ca87c

## Behavioral explanation
Parse a '<...>' markup tag group at the cursor, looping token->attr-apply until a terminating attribute bit (0x188) is set.

## Notes / uncertainty
Consumes back-to-back <tags> folding attrs until flags&0x188 set; skips escaped \<. Straightforward.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
