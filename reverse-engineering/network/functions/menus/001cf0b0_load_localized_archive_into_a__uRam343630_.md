# 0x001cf0b0 load_localized_archive_into_a (uRam343630)

| field | value |
|---|---|
| Original address | 0x001cf0b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf0b0 |
| Resolved name | load_localized_archive_into_a (uRam343630) |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cb360, FUN_001cf2b0
**Referenced globals:** uRam00343630 request arg
**Referenced strings:** 0x24cab0 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stores param_1 in uRam00343630, builds a templated message (FUN_001cf2b0 tmpl 0x24cab0) and sends it via FUN_001cb360.

## Notes / uncertainty
Loads localized archive 0x24cab0 into caller buf, publishes dest ptr to 0x343630. Dataset identity (string not dumped) unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf0b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
