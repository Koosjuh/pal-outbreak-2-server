# 0x005e82c0 text_token_expand

| field | value |
|---|---|
| Original address | 0x005e82c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e82c0 |
| Resolved name | text_token_expand |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8e40, FUN_005e9540, FUN_005e9750
**Callees:** —
**Referenced globals:** 0x6484c0 (token string ptr array[9]); 0x6484e8 (substitution char table); 0x6484f8 (delimiter string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
In-place text macro expander: scans for delimiter (0x6484f8), matches one of 9 named tokens (PTR_DAT_006484c0), replaces with single substitution char (0x6484e8) and shifts the tail.

## Notes / uncertainty
In-place text macro expander: strpbrk delimiter set 0x6484f8, match 9 token names 0x6484c0, replace with single subst byte 0x6484e8[i], memmove tail. Not network (glyph/string preprocessing). Table contents (actual token names/glyphs) not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e82c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
