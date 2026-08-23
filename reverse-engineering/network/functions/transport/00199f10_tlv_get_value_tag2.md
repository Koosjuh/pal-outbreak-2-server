# 0x00199f10 tlv_get_value_tag2

| field | value |
|---|---|
| Original address | 0x00199f10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00199f10 |
| Resolved name | tlv_get_value_tag2 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_0019a2f0, FUN_0019a300, FUN_0019a350
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Root-store tag 2 getter: search-hit(FUN_0019a300)->0; else find-or-load(FUN_0019a350)-> +4 or 0. search-hit-returns-0 asymmetry preserved verbatim; may be decompiler artefact. Tag-2 meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00199f10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
