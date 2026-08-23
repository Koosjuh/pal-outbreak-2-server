# 0x005e8810 tag_indent_level_dec

| field | value |
|---|---|
| Original address | 0x005e8810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8810 |
| Resolved name | tag_indent_level_dec |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0
**Referenced globals:** +0x14; +0x2531; +0xd892/+0xd894
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x14; +0x2531; +0xd892

## Behavioral explanation
Markup tag handler: decrements the 4-bit level/indent counter (+0x14 nibble or +0x2531), floored at 0.

## Notes / uncertainty
Inverse of inc, floor at 0; asymmetric — omits FUN_005ef780 on per-entry path (may leave margin stale).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
