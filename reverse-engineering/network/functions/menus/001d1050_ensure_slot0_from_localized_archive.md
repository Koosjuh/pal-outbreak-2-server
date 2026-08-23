# 0x001d1050 ensure_slot0_from_localized_archive

| field | value |
|---|---|
| Original address | 0x001d1050 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1050 |
| Resolved name | ensure_slot0_from_localized_archive |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8, FUN_001a79b0, FUN_001cb360, FUN_001cb5f0, FUN_001cbcb0, FUN_001cf2b0
**Referenced globals:** piRam003435bc work base
**Referenced strings:** 0x24ce50 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If channel-slot 0 is empty (FUN_001cbcb0), fetches tmpl 0x24ce50, parses the last record via FUN_001a79b0 and stores it into slot 0 via FUN_001cb5f0.

## Notes / uncertainty
Lazy: if slot0 empty, load archive 0x24ce50, decompress LAST record into scratch, install slot 0. Slot-id map inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1050.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
