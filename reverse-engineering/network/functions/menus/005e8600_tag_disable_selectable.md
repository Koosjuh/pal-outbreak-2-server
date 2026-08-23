# 0x005e8600 tag_disable_selectable

| field | value |
|---|---|
| Original address | 0x005e8600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8600 |
| Resolved name | tag_disable_selectable |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec100, FUN_005eef70
**Referenced globals:** +0xd892; +0xd894; +0x24fb (entry type); +0x17c / +0x252f
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0xd894; +0x24fb; +0x252f

## Behavioral explanation
Markup tag handler: clears the enable flag (+0x17c / +0x252f, guarded by entry type +0x24fb==3) and calls FUN_005ec100(0).

## Notes / uncertainty
Inverse of 0x005e8580; early-out guard when per-entry type +0x24fb==3 (locked class, inferred). Palette row 0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
