# 0x005e89f0 tag_cond_flush_entrytype

| field | value |
|---|---|
| Original address | 0x005e89f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e89f0 |
| Resolved name | tag_cond_flush_entrytype |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef0e0
**Referenced globals:** +0xd892; +0xd89a (entry-index map); +0x24fb (entry type); +0x188/+0x153c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x24fb; +0x188

## Behavioral explanation
Markup tag handler: conditional flush gated on per-entry type (+0x24fb==3/4) and per-page value +0x153c.

## Notes / uncertainty
Conditional line-break: soft-flush always; hard-flush when line pending AND (main mode) or entry type==3/4 (per-entry mode). Entry-type 3/4 meaning (list/menu row) unresolved; alt-entry record stride 0x5c.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e89f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
