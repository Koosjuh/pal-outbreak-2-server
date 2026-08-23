# 0x005e9c30 menu_row_commit_default_0x2d3

| field | value |
|---|---|
| Original address | 0x005e9c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9c30 |
| Resolved name | menu_row_commit_default_0x2d3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef200, FUN_005ef220
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x2d3 (0x10 str)
**Referenced strings:** 0x648520 (default const string)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Runs FUN_005ef200, strcpy's const string @0x648520 into cfg+0x2d3, then FUN_005ef220 (refresh).

## Notes / uncertainty
Commit menu row with DEFAULT flag: prologue FUN_005ef200 (opaque halt_baddata), strcpy const@0x648520→cfg+0x2d3, FUN_005ef220 latch row. Default-string content & ef200 behavior opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
