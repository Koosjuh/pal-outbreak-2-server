# 0x001cf100 load_localized_archive_into_b (uRam343634)

| field | value |
|---|---|
| Original address | 0x001cf100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf100 |
| Resolved name | load_localized_archive_into_b (uRam343634) |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cb360, FUN_001cf2b0
**Referenced globals:** uRam00343634 request arg
**Referenced strings:** 0x24cae0 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stores param_1 in uRam00343634, builds a templated message (tmpl 0x24cae0) and sends it via FUN_001cb360.

## Notes / uncertainty
Byte-twin of 0x1cf0b0 with base 0x24cae0 / global 0x343634. Dataset identity unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
