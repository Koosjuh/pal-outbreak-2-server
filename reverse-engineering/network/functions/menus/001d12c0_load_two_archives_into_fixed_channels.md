# 0x001d12c0 load_two_archives_into_fixed_channels

| field | value |
|---|---|
| Original address | 0x001d12c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d12c0 |
| Resolved name | load_two_archives_into_fixed_channels |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8, FUN_001a79b0, FUN_001cb360, FUN_001cb5f0
**Referenced globals:** piRam003435bc work base
**Referenced strings:** 0x24cf00 template; 0x24cf20 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fetches tmpl 0x24cf00, parses up to 4 records into channels 1..4 (last=10) via FUN_001a79b0/FUN_001cb5f0, then fetches tmpl 0x24cf20 and stores into channel 5.

## Notes / uncertainty
Archive A (0x24cf00, verbatim name) first<=4 records into slots 1,2,3 with LAST routed to slot 10; archive B (0x24cf20) raw buffer into slot 5. Slot-5 lacks a decompress step (possible decompiler drop).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d12c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
