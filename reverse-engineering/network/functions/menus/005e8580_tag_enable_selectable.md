# 0x005e8580 tag_enable_selectable

| field | value |
|---|---|
| Original address | 0x005e8580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8580 |
| Resolved name | tag_enable_selectable |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec100, FUN_005eef70
**Referenced globals:** +0xd892 (per-entry mode); +0xd894 (entry idx); +0x17c / +0x252f (enable flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0xd894; +0x17c; +0x252f

## Behavioral explanation
Markup tag handler: sets an enable flag (global +0x17c or per-entry +0x252f) and calls FUN_005ec100(1); toggles a selectable/highlight state.

## Notes / uncertainty
Sets selectable flag +0x17c (global) or per-entry +0x252f (stride 0x5c), palette row 1. Per-entry record layout beyond touched fields unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
