# 0x005e8750 tag_indent_level_inc

| field | value |
|---|---|
| Original address | 0x005e8750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8750 |
| Resolved name | tag_indent_level_inc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0, FUN_005ef780
**Referenced globals:** +0x14 (nibble counter); +0x2531 (per-entry counter); +0xd892/+0xd894
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x14; +0x2531; +0xd892

## Behavioral explanation
Markup tag handler: increments a 4-bit level/indent counter (global +0x14 nibble or per-entry +0x2531), saturating at 0xf.

## Notes / uncertainty
Cond-linefeed then nibble-inc level (+0x14 global / +0x2531 per-entry, saturate 0xF); per-entry path calls FUN_005ef780 (layout refresh, inferred, body not read). What the level nibble controls exactly is uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
