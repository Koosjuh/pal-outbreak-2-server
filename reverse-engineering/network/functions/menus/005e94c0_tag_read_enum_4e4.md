# 0x005e94c0 tag_read_enum_4e4

| field | value |
|---|---|
| Original address | 0x005e94c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e94c0 |
| Resolved name | tag_read_enum_4e4 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec920
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x4e4 (enum byte)
**Referenced strings:** 0x6482b0 (0x48-byte lookup table)
**Referenced opcodes:** —
**State vars:** cfg+0x4e4

## Behavioral explanation
Extracts token, looks it up in table @0x6482b0 (0x48 bytes) and stores the resulting enum byte at cfg+0x4e4.

## Notes / uncertainty
Keyword->enum via FUN_005ec920 table@0x6482b0 (9 entries, stride 8, case-fold DAT_006493b0), stored ctx+0x4e4 (0 if no match). Keyword/enum literals not dumped; mechanics + count certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e94c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
