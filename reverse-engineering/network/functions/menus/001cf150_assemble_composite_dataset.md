# 0x001cf150 assemble_composite_dataset

| field | value |
|---|---|
| Original address | 0x001cf150 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf150 |
| Resolved name | assemble_composite_dataset |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00109728, FUN_001cb360, FUN_001cf2b0
**Referenced globals:** uRam0034362c arg; uRam00343628 arg; uRam0034357a session id; piRam003435bc work base
**Referenced strings:** 0x24cb10 template; 0x24cb40 template
**Referenced opcodes:** —
**State vars:** uRam0034357a

## Behavioral explanation
Serializes a two-part request into param_1: encodes tmpl 0x24cb10 then a per-session tmpl 0x24cb40 (uRam0034357a) via FUN_001cb360, copying each encoded record body out with FUN_001069a8; returns total size.

## Notes / uncertainty
Concatenates last record of local archive 0x24cb10 + record[3] of per-session archive (mode 0x10001) into 0x40-aligned dest; returns total len. Part-2 memcpy length arg garbled in decompile (reconstructed as work[9]).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
